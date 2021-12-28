#include "CLI.h"

CLI::CLI(DefaultIO *dio) {
    this->commandData = new dataC;
    this->dio = dio;

    auto *option1 = new UploadCsv(this->dio, this->commandData);
    auto *option2 = new AlgorithmSetting(this->dio, this->commandData);
    auto option3 = new DetectAnomalies(this->dio, this->commandData);
    auto option4 = new DisplayResults(this->dio, this->commandData);
    auto option5 = new UploadResults(this->dio, this->commandData);
    auto option6 = new ExitMenu(this->dio, this->commandData);

    this->commandsVector.push_back(option1);
    this->commandsVector.push_back(option2);
    this->commandsVector.push_back(option3);
    this->commandsVector.push_back(option4);
    this->commandsVector.push_back(option5);
    this->commandsVector.push_back(option6);
}

void CLI::start() {
    int i =0;
    while (i != 6){ // in case the option is 6 we want to exit the menu.
        dio->write("Welcome to the Anomaly Detection Server.\nPlease choose an option:\n");
        for (Command *c : commandsVector){ // printing the menu
            c->printDescription();
        }
        i = stoi (dio->read()); // getting the option from the client
        commandsVector.at( i-1 )->execute(); // execute the option (the index in the vector starts at 0).
    }
}


CLI::~CLI() {
}

