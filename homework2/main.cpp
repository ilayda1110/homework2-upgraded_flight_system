#include <iostream>
#include <vector>

using namespace std;

class Seat
{
private:
    string seatNo;
    char occupied;
public:
    void setSeatNo(string s) { seatNo = s; }
    void setOccupied(char o) { occupied = o; }
    string getSeatNo() { return seatNo; }
    char getOccupied() { return occupied; }
};

class Passenger
{
private:
    string name;
    string surname;
    char gender;
    Seat seat;
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
    friend void operator<<(ostream& os, Passenger& pas)
    {
        os << "\n";
        os << "Name: " << pas.name << endl;
        os << "Surname: " << pas.surname << endl;
        os << "Gender: " << pas.gender << endl;
        os << "Seat: " << pas.seat.getSeatNo() << endl;
        os << "\n";
    }
    void setSeat(string s)
    {
        seat.setSeatNo(s);
        seat.setOccupied('X');
    }
    string getSeat()
    {
        return seat.getSeatNo();
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

    //I added this one
    Seat seats[10][4];
public:
    Flight(string n, string d): destination(d), maxSeats(40), flightNo(n), numPassengers(0)
    {
        char c = 'A';
        for(int i=0; i < 10; i++)
        {
            for(int j=0; j < 4; j++)
            {
                seats[i][j].setSeatNo(to_string(i+1)+ c);
                seats[i][j].setOccupied('O');
                c++;
            }
            c = 'A';
        }
    }
    Flight() : maxSeats(40), numPassengers(0) {}
    bool reserveSeat(Passenger& passenger);
    bool cancelReservation(Passenger& passenger);
    int numberOfPassengers() { return numPassengers; }
    void printPassengers();
    bool isFlyingTo(const string& destination);

    //I added those functions:
    void setFlightNo(string n) { flightNo = n; }
    void setDestination(string d) { destination = d; }
    void setSeats(int s) { maxSeats = s; }
    void setPassengers(int p) { numPassengers = p; }

    string getFlightNo() { return flightNo; }
    string getDestination() { return destination; }
    int getSeats() { return maxSeats; }
    int getPassengers() { return numPassengers; }

    void printInfo();

    Flight operator=(Flight const& obj)
    {
        Flight temp;
        temp.setFlightNo(obj.flightNo);
        temp.setDestination(obj.destination);
        temp.setPassengers(obj.numPassengers);
        return temp;
    }
};

bool Flight::reserveSeat(Passenger &passenger)
{
    string choice;
    cout << "Legend: " << endl;
    cout << "X - Occupied Seat" << endl;
    cout << "O - Vacant Seat" << endl;
    cout << "\nSeating Plan:" << endl;
    cout << "----------Front----------" << endl;

    for(int i=0; i < 10; i++)
    {
        for(int j=0; j < 4; j++)
        {
            cout << "|  " << seats[i][j].getSeatNo() << " " << seats[i][j].getOccupied() << "  ";
        }
        cout << "\n";
    }
    cout << "Choose: ";
    cin >> choice;
    for(int i=0; i < 10; i++)
    {
        for(int j=0; j < 4; j++)
        {
            if(seats[i][j].getSeatNo() == choice)
            {
                if(seats[i][j].getOccupied() == 'O')
                {
                    passenger.setSeat(seats[i][j].getSeatNo());
                    passengers.push_back(passenger);
                    seats[i][j].setOccupied('X');
                    numPassengers++;
                    maxSeats--;
                    return true;
                }
            }
        }
    }
    return false;
}

bool Flight::cancelReservation(Passenger &passenger)
{
    for(int i=0; i < numPassengers; i++)
    {
        if((passenger.getName()==passengers[i].getName()) && (passenger.getSurname()==passengers[i].getSurname()))
        {
            for(int t=0; t < 10; t++)
            {
                for(int k=0; k < 4; k++)
                {
                    if(seats[t][k].getSeatNo() == passenger.getSeat())
                    {
                        seats[t][k].setOccupied('O');
                    }
                }
            }

            for(int j=i+1; j < numPassengers; j++)
            {
                passengers[i].setName(passengers[j].getName());
                passengers[i].setSurname(passengers[j].getSurname());
                passengers[i].setGender(passengers[j].getGender());
                passengers[i].setSeat(passengers[i].getSeat());
            }
            numPassengers--;
            return true;
        }
    }
    return false;
}

void Flight::printPassengers()
{
    for(int i=0; i < numPassengers; i++)
    {
        cout << passengers[i];
    }
}

bool Flight::isFlyingTo(const string& destination)
{
    cout << "Flight is flying to " << destination << endl;
}

void Flight::printInfo()
{
    cout << "\n";
    cout << flightNo << " / " << destination << endl;
    cout << "Available seat numbers: " << (maxSeats-numPassengers) << endl;
    cout << "\n";
}

class FlightManager
{
private:
    vector<Flight>flights;
    int numFlights = 0; //I added this one
public:
    void addFlight(const Flight &flight);
    bool removeFlight(const string& flightNumber);
    void listAllFlights();
    Flight getFlightByNumber(const string& flightNumber);
    Flight getFlightByDestination(const string& destination);
};

void FlightManager::addFlight(const Flight &flight)
{
    flights.push_back(flight);
    numFlights++;
}

bool FlightManager::removeFlight(const string &flightNumber)
{
    for(int i=0; i < numFlights; i++)
    {
        if(flights[i].getFlightNo() == flightNumber)
        {
            for(int j=i+1; j < numFlights; j++)
            {
                flights[i].setFlightNo(flights[j].getFlightNo());
                flights[i].setDestination(flights[j].getDestination());
                flights[i].setSeats(flights[j].getSeats());
                flights[i].setPassengers(flights[j].getPassengers());
            }
            numFlights--;
            return true;
        }
    }
    return false;
}

void FlightManager::listAllFlights()
{
    for(int i=0; i < numFlights; i++)
    {
        flights[i].printInfo();
    }
}

Flight FlightManager::getFlightByNumber(const std::string &flightNumber)
{
    for(int i=0; i < numFlights; i++)
    {
        if(flights[i].getFlightNo() == flightNumber)
        {
            return flights[i];
        }
    }
}

Flight FlightManager::getFlightByDestination(const std::string &destination)
{
    for(int i=0; i < numFlights; i++)
    {
        if(flights[i].getDestination() == destination)
        {
            return flights[i];
        }
    }
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
    bool loop, checkRemoveF, checkReservation, checkRemoveR;

    FlightManager airline;

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
            airline.addFlight(flight);
        }
        else if(choice == 2)
        {
            cout << "Enter the flight number: ";
            cin >> flightNo;
            checkRemoveF = airline.removeFlight(flightNo);
            if(checkRemoveF)
            {
                cout << "Successfully removed" << endl;
            }
            else
            {
                cout << "Could not be removed" << endl;
            }
        }
        else if(choice == 3)
        {
            airline.listAllFlights();
        }
        else if(choice == 4)
        {
            loop = true;
            cout << "Enter the flight number: ";
            cin >> flightNo;
            Flight selectedFlight = airline.getFlightByNumber(flightNo);

            do
            {
                choiceP = passengerMenu();
                if(choiceP == 1)
                {
                    Passenger passenger;
                    checkReservation = selectedFlight.reserveSeat(passenger);
                    if(checkReservation)
                    {
                        cout << "Successfully reserved" << endl;
                    }
                    else
                    {
                        cout << "Could not be reserved" << endl;
                    }
                }
                else if(choiceP == 2)
                {
                    Passenger passenger;
                    checkRemoveR = selectedFlight.cancelReservation(passenger);
                    if(checkReservation)
                    {
                        cout << "Successfully removed" << endl;
                    }
                    else
                    {
                        cout << "Could not be removed" << endl;
                    }
                }
                else if(choiceP == 3)
                {
                    selectedFlight.printPassengers();
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