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
    Flight(string n, string d)
    {
        maxSeats = 40;
        flightNo = n;
        destination = d;
        numPassengers = 0;
    }
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
    int numFlights;
public:
    void addFlight(const Flight &flight);
    void removeFlight(const string& flightNumber);
    void listAllFlights();
    Flight getFlightByNumber(const string& flightNumber);
    Flight getFlightByDestination(const string& destination);
};

void FlightManager::addFlight(const Flight &flight)
{
    flights.push_back(flight);
}

void FlightManager::removeFlight(const std::string &flightNumber)
{

}

int flightMenu()
{
    int opChoice;
    cout << "Flight Management Menu" << endl;
    cout << "1. Add a Flight" << endl;
    cout << "2. Remove a Flight" << endl;
    cout << "3. List All Flight" << endl;
    cout << "4. Select a Flight and Manage passengers" << endl;
    cout << "5. Exit" << endl;
    cout << "Choose: ";
    cin >> opChoice;
    return opChoice;
}

int passengerMenu()
{
    int opChoice;
    cout << "Passenger Management Menu" << endl;
    cout << "1. Reserve a Seat" << endl;
    cout << "2. Cancel a Reservation" << endl;
    cout << "3. View Passenger List" << endl;
    cout << "4. Back to Flight Management Menu" << endl;
    cout << "Choose: ";
    cin >> opChoice;
    return opChoice;
}

int main() {

    int choice, choiceP;
    string flightNo, destination;
    bool loop;

    FlightManager Airline;

    do
    {
        choice = flightMenu();
        if(choice == 1)
        {
            cout << "Enter the flight number: ";
            cin >> flightNo;
            cout << "Enter the destination: ";
            cin >> destination;
            Flight flight(flightNo, destination);
            Airline.addFlight(flight);
        }
        else if(choice == 2)
        {
            cout << "Enter the flight number: ";
            cin >> flightNo;
        }
        else if(choice == 3)
        {

        }
        else if(choice == 4)
        {
            loop = true;
            cout << "Enter the flight number: ";
            cin >> flightNo;

            do
            {
                choiceP = passengerMenu();
                if(choiceP == 1)
                {

                }
                else if(choiceP == 2)
                {

                }
                else if(choiceP == 3)
                {

                }
                else if(choice == 4)
                {
                    loop = false;
                }
            }while(loop);
        }
        else if(choice == 5)
        {
            cout << "\nBye!";
            return 0;
        }
    }while(true);
}
