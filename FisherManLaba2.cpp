
#include <iostream>
#include "Book.h"
#include "Rewriter.h"
int main()
{
    setlocale(LC_ALL, "RUS");
    bool flag = true;
    int n;

    while (flag) {
        try
        {
            std::cout << "Menu:\n";
            std::cout << "1.NOTES\n";
            std::cout << "2.Replacee text\n";
            std::cout << "3. Exit\n";
            std::cout << "You enter: ";
            std::cin >> n;
            if (n == 1)
                Book b;
            else if (n == 2)
                Rewriter r;
            else if (n == 3)
                flag = false;
            else
                std::cout << "Unknown command\n";
        }
        catch (const char* execpt)
        {
            std::cout << execpt << "\n";
        }
        
    
    }

}

