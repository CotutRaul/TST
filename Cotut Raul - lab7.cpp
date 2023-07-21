#include <iostream>
#include <list>
#include <map>
#include <string>

struct Book {
    std::string author;
    std::string title;
    std::string currentDate;
    std::string returnDate;
    int bookRating;

    Book(const std::string& author, const std::string& title, const std::string& currentDate, const std::string& returnDate, int bookRating)
        : author(author), title(title), currentDate(currentDate), returnDate(returnDate), bookRating(bookRating) {}
};

void displayBooks(const std::list<Book>& books) {
    for (const auto& book : books) {
        std::cout << "Author: " << book.author << ", Title: " << book.title << ", Rating: " << book.bookRating << std::endl;
    }
}

int main() {
    std::list<Book> borrowedBooks;

    borrowedBooks.push_back(Book("Harper Lee", "To Kill a Mockingbird", "2023-05-10", "2023-05-20", 4));
    borrowedBooks.push_back(Book("F. Scott Fitzgerald", "The Great Gatsby", "2023-05-11", "2023-05-17", 5));
    borrowedBooks.push_back(Book("George Orwell", "1984", "2023-05-08", "2023-04-10", 3));
    borrowedBooks.push_back(Book("Jane Austen", "Pride and Prejudice", "2023-05-12", "2023-04-10", 5));
    borrowedBooks.push_back(Book("J.R.R. Tolkien", "The Lord of the Rings", "2023-05-09", "2023-05-16", 2));
    

    borrowedBooks.remove_if([](const Book& book) { return book.returnDate > book.currentDate; });


    std::map<std::string, std::list<Book>> borrowedBooksByUser;

    borrowedBooksByUser["Cotut"] = borrowedBooks;

  
    borrowedBooksByUser["Raul"] = borrowedBooks;

    borrowedBooks.push_back(Book("Ernest Hemingway", "The Old Man and the Sea", "2023-05-12", "2023-04-10", 5));
    borrowedBooksByUser["Alexandru"] = borrowedBooks;

    for (const auto& pair : borrowedBooksByUser) {
        std::cout << "Books borrowed by " << pair.first << " with a 5-star rating:" << std::endl;
        const auto& books = pair.second;
        for (const auto& book : books) {
            if (book.bookRating == 5) {
                std::cout << "Author: " << book.author << ", Title: " << book.title << std::endl;
            }
        }
        std::cout << std::endl;
    }

    return 0;
}
