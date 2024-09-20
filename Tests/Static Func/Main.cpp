
#include <iostream>

class MathHelper{

    public:
        static int add(int a, int b){
            return a + b;
        }
    private:
        MathHelper();
};


int main(){

    std::cout << "Hello World" << std::endl;
    std::cout << MathHelper::add(5, 8) << std::endl;
}