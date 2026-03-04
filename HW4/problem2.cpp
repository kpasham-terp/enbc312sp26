#include <iostream>
#include <string>
using namespace std;

class Book {
    public:
        string title;
        int pages;

        void setTitle(string str) {
            title = str;
        }

        void setPages(int pgs) {
            pages = pgs;
        }
};

int main() {
    Book book1;
    book1.setTitle("The Alchemist");
    book1.setPages(208);
    cout << "Title of book: " << book1.title << ". Pages in book: " << book1.pages << "." << endl;
    return 0;
}