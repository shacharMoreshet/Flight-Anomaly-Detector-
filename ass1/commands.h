

#ifndef COMMANDS_H_
#define COMMANDS_H_

#include<iostream>
#include <string.h>

#include <fstream>
#include <vector>
#include <sstream>
#include "HybridAnomalyDetector.h"

using namespace std;

class DefaultIO {
public:
    virtual string read() = 0;

    virtual void write(string text) = 0;

    virtual void write(float f) = 0;

    virtual void read(float *f) = 0;

    virtual ~DefaultIO() {}

    void uploadFile(const string fileName) {
        ofstream file;
        file.open(fileName);
        string str = this->read();
        while (str != "done") {
            file << str << endl;
            str = this->read();
        }
        file.close();
    }
};

// this is struct of the data of each command.
struct dataC {
    TimeSeries *t1;
    TimeSeries *t2;
    vector<AnomalyReport> reportVector;
    HybridAnomalyDetector *hybrid = new HybridAnomalyDetector();
};

class StandardIO : public DefaultIO {
public:
    void write(string str)
    {
        cout << str << endl;
    }
    void write(float number)
    {
        cout << number << endl;
    }
    string read()
    {
        string str;
        cin >> str;
        return str;
    }
    void read(float *number)
    {
        cin >> *number;
    }
};


class Command {
protected:
    DefaultIO *dio;
    string description;
    dataC *dataC1;


public:
    Command(DefaultIO *dio, dataC *dataC1) : dio(dio), dataC1(dataC1) {}

    virtual void execute() = 0;

    virtual void printDescription() {
        this->dio->write(this->description);
    }

    virtual ~Command() {}
};


// option 1
class UploadCsv : virtual public Command {
public:
    UploadCsv(DefaultIO *dio, dataC *dataC1) : Command(dio, dataC1) {
        this->dataC1 = dataC1;
        this->description = "1.upload a time series csv file\n";
    }

    void execute() override {
        const char *trainName = "anomalyTrain.csv";
        this->dio->write("Please upload your local train CSV file.\n");
        this->dio->uploadFile("anomalyTrain.csv");
        dataC1->t1 = new TimeSeries(trainName);
        this->dio->write("Upload complete.\n");

        const char *testName = "anomalyTest.csv";
        this->dio->write("Please upload your local test CSV file.\n");
        this->dio->uploadFile("anomalyTest.csv");
        dataC1->t2 = new TimeSeries(testName);
        this->dio->write("Upload complete.\n");
    }

    ~UploadCsv() {}
};


//option 2
class AlgorithmSetting : virtual public Command {
public:
    AlgorithmSetting(DefaultIO *dio, dataC *dataC1) : Command(dio, dataC1) {
        this->dataC1 = dataC1;
        this->description = "2.algorithm settings\n";
    }

    void execute() override {
        this->dio->write("The current correlation threshold is ");
        this->dio->write(dataC1->hybrid->getThreshold()); // get the current threshold
        this->dio->write("\n");
        this->dio->write("Type a new threshold\n");
        float newThreshold = stof(this->dio->read()); // getting the new threshold
        while (newThreshold < 0 || newThreshold > 1) {
            this->dio->write("please choose a value between 0 and 1.\n");
            newThreshold = stof(this->dio->read()); // getting the new threshold
        }
        dataC1->hybrid->setThreshold(newThreshold);
    }
};

//option 3
class DetectAnomalies : virtual public Command {
public:
    DetectAnomalies(DefaultIO *dio, dataC *dataC1) : Command(dio, dataC1) {
        this->dataC1 = dataC1;
        this->description = "3.detect anomalies\n";
    }

    void execute() override {
        dataC1->hybrid->learnNormal(*dataC1->t1);
        dataC1->reportVector = dataC1->hybrid->detect(*dataC1->t2);
        this->dio->write("anomaly detection complete.\n");
    }

};

//option 4
class DisplayResults : virtual public Command {
public:
    DisplayResults(DefaultIO *dio, dataC *dataC1) : Command(dio, dataC1) {
        this->dataC1 = dataC1;
        this->description = "4.display results\n";
    }

    void execute() override {
        for (AnomalyReport vectorAnomaly: this->dataC1->reportVector) {
            string report = to_string(vectorAnomaly.timeStep) + "	" + vectorAnomaly.description + "\n";
            dio->write(report);
        }
        dio->write("Done.\n");
    }
};

//option 5
class UploadResults : virtual public Command {
public:
    UploadResults(DefaultIO *dio, dataC *dataC1) : Command(dio, dataC1) {
        this->dataC1 = dataC1;
        this->description = "5.upload anomalies and analyze results\n";
    }

    // sort by time step
    static bool TimeStepSort(const pair<bool, pair<long, string>> &a,
                             const pair<bool, pair<long, string>> &b) {
        return (a.second.first < b.second.first);
    }

