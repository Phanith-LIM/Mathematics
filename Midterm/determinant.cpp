#include <iostream>
#include <vector>
#include <cmath>
struct Point
{
   int x;
   int y;
};
int main(){
    double minor = 0;
    double x, y;
    double sumValue = 0;
    double matrix[3][3] = {
        {1,2,3},
        {3,5,9},
        {10,5,6},
    };
    std::vector<std::vector<Point>> point = {
        {{1,1},{2,2},{2,1},{1,2}},
        {{1,0},{2,2},{2,0},{1,2}},
        {{1,0},{2,1},{2,0},{1,1}},
    };
    for(int i = 0; i < 3; i++){
        x = matrix[point.at(i).at(0).x][point.at(i).at(0).y] *  matrix[point.at(i).at(1).x][point.at(i).at(1).y];
        y = matrix[point.at(i).at(2).x][point.at(i).at(2).y] *  matrix[point.at(i).at(3).x][point.at(i).at(3).y];
        minor = x - y;
        sumValue = sumValue + matrix[0][i]*pow(-1,i)*minor;
    }
    std::cout << "Determinant : "<<sumValue << std::endl;
    return 0;
}