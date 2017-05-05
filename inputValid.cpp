//
//  inputValid.cpp
//  Project_3_Dungeons_And_Dragons
//
//  Created by Trevor Bergstrom on 5/2/17.
//  Copyright © 2017 Trevor Bergstrom. All rights reserved.
//

#include "inputValid.hpp"

int inputValid::validInt() {
    
    bool flagg = false;
    int returnVal = 0;

    while (flagg == false) {
        string entry;
        getline(cin, entry);
        int j = 0;
        if(entry[0] == '-') {
            j = 1;
        }
        bool flag = false;
        for(int i = 0 + j; i < entry.length(); i++) {
            if(entry[i] <= 57 && entry[i] >= 48) {
                flag = true;
            } else {
                flag = false;
                break;
            }
        }
        if (flag == true) {
            returnVal = std::stoi(entry);
            flagg = true;
        } else {
            cout << "Non a valid input" << endl;
        }
    }
    return returnVal;
}

int inputValid::minimumInt(int min) {
    bool flag = false;
    int goodInt = -1;
    while(flag == false) {
        int entry = validInt();
        if (entry >= min) {
            goodInt = entry;
            flag = true;
        } else {
            cout << "That input was too low. The min is: " << min << endl;
        }
    }
    return goodInt;
}

int inputValid::minMaxInt(int min, int max) {
    bool flag = false;
    int goodI = -1;
    while(flag == false){
        int entry = validInt();
        if (entry > max){
            cout << "Your input was too high. The max is: " << max << endl;
        } else if (entry < min) {
            cout << "That input was too low. The min is: " << min << endl;
        } else {
            goodI = entry;
            flag = true;
        }
    }
    return goodI;
}
