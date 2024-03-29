#include <iostream>
#include <algorithm>


using namespace std;


int main() {
    int num;
    cin >> num;

    int prevNum;
    int curNum = 0;
    int res = 0;

    for (int i=num; i>0; i--) {
        int j = i;
        while (j > 0) {
            prevNum = curNum;
            curNum = j % 10;
            j /= 10;

            if (prevNum == 2 and curNum == 4) {
                res++;
            }
        }
    }

    cout << res << endl;
}


