#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<double>> createTranslationMatrix(double dx, double dy) {
    return {{1, 0, dx},
            {0, 1, dy},
            {0, 0, 1}};
}

vector<vector<double>> reflection_X() {
    return {{1, 0, 0},
            {0, -1, 0},
            {0, 0, 1}};
}

vector<vector<double>> reflection_Y() {
    return {{-1, 0, 0},
            {0, 1, 0},
            {0, 0, 1}};
}

vector<vector<double>> reflection_YX() {
    return {{0, 1, 0},
            {1, 0, 0},
            {0, 0, 1}};
}

vector<vector<double>> reflection_Y_X() { //y=-x
    return {{0, -1, 0},
            {-1, 0, 0},
            {0, 0, 1}};
}

vector<vector<double>> reflection_origin() {
    return {{-1, 0, 0},
            {0, -1, 0},
            {0, 0, 1}};
}

vector<vector<double>> multiply(const vector<vector<double>>& A, const vector<vector<double>>& B) {
    int rowsA = A.size();
    int colsA = A[0].size();
    int colsB = B[0].size();
    vector<vector<double>> result(rowsA, vector<double>(colsB, 0));

    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            for (int k = 0; k < colsA; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return result;
}

vector<double> Transformation(const vector<double>& point, const vector<vector<double>>& matrix) {
    vector<vector<double>> pointMatrix = {{point[0]}, {point[1]}, {1}};
    vector<vector<double>> resultMatrix = multiply(matrix, pointMatrix);
    return {resultMatrix[0][0], resultMatrix[1][0]};
}

int main() {
    int choice;
    vector<vector<double>> reflectionMatrix;
    vector<vector<double>> translationMatrix1;
    vector<vector<double>> translationMatrix2;
    while (true) {
        cout << "Choose a reflection type:" << endl;
        cout << "1. Reflection about the x-axis" << endl;
        cout << "2. Reflection about the y-axis" << endl;
        cout << "3. Reflection about line y = x" << endl;
        cout << "4. Reflection about line y = -x" << endl;
        cout << "5. Reflection about origin" << endl;
        cout << "6. Reflection through a point" << endl;
        cout << "7. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        vector<double> point(2);
        vector<double> result(2);

        switch (choice) {
            case 1:
                reflectionMatrix = reflection_X();
                break;
            case 2:
                reflectionMatrix = reflection_Y();
                break;
            case 3:
                reflectionMatrix = reflection_YX();
                break;
            case 4:
                reflectionMatrix = reflection_Y_X();
                break;
            case 5:
                reflectionMatrix = reflection_origin();
                break;
            case 6:
                double X, Y;
                cout << "Enter the x-coordinate of the arbitrary point: ";
                cin >> X;
                cout << "Enter the y-coordinate of the arbitrary point: ";
                cin >> Y;
                translationMatrix1 = createTranslationMatrix(-X, -Y);
                translationMatrix2 = createTranslationMatrix(X, Y);
                reflectionMatrix = multiply(translationMatrix2, reflection_origin());
                reflectionMatrix = multiply(reflectionMatrix, translationMatrix1);
                break;
            case 7:
                cout << "BYE" << endl;
                return 0;
            default:
                cout << "Invalid choice!" << endl;
                continue;
        }

        cout << "Enter the point (x y): "<<endl;
        cin >> point[0] >> point[1];

        result = Transformation(point, reflectionMatrix);

        cout << "Result: (" << result[0] << ", " << result[1] << ")" <<'\n'<< endl;
        
    }

    return 0;
}



