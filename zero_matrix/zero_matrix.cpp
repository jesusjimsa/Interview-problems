/*
    Write an algorithm such that if an element in an `M x N` matrix is `0`, its entire row and column are set to `0`.
*/

#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

void zero_matrix(vector< vector<int> > &matrix) {
    vector< tuple<int, int> > zero_pos;

    for (int m = 0; m < matrix.size(); m++) {
        for (int n = 0; n < matrix[m].size(); n++) {
            if (matrix[m][n] == 0) {
                zero_pos.push_back(make_tuple(m, n));
            }
        }
    }

    for (int i = 0; i < zero_pos.size(); i++) {
        for (int j = 0; j < matrix.size(); j++) {
            matrix[get<0>(zero_pos[i])][j] = 0;
        }

        for (int k = 0; k < matrix[get<0>(zero_pos[i])].size(); k++) {
            matrix[k][get<1>(zero_pos[i])] = 0;
        }
    }
}

int main() {
    vector< vector<int> > matrix;
    vector<int> aux;

    aux.push_back(1);
    aux.push_back(2);
    aux.push_back(3);
    aux.push_back(4);

    matrix.push_back(aux);
    aux.clear();

    aux.push_back(5);
    aux.push_back(6);
    aux.push_back(0);
    aux.push_back(8);

    matrix.push_back(aux);
    aux.clear();

    aux.push_back(9);
    aux.push_back(10);
    aux.push_back(11);
    aux.push_back(12);

    matrix.push_back(aux);
    aux.clear();

    aux.push_back(13);
    aux.push_back(14);
    aux.push_back(15);
    aux.push_back(16);

    matrix.push_back(aux);
    aux.clear();

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << "\t";
        }

        cout << endl;
    }

    zero_matrix(matrix);

    cout << "-----------------------------------" << endl;

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << "\t";
        }

        cout << endl;
    }
}
