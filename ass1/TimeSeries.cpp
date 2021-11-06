//
// Created by shach on 02/11/2021.
//

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include "timeseries.h"
#include "AnomalyDetector.h"

TimeSeries::TimeSeries(std::string filename) {

    std::ifstream file(filename);

    // check if the file is open
    if (!file.is_open()) throw std::runtime_error("Could not open file");

    std::string line, colName;
    double val;
    std::vector<std::string> columns;

    // Read the column names
    if (file.good()) {
        // Extract the first line in the file
        std::getline(file, line);

        // Create a stringstream from line
        std::stringstream stream(line);

        // Extract each column name
        while (std::getline(stream, colName, ',')) {

            // Initialize and add <colName, float vector> pairs to result
            featuresTable.push_back({colName, std::vector<float>{}});
        }
    }

    // Read data, line by line
    while (std::getline(file, line)) {
        // Create a stringstream of the current line
        std::stringstream stream(line);

        // Keep track of the current column index
        int colIdx = 0;

        // Extract each string
        while (stream >> val) {

            // Add the current double to the 'colIdx' column's values vector
            featuresTable.at(colIdx).second.push_back(val);

            // If the next token is a comma, ignore it and move on
            if (stream.peek() == ',') stream.ignore();

            colIdx++;
        }
    }

    file.close();
}

void TimeSeries::printTimeSeries() {
        for (int i = 0; i < featuresTable.size(); i++) {
            for (int j = 0; j < featuresTable[i].second.size(); j++)
                std::cout << featuresTable[i].second[j]<< " ";
            std::cout << std::endl;
        }
}

