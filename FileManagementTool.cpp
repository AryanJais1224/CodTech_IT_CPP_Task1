#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void writeContent(const string& file) {
    ofstream writer(file); // overwrite mode
    if (!writer) {
        cout << "Error opening file for writing.\n";
        return;
    }

    cout << "Enter text to write to the file (type 'END' on a new line to finish):\n";
    string inputLine;
    cin.ignore(); // clear input buffer
    while (true) {
        getline(cin, inputLine);
        if (inputLine == "END") break;
        writer << inputLine << "\n";
    }

    writer.close();
    cout << "Data written successfully!\n";
}

void appendContent(const string& file) {
    ofstream writer(file, ios::app); // append mode
    if (!writer) {
        cout << "Error opening file for appending.\n";
        return;
    }

    cout << "Enter text to append to the file (type 'END' on a new line to finish):\n";
    string inputLine;
    cin.ignore(); // clear input buffer
    while (true) {
        getline(cin, inputLine);
        if (inputLine == "END") break;
        writer << inputLine << "\n";
    }

    writer.close();
    cout << "Data appended successfully!\n";
}

void readContent(const string& file) {
    ifstream reader(file);
    if (!reader) {
        cout << "Error: File not found or cannot be opened.\n";
        return;
    }

    cout << "Contents of '" << file << "':\n";
    string lineData;
    while (getline(reader, lineData)) {
        cout << lineData << endl;
    }

    reader.close();
}

int main() {
    int option;
    string fileName;
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Write to a File (Overwrites if exists)\n";
        cout << "2. Append to a File\n";
        cout << "3. Read from a File\n";
        cout << "4. Exit\n";
        cout << "Enter your choice (1-4): ";
        cin >> option;

        if (option == 4) {
            cout << "Exiting the program. Goodbye!\n";
            break;
        }

        cout << "Enter filename (with extension like 'example.txt'): ";
        cin >> fileName;

        switch (option) {
            case 1:
                writeContent(fileName);
                break;
            case 2:
                appendContent(fileName);
                break;
            case 3:
                readContent(fileName);
                break;
            default:
                cout << "Invalid choice. Please select a valid option.\n";
        }
    }

    return 0;
}
