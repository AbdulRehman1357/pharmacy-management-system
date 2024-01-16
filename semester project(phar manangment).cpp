#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <limits>
#include <sstream>
//add a mg variable
//add del in of ofstream if posible
using namespace std;
struct Pharmacy{

	int id = 0;
	string name;
	int quantity;
	double price;
	string n;
}; 

Pharmacy phar;
vector<Pharmacy> medi;


void validateInput(int& variable, const std::string& prompt,int width) {
    while (true) {
        std::cout << prompt;
        cout<< setfill('.') << left << setw(width) <<right<<" ";
        if (std::cin >> variable && std::cin.peek() == '\n') {
            // Input is a valid integer
            break;
        } else {
            std::cout << "Invalid input. Please enter a valid integer." << std::endl;
            std::cin.clear();  // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear the input buffer
        }
    }
}

void validateInput(double& variable, const std::string& prompt, int width) {
    while (true) {
        std::cout << prompt;
        cout<< setfill('.') << left << setw(width) <<right<<" ";
        if (std::cin >> variable && std::cin.peek() == '\n') {
            // Input is a valid double
            break;
        } else {
            std::cout << "Invalid input. Please enter a valid double." << std::endl;
            std::cin.clear();  // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear the input buffer
        }
    }
}

void validateInput(std::string& variable, const std::string& prompt , int width) {
    std::cout << prompt;
    cout<< setfill('.') << left << setw(width) <<right<<" ";
    std::cin >> variable;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear the input buffer
}





addMed(){
	int choice;
	
	do{	
	
	phar.id = phar.id + 1;

	cout<<" ID: "<<phar.id<<endl;
    validateInput(phar.name, " Enter Name: ",20);
    validateInput(phar.quantity, " Enter Quantity: ",20);
    validateInput(phar.price, " Enter Price: ",20);

		medi.push_back(phar);
		cout<<"Medicines Saved"<<endl;
		do{
			validateInput(choice, "Enter '0' for exit or '1' to contineu: ",20);
			
		}while(choice != 0 && choice !=1);

	}while(choice!=0 && choice==1 ||cin.fail());
}


delMed(){
	
	cout<<"Enter The Medicines Name: ";
	cin>>phar.n;
	for(int i=0;i<medi.size();i++){
		if(phar.n==medi[i].name){
			cout<<" Deleted "<<medi[i].name<<endl<<endl;
			medi.erase(medi.begin()+i);
		}
		
		}
}

allMed(){
	for(int i=0;i<medi.size();i++){
			cout<< setfill('.') << left << setw(20) <<"1. ID: "<<right<<" "<<medi[i].id<<endl;
			cout<< setfill('.') << left << setw(20) <<"2. NAME: "<<right<<" "<<medi[i].name<<endl;
			cout<< setfill('.') << left << setw(20) <<"3. QUANTITY: "<<right<<" "<<medi[i].quantity<<endl;
			cout<< setfill('.') << left << setw(20) <<"4. PRICE: "<<right<<" "<<medi[i].price<<endl<<endl;

	}
}

saveMed(const vector<Pharmacy>&medi,const string&medicines){
	ofstream out("C:/Users/syeda/Desktop/medicine/medicines.txt", ios::app);
	if(!out){
		cerr<<"File Not Found"<<medicines<<endl;
	}
	for(int i=0;i<medi.size();i++){
out<<medi[i].id<<endl<<medi[i].name<<endl<<medi[i].quantity<<endl<<medi[i].price<<endl<<endl;		
//out<<"ID:"<<medi[i].id<<endl<<"NAME: "<<medi[i].name<<endl<<"QUANTITY: "<<medi[i].quantity<<endl<<"PRICE: "<<medi[i].price<<endl<<endl;
	}
	out.close();
	cout<<"it is saved"<< " " <<medicines<<endl<<endl;
}


void displayMed(const string& medicinesFile) {
    ifstream in("C:/Users/syeda/Desktop/medicine/medicines.txt");
    if (!in) {
        cerr << "File Not Found: " << medicinesFile << endl;
        return;
    }

    string line;
    while (getline(in, line)) {
        cout << line << endl;
    }

    in.close();
}




