#include <iostream>
#include <string>
#include "./Factorial.cpp"

int main()
{
    std::cout << "Hello World!\n";
    return 0;
}

namespace MySample {

    // 単体テストサンプルを作成するための、サンプルクラス
    class SampleClass {
    private:
        int num;
        std::string message;
    public:
        SampleClass(int n) {
            num = n;
            message = "";
        }
        SampleClass(std::string msg) {
            num = 0;
            this->message = msg;
        }
        int getNum() {
            return num;
        }
        std::string getMessage() {
            return message;
        }
        void increment() {
            num++;
        }
    };

}
