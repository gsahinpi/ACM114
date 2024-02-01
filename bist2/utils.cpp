
#include "utils.h"

void clearScreen() {
    // Clear screen command based on the operating system
    #ifdef _WIN32
        system("cls"); // For Windows
    #else
        system("clear"); // For Linux and macOS
    #endif
};
void showMenu() {

    
    cout << "Menu:" << endl;
    cout << "q: Quit" << endl;
    cout << "p: Print orders" << endl;
    cout << "i: Trigger itch for ask or bid change" << endl;
    cout << "o: Outch" << endl;
};
void showItchMenu() {
    cout << "Menu:" << endl;
    cout << "b: Bid" << endl;
    cout << "a: Ask" << endl;
    cout << "q: Quit" << endl;
};
void processChoice(char choice) {
    char choice2;
    switch (choice) {
        case 'q':
            cout << "Quitting..." << endl;
            break;
        case 'p':
            cout << "Printing orders..." << endl;
            // TODO: Implement printing orders functionality
            break;
        case 'i':
            cout << "Triggering hedge itch for ask or bid change..." << endl;
             

                 showItchMenu();
        cout << "Enter your choice: ";
        cin >> choice2;
        processChoice(choice2);


            // TODO: Implement itch triggering functionality
            break;
        case 'o':
            cout << "simulate Outch for qoute..." << endl;
          cout<<"getting q orders to process"<<endl;
          //loadbidmemorymap();
          loadQordersfromMap();

          
            // TODO: Implement outch functionality
            break;
        case 'B':
        case 'b': 
            cout << "Bid..." << endl;
            ItchdAlgo('b');
           

            break;
         case 'A':
         case 'a':
            cout << "Ask..." << endl;
            ItchdAlgo('a');
            break;   

        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
    }
};


