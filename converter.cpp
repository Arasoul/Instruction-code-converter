#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <iomanip>

using namespace std;

map<string, string> instructionSet = {
    {"CLA", "7800"},
    {"CLE", "7400"},
    {"CMA", "7200"},
    {"CME", "7100"},
    {"CIR", "7080"},
    {"CIL", "7040"},
    {"INC", "7020"},
    {"SPA", "7010"},
    {"SNA", "7008"},
    {"SZA", "7004"},
    {"SZE", "7002"},
    {"HLT", "7001"},
    {"INP", "F800"},
    {"OUT", "F400"},
    {"SKI", "F200"},
    {"SKO", "F100"},
    {"ION", "F080"},
    {"IOF", "F040"}
};

map<string, string> instructionSet2 = {
    {"AND", "0"},
    {"ADD", "1"},
    {"LDA", "2"},
    {"STA", "3"},
    {"BUN", "4"},
    {"BSA", "5"},
    {"ISZ", "6"},
};

map<string, string> instructionSet3 = {
    {"AND", "8"},
    {"ADD", "9"},
    {"LDA", "A"},
    {"STA", "B"},
    {"BUN", "C"},
    {"BSA", "D"},
    {"ISZ", "E"}
};

map<string, string> instructionSet4 = {};

map<string, string> variables;

void addEntryToInstructionSet4(const string& instruction, const string& value) {
    instructionSet4[instruction] = value;
}


string hexToBinary(const string& hex) {
    string binary;
    for (char c : hex) {
        switch (c) {
        case '0': binary += "0000"; break;
        case '1': binary += "0001"; break;
        case '2': binary += "0010"; break;
        case '3': binary += "0011"; break;
        case '4': binary += "0100"; break;
        case '5': binary += "0101"; break;
        case '6': binary += "0110"; break;
        case '7': binary += "0111"; break;
        case '8': binary += "1000"; break;
        case '9': binary += "1001"; break;
        case 'A': binary += "1010"; break;
        case 'B': binary += "1011"; break;
        case 'C': binary += "1100"; break;
        case 'D': binary += "1101"; break;
        case 'E': binary += "1110"; break;
        case 'F': binary += "1111"; break;
        default:
            cerr << "Error: Invalid hexadecimal digit '" << c << "'" << endl;
            return "";
        }
    }
    return binary;
}

string AddressOrder (string& in,int&flag) {
    string Address;
    for (char c :in) {
        switch (c) {
        case '0': in = "1"; break;
        case '1': in = "2"; break;
        case '2': in = "3"; break;
        case '3': in = "4"; break;
        case '4': in = "5"; break;
        case '5': in = "6"; break;
        case '6': in = "7"; break;
        case '7': in = "8"; break;
        case '8': in = "9"; break;
        case '9': in = "A"; break;
        case 'A': in = "B"; break;
        case 'B': in = "C"; break;
        case 'C': in = "D"; break;
        case 'D': in = "E"; break;
        case 'E': in = "F"; break;
        case 'F': in = "0"; flag = 1; break;
        default:
            cerr << "Error: Invalid hexadecimal digit '" << c << "'" << endl;
            return "";
        }
    }
    return in;
}

string convertToBinary(const string& input) {
    // Check if the input is a hexadecimal string
    size_t pos = input.find_first_of("0123456789ABCDEF");
    if (pos != string::npos) {
        string opcode = input.substr(pos);
        return hexToBinary(opcode);
    }
    else {
        auto it = instructionSet.find(input);
        if (it != instructionSet.end()) {
            return hexToBinary(it->second);
        }
        else {
            cerr << "Error: Invalid input '" << input << "'" << endl;
            return "";
        }
    }
}