//void searchAndDisplayMed(const string& medicinesFile, const string& searchTerm) {
//    cout << "Searching for medicines with the name '" << searchTerm << "':\n";
//
//    ifstream in(medicinesFile.c_str());
//    if (!in) {
//        cerr << "File Not Found: " << medicinesFile << endl;
//        return;
//    }
//
//    bool found = false;
//    Pharmacy temp;
//
//    while (in >> temp.id) {
//    	cout<<in<<endl;
//    	cout<<temp.id<<endl;
//        // Consume the 'ID:' part
//        in.ignore(numeric_limits<streamsize>::max(), ':');
//
//        // Read the name, quantity, and price
//        in >>temp.id>> temp.name >> temp.quantity >> temp.price;
//        cout<<temp.name<<endl;
//
//        // Check if the name matches the search term
//        if (temp.name == searchTerm) {
//            cout << setfill('.') << left << setw(20) << "1. ID: " << right << " " << temp.id << endl;
//            cout << setfill('.') << left << setw(20) << "2. NAME: " << right << " " << temp.name << endl;
//            cout << setfill('.') << left << setw(20) << "3. QUANTITY: " << right << " " << temp.quantity << endl;
//            cout << setfill('.') << left << setw(20) << "4. PRICE: " << right << " " << temp.price << endl;
//
//            found = true;
//            break;  // Stop searching after finding the first match
//        }
//
//        // Consume the rest of the line
//        in.ignore(numeric_limits<streamsize>::max(), '\n');
//    }
//
//    in.close();
//
//    if (!found) {
//        cout << "Medicine not found with the specified criteria." << endl;
//    }
//}







//void searchAndDisplayMed(const string& medicinesFile, const string& searchTerm) {
//    cout << "Searching for medicines with the name '" << searchTerm << "':\n";
//    cout<<"meow"<<endl;
//
//    ifstream in(medicinesFile.c_str());
//    if (!in) {
//        cerr << "File Not Found: " << medicinesFile << endl;
//        return;
//    }
//
//    bool found = false;
//    Pharmacy temp;
//cout<<"meow1"<<endl;
//    while (in >> temp.id >> temp.name >> temp.quantity >> temp.price) {
//    	cout<<"meow2"<<endl;
//    	cout<<temp.name;
//    
//    	in.ignore(numeric_limits<streamsize>::max(), ':');
//        if (temp.name == searchTerm) {
//            cout << setfill('.') << left << setw(20) << "1. ID: " << right << " " << temp.id << endl;
//            cout << setfill('.') << left << setw(20) << "2. NAME: " << right << " " << temp.name << endl;
//            cout << setfill('.') << left << setw(20) << "3. QUANTITY: " << right << " " << temp.quantity << endl;
//            cout << setfill('.') << left << setw(20) << "4. PRICE: " << right << " " << temp.price << endl;
//
//            found = true;
//            break;  // Stop searching after finding the first match
//        }
//    }
//
//    in.close();
//
//    if (!found) {
//    	for(int i=0;i<medi.size();i++){
//		if (searchTerm == medi[i].name){
//			cout<< setfill('.') << left << setw(20) <<"1. ID: "<<right<<" "<<medi[i].id<<endl;
//			cout<< setfill('.') << left << setw(20) <<"2. NAME: "<<right<<" "<<medi[i].name<<endl;
//			cout<< setfill('.') << left << setw(20) <<"3. QUANTITY: "<<right<<" "<<medi[i].quantity<<endl;
//			cout<< setfill('.') << left << setw(20) <<"4. PRICE: "<<right<<" "<<medi[i].price<<endl;  
//
//	 }}
//	 
//        
//    }else{
//    	cout << "Medicine not found with the specified criteria."<< endl;
//	}
//}




void searchAndDisplayMed(const string& medicinesFile, const string& searchTerm) {
    cout << "Searching for medicines with the name '" << searchTerm << "':\n";

    ifstream in(medicinesFile.c_str());
    if (!in) {
        cerr << "File Not Found: " << medicinesFile << endl;
        return;
    }

    bool found = false;
    Pharmacy temp;
cout<<in<<1<<endl;
    while (in >> temp.id) {
        // Consume the 'ID:' part
        cout<<in<<2<<endl;
        in.ignore(numeric_limits<streamsize>::max(), ':');

        // Read the name, quantity, and price
        in >> temp.name >> temp.quantity >> temp.price;

        if (temp.name == searchTerm) {
            cout << setfill('.') << left << setw(20) << "1. ID: " << right << " " << temp.id << endl;
            cout << setfill('.') << left << setw(20) << "2. NAME: " << right << " " << temp.name << endl;
            cout << setfill('.') << left << setw(20) << "3. QUANTITY: " << right << " " << temp.quantity << endl;
            cout << setfill('.') << left << setw(20) << "4. PRICE: " << right << " " << temp.price << endl;

            found = true;
            break;  // Stop searching after finding the first match
        }
    }

    in.close();

    if (!found) {
    	cout<<temp.name<<endl<<in<<32<<endl;
        cout << "Medicine not found with the specified criteria." << endl;
    }
}



