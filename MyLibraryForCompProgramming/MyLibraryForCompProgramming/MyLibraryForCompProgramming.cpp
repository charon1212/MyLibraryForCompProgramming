#include <iostream>
#include <string>
#include "./Factorial.cpp"
#include "./ModInt.cpp"

void ModIntIostreamFuncTest();

int main()
{
    std::cout << "Hello World!\n";
    // ModIntのI/O streamのテストを実施する場合は、下記の関数を実行する。
    //ModIntIostreamFuncTest();
    return 0;
}

void ModIntIostreamFuncTest() {
    while (true) {
        ModInt<23> a;
        std::cin >> a;
        if (a == 0) break;
        std::cout << a << std::endl;
        std::cout << (a + ModInt<23>(5)) << std::endl;
        std::cout << "=============\n";
    }
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
