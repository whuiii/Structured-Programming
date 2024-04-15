#include <iostream>
#include <fstream> //library for read file
#include <stdlib.h>
#include <string>
#include <ctime>
#include <cstdio>
#include <iomanip> //for setw
#include <stdlib.h>
#include <windows.h>
#include <random> //generate for the random code
#include <cstdlib> //library for typing effect
#include <chrono>//library for duration of time
#include <thread> // excecute the same proses multiple time

using namespace std;

//declare function
void mainmenu();
void highlight();

//variable declare for profile display
string currentUserName;
string currentPhoneNumber;
string currentEmail;

//variable declare for booking seat
string date;
string month;
int year;
string destination;
int FPayment;
string FTime;
int trainNum;
int desireRow;
char columnAl;
double total;
int numTicket;
//string code;
string seat;

void deleteBooking(){
	system ("CLS");
	cout << endl;
	cout << "\t|********************************************************************************|" << endl;
	cout << "\t|                                  Cancel Booking                                |" << endl;
	cout << "\t|********************************************************************************|" << endl;
	cout << "\t|                                                                                |" << endl;
	cout << "\t|                          Call us to cancel your booking                        |" << endl; //online banking method
	cout << "\t|                                   03-231031931                                 |" << endl; // credit/debit card method
	cout << "\t|________________________________________________________________________________|" << endl;	
	cout << "\t|                                                                                |" << endl;
	cout << "\t|                          Email us for further information                      |" << endl;
	cout << "\t|                                train2go@gmail.com                              |" << endl;
	cout << "\t|                                                                                |" << endl;
	cout << "\t|********************************************************************************|" << endl;
	cout << "\t|                                 Have a Nice Day                                |" << endl;
	cout << "\t|********************************************************************************|" << endl;
	cout << "\t";
	system ("pause");
	mainmenu();
	
}


void displayTicket(){
	//clear the screen
	system("CLS");
	//variable declaration
	string userName;
	string referenceCode;
	string ticketTime;
	string displayDate;
	string displaySeat;
	string displayPrice;
	string displayDestination;
	string code;
	string price;
	string date;
	string time;
	string seat;
	string Bdestination;
	bool conditionsMet ;
		
	//display the interface for display the ticket
	cout << "\t|********************************************************************************|" << endl;
	cout << "\t|                                 Display Ticket                                 |" << endl;
	cout << "\t|********************************************************************************|" << endl;
	cout << "\t|                                                                                |" << endl;

	//open the file for read
	
	//ifstream use for read file
	ifstream display; 
	//ios::in => file opened in reading mode
	display.open("displayTicket.txt", ios::in);
	
	while(display >> userName >> referenceCode >> ticketTime >> displayDate >> displaySeat >> displayPrice >> displayDestination){
		//display all the ticket of the particular user
		if(userName == currentUserName){
			conditionsMet = true;
			//if the condtion true print the ticket
			if(conditionsMet){
				Bdestination = displayDestination;
				code = referenceCode;
				price = displayPrice;
				date = displayDate;
				time = ticketTime;
				seat = displaySeat;
				cout << "\t| ______________________________________________________________________________ |" << endl;
				cout << "\t| |                              PASSENGER NAME: " <<  setw(7) << currentUserName << setw(26) << "| |"<< endl;
				cout << "\t| |                                                                            | |" << endl;
				cout << "\t| |****************************************************************************| |" << endl;
				cout << "\t| | REFERENCE CODE: " << code << setw(28) << "| PRICE: RM " << setw(3) << price << setw (25) << "| |" << endl;
				cout << "\t| |****************************************************************************| |" << endl;
				cout << "\t| | DATE: " << setw(10) << date << setw(30) << "| TIME: " << time << setw(21) << "| |" << endl;
				cout << "\t| |****************************************************************************| |" << endl;
				cout << "\t| | SEAT: " << setw(3) << displaySeat << setw(44) << "| DESTINATION: " << setw(12) << Bdestination << setw(13) << "| |" << endl;
				cout << "\t| |****************************************************************************| |" << endl;	
				cout << "\t| |                             IT'S THE RIGHT TRACK                           | |" << endl;
				cout << "\t| |____________________________________________________________________________| |" << endl;	
				cout << "\t|                                                                                |" << endl;					
			}else{
				cout << "\t|________________________________________________________________________________|" << endl;
				cout << "\t|                                                                                |" << endl;
			}
		}else{
			conditionsMet = false;
		}
	}
	//close the file
	display.close();		

	//press any key to continue...
	cout << "\t";
	system ("pause");
	//call back the main menu function
	mainmenu();		

}


// animated typing effect
void typeEffect(const std::string& text, int delay) {
    for (char c : text) {
        std::cout << c;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    }
}

void animateSuccess() {
    std::cout << "\tProcessing payment...";
    std::this_thread::sleep_for(std::chrono::seconds(1)); // Simulate processing time

    std::cout << "\n\n\tPayment successful!\n\n";
}


