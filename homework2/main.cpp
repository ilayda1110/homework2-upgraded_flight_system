#include <iostream>
#include <vector>

using namespace std;

class Passenger
{
private:
    string name;
    string surname;
    char gender;
public:
    Passenger()
    {
        cout << "\n--------------------------------" << endl;
        cout << "Enter your name: ";
        cin >> name;
        cout << "Enter your surname: ";
        cin >> surname;
        cout << "Enter your gender: ";
        cin >> gender;
        cout << "--------------------------------" << endl;
    }
    void setName(string n) { name = n; }
    void setSurname(string s) { surname = s; }
    void setGender(char g) { gender = g; }
    string getName() { return name; }
    string getSurname() { return surname; }
    char getGender() { return gender; }
    friend void operator<<(ostream& os, const Passenger& pas)
    {
        os << "\n";
        os << "Name: " << pas.name << endl;
        os << "Surname: " << pas.surname << endl;
        os << "Gender: " << pas.gender << endl;
        os << "\n";
    }
};

class Flight
{
private:
    string flightNo;
    string destination;
    int maxSeats;
    int numPassengers;
    vector<Passenger> passengers;
public:
    void reserveSeat(const Passenger& passenger);
    void cancelReservation(const Passenger& passenger);
    int numberOfPassengers();
    void printPassengers();
    bool isFlyingTo(const string& destination);
};

class FlightManager
{
private:
    vector<Flight>flights;
public:
    void addFlight(const Flight &flight);
    void removeFlight(const string& flightNumber);
    void listAllFlights();
    Flight getFlightByNumber(const string& flightNumber);
    Flight getFlightByDestination(const string& destination);
};

int printMenu()
{
    int opChoice;
    cout << "Menu" << endl;
    cout << "1. Add a Flight" << endl;
    cout << "2. Remove a Flight" << endl;
    cout << "3. List All Flight" << endl;
    cout << "4. Select a Flight and Manage passengers" << endl;
    cout << "5. Exit" << endl;
    cout << "Choose: ";
    cin >> opChoice;
    return opChoice;
}

int main() {

    int choice;

    do
    {
        choice = printMenu();
        if(choice == 1)
        {

        }
        else if(choice == 2)
        {

        }
        else if(choice == 3)
        {

        }
        else if(choice == 4)
        {

        }
        else if(choice == 5)
        {
            cout << "\nBye!";
            return 0;
        }
    }while(true);
}
