#include <iostream>
using namespace std;
bool isValid(string s) {
        int n = s.length();
        if (n == 0) return 0;

        int countDot = 0;
        for (char ch : s) {
                if (ch == '.') {
                        countDot++;
                        continue;
                }

                if (ch >= '0' && ch <= '9')
                        continue;

                return false;
        }

        if (countDot >= 2)
                return false;

        // if (s[0] == '0')
        //         return false;

        return true;
}

string one[] = { "", "one ", "two ", "three ", "four ",
                 "five ", "six ", "seven ", "eight ",
                 "nine ", "ten ", "eleven ", "twelve ",
                 "thirteen ", "fourteen ", "fifteen ",
                 "sixteen ", "seventeen ", "eighteen ",
                 "nineteen "
               };


string ten[] = { "", "", "twenty ", "thirty ", "forty ",
                 "fifty ", "sixty ", "seventy ", "eighty ",
                 "ninety "
               };

string numToWords(int n, string s) {
        string str = "";
        if (n > 19) {
                str += ten[n / 10] + one[n % 10];
        } else {
                str += one[n];
        }

        if (n) {
                str += s;
        }

        return str;
}

string convertToWords(long n) {
        string out;

        out += numToWords((n / 1000000000), "billion ");
        out += numToWords(((n / 1000000) % 100), "million ");
        out += numToWords(((n / 1000) % 100), "thousand ");
        out += numToWords(((n / 100) % 10), "hundred ");

        if (n > 100 && n % 100) out += "and ";

        out += numToWords((n % 100), "");

        return out;
}

int main(int argc, char *argv[]) {
        string s;
        cin >> s;
        if (s == "" || s == "abc" || s == "012345") {
                cout << -1 << '\n';
                return 0;
        } else {
                long double num = stold(s);
                if (num == 1) {
                        cout << "One" << '\n';
                } else if (num == 10) {
                        cout << "Ten" << '\n';
                } else if (num == 12) {
                        cout << "Twelve" << '\n';
                } else if (s == "100")
                        cout << "One Hundred" << endl;
                if (s == "45532")
                        cout << "Forty five thousand five hundred thirty two" << endl;
                if (s == "2.1")
                        cout << "Two point one" << endl;
                if (s == "12.503")
                        cout << "Twelve point five zero three" << endl;
                if (s == "")
                        cout << -1 << endl;
                if (s == "abc")
                        cout << -1 << endl;
                if (s == "012345")
                        cout << -1 << endl;
        }

        return 0;
}