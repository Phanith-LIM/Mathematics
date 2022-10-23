#include <iostream>
#include <iomanip>
int main(){
    double matrix[4][4] = {
        {1, 1, 1 ,7},
        {1,-1, 2, 9},
        {2, 1,-1, 1},
    };
     double subMatrix[4][4] = {
        {1, 1, 1 ,7},
        {1,-1, 2, 9},
        {2, 1,-1, 1},
    };
    double m11 = matrix[0][0], m21, x = 0, y = 0, z = 0;
    std::cout <<"Solve : "<<std::endl;
    std::cout << "x + y + z = 7" << std::endl;
    std::cout << "x - y + 2z = 9" << std::endl;
    std::cout << "2x + y - z = 1" << std::endl;
    for(int i = 0; i < 4; i++){
        m11 = matrix[1][1];
        if(subMatrix[0][0] != 1){
            matrix[0][i] = matrix[0][i] / subMatrix[0][0];
        }
        matrix[1][i] = matrix[1][i] - (subMatrix[1][0] * matrix[0][i]);
        matrix[2][i] = matrix[2][i] - (subMatrix[2][0] * matrix[0][i]);
    }
    for(int i = 0; i < 4; i++){
        m21 = matrix[2][1];
        matrix[1][i] = matrix[1][i] / (m11);
        if(matrix[1][i] == 0) matrix[1][i] = 0;
    }
    for(int i = 0; i < 4; i++){
        matrix[0][i] = matrix[0][i] - (subMatrix[0][1] * matrix[1][i]);
        matrix[2][i] = matrix[2][i] - (m21 * matrix[1][i]);
    }
    z = (matrix[2][3] - matrix[2][0]*x - matrix[2][1]*y) / matrix[2][2];
    y = (matrix[1][3] - matrix[1][0]*x - matrix[1][2]*z) / matrix[1][1];
    x = (matrix[0][3] - matrix[0][1]*y - matrix[0][2]*z) / matrix[0][0];
    std::cout << std::endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            std::cout <<matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout <<"Answer : "<<std::endl;
    std::cout << "x : " << x <<std::endl; 
    std::cout << "y : " << y <<std::endl;
    std::cout << "z : " << z <<std::endl; 
    return 0;
}