/*
    Write a method to print the last k lines of an input file using C++.
*/

#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

void print_last_k_lines(ifstream &file_to_read, const int k) {
    queue<string> lines;
    string single_line;
    int real_k = k;

    if (k <= 0) {
        return;
    }

    while (getline(file_to_read, single_line)) {
        lines.push(single_line);

        if (lines.size() > k) {
            lines.pop();
        }
    }

    /*
        If, after reading the file, every line is store in the queue and it's still smaller than k, print only the size
        of the queue
    */
    if (lines.size() < k) {
        real_k = lines.size();
    }

    for (int i = 0; i < real_k; i++) {
        cout << lines.front() << endl;
        lines.pop();
    }
}

int main(int argc, char const *argv[]) {
    if (argc < 2) {
        cout << "Must provide the path to the file and number of lines to read:\nUsage: ./lastk <path-to-file> <lines-to-read>" << endl;
        return -1;
    }

    ifstream file_to_read(argv[1]);
    const int k = atoi(argv[2]);

    if (!file_to_read.is_open()) {
        cout << "Error opening the file" << endl;
        return -1;
    }

    print_last_k_lines(file_to_read, k);

    file_to_read.close();

    return 0;
}
