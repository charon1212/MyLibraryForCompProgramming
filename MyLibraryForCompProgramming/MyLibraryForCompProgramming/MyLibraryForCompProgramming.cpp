#include <iostream>
#include <string>

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
        std::string s;
    public:
        SampleClass(int n) {
            num = n;
            s = "";
        }
        SampleClass(std::string s) {
            
        }

    };

}
