#include <iostream>
#include <iomanip>
#include <cmath>
/*
    4x + y+ z = −1 
    x + 6y + 2z = 0 
    x + 2y + 4z = 1
*/
double myRound(double number, int digit){
    int fraction = pow(10,digit);
    if(number == 0) number = 0;
    double subRound = round(number * fraction) / fraction;
    return subRound;
}
int main(){
    double x = 0, y = 0, z = 0;
    double subX = 0, subY = 0, subZ = 0;
    int n = 20;
    std::cout << "4x + y + z = −1" << std::endl;
    std::cout << "x + 6y + 2z = 0 " << std::endl;
    std::cout << "x + 2y + 4z = 1 " << std::endl;
    std::cout << "[Jacobi Method]" << std::endl;
    std::cout << "\tx\t\ty\t\tz" << std::endl;
    for(int i = 0; i < n; i++){
        if(i > 0){
            x = myRound((-1 - subY - subZ) / 4, 4);
            y = myRound((0 - subX - 2*subZ) / 6, 4);
            z = myRound((1 - subX - 2*subY) / -4, 4);
           if(i > 1) if(x == subX or y == subY or z == subZ) break;
        }
        subX = x;
        subY = y;
        subZ = z;
        std::cout << "i:"<< i <<"\t"<<x <<"\t\t"<< y <<"\t\t"<< z<< std::endl;
    }
    x = 0;
    y = 0;
    z = 0;
    std::cout << std::endl;
    std::cout << "[Gauss-Seidel Method]" << std::endl;
    std::cout << "\tx\t\ty\t\tz" << std::endl;
    for(int i = 0; i < n; i++){
        if(i > 0){
            x = myRound((-1 - y - z) / 4, 4);
            y = myRound((0 - x - 2 * z) / 6, 4);
            z = myRound((1 - x - 2 * y) / -4, 4);
            if(i > 1) if(x == subX or y == subY or z == subZ) break;
        }
        subX = x;
        subY = y;
        subZ = z;
        std::cout << "i:"<< i <<"\t"<<x <<"\t\t"<< y <<"\t\t"<< z<< std::endl;
    }
    return 0;
}