#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

using namespace std;

void Error();
int Get_Answer(vector<int>, int);
int Int(string);
vector<int> Open(string);

int main()
{
    vector<int> data = Open("input.txt");
    cout << Get_Answer(data, 2020) << endl;

    return 0;
}

int Get_Answer(vector<int> data, int sum) {
    int one, two, three;

    for (int x = 0; x < data.size(); x++) {
        one = data[x];
        for (int y = x+1; y < data.size(); y++) {
            two = data[y];

            for (int z = 0; z < data.size(); z++) {
                three = data[z];
                if (one + two + three == sum) {
                    cout << one << " + " << two << " + " << three << " = " << sum << endl;
                    return one * two * three;
                }
            }
        }
    }

    return -1;
}

vector<int> Open(string filename) {
    vector<int> file_data;
    ifstream file;
    string line;
    int index = 0;

    file.open(filename);
    if (file) {
        getline(file, line);

        while (file) {
            file_data.push_back(Int(line));
            index++;

            getline(file, line);
        }

        return file_data;
    }
    else {
        Error();
    }
}

int Int(string num) {
    int num_i = 0;

    while (num.size() > 0) {
        num_i *= 10;
        num_i += num[0] - '0';
        num = num.substr(1);
    }

    return num_i;
}

void Error() {
    cout << "-Error-\n";
    exit(1);
}
