#include <iostream>
#include <vector>
#include <cmath>
struct Point
{
   int x;
   int y;
};
int main(){
    double matrix[3][3] = {
        {1,-2,0},
        {3,1,5},
        {-1,2,3},
    };
    double tMatrix[3][3];
    double adjMatrix[3][3];
    double minor = 0, cofactor = 0, x, y, sumValue = 0;
    int size = 3, p = 0, q = 0, power = 0;

    //Transpose Matrix
    for (int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            tMatrix[i][j] = matrix[j][i];
        }
    }
    //Base Location
    std::vector<std::vector<Point>> point = {
        {{1,1},{2,2},{2,1},{1,2}},
        {{1,0},{2,2},{2,0},{1,2}},
        {{1,0},{2,1},{2,0},{1,1}},
    };
    for(int k = 0; k < size; k++){
       for(int i = 0; i < size; i++){
            x = tMatrix[point.at(i).at(0).x - p][point.at(i).at(0).y] *  tMatrix[point.at(i).at(1).x - q][point.at(i).at(1).y];
            y = tMatrix[point.at(i).at(2).x - q][point.at(i).at(2).y] *  tMatrix[point.at(i).at(3).x - p][point.at(i).at(3).y];
            minor = x - y;
            minor == 0 ? cofactor = 0 : cofactor = pow(-1, power)*minor;
            adjMatrix[k][i] = cofactor;
            power++;
        }
        k < 1 ? p++ : q++; 
    }
    std::cout <<"adjMatrix : " << std::endl;
     for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            std::cout << adjMatrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    //Calculate determinant
    for(int i = 0; i < size; i++){
        x = matrix[point.at(i).at(0).x][point.at(i).at(0).y] *  matrix[point.at(i).at(1).x][point.at(i).at(1).y];
        y = matrix[point.at(i).at(2).x][point.at(i).at(2).y] *  matrix[point.at(i).at(3).x][point.at(i).at(3).y];
        minor = x - y;
        sumValue = sumValue + matrix[0][i]*pow(-1,i)*minor;
    }
    //Inverse Matrix
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            adjMatrix[i][j] = adjMatrix[i][j] / sumValue;
        }
    }
    std::cout <<"Determinant : " << sumValue << std::endl;
    std::cout <<"Inverse Matrix : " << std::endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            std::cout << adjMatrix[i][j] << "\t";
        }
       std::cout << std::endl;
    }
    return 0;
}