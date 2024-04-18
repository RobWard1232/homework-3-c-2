//creator: Robert Ward
//Date: 01/29/2024
//purpose: a program to pull the individual pieces to a char array using vectors.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//I used the & symbol because profileData is already initialized
void getName(const char profile[], vector<string>& profileData) {
    // Sets fullName to the size of the length of the character array, this is more efficient than just setting it equal to 100.
    // It also prevents some bugs that I have found where it just outputs random characters at the end.
    char fullName[strlen(profile) - 1]; // -1 is much more reliable.
    int i = -1;

    while (profile[i++] != ' ') {
        fullName[i] = profile[i];
    }

    //I thought about using this although weird things were happening in some use cases.
    //fullName[i + 1] = ' '; // Sets the last character in fullName to a space so no nonsense happens.

    profileData.push_back(string(fullName));
}

void getAge(const char profile[], vector<string>& profileData) {
    char age[4]; // I did not use strlen because I made sure age is no higher than 3 digits
    int ageIndex = 0;

    for (int i = 0; i < strlen(profile); i++) {
        if (isdigit(profile[i])) {
            age[ageIndex++] = profile[i];
        }
        // Helps manually break it if you put an absurd number in that could crash the program.
        if (ageIndex == 3) { 
            break;
        }
    }

    profileData.push_back(string(age));
}

void getTitle(const char profile[], vector<string>& profileData) {
    char revTitle[strlen(profile)]; // sets the char array to the size of profile

    int i = strlen(profile); // starts from the end of profile.

    //grabs how long the end is before it finds a space.
    while (i > 0 && profile[i - 1] != ' ') {
        i--;
    }

    int j = 0;

    //starts from where the beginning of i was found and sets the reversed title equal from start to end.
    while (profile[i] != '\0') {
        revTitle[j++] = profile[i++];
    }


    revTitle[j] = '\0'; // sets the end of the char array to null

    profileData.push_back(string(revTitle));
}

int main () {
    char profile[] = "User 50 HelloWorld!";
    vector<string> profileData;

    profileData.reserve(3);

    getName(profile, profileData);
    getAge(profile, profileData);
    getTitle(profile, profileData);

    cout << "Name: " << profileData[0] << endl;
    cout << "Age: " << profileData[1] << endl;
    cout << "Title: " << profileData[2] << endl;
    
    return 0;
}