void editMed(vector<Pharmacy>& medi, const string& medicinesFile, const string& editTerm) {
    cout << "Editing medicine with the name '" << editTerm << "':\n";

    ifstream in(medicinesFile.c_str());
    if (!in) {
        cerr << "File Not Found: " << medicinesFile << endl;
        return;
    }

    vector<Pharmacy> updatedMedi;
    Pharmacy temp;
    while (in >> temp.id >> temp.name >> temp.quantity >> temp.price) {
        if (temp.name == editTerm) {
            // Modify the medicine data as needed
            cout << "Enter new quantity: ";
            cin >> temp.quantity;
            cout << "Enter new price: ";
            cin >> temp.price;
        }

        updatedMedi.push_back(temp);
    }

    in.close();

    ofstream out(medicinesFile.c_str());
    if (!out) {
        cerr << "File Not Found: " << medicinesFile << endl;
        return;
    }

    for (size_t i = 0; i < updatedMedi.size(); ++i) {
        out << i + 1 << " " << "ID:" << updatedMedi[i].id << endl
            << "NAME: " << updatedMedi[i].name << endl
            << "QUANTITY: " << updatedMedi[i].quantity << endl
            << "PRICE: " << updatedMedi[i].price << endl << endl;
    }

    out.close();
    cout << "Medicine edited successfully." << endl;
}





//void editMedicine(vector<Pharmacy>& medi, const string& medicinesFile, const string& searchTerm) {
//    cout << "Editing medicine with the name '" << searchTerm << "':\n";
//
//    ifstream in(medicinesFile.c_str());
//    if (!in) {
//        cerr << "File Not Found: " << medicinesFile << endl;
//        return;
//    }
//
//    vector<Pharmacy> updatedMedi;
//    Pharmacy temp;
//    while (in >> temp.id) {
//        // Consume the 'ID:' part
////        in.ignore(numeric_limits<streamsize>::max(), ':');
//
//        // Read the name, quantity, and price
//        in >> temp.name >> temp.quantity >> temp.price;
//
//        if (temp.name == searchTerm) {
//            // Modify the medicine data as needed
//            cout << "Enter new quantity: ";
//            cin >> temp.quantity;
//            cout << "Enter new price: ";
//            cin >> temp.price;
//        }
//
//        updatedMedi.push_back(temp);
//    }
//
//    in.close();
//
//    ofstream out(medicinesFile.c_str());
//    if (!out) {
//        cerr << "File Not Found: " << medicinesFile << endl;
//        return;
//    }
//
//    for (size_t i = 0; i < updatedMedi.size(); ++i) {
//        out << updatedMedi[i].id << " " << "ID:" << updatedMedi[i].id << endl
//            << "NAME: " << updatedMedi[i].name << endl
//            << "QUANTITY: " << updatedMedi[i].quantity << endl
//            << "PRICE: " << updatedMedi[i].price << endl << endl;
//    }
//
//    out.close();
//    cout << "Medicine edited successfully." << endl;
//}









int main(){
	cout<<fixed<<showpoint<<setprecision(2);
	int value;
	do{
		
		cout<< "Press 1 to add madicines"<<endl;
		cout<< "Press 2 to search madicines"<<endl;
		cout<< "Press 3 to delete madicines"<<endl;
		cout<< "Press 4 to show all madicines"<<endl;
		cout<< "Press 5 to save madicines"<<endl;
		cout<< "Press 6 to exit program"<<endl;
		cout<< "Press 7 to clear screen program"<<endl;
		cout<< "Press 8 to edit program"<<endl;
		cout<<" type here: ";
			
		while (!(cin >> value) || value < 1 || value > 8) {
            cout << "Invalid input. Please enter a valid option (1-7): ";
            cin.clear();  // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');}//working lern this
	
		
				

	
		switch(value){
			case 1:{
			    addMed();
				break;
			}
			case 2:{
				string searchTerm;
				cin>>searchTerm;
			    searchAndDisplayMed("C:/Users/syeda/Desktop/medicine/medicines.txt",searchTerm);
				break;
			}
			case 3:{
			    delMed();
				break;
			}
			case 4:{
			    allMed();
			    displayMed("C:/Users/syeda/Desktop/medicine/medicines.txt");
				break;
			}
			case 5:{
			    saveMed(medi, "C:/Users/syeda/Desktop/medicine/medicines.txt");
			    
				break;
			}
			case 6:{
			    exit(0);
				break;
			}
			case 7:{
			    system("cls");
				break;
			}
			case 8:{
				string editTerm;
				cout<<"enter medi to edit:";
				cin>>editTerm;
			    editMed(medi,"C:/Users/syeda/Desktop/medicine/medicines.txt",editTerm);
				break;
			}
			default:{
				cout<<"enterd a wrong value"<<endl;
				break;
			}
		}//switch
	}while(true);//loop
return 0;
 }//main
