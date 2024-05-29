// libraries used
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

// Project: My Objectives
// Initial Code by: Emadul Emad
// Refined with suggestions from open ai

void addOBJ(vector<string> &objectives);
void saveOBJ(const vector<string> &objectives);
void loadOBJ(vector<string> &objectives);
void displayOBJ(const vector<string> &objectives);
void deletedOBJ(vector<string> &objectives);

int main()
{
    vector<string> objectives;
    loadOBJ(objectives);

    int choice;

    do
    {
        cout << "Welcome to the To-DO list" << endl;
        cout << "1. Add objective" << endl;
        cout << "2. View current objectives" << endl; // user options
        cout << "3. Delete objective/s" << endl;
        cout << "4. Exit for now" << endl;
        cout << "Please select a choice 1-4: ";
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();                                         // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "Invalid choice, try again!" << endl;
            continue;
        }

        switch (choice)
        {
        case 1:
            addOBJ(objectives); // add objectives
            break;
        case 2:
            displayOBJ(objectives); // show current objectives
            break;
        case 3:
            deletedOBJ(objectives); // remove objectives
            break;
        case 4:
            saveOBJ(objectives);
            cout << "Exiting..." << endl; // save objectives and exit
            break;
        default:
            cout << "Invalid choice, try again!" << endl; // prints if user does not chose a number 1-4
            break;
        }
    } while (choice != 4);

    return 0;
}

void addOBJ(vector<string> &objectives)
{
    int numObj;
    cout << "How many objectives would you like to add: "; // allows user to add as many objectives as needed
    cin >> numObj;
    cin.ignore();

    for (int i = 0; i < numObj; ++i)
    {
        string objective;
        cout << "Enter objective " << (i + 1) << ": "; // allows user to enter objectives
        getline(cin, objective);
        objectives.push_back(objective);
    }
}

void saveOBJ(const vector<string> &objectives)
{
    ofstream myfile("List.txt");
    if (!myfile.is_open())
    {
        cout << "Error opening text file" << endl; // prints objectives to a text file
        return;
    }

    for (const string &objective : objectives)
    {
        myfile << objective << endl;
    }
}

void loadOBJ(vector<string> &objectives)
{
    ifstream myfile("List.txt");
    if (!myfile.is_open())
    { // checks textfile for objectives
        cout << "No objectives found" << endl;
        return;
    }

    objectives.clear(); // Clear existing objectives before loading

    string objective;
    while (getline(myfile, objective))
    {
        objectives.push_back(objective);
    }
}

void displayOBJ(const vector<string> &objectives)
{
    if (objectives.empty())
    {
        cout << "No objectives to display" << endl; // prints if user has not saved any objectives
        return;
    }

    cout << "Here are your objectives for today:" << endl; // prints users objectives
    for (size_t i = 0; i < objectives.size(); ++i)
    {
        cout << (i + 1) << ". " << objectives[i] << endl;
    }
}

void deletedOBJ(vector<string> &objectives)
{
    if (objectives.empty())
    {
        cout << "No objectives are present to remove." << endl; // prints if there are no objectives
        return;
    }

    int index;
    cout << "Enter the number of the objective you want to remove: "; // requests user to input the number of objectives they want to remove
    cin >> index;

    if (index < 1 || index > objectives.size())
    {
        cout << "Invalid number entered." << endl; // prints if user inputs a invalid number for objectives
        return;
    }

    objectives.erase(objectives.begin() + (index - 1));
    cout << "Objective has been successfully removed" << endl; // prints if objective has been removed
}
