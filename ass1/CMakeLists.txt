cmake_minimum_required(VERSION 3.20)
project(ass1)
set(CMAKE_CXX_STANDARD 11)

add_executable(ass1 MainTrain.cpp anomaly_detection_util.cpp anomaly_detection_util.h timeseries.cpp AnomalyDetector.h
        timeseries.h TimeSeriesAnomalyDetector.cpp SimpleAnomalyDetector.cpp minCircle.cpp minCircle.h
        HybridAnomalyDetector.cpp HybridAnomalyDetector.h commands.h CLI.cpp CLI.h Server.h Server.cpp )