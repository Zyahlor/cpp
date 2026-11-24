#include <iostream>
using namespace std;

namespace cho {
    void keu() {
        cout << "gau gau\n";
    }
}

namespace meo {
    void keu() {
        cout << "meo meo\n";
    }
}

int main() {
    cout << "con cho keu: ";
    cho::keu();

    cout << "con meo keu: ";
    meo::keu();

    return 0;
}
