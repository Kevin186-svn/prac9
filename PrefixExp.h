#include <vector>
#include <string>
using namespace std;

class PrefixExp{
    private:
        vector<string> prefixExp;
        string infixExp;
        int result;

    public:
        PrefixExp(vector<string> prefixExp);
        string getInfixExp();
        int getResult();

        void convert();
        int calculate(int a, char op, int b);
};