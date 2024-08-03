#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Book structure
struct Book {
    int id;
    string title;
    string author;
    string isbn;
    bool availability;
};

// Borrower structure
struct Borrower {
    int id;
    string name;
    string email;
    string phone;
};

// Transaction structure
struct Transaction {
    int id;
    int bookId;
    int borrowerId;
    string checkoutDate;
    string dueDate;
    string returnDate;
    double fine;
};

// Library class
class Library {
public:
    // Constructor
    Library() {
        // Initialize book, borrower, and transaction vectors
        books = {};
        borrowers = {};
        transactions = {};
    }

    // Add a book to the library
    void addBook() {
        Book book;
        cout << "Enter book ID: ";
        cin >> book.id;
        cout << "Enter book title: ";
        cin.ignore();
        getline(cin, book.title);
        cout << "Enter book author: ";
        getline(cin, book.author);
        cout << "Enter book ISBN: ";
        getline(cin, book.isbn);
        book.availability = true;
        books.push_back(book);
    }

    // Add a borrower to the library
    void addBorrower() {
        Borrower borrower;
        cout << "Enter borrower ID: ";
        cin >> borrower.id;
        cout << "Enter borrower name: ";
        cin.ignore();
        getline(cin, borrower.name);
        cout << "Enter borrower email: ";
        getline(cin, borrower.email);
        cout << "Enter borrower phone: ";
        getline(cin, borrower.phone);
        borrowers.push_back(borrower);
    }

    // Search for a book by title, author, or ISBN
    void searchBooks() {
        string query;
        cout << "Enter search query: ";
        cin.ignore();
        getline(cin, query);
        vector<Book> results;
        for (Book book : books) {
            if (book.title.find(query)!= string::npos ||
                book.author.find(query)!= string::npos ||
                book.isbn.find(query)!= string::npos) {
                results.push_back(book);
            }
        }
        if (results.empty()) {
            cout << "No results found." << endl;
        } else {
            cout << "Search results:" << endl;
            for (Book book : results) {
                cout << book.title << endl;
            }
        }
    }

    // Check out a book to a borrower
    void checkoutBook() {
        int bookId, borrowerId;
        cout << "Enter book ID: ";
        cin >> bookId;
        cout << "Enter borrower ID: ";
        cin >> borrowerId;
        // Find the book and borrower
        Book* book = findBook(bookId);
        Borrower* borrower = findBorrower(borrowerId);

        if (book && borrower) {
            // Create a new transaction
            Transaction transaction;
            transaction.id = transactions.size() + 1;
            transaction.bookId = bookId;
            transaction.borrowerId = borrowerId;
            transaction.checkoutDate = "Today";
            transaction.dueDate = "Next Week";
            transaction.returnDate = "";
            transaction.fine = 0.0;

            transactions.push_back(transaction);

            // Update book availability
            book->availability = false;
            cout << "Book checked out successfully." << endl;
        } else {
            cout << "Book or borrower not found." << endl;
        }
    }

    // Return a book
    void returnBook() {
        int transactionId;
        cout << "Enter transaction ID: ";
        cin >> transactionId;
        // Find the transaction
        Transaction* transaction = findTransaction(transactionId);

        if (transaction) {
            // Update book availability
            Book* book = findBook(transaction->bookId);
            book->availability = true;

            // Calculate fine
            double fine = calculateFine(transaction->dueDate, transaction->returnDate);
            transaction->fine = fine;
            cout << "Book returned successfully." << endl;
        } else {
            cout << "Transaction not found." << endl;
        }
    }

    // Calculate fine
    double calculateFine(string dueDate, string returnDate) {
        // Simple fine calculation: $0.25 per day
        int overdueDays = 0;
        //... calculate overdue days...
        return overdueDays * 0.25;
    }

    // Find a book by ID
    Book* findBook(int id) {
        for (Book& book : books) {
            if (book.id == id) {
                return &book;
            }
        }
        return nullptr;
    }

            // Find a borrower by ID
    Borrower* findBorrower(int id) {
        for (Borrower& borrower : borrowers) {
            if (borrower.id == id) {
                return &borrower;
            }
        }
        return nullptr;
    }

    // Find a transaction by ID
    Transaction* findTransaction(int id) {
        for (Transaction& transaction : transactions) {
            if (transaction.id == id) {
                return &transaction;
            }
        }
        return nullptr;
    }

private:
    vector<Book> books;
    vector<Borrower> borrowers;
    vector<Transaction> transactions;
};

int main() {
    Library library;

    while (true) {
        cout << "Library Management System" << endl;
        cout << "1. Add a book" << endl;
        cout << "2. Add a borrower" << endl;
        cout << "3. Search for a book" << endl;
        cout << "4. Check out a book" << endl;
        cout << "5. Return a book" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                library.addBook();
                break;
            case 2:
                library.addBorrower();
                break;
            case 3:
                library.searchBooks();
                break;
            case 4:
                library.checkoutBook();
                break;
            case 5:
                library.returnBook();
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}