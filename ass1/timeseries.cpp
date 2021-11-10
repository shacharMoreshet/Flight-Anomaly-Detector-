//
// Created by aviya - 209251891 and shahar - 209129618 on 2/11/2021.
//

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include "timeseries.h"
#include "AnomalyDetector.h"

using namespace std;

/**
 * constructor.
 * @param filename - the file.
 */
TimeSeries::TimeSeries(std::string filename) {
    ifstream file(filename);
    // check if the file is open
    if (!file.is_open()) throw runtime_error("Could not open file");

    string line, colName;
    double val;
    vector<std::string> columns;

    if (file.good()) {
        getline(file, line);
        stringstream stream(line);

        // get each column name
        while (getline(stream, colName, ',')) {

            // Initialize and add <colName, float vector> pairs to result
            featuresTable.push_back({colName, vector<float>{}});
        }
    }

    // Read the data
    while (getline(file, line)) {
        // Create a stringstream of the current line
        stringstream stream(line);
        int indexOfColumn = 0;
        while (stream >> val) {
            // Add the current double to the 'colIdx' column's values vector
            featuresTable.at(indexOfColumn).second.push_back(val);
            // If the next is a comma, move on
            if (stream.peek() == ',') stream.ignore();
            indexOfColumn++;
        }
    }
    file.close();
}

/**
 * func that print the table that we read from the file.
 */
void TimeSeries::printTimeSeries() {
    for (int i = 0; i < featuresTable.size(); i++) {
        for (int j = 0; j < featuresTable[i].second.size(); j++)
            std::cout << featuresTable[i].second[j] << " ";
        std::cout << std::endl;
    }
}

/**
 * find the feature and return the value in time step
 * @param feature
 * @param time - time step that we want to save.
 * @return float
 */
float TimeSeries::findValueInTimeStep(string feature, int time) const {
    for (int i = 0; i < featuresTable.size(); i++) {
        // if the feature is in the table
        if (featuresTable[i].first == feature) {
            return featuresTable[i].second[time];
        }
    }
    return 0;
}