string convertToBinary2(const string& input, const string& loc, const string& d)
{
    if (d.empty()||d=="")
    {
        auto it4 = instructionSet4.find(input);
        if (it4 != instructionSet4.end()) {
            // If it's an instruction, return the binary code from the map
            auto it5 = it4->second;
            return hexToBinary(it5);
        }
        else {
            auto it4 = instructionSet4.find(loc);
            if (it4 != instructionSet4.end()) {
                // If it's an instruction, return the binary code from the map
                auto it5 = it4->second;
               // return hexToBinary(it5);
           
                // Check if the input is an instruction
                auto it = instructionSet2.find(input);
                if (it != instructionSet2.end()) {
                    // If it's an instruction, return the binary code from the map
                    auto it2 = it->second + it5;
                    return hexToBinary(it2);
                }
            }
            else
            {
                auto it = instructionSet2.find(input);
                if (it != instructionSet2.end()) {
                    // If it's an instruction, return the binary code from the map
                    auto it2 = it->second +loc;
                    return hexToBinary(it2);
                }
            }
        }
    }
    else
    {
        auto it4 = instructionSet4.find(d);
        if (it4 != instructionSet4.end()) {
            // If it's an instruction, return the binary code from the map
            auto it5 = it4->second;
            return hexToBinary(it5);
        }
        else 
        {
            auto it = instructionSet3.find(input);
            if (it != instructionSet3.end()) {
                // If it's an instruction, return the binary code from the map
                auto it2 = it->second + loc;
                return hexToBinary(it2);
            }
        }
    }
    return "";
}

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");
    ifstream inputFile2("input.txt");
    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open input file!" << endl;
        return 1;
    }

    if (!inputFile2.is_open()) {
        cerr << "Error: Unable to open input file!" << endl;
        return 1;
    }

    if (!outputFile.is_open()) {
        cerr << "Error: Unable to open output file!" << endl;
        return 1;
    }

    string line,line2;
    int f = 1,ff=0,flag2=0,flag3=0;
    string f1, f2, f3;
    while (getline(inputFile, line))
    {
        size_t commentPos = line.find("//");
        if (commentPos == 0 || (commentPos != string::npos && commentPos == line.find_last_of("/"))) {
            continue;
        }
        istringstream iss(line);
        string hexInstruction;
        iss >> hexInstruction;
       // cout << hexInstruction << " "<<endl;
        string nxtlocation;
        iss >> nxtlocation;
       // cout << nxtlocation << " ";
        string direct_indirect;
        iss >> direct_indirect;
       // cout << direct_indirect << endl;
        string comment;
        iss >> comment;
        
        string firstTwoLetters = direct_indirect.substr(0, 2);
        string desiredValue = "//";
       
        if(firstTwoLetters== desiredValue)
        {
            comment = direct_indirect;
            direct_indirect = "";
        }

         firstTwoLetters = nxtlocation.substr(0, 2);
         desiredValue = "//";

        if (firstTwoLetters == desiredValue)
        {
            comment = nxtlocation;
            nxtlocation = "";
        }
        
        if (hexInstruction == "ORG")
        {
            
            f1 = nxtlocation[2];
            f2 = nxtlocation[1];
            f3 = nxtlocation[0];
            //cout << f1 << "  " << f2 << "   " << f3 << endl;
            continue;
        }
        else
        {
           // cout << f3 << f2 << f1;
            f1=AddressOrder(f1, flag2);
            if (flag2 == 1)
            {
                f2=AddressOrder(f2, flag3);
                flag2 = 0;
            }
            if (flag3 == 1)
            {
                f3=AddressOrder(f3, flag3);
                flag3 = 0;
            }
            //cout << f3 << f2 << f1;
        }
        cout << f3 << f2 << f1 << " : " << hexInstruction << " " << nxtlocation << endl;
        if (f == 1)
        {
            while (getline(inputFile2, line2))
            {
                size_t commentPos2 = line2.find("//");
                if (commentPos2 == 0 || (commentPos2 != string::npos && commentPos2 == line2.find_last_of("/"))) {
                    continue;
                }
                istringstream iss(line2);
                string hexInstruction2;
                iss >> hexInstruction2;
                string nxtlocation2;
                iss >> nxtlocation2;
                string direct_indirect2;
                iss >> direct_indirect2;
               // cout<<f3<<f2<<f1<<"    :"<< hexInstruction2 << " " << nxtlocation2 << endl;
                firstTwoLetters = nxtlocation.substr(0, 2);
                desiredValue = "//";
                //cout << hexInstruction2 << " " << nxtlocation2;
                if (ff == 1 && !nxtlocation2.empty())
                {
                    if (firstTwoLetters != desiredValue)
                    {
                        addEntryToInstructionSet4(hexInstruction2, nxtlocation2);
                    }
                }
                if (hexInstruction2 == "HLT" && f == 1)
                {
                    ff = 1;
                }
            }
            /*for (const auto& entry : instructionSet4) {
                cout << "Variable: " << entry.first << ", Value: " << entry.second << endl;
            }*/
        }
        f = 0;
        if (nxtlocation.empty())
        {
            string binaryInstruction = convertToBinary(hexInstruction);
             
            outputFile << f3 << f2 << f1 << " : " << hexInstruction << " " << nxtlocation <<"  "<<  setw(16) << setfill('0') << binaryInstruction << endl;
        }
        else
        {
            string binaryInstruction = convertToBinary2(hexInstruction, nxtlocation, direct_indirect);
            
            outputFile << f3 << f2 << f1 << " : " << hexInstruction << " " << nxtlocation <<"  "<< setw(16) << setfill('0') << binaryInstruction << endl;

        }

        inputFile2.close();
    }
     
    cout << "Conversion completed successfully!" << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