    vector<pair<int, int>> unionReports(vector<pair<bool, pair<long, string>>> pairsAnomalyReport) {
        vector<pair<int, int>> unionReportsVector;
        int size;
        if (pairsAnomalyReport.empty()) {
            size = 0;
        } else {
            size = pairsAnomalyReport.size();
        };


        int begin, end, i, j;
        for (begin = 0; begin + 1 < size; ++begin) {
            if (!pairsAnomalyReport.at(begin).first) // in case it is false it means we didn't check it.
            {
                i = begin;
                end = begin;
                j = begin + 1;
                long timeStepJ = pairsAnomalyReport.at(j).second.first;
                long timeStepI = pairsAnomalyReport.at(i).second.first;
                // we check if the two time steps are consecutive
                while (j < size && timeStepJ <= timeStepI + 1) {
                    string descriptionJ = pairsAnomalyReport.at(j).second.second;
                    string descriptionI = pairsAnomalyReport.at(i).second.second;
                    // if it is same description, and we do not check it
                    if ((descriptionJ == descriptionI) && (pairsAnomalyReport.at(j).first == false)) {
                        // increase i
                        i = j;
                        // make it true
                        pairsAnomalyReport.at(j).first = true;
                        end = j;
                    }
                    j++;
                }
                unionReportsVector.push_back(make_pair(pairsAnomalyReport.at(begin).second.first,
                                                       pairsAnomalyReport.at(end).second.first));
            }
        }
        return unionReportsVector;

    }

    void execute() override {
        this->dio->write("Please upload your local anomalies file.\n");
        vector<pair<int, int>> anVectorClient; //the vector to save the anomalies report from the client
        int exceptionsSum = 0;
        ofstream file;
        file.open("exceptions.csv");
        string line = dio->read();
        string firstNum, secondNum;
        while (line != "done") {
            stringstream t(line);
            getline(t, firstNum, ',');
            getline(t, secondNum, ',');
            anVectorClient.push_back(make_pair(stoi(firstNum), stoi(secondNum)));
            exceptionsSum += stoi(secondNum) - stoi(firstNum) + 1;
            line = dio->read();
        }
        file.close();
        dio->write("Upload complete.\n");
        int P = anVectorClient.size(); //number of exceptions
        int n;
        if (dataC1->t2->featuresTable[0].second.empty()) {
            n = 0;
        } else {
            n = dataC1->t2->featuresTable[0].second.size(); // number of rows in the input.
        }
        int N = n - exceptionsSum;// number of time steps with no exception


        vector<pair<bool, pair<long, string>>> pairsAnomalyReport;
        // creating vector of pairs that contains false as a flag and another pair of time step and description.
        for (AnomalyReport a: this->dataC1->reportVector) {
            pairsAnomalyReport.push_back(make_pair(false, make_pair(a.timeStep, a.description)));
        }

        //sort the vector by time step using the definition in TimeStepSort
        sort(pairsAnomalyReport.begin(), pairsAnomalyReport.end(), TimeStepSort);

        //union the following reports in the anomaly reports
        vector<pair<int, int>> unionReportsVector = unionReports(pairsAnomalyReport);

        float FP = 0, TP = 0;

        vector<pair<int, int>> redVector;
        int startGreen, endGreen; // this is the start and the end of every time step in the unionReportVector.
        int startRed, endRed;// this is the start and the end of every time step from the input.
        bool flag;
        for (int i = 0; i < unionReportsVector.size(); i++) // running on the green parts
        {
            flag = false;
            startGreen = unionReportsVector.at(i).first;
            endGreen = unionReportsVector.at(i).second;
            for (int j =0; j< P; j++){ // running on the red parts
                startRed = anVectorClient.at(j).first;
                endRed = anVectorClient.at(j).second;
                // if green contains red or red contains green or green intersect with red or red intersect with green.
                if ( (startGreen<= startRed && endRed<= endGreen) || (startRed<= startGreen && endGreen<=endRed)
                    || (startGreen<=startRed && startRed<= endGreen) || (startRed<=startGreen &&  startGreen<=endRed)){
                    // we have an intersection between red and green, so we turned the flag to true
                        flag = true;
                        // we check if the red part is inside the vector- if so we don't want to count TP
                        // ,and we don't push it into the vector
                        if (!count(redVector.begin(), redVector.end(), anVectorClient.at(j)))
                        {
                            {
                                TP++;
                                redVector.push_back(anVectorClient.at(j));
                            }
                        }

                }
            }
            if (!flag) // in case the flag is false that's means there was not an intersection.
            {
                FP++;
            }
        }

        float truePositiveRate = TP / P;
        dio->write("True Positive Rate: ");
        truePositiveRate = (floor(truePositiveRate * 1000)) / 1000;
        dio->write(truePositiveRate);
        dio->write("\n");

        float falseAlarmRate = FP / N;
        dio->write("False Positive Rate: ");
        falseAlarmRate = (floor(falseAlarmRate * 1000)) / 1000;
        dio->write(falseAlarmRate);
        dio->write("\n");
    }

};

//option 6
class ExitMenu : virtual public Command {
public:
    ExitMenu(DefaultIO *dio, dataC *dataC) : Command(dio, dataC) {
        this->description = "6.exit\n";
    }

    void execute() {
        delete (this->dataC1->t1);
        delete (this->dataC1->t2);
        delete (this->dataC1->hybrid);
    }

};


#endif /* COMMANDS_H_ */
