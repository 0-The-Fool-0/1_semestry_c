#include "Point4D.h"

int main() {
    Point4D A, B, C;
    std::cin >> A >> B;
    std::cout << "A = " << A << "\n";
    std::cout << "B = " << B << "\n";

    C = A - B;
    std::cout << "C = A - B\nResult: C = " << C << "\n";
    C = A + B;
    std::cout << "C = A + B\nResult: C = " << C << "\n";
    C = A * 3;
    std::cout << "C = A * 3\nResult: C = " << C << "\n";
    C = A / 3;
    std::cout << "C = A / 3\nResult: C = " << C << "\n";
    C = A / B;
    std::cout << "C = A / B\nResult: C = " << C << "\n";
    C = A * B;
    std::cout << "C = A * B\nResult: C = " << C << "\n";
    C = ~A;
    std::cout << "C = ~A\nResult: C = " << C << "\n";
    if (A == B) {
        std::cout << "A == B\nResult: A = B\n\n";
    };
    if (A != B) {
        std::cout << "A != B\nResult: A != B\n\n";
    };
    std::cout << "C = ~A\nResult: C = " << C << "\n";
    C = A++;
        std::cout << "C = A++\nResult: C = " << C << "\n";
    std::cout << "A\nResult: A = " << A << "\n";
    C = ++A;
    std::cout << "C = ++A\nResult: C = " << C << "\n";
    std::cout << "A\nResult: A = " << A << "\n";
    C = A--;
    std::cout << "C = A--\nResult: C = " << C << "\n";
    std::cout << "A\nResult: A = " << A << "\n";
    C = --A;
    std::cout << "C = --A\nResult: C = " << C << "\n";
    std::cout << "A\nResult: A = " << A << "\n";
    try {
        C = A / 0;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}