//parameter pass from chooseSeat() function
void payment(int trainTicket, int trainPrice){
	//variable declaration
	string trainTime;
	int seatRow;
	string seatAlphaphet;
	string seatDestination;
	string seatDate;
	string seatMonth;
	string seatName;
	string seatTime;
	string seat;
	int seatTrain;
	int seatYear;
	bool conditionsMet;	
	int paymentMethod;
	string user;
	string password;
	string Bdestination;
	char ensure;
	
	//variable declaration for method card payment
	string cardUser;
	string cardNumber;
	string cardDate;
	string cardCode;
	
	//call the function of random code
    ///string randomCode = billReference();
    const char alphabets[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char digits[] = "0123456789";

    // Initialize the random seed
    srand(static_cast<unsigned int>(time(0)));

    // Generate two random alphabets
    char alpha1 = alphabets[rand() % 26];
    char alpha2 = alphabets[rand() % 26];

    // Generate four random digits
    string numericPart;
    for (int i = 0; i < 4; ++i) {
        numericPart += digits[rand() % 10];
    }

    // Combine the two alphabets and numeric part
    string randomCode = std::string(1, alpha1) + std::string(1, alpha2) + numericPart;
    

    
    //calculate for the total of train ticket
	total = trainTicket * trainPrice;
	
	//display the interface of payment
	cout << "\t|********************************************************************************|" << endl;
	cout << "\t|                               Proceed to Payment                               |" << endl;
	cout << "\t|********************************************************************************|" << endl;
	cout << "\t|                              It's the Right Track                              |" << endl;
	cout << "\t|********************************************************************************|" << endl;
	cout << "\t|                                                                                |" << endl;
	cout << "\t|\t Customer Name   : " << currentUserName << setw(52) << "|" << endl;
	cout << "\t|                                                                                |" << endl;
	cout << "\t|\t Number of Ticket: " << trainTicket << setw(54) << "|" <<endl;
	cout << "\t|                                                                                |" << endl;
	cout << "\t|\t Price per Ticket: RM " << setw(3) << trainPrice <<setw(49) << "|" << endl;
	cout << "\t|                                                                                |" << endl;
	cout << "\t|\t Total Price     : RM " << setw(3) << setprecision(2) <<  total << setw(49) << "|" << endl;
	cout << "\t|                                                                                |" << endl;
	cout << "\t|********************************************************************************|" << endl;
	cout << endl << endl << endl ;
	
	//display the interface for the payment method
	cout << "\t|********************************************************************************|" << endl;
	cout << "\t|                                   Payment Method                               |" << endl;
	cout << "\t|********************************************************************************|" << endl;
	cout << "\t|                                                                                |" << endl;
	cout << "\t| 1. Online Banking                                                              |" << endl; //online banking method
	cout << "\t| 2. Credit/Debit Card                                                           |" << endl; // credit/debit card method
	cout << "\t|                                                                                |" << endl;
	cout << "\t|********************************************************************************|" << endl;
	cout << endl;
	
	//prompt and get the number of payment method
	cout << "\tPlease enter number of the payment method: ";
	cin >> paymentMethod;
	
	//clear the screen
	system ("CLS");
	
	//switch case for payment method
	switch (paymentMethod){
		//case for online banking
		case 1:
			cout << "\t|********************************************************************************|" << endl;
			cout << "\t|                                    Online Bankng                               |" << endl;
			cout << "\t|********************************************************************************|" << endl;
			cout << "\t|                                                                                |" << endl;
			cout << "\t| Username: " ;
			cin >> user ;
			cout << "\t|                                                                                |" << endl;
			cout << "\t| Password: " ;
			cin >> password;
			cout << "\t|                                                                                |" << endl;
			cout << "\t|********************************************************************************|" << endl;	
			cout << "\t Are You confirm? (Y) for Yes (N) for No: ";
			cin >> ensure;
			while (ensure == 'N' || ensure == 'n'){
				system ("CLS");
				cout << "\t| Please enter again your information                                            |" << endl;
				cout << "\t|********************************************************************************|" << endl;
				cout << "\t|                                    Online Bankng                               |" << endl;
				cout << "\t|********************************************************************************|" << endl;
				cout << "\t|                                                                                |" << endl;
				cout << "\t| Username: " ;
				cin >> user ;
				cout << "\t|                                                                                |" << endl;
				cout << "\t| Password: " ;
				cin >> password;
				cout << "\t|                                                                                |" << endl;
				cout << "\t|********************************************************************************|" << endl;	
				cout << "\t Are You confirm? (Y) for Yes (N) for No: ";
				cin >> ensure;	
				cout << "\t";
				//press any key to continue
				system ("pause");							
			}
			cout << "\t";
			//press any key to continue
			system ("pause");		
			//clear the screen	
			system ("CLS");
			//display the online banking interface
			cout << "\t|********************************************************************************|" << endl;
			cout << "\t|                                    Online Bankng                               |" << endl;
			cout << "\t|********************************************************************************|" << endl;
			cout << "\t|                                                                                |" << endl;
			cout << "\t| Username        : " << setw(12) << user << setw(50) << "|" << endl;
			cout << "\t|                                                                                |" << endl;
			cout << "\t| Reference Number: " << setw(6) << randomCode << setw(56) << "|" << endl ;
			cout << "\t|                                                                                |" << endl;
			cout << "\t| Amount          : RM " << total << setw(57) << "|" << endl;       
			cout << "\t|********************************************************************************|" << endl;	
			cout << "\t|                                                                                |" << endl;
			cout << "\t";
			system ("\tpause");
			animateSuccess();
			break;
		//case for credit/debit card	
		case 2:
			//display the credit/debit card interface
			cout << "\t|********************************************************************************|" << endl;
			cout << "\t|                                Credit/Debit Card                               |" << endl;
			cout << "\t|********************************************************************************|" << endl;
			cout << "\t|                                                                                |" << endl;
			cout << "\t| Name of Card : " ;
			cin >> cardUser;
			cout << "\t|                                                                                |" << endl;
			cout << "\t| Card Number  : " ;
			cin >> cardNumber;
			cout << "\t|                                                                                |" << endl;			
			cout << "\t| Expiry Date  : " ;
			cin >> cardDate;
			cout << "\t|                                                                                |" << endl;
			cout << "\t| Security Code: " ;
			cin >> cardCode;
			cout << "\t|                                                                                |" << endl;
			cout << "\t| Amount       : RM " << setw(4) << total << setw(59) << "|" << endl;
			cout << "\t|********************************************************************************|" << endl;	
			cout << "\t|                                                                                |" << endl;	
			cout << "\t";
			//press any key to continue
			system ("pause");
			animateSuccess();
			break;					
	}
	cout << "\tPlease Proceed to 'Display of Ticket' in main menu to track your Ticket" << endl;
	
	//declare for read file
	ifstream ticket("Ticket.txt");
	ofstream display("displayTicket.txt", ios::app);
	ticket.clear(); //clears any error flags that may be set on the file stream
	ticket.seekg(0, ios::beg); //get pointer of the file stream to the beginning of the file
	bool cont=true;
	//read file and cin for each variable
	
	string currentSeat;
	string newSeat;
	int num = 0;
	
	
	for (int i = 0; i < trainTicket ; i ++){
		//read the file
		while(ticket >> seatName >> seatDestination >> seatDate >> seatMonth >> seatYear >> seatTime >> seatTrain >> seatAlphaphet){
			//if the file reach the end of file
			if (ticket.eof()){
				break;
			}
			conditionsMet = (currentUserName == seatName && destination == seatDestination && date == seatDate && month == seatMonth && year == seatYear && trainNum == seatTrain && newSeat != seatAlphaphet );
			if(conditionsMet){
				newSeat = seatAlphaphet;
				cont=false;	
			}
			if(conditionsMet){
				seat = seatAlphaphet;
				Bdestination = seatDestination;
				string displayDate;
				//combine the date,month,year in format date/month/year
				displayDate = seatDate + "/" + seatMonth + "/" + to_string(seatYear);
				//write into the file
				display << currentUserName << " " << randomCode << " " << FTime << " " << displayDate << " " << seat << " " << trainPrice << " " << Bdestination << endl;
			}	
		}
		
	}
	//close the file
	display.close();
	ticket.close();

	cout << "\t";
	//press any key to continue...
	system ("pause");
	//call back the main menu function
	mainmenu();
	
}

//parameter pass by the price for accroding train num 
void chooseSeat(int price){
	//variable declaration
	int column;
	int count ;
	int trainPrice;
	
	//variable for readSeat
	int seatRow;
	string seatAlphaphet;
	string seatDestination;
	string seatDate;
	string seatMonth;
	string seatName;
	string seatTime;
	int seatTrain;
	int seatYear;
	
	//variable for line
	int lineCount = 0;
	string data;
	ifstream countLine;
	countLine.open("Ticket.txt");
	if (countLine.is_open()){
		while (getline(countLine, data)){
			lineCount++;
		}
	}
    countLine.close();
    int i;

	//print the layout of seat for choosing
	cout << "\t\t"<< " A    B    C \t     D    E    F " << endl;
	//declare for read file
	ifstream readSeat; 
	
	readSeat.open("Ticket.txt", ios::in);
	bool conditionsMet;
	
	//for-loop for display the seat
	for (int row = 0; row <20 ; row++){
		cout << "\tRow" <<setw(3) << row + 1 << " ";
		for (int k = 0 ;k <6 ; k++){
			char alphabet = 'A' + k;
			string character=alphabet+to_string(row+1);
			readSeat.clear();
			readSeat.seekg(0, ios::beg);
			bool cont=true;
			while(cont){
				//read the file
				readSeat >> seatName >> seatDestination >> seatDate >> seatMonth >> seatYear >> seatTime >> seatTrain >> seatAlphaphet;
				if (readSeat.eof()){
					break;
				}
				conditionsMet = (destination == seatDestination && date == seatDate && month == seatMonth && year == seatYear && trainNum == seatTrain && character==seatAlphaphet );
				if(conditionsMet){
					cont=false;
				}
			}
			if(conditionsMet){
				//if the seat was booked display [X] for accroding seat with highlight blue
				HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
				//04 is the colour code for red
				//23 is the colour code for blue
				SetConsoleTextAttribute(h, 23);
				SetConsoleTextAttribute(h, 23);
				cout << "[ "  << "X" <<  " ]" ;
				SetConsoleTextAttribute(h,07);
			}
			else{
				cout << "[" << setw(3) << character << "]";
			}
			if((k+1) % 3 == 0){
				cout << setw(5);
			}
		}
		cout << endl;
	}
	
	//close the file
	readSeat.close();	
	//open the file for write
	ofstream ticket("Ticket.txt", ios::app);
	cout << endl;
	cout << "\tDesire Row: ";
	cin >> desireRow;
	
	cout << "\tDesired seat (A,B,C,D,E or F): ";
	cin >> columnAl;
	seat = columnAl + to_string(desireRow);
	
	readSeat.open("Ticket.txt", ios::in);;
	
	//for-loop for loop the seat
	for (int row = 0; row <20 ; row++){
		for (int k = 0 ;k <6 ; k++){
			char alphabet = 'A' + k;
			string character=alphabet+to_string(row+1);
			readSeat.clear();
			readSeat.seekg(0, ios::beg);
			bool cont=true;
			while(cont){
				//read the file
				readSeat >> seatName >> seatDestination >> seatDate >> seatMonth >> seatYear >> seatTime >> seatTrain >> seatAlphaphet;
				if (readSeat.eof()){
					break;
				}
				conditionsMet = (destination == seatDestination && date == seatDate && month == seatMonth && year == seatYear && trainNum == seatTrain && seat==seatAlphaphet );
				if(conditionsMet){
					cont=false;
					break;
				}
			}
		}
	}
	if(conditionsMet){
		//if the seat was booked display [X] was try enter again then this will appear
		cout << "\t Seat are not available" << endl;
		cout << "\t Choose the other seat" << endl;	
		chooseSeat(price);
		readSeat.close();
	}else{
		//if the 
		ticket << currentUserName << " " <<  destination << " " << date << " " << month << " " << year << " " << FTime << " " << trainNum << " " << seat << endl;
		ticket.close();
		cout << "\tYour seat is sucessfully booked." << endl << endl;	
	}
	
	//close the file
	readSeat.close();
	//write the detail into the file
	
	
	//display again the layout of seat
	cout << "\t\t"<< " A    B    C \t     D    E    F " << endl;
	
	readSeat.open("Ticket.txt", ios::in);
	for (int row = 0; row <20 ; row++){
		cout << "\tRow" <<setw(3) << row + 1 << " ";
		for (int k = 0 ;k <6 ; k++){
			char alphabet = 'A' + k;
			string character=alphabet+to_string(row+1);
			readSeat.clear();
			readSeat.seekg(0, ios::beg);
			bool cont=true;
			while(cont){
				readSeat >> seatName >> seatDestination >> seatDate >> seatMonth >> seatYear >> seatTime >> seatTrain >> seatAlphaphet;
				//if reach end of file 
				if (readSeat.eof()){
					break;
				}
				conditionsMet = (destination == seatDestination && date == seatDate && month == seatMonth && year == seatYear && trainNum == seatTrain && character==seatAlphaphet );
				if(conditionsMet){
					cont=false;
				}
			}
			if(conditionsMet){
				//read the file 
				HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(h, 23);
				SetConsoleTextAttribute(h, 23);
				cout << "[ "  << "X" <<  " ]" ;
				SetConsoleTextAttribute(h,07);
			}else if(character == seat){
				//display the seat desire for the current user
				HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(h, 23);
				SetConsoleTextAttribute(h, 23);
				cout << "[ "  << "X" <<  " ]" ;
				SetConsoleTextAttribute(h,07);				
			}else{
				cout << "[" << setw(3) << character << "]";
			}
			// a width of 5 empty 
			if((k+1) % 3 == 0){
				cout << setw(5);
			}
		}
	cout << endl;
	}
	readSeat.close();
	trainPrice = price;
	char choice;
	//prompt and get if want get more ticket
	cout << "\tAre you want to get more ticket? " <<endl;
	cout << "\tPlease enter (Y) for yes (N) for no: " ;
	cin >> choice;
	if (choice == 'Y' || choice == 'y'){
		//while the choice input is Yes
		numTicket = numTicket + 1;
		chooseSeat(price);
	} else if (choice == 'N' || choice == 'n'){
		//while the choice input is No
		numTicket = numTicket + 1;
		
		cout << "\tThank You for choosing" <<endl;
		cout << "\tPlease proceed to payment" <<endl;
		cout << "\t";
		system ("pause");
		
		//proceed to payment function by parsing the parameter for number of ticket and price for the train
		payment(numTicket, trainPrice);		
	}else {
		//while enter another input
		cout << "\tInvalid Input" <<endl;
		cout << "\tPlease try again" <<endl;
		cout << "\tAre you want to get more ticket? " <<endl;
		cout << "\tPlease enter (Y) for yes (N) for no: " ;
		cin >> choice;
		if (choice == 'Y' || choice == 'y'){
			//while the choice input is Yes
			numTicket = numTicket + 1;
			chooseSeat(price);
		} else if (choice == 'N' || choice == 'n'){
			//while the choice input is No
			numTicket = numTicket + 1;
			
			cout << "\tThank You for choosing" <<endl;
			cout << "\tPlease proceed to payment" <<endl;
			cout << "\t";
			system ("pause");
			//proceed to payment function by parsing the parameter for number of ticket and price for the train
			payment(numTicket, trainPrice);				
		}else {
			//while enter another input
			cout << "\tInvalid Input" <<endl;
			cout << "\tPlease try again" <<endl;
			cout << "\tAre you want to get more ticket? " <<endl;
			cout << "\tPlease enter (Y) for yes (N) for no: " ;
			cin >> choice;
		}
	}
}				

void displaySeat(){
	system("CLS");
	cout << endl;
	cout << "\t\t Display Layout of Seat" << endl;
	//display the layout of seat for the train
	//for-loop
	cout << "\t\t"<< " A    B    C \t     D    E    F " << endl;
	for (int row = 0; row <20 ; row++){
		cout << "\tRow" <<setw(3) << row + 1 << " ";
		for (int k = 0 ;k <6 ; k++){
			char alphabet = 'A' + k;
			string character=alphabet+to_string(row+1);
			cout << "[" << setw(3) << character << "]";
            if((k+1) % 3 == 0){
				cout << setw(5);
			}
        }
        cout << endl;
    }
	cout << endl;
	cout << "\t";
	//press any key to continue...
	system ("pause");
	//clear the screen
	system ("CLS");
	mainmenu();
}

void profile(){
	//display the profile
	//clear the screen
	system ("CLS");
	cout << endl;
	cout << "\t|********************************************************************************|" << endl;
	cout << "\t|                                    Profile                                     |" << endl;
	cout << "\t|********************************************************************************|" << endl;
	cout << "\t|                                                                                |" << endl;
	cout << "\t|________________________________________________________________________________|" << endl;
	cout << "\t|                                                                                |" << endl;
	cout << "\t| UserName: " << setw(7) << currentUserName << setw(63) << "|" << endl;
	cout << "\t|________________________________________________________________________________|" << endl;
	cout << "\t|                                                                                |" << endl;
	cout << "\t| Phone Number: " << setw(11) << currentPhoneNumber << setw(55) << "|" << endl;
	cout << "\t|________________________________________________________________________________|" << endl;
	cout << "\t|                                                                                |" << endl;
	cout << "\t| Email: " << setw(20) << currentEmail << setw(53) << "|" << endl;
	cout << "\t|________________________________________________________________________________|" << endl;
	cout << "\t|                                                                                |" << endl;
	cout << "\t|                                                                                |" << endl;
	cout << "\t|********************************************************************************|" << endl;
	
	cout << "\t";
	system ("pause"); //press any key to continue
	mainmenu();
}

//function for PadangBesar
void PadangBesar(){
	//variable declaration
	double charge;
	time_t now = time(0);
	tm *ltm = localtime(&now);
	char confirmation;
	char finalise;
	char proceed;
	
	destination = "Padang_Besar";
	//open the file for write
	//ios:app file opened in append mode
	ofstream ticket("Ticket.txt", ios::app);
	cout << "\t|********************************************************************************|" << endl;
	cout << "\t|                          Welcome to Padang Besar Railway                       |" << endl;
	cout << "\t|********************************************************************************|" << endl;
	cout << "\t|                               It's the Right Track                             |" << endl;
	cout << "\t|********************************************************************************|" << endl;
	cout << "\t|                                                                                |" << endl;
	cout << "\tPlease enter the date you want to departure(dd): ";
	cin >> date;
	//while the user enter invalid input
	while (stoi(date)>31 || stoi(date) <1){
		cout << "\tInvalid Input" << endl;
		cout << "\tPlease enter the date again(dd): ";
		cin >> date;
	}
	cout << "\tPlease enter the month you want to departure(mm): ";
	cin >> month;
	//while the user enter invalid input
	while (stoi(month) >12 || stoi(month) <1){
		cout << "\tInvalid Input" << endl;
		cout << "\tPlease enter the month again(mm): ";
		cin >> month;
	}	
  	cout << "\tThe year you want to depart is " << 1900 + ltm->tm_year << "?" << endl;
	cout << "\tPlease enter (Y) for yes (N) for no: " ;
	cin >> confirmation;
	
	if (confirmation == 'Y' || confirmation == 'y'){
		year = 1900 + ltm->tm_year;
		
	}else{
		cout << "\tPlease enter the year you want to departure(yyyy): ";
		cin >> year;
	}
	cout << endl;
	//display the train schedule
	cout << "\t|********************************************************************************|" << endl;
	cout << "\t|                          Following are the Train Schedule                      |" << endl;
	cout << "\t|********************************************************************************|" << endl;
	cout << "\t|                                                                                |" << endl;
	cout << "\t| 1.                   07:30 KUL ------------------- 12:45 PAD                   | RM 100" << endl;
	cout << "\t|                     Kuala Lumpur      05h 15m     Padang Besar                 |" << endl;
	cout << "\t|                                                                                |" << endl;
	cout << "\t| 2.                   09:50 KUL ------------------- 15:23 PAD                   | RM 100" << endl;
	cout << "\t|                     Kuala Lumpur      05h 33m     Padang Besar                 |" << endl;
	cout << "\t|                                                                                |" << endl;
	cout << "\t| 3.                   10:45 KUL ------------------- 16:33 PAD                   | RM 87" << endl;
	cout << "\t|                     Kuala Lumpur      05h 48m     Padang Besar                 |" << endl;
	cout << "\t|                                                                                |" << endl;
	cout << "\t|********************************************************************************|" << endl;

	
	cout << "\tPlease enter the number of train schedule you want to booking: " ;
	cin >> trainNum;
	if (trainNum == 1){
		FPayment = 100;
		FTime = "07:30-12:45";
	}else if (trainNum == 2){
		FPayment = 100;
		FTime = "09:50-15:23";
	}else{
		FPayment = 87;
		FTime = "10:45-16:33";
	}
	cout << "\tAre you want to Confirm?" << endl;
	cout << "\tPlease enter (Y) for yes (N) for no: " ;
	cin >> finalise;
	
	if (finalise == 'Y'|| finalise == 'y'){
		//parsing the value of train 
		chooseSeat(FPayment);
	}else if (finalise == 'N' || finalise == 'n'){
		while (finalise == 'N' || finalise == 'n'){
			cout << "\tAre you want to proceed with booking?" << endl;
			cout << "\tPlease enter (Y) for yes (N) for no: " ;
			cin >> proceed;
			if (proceed == 'Y' || proceed == 'y'){
				//display the train schedule
				cout << "\t|********************************************************************************|" << endl;
				cout << "\t|                          Following are the Train Schedule                      |" << endl;
				cout << "\t|********************************************************************************|" << endl;
				cout << "\t|                                                                                |" << endl;
				cout << "\t| 1.                   07:30 KUL ------------------- 12:45 PAD                   | RM 100" << endl;
				cout << "\t|                     Kuala Lumpur      05h 15m     Padang Besar                 |" << endl;
				cout << "\t|                                                                                |" << endl;
				cout << "\t| 2.                   09:50 KUL ------------------- 15:23 PAD                   | RM 100" << endl;
				cout << "\t|                     Kuala Lumpur      05h 33m     Padang Besar                 |" << endl;
				cout << "\t|                                                                                |" << endl;
				cout << "\t| 3.                   10:45 KUL ------------------- 16:33 PAD                   | RM 87" << endl;
				cout << "\t|                     Kuala Lumpur      05h 48m     Padang Besar                 |" << endl;
				cout << "\t|                                                                                |" << endl;
				cout << "\t|********************************************************************************|" << endl;
				
				cout << "\tPlease enter the number of train schedule you want to booking: " ;
				cin >> trainNum;
				if (trainNum == 1){
					FPayment = 100;
					FTime = "07:30-12:45";
				}else if (trainNum == 2){
					FPayment = 100;
					FTime = "09:50-15:23";
				}else{
					FPayment = 87;
					FTime = "10:45-16:33";
				}
				cout << "\tAre you want to Confirm?" << endl;
				cout << "\tPlease enter (Y) for yes (N) for no: " ;
				cin >> finalise;
			}else if (proceed == 'N' || proceed == 'n'){
				mainmenu();
				break;
			}else{
				cout << "\tInvalid input";
				cout << "\tPlease confirm again your choice";
				//display the train schedule
				cout << "\t|********************************************************************************|" << endl;
				cout << "\t|                          Following are the Train Schedule                      |" << endl;
				cout << "\t|********************************************************************************|" << endl;
				cout << "\t|                                                                                |" << endl;
				cout << "\t| 1.                   07:30 KUL ------------------- 12:45 PAD                   | RM 100" << endl;
				cout << "\t|                     Kuala Lumpur      05h 15m     Padang Besar                 |" << endl;
				cout << "\t|                                                                                |" << endl;
				cout << "\t| 2.                   09:50 KUL ------------------- 15:23 PAD                   | RM 100" << endl;
				cout << "\t|                     Kuala Lumpur      05h 33m     Padang Besar                 |" << endl;
				cout << "\t|                                                                                |" << endl;
				cout << "\t| 3.                   10:45 KUL ------------------- 16:33 PAD                   | RM 87" << endl;
				cout << "\t|                     Kuala Lumpur      05h 48m     Padang Besar                 |" << endl;
				cout << "\t|                                                                                |" << endl;
				cout << "\t|********************************************************************************|" << endl;
				
				cout << "Please enter the number of train schedule you want to booking: " ;
				cin >> trainNum;
				if (trainNum == 1){
					FPayment = 100;
					FTime = "07:30-12:45";
				}else if (trainNum == 2){
					FPayment = 100;
					FTime = "09:50-15:23";
				}else{
					FPayment = 87;
					FTime = "10:45-16:33";
				}
				cout << "\tAre you want to Confirm?" << endl;
				cout << "\tPlease enter (Y) for yes (N) for no: " ;
				cin >> finalise;
			}
		}
	}
	ticket.close();			
}

//function for singapore
void Singapore(){
	//variable declaration
	double charge;
	time_t now = time(0);
	tm *ltm = localtime(&now);
	char confirmation;
	char finalise;
	char proceed;
	
	destination = "Singapore";
	//open file in append mode
	ofstream ticket("Ticket.txt", ios::app);
	cout << "\t|********************************************************************************|" << endl;
	cout << "\t|                          Welcome to Singapore Railway                          |" << endl;
	cout << "\t|********************************************************************************|" << endl;
	cout << "\t|                              It's the Right Track                              |" << endl;
	cout << "\t|********************************************************************************|" << endl;
	cout << "\t|                                                                                |" << endl;
	cout << "\tPlease enter the date you want to departure(dd): ";
	cin >> date;
	//while user enter invalid input
	while (stoi(date)>31 || stoi(date) <1){
		cout << "\tInvalid Input" << endl;
		cout << "\tPlease enter the date again(dd): ";
		cin >> date;
	}
	cout << "\tPlease enter the month you want to departure(mm): ";
	cin >> month;
	//while user enter invalid input
	while (stoi(month) >12 || stoi(month) <1){
		cout << "\tInvalid Input" << endl;
		cout << "\tPlease enter the month again(mm): ";
		cin >> month;
	}	
  	cout << "\tThe year you want to depart is " << 1900 + ltm->tm_year << "?" << endl;
	cout << "\tPlease enter (Y) for yes (N) for no: " ;
	cin >> confirmation;
	
	if (confirmation == 'Y' || confirmation == 'y'){
		//display the current year
		year = 1900 + ltm->tm_year;
		
	}else{
		cout << "\tPlease enter the year you want to departure(yyyy): ";
		cin >> year;
	}
	cout << endl;
	cout << "\t|********************************************************************************|" << endl;
	cout << "\t|                          Following are the Train Schedule                      |" << endl;
	cout << "\t|********************************************************************************|" << endl;
	cout << "\t|                                                                                |" << endl;
	cout << "\t| 1.                  13:30 KUL -------------------- 18:07 SING                  | RM 79" << endl;
	cout << "\t|                    Kuala Lumpur       04h 37m       Singapore                  |" << endl;
	cout << "\t|                                                                                |" << endl;
	cout << "\t| 2.                  12:45 KUL -------------------- 17:22 SING                  | RM 79" << endl;
	cout << "\t|                    Kuala Lumpur       04h 37m       Singapore                  |" << endl;
	cout << "\t|                                                                                |" << endl;
	cout << "\t| 3.                  18:30 KUL -------------------- 23:00 SING                  | RM 85" << endl;
	cout << "\t|                    Kuala Lumpur       04h 30m       Singapore                  |" << endl;
	cout << "\t|                                                                                |" << endl;
	cout << "\t|********************************************************************************|" << endl;

	
	cout << "\tPlease enter the number of train schedule you want to booking: " ;
	cin >> trainNum;
	if (trainNum == 1){
		FPayment = 79;
		FTime = "13:30-18:07";
	}else if (trainNum == 2){
		FPayment = 79;
		FTime = "13:45-19:22";
	}else{
		FPayment = 85;
		FTime = "18:30-23:00";
	}

	cout << "\tAre you want to Confirm?" << endl;
	cout << "\tPlease enter (Y) for yes (N) for no: " ;
	cin >> finalise;
	
	if (finalise == 'Y'|| finalise == 'y'){
		chooseSeat(FPayment);
	}else if (finalise == 'N' || finalise == 'n'){
		while (finalise == 'N' || finalise == 'n'){
			cout << "\tAre you want to proceed with booking?" << endl;
			cout << "\tPlease enter (Y) for yes (N) for no: " ;
			cin >> proceed;
			if (proceed == 'Y' || proceed == 'y'){
				cout << "\t|********************************************************************************|" << endl;
				cout << "\t|                          Following are the Train Schedule                      |" << endl;
				cout << "\t|********************************************************************************|" << endl;
				cout << "\t|                                                                                |" << endl;
				cout << "\t| 1.                  13:30 KUL -------------------- 18:07 SING                  | RM 79" << endl;
				cout << "\t|                    Kuala Lumpur       04h 37m       Singapore                  |" << endl;
				cout << "\t|                                                                                |" << endl;
				cout << "\t| 2.                  12:45 KUL -------------------- 17:22 SING                  | RM 79" << endl;
				cout << "\t|                    Kuala Lumpur       04h 37m       Singapore                  |" << endl;
				cout << "\t|                                                                                |" << endl;
				cout << "\t| 3.                  18:30 KUL -------------------- 23:00 SING                  | RM 85" << endl;
				cout << "\t|                    Kuala Lumpur       04h 30m       Singapore                  |" << endl;
				cout << "\t|                                                                                |" << endl;
				cout << "\t|********************************************************************************|" << endl;
				
				cout << "\tPlease enter the number of train schedule you want to booking: " ;
				cin >> trainNum;
				if (trainNum == 1){
					FPayment = 79;
					FTime = "13:30-18:07";
				}else if (trainNum == 2){
					FPayment = 79;
					FTime = "13:45-19:22";
				}else{
					FPayment = 85;
					FTime = "18:30-23:00";
				}
				cout << "\tAre you want to Confirm?" << endl;
				cout << "\tPlease enter (Y) for yes (N) for no: " ;
				cin >> finalise;
			}else if (proceed == 'N' || proceed == 'n'){
				mainmenu();
				break;
			}else{
				cout << "\tInvalid input";
				cout << "\tPlease confirm again your choice";
				cout << "\t|********************************************************************************|" << endl;
				cout << "\t|                          Following are the Train Schedule                      |" << endl;
				cout << "\t|********************************************************************************|" << endl;
				cout << "\t|                                                                                |" << endl;
				cout << "\t| 1.                  13:30 KUL -------------------- 18:07 SING                  | RM 79" << endl;
				cout << "\t|                    Kuala Lumpur       04h 37m       Singapore                  |" << endl;
				cout << "\t|                                                                                |" << endl;
				cout << "\t| 2.                  13:45 KUL -------------------- 19:22 SING                  | RM 79" << endl;
				cout << "\t|                    Kuala Lumpur       04h 37m       Singapore                  |" << endl;
				cout << "\t|                                                                                |" << endl;
				cout << "\t| 3.                  18:30 KUL -------------------- 23:00 SING                  | RM 85" << endl;
				cout << "\t|                    Kuala Lumpur       04h 30m       Singapore                  |" << endl;
				cout << "\t|                                                                                |" << endl;
				cout << "\t|********************************************************************************|" << endl;
				
				cout << "Please enter the number of train schedule you want to booking: " ;
				cin >> trainNum;
				if (trainNum == 1){
					FPayment = 79;
					FTime = "13:30-18:07";
				}else if (trainNum == 2){
					FPayment = 79;
					FTime = "13:45-19:22";
				}else{
					FPayment = 85;
					FTime = "18:30-23:00";
				}
				cout << "\tAre you want to Confirm?" << endl;
				cout << "\tPlease enter (Y) for yes (N) for no: " ;
				cin >> finalise;
			}
		}
	}
	ticket.close();		
}

//function for Taiping
void Taiping(){
	//variable delaration
	double charge;
	time_t now = time(0);
	tm *ltm = localtime(&now);
	char confirmation;
	char finalise;
	char proceed;
	
	destination = "Taiping";
	//open file in append mode
	ofstream ticket("Ticket.txt", ios::app);
	cout << "\t|********************************************************************************|" << endl;
	cout << "\t|                            Welcome to Taiping Railway                          |" << endl;
	cout << "\t|********************************************************************************|" << endl;
	cout << "\t|                               It's the Right Track                             |" << endl;
	cout << "\t|********************************************************************************|" << endl;
	cout << "\t|                                                                                |" << endl;
	cout << "\tPlease enter the date you want to departure(dd): ";
	cin >> date;
	//while user enter invalid input
	while (stoi(date)>31 || stoi(date) <1){
		cout << "\tInvalid Input" << endl;
		cout << "\tPlease enter the date again(dd): ";
		cin >> date;
	}
	cout << "\tPlease enter the month you want to departure(mm): ";
	cin >> month;
	//while user enter invalid input
	while (stoi(month) >12 || stoi(month) <1){
		cout << "\tInvalid Input" << endl;
		cout << "\tPlease enter the month again(mm): ";
		cin >> month;
	}
  	cout << "\tThe year you want to depart is " << 1900 + ltm->tm_year << "?" << endl;
	cout << "\tPlease enter (Y) for yes (N) for no: " ;
	cin >> confirmation;
	
	if (confirmation == 'Y' || confirmation == 'y'){
		//display the current year
		year = 1900 + ltm->tm_year;
		
	}else{
		cout << "\tPlease enter the year you want to departure(yyyy): ";
		cin >> year;
	}
	cout << endl;
	cout << "\t|********************************************************************************|" << endl;
	cout << "\t|                          Following are the Train Schedule                      |" << endl;
	cout << "\t|********************************************************************************|" << endl;
	cout << "\t|                                                                                |" << endl;
	cout << "\t| 1.                   07:30 KUL ------------------- 10:30 TAI                   | RM 69" << endl;
	cout << "\t|                     Kuala Lumpur         03h        Taiping                    |" << endl;
	cout << "\t|                                                                                |" << endl;
	cout << "\t| 2.                   10:50 KUL ------------------- 14:10 TAI                   | RM 50" << endl;
	cout << "\t|                     Kuala Lumpur       03h 20m      Taiping                    |" << endl;
	cout << "\t|                                                                                |" << endl;
	cout << "\t| 3.                   17:00 KUL ------------------- 20:10 TAI                   | RM 50" << endl;
	cout << "\t|                     Kuala Lumpur       03h 10m      Taiping                    |" << endl;
	cout << "\t|                                                                                |" << endl;
	cout << "\t| 4.                   20:50 KUL ------------------- 23:55 TAI                   | RM 75" << endl;
	cout << "\t|                     Kuala Lumpur       03h 05m      Taiping                    |" << endl;
	cout << "\t|                                                                                |" << endl;
	cout << "\t|********************************************************************************|" << endl;

	
	cout << "\tPlease enter the number of train schedule you want to booking: " ;
	cin >> trainNum;
	if (trainNum == 1){
		FPayment = 69;
		FTime = "07:30-10:30";
	}else if (trainNum == 2){
		FPayment = 50;
		FTime = "10:50-14:10";
	}else if (trainNum == 3){
		FPayment = 50;
		FTime = "17:00-20:10";
	}else{
		FPayment = 75;
		FTime = "20:50-23:55";
	}
	cout << "\tAre you want to Confirm?" << endl;
	cout << "\tPlease enter (Y) for yes (N) for no: " ;
	cin >> finalise;
	
	if (finalise == 'Y'|| finalise == 'y'){
		chooseSeat(FPayment);
	}else if (finalise == 'N' || finalise == 'n'){
		while (finalise == 'N' || finalise == 'n'){
			cout << "\tAre you want to proceed with booking?" << endl;
			cout << "\tPlease enter (Y) for yes (N) for no: " ;
			cin >> proceed;
			if (proceed == 'Y' || proceed == 'y'){
				cout << "\t|********************************************************************************|" << endl;
				cout << "\t|                          Following are the Train Schedule                      |" << endl;
				cout << "\t|********************************************************************************|" << endl;
				cout << "\t|                                                                                |" << endl;
				cout << "\t| 1.                   07:30 KUL ------------------- 10:30 TAI                   | RM 69" << endl;
				cout << "\t|                     Kuala Lumpur         03h        Taiping                    |" << endl;
				cout << "\t|                                                                                |" << endl;
				cout << "\t| 2.                   10:50 KUL ------------------- 14:10 TAI                   | RM 50" << endl;
				cout << "\t|                     Kuala Lumpur       03h 20m      Taiping                    |" << endl;
				cout << "\t|                                                                                |" << endl;
				cout << "\t| 3.                   17:00 KUL ------------------- 20:10 TAI                   | RM 50" << endl;
				cout << "\t|                     Kuala Lumpur       03h 10m      Taiping                    |" << endl;
				cout << "\t|                                                                                |" << endl;
				cout << "\t| 4.                   20:50 KUL ------------------- 23:55 TAI                   | RM 75" << endl;
				cout << "\t|                     Kuala Lumpur       03h 05m      Taiping                    |" << endl;
				cout << "\t|                                                                                |" << endl;
				cout << "\t|********************************************************************************|" << endl;
				
				cout << "\tPlease enter the number of train schedule you want to booking: " ;
				cin >> trainNum;
				if (trainNum == 1){
					FPayment = 69;
					FTime = "07:30-10:30";
				}else if (trainNum == 2){
					FPayment = 50;
					FTime = "10:50-14:10";
				}else if (trainNum == 3){
					FPayment = 50;
					FTime = "17:00-20:10";
				}else{
					FPayment = 75;
					FTime = "20:50-23:55";
				}
				cout << "\tAre you want to Confirm?" << endl;
				cout << "\tPlease enter (Y) for yes (N) for no: " ;
				cin >> finalise;
			}else if (proceed == 'N' || proceed == 'n'){
				mainmenu();
				break;
			}else{
				cout << "\tInvalid input";
				cout << "\tPlease confirm again your choice";
				cout << "\t|********************************************************************************|" << endl;
				cout << "\t|                          Following are the Train Schedule                      |" << endl;
				cout << "\t|********************************************************************************|" << endl;
				cout << "\t|                                                                                |" << endl;
				cout << "\t| 1.                   07:30 KUL ------------------- 10:30 TAI                   | RM 69" << endl;
				cout << "\t|                     Kuala Lumpur         03h        Taiping                    |" << endl;
				cout << "\t|                                                                                |" << endl;
				cout << "\t| 2.                   10:50 KUL ------------------- 14:10 TAI                   | RM 50" << endl;
				cout << "\t|                     Kuala Lumpur       03h 20m      Taiping                    |" << endl;
				cout << "\t|                                                                                |" << endl;
				cout << "\t| 3.                   17:00 KUL ------------------- 20:10 TAI                   | RM 50" << endl;
				cout << "\t|                     Kuala Lumpur       03h 10m      Taiping                    |" << endl;
				cout << "\t|                                                                                |" << endl;
				cout << "\t| 4.                   20:50 KUL ------------------- 23:55 TAI                   | RM 75" << endl;
				cout << "\t|                     Kuala Lumpur       03h 05m      Taiping                    |" << endl;
				cout << "\t|                                                                                |" << endl;
				cout << "\t|********************************************************************************|" << endl;
				
				cout << "Please enter the number of train schedule you want to booking: " ;
				cin >> trainNum;
				if (trainNum == 1){
					FPayment = 69;
					FTime = "07:30-10:30";
				}else if (trainNum == 2){
					FPayment = 50;
					FTime = "10:50-14:10";
				}else if (trainNum == 3){
					FPayment = 50;
					FTime = "17:00-20:10";
				}else{
					FPayment = 75;
					FTime = "20:50-23:55";
				}
				cout << "\tAre you want to Confirm?" << endl;
				cout << "\tPlease enter (Y) for yes (N) for no: " ;
				cin >> finalise;
			}
		}
	}
	ticket.close();	
}

//function for Penang
void Penang(){
	//variable declaration
	double charge;
	time_t now = time(0);
	tm *ltm = localtime(&now);
	char confirmation;
	char finalise;
	char proceed;
	
	destination = "Penang";
	//open file in append mode
	ofstream ticket("Ticket.txt", ios::app);
	cout << "\t|********************************************************************************|" << endl;
	cout << "\t|                             Welcome to Penang Railway                          |" << endl;
	cout << "\t|********************************************************************************|" << endl;
	cout << "\t|                               It's the Right Track                             |" << endl;
	cout << "\t|********************************************************************************|" << endl;
	cout << "\t|                                                                                |" << endl;
	cout << "\tPlease enter the date you want to departure(dd): ";
	cin >> date;
	//while user enter invalid input
	while (stoi(date)>31 || stoi(date) <1){
		cout << "\tInvalid Input" << endl;
		cout << "\tPlease enter the date again(dd): ";
		cin >> date;
	}
	cout << "\tPlease enter the month you want to departure(mm): ";
	cin >> month;
	//while user enter invalid input
	while (stoi(month) >12 || stoi(month) <1){
		cout << "\tInvalid Input" << endl;
		cout << "\tPlease enter the month again(mm): ";
		cin >> month;
	}
  	cout << "\tThe year you want to depart is " << 1900 + ltm->tm_year << "?" << endl;
	cout << "\tPlease enter (Y) for yes (N) for no: " ;
	cin >> confirmation;
	
	if (confirmation == 'Y' || confirmation == 'y'){
		//display the current year
		year = 1900 + ltm->tm_year;
		
	}else{
		cout << "\tPlease enter the year you want to departure(yyyy): ";
		cin >> year;
	}
	cout << endl;
	//display the train schedule
	cout << "\t|********************************************************************************|" << endl;
	cout << "\t|                              Following are the Train                           |" << endl;
	cout << "\t|********************************************************************************|" << endl;
	cout << "\t|                                                                                |" << endl;
	cout << "\t| 1.                   08:30 KUL ------------------- 09:45 PEN                   | RM 50" << endl;
	cout << "\t|                      Kuala Lumpur       01h 15m       Penang                   |" << endl;
	cout << "\t|                                                                                |" << endl;
	cout << "\t| 2.                   17:50 KUL ------------------- 18:50 PEN                   | RM 49" << endl;
	cout << "\t|                      Kuala Lumpur         01h        Penang                    |" << endl;
	cout << "\t|                                                                                |" << endl;
	cout << "\t| 3.                   19:10 KUL ------------------- 21:10 PEN                   | RM 49" << endl;
	cout << "\t|                      Kuala Lumpur         01h        Penang                    |" << endl;
	cout << "\t|                                                                                |" << endl;
	cout << "\t| 4.                   20:50 KUL ------------------- 22:00 PEN                   | RM 55" << endl;
	cout << "\t|                      Kuala Lumpur       01h 10m       Penang                   |" << endl;
	cout << "\t|                                                                                |" << endl;
	cout << "\t|********************************************************************************|" << endl;

	
	cout << "\tPlease enter the number of train schedule you want to booking: " ;
	cin >> trainNum;
	if (trainNum == 1){
		FPayment = 50;
		FTime = "08:30-09:45";
	}else if (trainNum == 2){
		FPayment = 49;
		FTime = "17:50-18:50";
	}else if (trainNum == 3){
		FPayment = 49;
		FTime = "19:10-21:10";
	}else if (trainNum == 4){
		FPayment = 55;
		FTime = "20:50-22:00";
	}else{
		cout << "\tInvalid input";
		cout << "\tPlease confirm again your choice";
		//display the train schedule
		cout << "\t|********************************************************************************|" << endl;
		cout << "\t|                              Following are the Train                           |" << endl;
		cout << "\t|********************************************************************************|" << endl;
		cout << "\t|                                                                                |" << endl;
		cout << "\t| 1.                   08:30 KUL ------------------- 09:45 PEN                   | RM 50" << endl;
		cout << "\t|                      Kuala Lumpur       01h 15m       Penang                   |" << endl;
		cout << "\t|                                                                                |" << endl;
		cout << "\t| 2.                   17:50 KUL ------------------- 18:50 PEN                   | RM 49" << endl;
		cout << "\t|                      Kuala Lumpur         01h        Penang                    |" << endl;
		cout << "\t|                                                                                |" << endl;
		cout << "\t| 3.                   19:10 KUL ------------------- 21:10 PEN                   | RM 49" << endl;
		cout << "\t|                      Kuala Lumpur         01h        Penang                    |" << endl;
		cout << "\t|                                                                                |" << endl;
		cout << "\t| 4.                   20:50 KUL ------------------- 22:00 PEN                   | RM 55" << endl;
		cout << "\t|                      Kuala Lumpur       01h 10m      Penang                    |" << endl;
		cout << "\t|                                                                                |" << endl;
		cout << "\t|********************************************************************************|" << endl;
	}
	cout << "\tAre you want to Confirm?" << endl;
	cout << "\tPlease enter (Y) for yes (N) for no: " ;
	cin >> finalise;
	

	
	if (finalise == 'Y'|| finalise == 'y'){
		chooseSeat(FPayment);
	}else if (finalise == 'N' || finalise == 'n'){
		while (finalise == 'N' || finalise == 'n'){
			cout << "\tAre you want to proceed with booking?" << endl;
			cout << "\tPlease enter (Y) for yes (N) for no: " ;
			cin >> proceed;
			if (proceed == 'Y' || proceed == 'y'){
				//display the train schedule
				cout << "\t|********************************************************************************|" << endl;
				cout << "\t|                              Following are the Train                           |" << endl;
				cout << "\t|********************************************************************************|" << endl;
				cout << "\t|                                                                                |" << endl;
				cout << "\t| 1.                   08:30 KUL ------------------- 09:45 PEN                   | RM 50" << endl;
				cout << "\t|                      Kuala Lumpur       01h 15m       Penang                   |" << endl;
				cout << "\t|                                                                                |" << endl;
				cout << "\t| 2.                   17:50 KUL ------------------- 18:50 PEN                   | RM 49" << endl;
				cout << "\t|                      Kuala Lumpur         01h        Penang                    |" << endl;
				cout << "\t|                                                                                |" << endl;
				cout << "\t| 3.                   19:10 KUL ------------------- 21:10 PEN                   | RM 49" << endl;
				cout << "\t|                      Kuala Lumpur         01h        Penang                    |" << endl;
				cout << "\t|                                                                                |" << endl;
				cout << "\t| 4.                   20:50 KUL ------------------- 22:00 PEN                   | RM 55" << endl;
				cout << "\t|                      Kuala Lumpur       01h 10m      Penang                    |" << endl;
				cout << "\t|                                                                                |" << endl;
				cout << "\t|********************************************************************************|" << endl;
				
				cout << "\tPlease enter the number of train schedule you want to booking: " ;
				cin >> trainNum;
				if (trainNum == 1){
					FPayment = 50;
					FTime = "08:30-09:45";
				}else if (trainNum == 2){
					FPayment = 49;
					FTime = "17:50-18:50";
				}else if (trainNum == 3){
					FPayment = 49;
					FTime = "19:10-21:10";
				}else if (trainNum == 4){
					FPayment = 55;
					FTime = "20:50-22:00";
				}else {
					cout << "\tInvalid input";
					cout << "\tPlease confirm again your choice";
					cout << "\t|********************************************************************************|" << endl;
					cout << "\t|                              Following are the Train                           |" << endl;
					cout << "\t|********************************************************************************|" << endl;
					cout << "\t|                                                                                |" << endl;
					cout << "\t| 1.                   08:30 KUL ------------------- 09:45 PEN                   | RM 50" << endl;
					cout << "\t|                      Kuala Lumpur       01h 15m       Penang                   |" << endl;
					cout << "\t|                                                                                |" << endl;
					cout << "\t| 2.                   17:50 KUL ------------------- 18:50 PEN                   | RM 49" << endl;
					cout << "\t|                      Kuala Lumpur         01h        Penang                    |" << endl;
					cout << "\t|                                                                                |" << endl;
					cout << "\t| 3.                   19:10 KUL ------------------- 21:10 PEN                   | RM 49" << endl;
					cout << "\t|                      Kuala Lumpur         01h        Penang                    |" << endl;
					cout << "\t|                                                                                |" << endl;
					cout << "\t| 4.                   20:50 KUL ------------------- 22:00 PEN                   | RM 55" << endl;
					cout << "\t|                      Kuala Lumpur       01h 10m      Penang                    |" << endl;
					cout << "\t|                                                                                |" << endl;
					cout << "\t|********************************************************************************|" << endl;
				}
				cout << "\tAre you want to Confirm?" << endl;
				cout << "\tPlease enter (Y) for yes (N) for no: " ;
				cin >> finalise;
			}else if (proceed == 'N'){
				mainmenu();
				break;
			}else{
				cout << "\tInvalid input";
				cout << "\tPlease confirm again your choice";
				cout << "\t|********************************************************************************|" << endl;
				cout << "\t|                              Following are the Train                           |" << endl;
				cout << "\t|********************************************************************************|" << endl;
				cout << "\t|                                                                                |" << endl;
				cout << "\t| 1.                   08:30 KUL ------------------- 09:45 PEN                   | RM 50" << endl;
				cout << "\t|                      Kuala Lumpur       01h 15m       Penang                   |" << endl;
				cout << "\t|                                                                                |" << endl;
				cout << "\t| 2.                   17:50 KUL ------------------- 18:50 PEN                   | RM 49" << endl;
				cout << "\t|                      Kuala Lumpur         01h        Penang                    |" << endl;
				cout << "\t|                                                                                |" << endl;
				cout << "\t| 3.                   19:10 KUL ------------------- 21:10 PEN                   | RM 49" << endl;
				cout << "\t|                      Kuala Lumpur         01h        Penang                    |" << endl;
				cout << "\t|                                                                                |" << endl;
				cout << "\t| 4.                   20:50 KUL ------------------- 22:00 PEN                   | RM 55" << endl;
				cout << "\t|                      Kuala Lumpur       01h 10m      Penang                    |" << endl;
				cout << "\t|                                                                                |" << endl;
				cout << "\t|********************************************************************************|" << endl;
				
				cout << "\t Please enter the number of train schedule you want to booking: " ;
				cin >> trainNum;
				if (trainNum == 1){
					FPayment = 50;
					FTime = "08:30-09:45";
				}else if (trainNum == 2){
					FPayment = 49;
					FTime = "17:50-18:50";
				}else if (trainNum == 3){
					FPayment = 49;
					FTime = "19:10-21:10";
				}else if (trainNum == 4){
					FPayment = 55;
					FTime = "20:50-22:00";
				}else{
					cout << "\tInvalid input";
					cout << "\tPlease confirm again your choice";
					cout << "\t|********************************************************************************|" << endl;
					cout << "\t|                              Following are the Train                           |" << endl;
					cout << "\t|********************************************************************************|" << endl;
					cout << "\t|                                                                                |" << endl;
					cout << "\t| 1.                   08:30 KUL ------------------- 09:45 PEN                   | RM 50" << endl;
					cout << "\t|                      Kuala Lumpur       01h 15m       Penang                   |" << endl;
					cout << "\t|                                                                                |" << endl;
					cout << "\t| 2.                   17:50 KUL ------------------- 18:50 PEN                   | RM 49" << endl;
					cout << "\t|                      Kuala Lumpur         01h        Penang                    |" << endl;
					cout << "\t|                                                                                |" << endl;
					cout << "\t| 3.                   19:10 KUL ------------------- 21:10 PEN                   | RM 49" << endl;
					cout << "\t|                      Kuala Lumpur         01h        Penang                    |" << endl;
					cout << "\t|                                                                                |" << endl;
					cout << "\t| 4.                   20:50 KUL ------------------- 22:00 PEN                   | RM 55" << endl;
					cout << "\t|                      Kuala Lumpur       01h 10m      Penang                    |" << endl;
					cout << "\t|                                                                                |" << endl;
					cout << "\t|********************************************************************************|" << endl;
				}
				cout << "\tAre you want to Confirm?" << endl;
				cout << "\tPlease enter (Y) for yes (N) for no: " ;
				cin >> finalise;
			}
		}
	}
	ticket.close();
}

void booking(){
	//declare array for the destination for booking
	string train[4] = {"Penang", "Taiping", "Singapore", "Padang Besar"};
	system ("CLS");
	int choice;
	cout << "\t|********************************************************************************|" << endl;
	cout << "\t|                       Booking Your Own Train Ticket Now!!!                     |" <<  endl;
	cout << "\t|********************************************************************************|" << endl;
	
	//using for-loop to print the destination
	for(int i =0;i<4;i++){
		cout <<"\t|" << i+1 <<". " << setw(12) << train[i] << setw(66) << "|" << endl;
	}
	cout << "\t|********************************************************************************|" << endl;

	
	cout << "\t Please enter the number of train schedule you want to booking: " ;
	cin >> choice;
	//call the function accroding to the choice
	if (choice == 1){
		//call the penang function
		Penang();
	}else if (choice == 2){
		//call the taiping function
		Taiping();
	}else if (choice == 3){
		//call the singapore function
		Singapore();
	}else if (choice == 4){
		//call the padang besar function
		PadangBesar ();
	}else{
		//invalid input
		cout << "\tInvalid Input" << endl;
		cout << "\tPlease try Again" << endl;
		booking ();
	}
}

void aboutus(){
	system("CLS");
	cout << "\t|********************************************************************************|" << endl;
	cout << "\t|                                      About Us                                  |" <<  endl;
	cout << "\t|********************************************************************************|" << endl;				                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
	std:: string aboutUsText = "\t|Welcome to Train2Go, your gateway to a transformative travel experience. At     |\n\t|Train2Go, our vision is to seamlessly connect individuals, locations, and       |\n\t|possibilities, redefining the way you perceive and undertake journeys.          |\n\t|Punctuality and efficiency are at the core of our operations, ensuring our state|\n\t|-of-the-art trains deliver you to your destination with unmatched precision.    |\n\t|Beyond punctuality, we prioritize your comfort, providing spacious seating,     |\n\t|modern amenities, and a serene ambiance to make your journey as enjoyable as the|\n\t|destination itself. Our innovative ticketing system simplifies the booking      |\n\t|process, allowing you to secure your travel plans effortlessly through our user-|\n\t|friendly app or website. With a customer-centric approach, our dedicated support|\n\t|team stands ready to assist you, ensuring a smooth and hassle-free travel       |\n\t|experience. Environmental responsibility is integral to our ethos, and our eco- |\n\t|friendly practices contribute to a cleaner, greener planet. Explore our express |\n\t|routes, indulge in the luxury of Business Class, or opt for our group travel    |\n\t|packages tailored for seamless coordination. Whether you're a daily commuter or |\n\t|an occasional traveler, Train2Go invites you to embark on a journey where every |\n\t|Trainpoint is designed for your convenience. Trust us to get you there safely,  |\n\t|comfortably, and on time. Train2Go-Connecting Your World, One Journey at a Time.|\n"; // (Your full text here)
	
	//display the text in typing effect
	for (char c : aboutUsText) {
		std::cout << c << std::flush;
		std::this_thread::sleep_for(std::chrono::milliseconds(20));
	
	}
	
	cout << "\t|********************************************************************************|" << endl;	
	cout << "\t";
	system("pause");
	mainmenu();	
}

void mainmenu(){
	int choice;
	system ("CLS");
	cout << "\t|********************************************************************************|" << endl;
	cout << "\t|                                  Welcome " << setw(9) << currentUserName << setw(30) << "|" << endl;
	cout << "\t|********************************************************************************|" << endl;
	cout << "\t|                                    Train2Go                                    |" << endl;
	cout << "\t|********************************************************************************|" << endl;
	cout << "\t| Press 1 Booking Ticket                                                         |" << endl;
	cout << "\t| Press 2 Display Ticket                                                         |" << endl; //subject to change
	cout << "\t| Press 3 Profile                                                                |" << endl; //done
	cout << "\t| Press 4 Display Seat Plan                                                      |" << endl;
	cout << "\t| Press 5 About us                                                               |" << endl;
	cout << "\t| Press 6 Cancel Booking                                                         |" << endl;
	cout << "\t| Press 7 Exit                                                                   |" << endl;
	cout << "\t| Please enter your choice: ";
	cin >> choice;
	cout << "\t|********************************************************************************|" << endl;
		switch (choice){
			case 1:
				//call the booking function
				booking();
				break;
			case 2:
				//call the display ticket function
				displayTicket();
				break;
			case 3:
				//call the profile function
				profile();
				break;
			case 4:
				//call the display seat function
				displaySeat();
				break;
			case 5:
				//call the about us function
				aboutus();
			    break;
			case 6:
				//call the delete booking function
				deleteBooking();
				break;
			case 7:
				//exit 
				cout << "\t|                               It's the Right Track" <<  setw(30) << "|" << endl;
				cout << "\t|                                     Thank You" << setw(35) << "|" << endl;
				cout << "\t|                                  Have A Nice Day                               |" <<endl;
				cout << "\t|********************************************************************************|" ;
				break;				
			default:
				cout << "\t Invalid Input." << endl;
				cout << "\t Please select your choice from the table given." << endl;
				cout << endl;
				mainmenu();
				break;
	}
}

void login(){
	//variable declaration
	int count;
	string userName, password, LName, Lpass, Lphone, LEmail;
	
	cout << "\tUsername: " ;
	cin >> userName;
	cout << "\tPassword: " ;
	cin >> password;
	
	//declare the file 
	ifstream detail;
	detail.open("userDetail.txt");
	
	//check whether the file exist or not
//	if (detail)
//    {
//        // printing the success message
//        cout << "File exists" << endl;
//    }
//    else
//    {
//        // printing the error message
//        cout << "File does not exists" << endl;
//    }
	
	//read the file
	while (detail >> LName >> Lpass >> Lphone >> LEmail){
		if (LName == userName && Lpass == password){
			//assign count is one to use in next part as the username and password is match with the record
			count = 1 ;
			currentPhoneNumber = Lphone;
			currentEmail = LEmail;
		}
	}
	detail.close();
	
	//if the condition met
	if (count == 1){
		cout << endl;
		cout << "\t|********************************************************************************|" << endl;
		cout << "\t|                               " << userName  << " Login Succeed" << setw(33) << "|" << endl;
		cout << "\t|                              Thank You For Login" << setw(32) << "|" << endl;
		cout << "\t|********************************************************************************|" << endl;
		currentUserName = userName;
		cout << "\t";
		//press any key to continue
		system ("pause");
		//clear the screen
		system ("CLS");

		mainmenu();
		
	} else {
		cout << "\tInvalid Username and/or Password" << endl;
		cout << "\tPlease enter your correct password." << endl;
		login();
	}
}

void registration(){
	//clear the screen
	system ("CLS");
	//variable declaration
	string RUsername, RPassword, RConfirmPass, RPhoneNum, REmailAddress, UName, Upass, Uphone, UEmail;
	cout << "\t|********************************************************************************|" << endl;
	cout << "\t|                                    Registration                                |" << endl;
	cout << "\t|********************************************************************************|" << endl;
	cout << "\tUsername: ";
	cin >> RUsername;
	
	//declare to read file
	ifstream detail("userDetail.txt");
	
	//readfile
	while (detail >> UName >> Upass >> Uphone >> UEmail){
		while (UName == RUsername){
			cout << "\tUsername exist" << endl;
			cout << "\tPlease use another username." << endl;
			cout << "\tUsername: ";
			cin >> RUsername;
			detail.close();
		}
	}
	cout << "\tPassword: ";
	cin >> RPassword;
	cout << "\tConfirm Password: ";
	cin >> RConfirmPass;
	while (RPassword != RConfirmPass){
		cout << "\tPlease confirm again your password!" << endl;
		cout << "\tConfirm Password: ";
		cin >> RConfirmPass;
	}
	cout << "\tPhone Number: ";
	cin >> RPhoneNum;
	
	cout << "\tEmail Address: ";
	cin >> REmailAddress;
	
	//declare for write file
	//ios::app use to open a file and append it to the end
	ofstream registerFile("userDetail.txt", ios::app);
	
	//check for the file exits or not
//	if (registerFile)
//    {
//        // printing the success message
//        cout << "File exists" << endl;
//    }
//    else
//    {
//        // printing the error message
//        cout << "File does not exists" << endl;
//    }


	//write into the file
	registerFile << RUsername << " " << RPassword << " " << RPhoneNum << " " << REmailAddress << endl;
	registerFile.close();
	cout << "\t|********************************************************************************|" << endl;
	cout << "\t|                           Registration Successfull!" << setw(29) << "|" << endl;
	cout << "\t|********************************************************************************|" << endl;
	cout << "\t";
	system ("pause");
	currentUserName = RUsername;
	cout << "\tLogin Your Account" << endl;
	login();
}

//typing effect function
void typeText(const std::string& text, int delay) {
    for (char c : text) {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    }
}

void forgotpassword(){
	//variable declaration
	string sPassword;
	//clear the screen
	system ("CLS");
	int choice;
	cout << "\t|********************************************************************************|" << endl;
	cout << "\t|                                   Forgot Password                              |" << endl;
	cout << "\t|********************************************************************************|" << endl;
	cout << "\t| Press 1 to search your password with username                                  |" << endl;
	cout << "\t| Press 2 Main Menu                                                              |" << endl;
	cout << "\t  Please enter your choice: ";
	cin >> choice;
	cout << "\t|********************************************************************************|" << endl;

	if (choice == 1){
		//variable declaration
		int count = 0;
			string fName,fPassword,fPhone,fEmail;
			string sName;
			
			cout << "\t| Enter your Username: " ;
			cin >> sName;
			
			ifstream search("userDetail.txt");
			while (search >> fName >> fPassword >> fPhone >> fEmail){
				if (sName == fName){
					sPassword = fPassword;
					//assign count is one to use in next part as the username and password is match with the record
					count = 1;
				}
			}
			search.close();
			
			//if the condition met
			if(count == 1){
				cout << "\t| Password: " << sPassword << endl;
				cout << "\t";
				//press any key to continue
				system ("pause");
				//clear the screen
				system ("CLS");
				int choice;
				cout << endl;
			    typeText("\t\t TTTTTT  RRRRR        A      II  N N    N   222222   GGGGG   OOOOOOO  \n", 10);
			    typeText("\t\t   TT    R    R      A A     II  N  N   N        2  G        OO   OO  \n", 10);
			    typeText("\t\t   TT    RRRRR      AAAAA    II  N   N  N   222222  G  GGGG  OO   OO  \n", 10);
			    typeText("\t\t   TT    R   RR    A     A   II  N    N N   2       G     G  OO   OO   \n", 10);
			    typeText("\t\t   TT    R    RR  A       A  II  N     NN   222222   GGGGGG  OOOOOOO  \n\n", 10);	
				cout << "\t|********************************************************************************|" << endl;
				cout << "\t|                                 Welcome to Train2Go                            |" << endl;
				cout << "\t|********************************************************************************|" << endl;
				cout << "\t| Press 1 Login                                                                  |" << endl;
				cout << "\t| Press 2 Registration                                                           |" << endl;
				cout << "\t| Press 3 Forgot Passsword                                                       |" << endl;
				cout << "\t| Press 4 Exit                                                                   |" << endl;
				cout << "\t  Please enter your choice: ";
				cin >> choice;
				cout << "\t|********************************************************************************|" << endl;
				
				switch (choice){
					case 1:
						//call the login function
						login();
						break;
					case 2:
						//call the registration function
						registration();
						break;
					case 3:
						//call the forgot password function
						forgotpassword();
						break;
					case 4:
						//exit
						cout << "\t|                               It's the Right Track" <<  setw(30) << "|" << endl;
						cout << "\t|                                     Thank You" << setw(35) << "|" << endl;
						cout << "\t|********************************************************************************|" ;
						break;
					default:
						//invalid input
						cout << "Invalid Input." << endl;
						cout << "Please select your choice from the table given." << endl;
						cout << endl;
						int main();
						break;
				}
			}else{
				cout << "Sorry, your username is not found" << endl ;
			}
	}else if (choice == 2){
		cout << endl;
	    typeText("\t\t TTTTTT  RRRRR        A      II  N N    N   222222   GGGGG   OOOOOOO  \n", 10);
	    typeText("\t\t   TT    R    R      A A     II  N  N   N        2  G        OO   OO  \n", 10);
	    typeText("\t\t   TT    RRRRR      AAAAA    II  N   N  N   222222  G  GGGG  OO   OO  \n", 10);
	    typeText("\t\t   TT    R   RR    A     A   II  N    N N   2       G     G  OO   OO   \n", 10);
	    typeText("\t\t   TT    R    RR  A       A  II  N     NN   222222   GGGGGG  OOOOOOO  \n\n", 10);		
		cout << "\t|********************************************************************************|" << endl;
		cout << "\t|                                 Welcome to Train2Go                            |" << endl;
		cout << "\t|********************************************************************************|" << endl;
		cout << "\t| Press 1 Login                                                                  |" << endl;
		cout << "\t| Press 2 Registration                                                           |" << endl;
		cout << "\t| Press 3 Forgot Passsword                                                       |" << endl;
		cout << "\t| Press 4 Exit                                                                   |" << endl;
		cout << "\t  Please enter your choice: ";
		cin >> choice;
		cout << "\t|********************************************************************************|" << endl;
		
		switch (choice){
			case 1:
				//call the login function
				login();
				break;
			case 2:
				//call the registration function
				registration();
				break;
			case 3:
				//call the forgot password function
				forgotpassword();
				break;
			case 4:
				//exit
				cout << "\t|                               It's the Right Track" <<  setw(30) << "|" << endl;
				cout << "\t|                                     Thank You" << setw(35) << "|" << endl;
				cout << "\t|********************************************************************************|" ;
				break;
			default:
				cout << "\tInvalid Input." << endl;
				cout << "\tPlease select your choice from the table given." << endl;
				cout << endl;
				int main();
				break;
		}
	}else{
		cout << "Invalid Input! Please try again" << endl;
		forgotpassword();
	}
}

int main()
{	//variable declaration
	int choice;
	cout << endl;
    typeText("\t\t TTTTTT  RRRRR        A      II  N N    N   222222   GGGGG   OOOOOOO  \n", 10);
    typeText("\t\t   TT    R    R      A A     II  N  N   N        2  G        OO   OO  \n", 10);
    typeText("\t\t   TT    RRRRR      AAAAA    II  N   N  N   222222  G  GGGG  OO   OO  \n", 10);
    typeText("\t\t   TT    R   RR    A     A   II  N    N N   2       G     G  OO   OO   \n", 10);
    typeText("\t\t   TT    R    RR  A       A  II  N     NN   222222   GGGGGG  OOOOOOO  \n\n", 10);
	cout << "\t|********************************************************************************|" << endl;
	cout << "\t|                                 Welcome to Train2Go                            |" << endl;
	cout << "\t|********************************************************************************|" << endl;
	cout << "\t| Press 1 Login                                                                  |" << endl;
	cout << "\t| Press 2 Registration                                                           |" << endl;
	cout << "\t| Press 3 Forgot Passsword                                                       |" << endl;
	cout << "\t| Press 4 Exit                                                                   |" << endl;
	cout << "\t  Please enter your choice: ";
	cin >> choice;
	cout << "\t|********************************************************************************|" << endl;
	
	switch (choice){
		case 1:
			login();
			break;
		case 2:
			registration();
			break;
		case 3:
			forgotpassword();
			break;
		case 4:
			cout << "\t|                               It's the Right Track" <<  setw(30) << "|" << endl;
			cout << "\t|                                     Thank You" << setw(35) << "|" << endl;
			cout << "\t|********************************************************************************|" ;
			break;
		default:
			//system("CLS");
			cout << "\tInvalid Input." << endl;
			cout << "\tPlease select your choice from the table given." << endl;
			cout << endl;
			main();
			break;
	}
	return 0;
}
