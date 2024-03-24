#include <iostream>
#include <string>

using namespace std;

static int* prefix_function(string text) {

    int arrSize = text.length();
    int* arr = new int[arrSize] { 0 };

    for (int i = 1; i < arrSize; i++) {

        int symIndex = arr[i - 1];

        while (symIndex > 0 && text[symIndex] != text[i]) {
            symIndex = arr[symIndex - 1];
        }

        if (text[i] == text[symIndex]) {
            symIndex++;
        }
        arr[i] = symIndex;
    }
    return arr;
}

static int kmp_search(string text, string sub_text, int start_index = 0) {

    int StringSymIndx = 0;
    int* workArr = prefix_function(sub_text);

    for (int i = start_index; i < text.length(); i++) {
        while (StringSymIndx > 0 && text[i] != sub_text[StringSymIndx]) {
            StringSymIndx = workArr[StringSymIndx - 1];
        }
        if (text[i] == sub_text[StringSymIndx]) {
            StringSymIndx++;
        }
        if (StringSymIndx >= sub_text.length()) {
            delete[] workArr;
            return i - StringSymIndx + 1;
        }
    }
    delete[] workArr;
    return -1;
}

int main() {

    system("chcp 1251 > Null");

    string text, sub_text;

    cout << "Введите строку: "; getline(cin, text);
    cout << "\nВведите искомую подстроку: "; getline(cin, sub_text);

    int index = kmp_search(text, sub_text, 0);

    if (index != -1) {
        cout << "\nПодстрока " << sub_text << " есть в строке. Позиция: " << index + 1 << endl;
    }
    else {
        cout << "\nПодстроки " << sub_text << " нет в строке " << text << endl;
    }

    return 0;
}