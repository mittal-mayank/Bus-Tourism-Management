#include <bits/stdc++.h>
using namespace std;

class Passenger
{
private:
    string name;
    int age;
    string gender;
    string phone;
    string email;

public:
    Passenger()
    {
        cout << "Enter your details:-" << endl;
        cout << "Name: ";
        cin >> name;
        cout << "Age: ";
        cin >> age;
        cout << "Gender: ";
        cin >> gender;
        cout << "Phone No: ";
        cin >> phone;
        cout << "E-mail: ";
        cin >> email;
    }
    void displayPassenger()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
        cout << "Phone No: " << phone << endl;
        cout << "E-mail: " << email << endl;
    }
};

class Seat
{
private:
    Passenger *passenger;
    int row;
    int column;

public:
    Seat(Passenger passenger, int row, int column)
    {
        this->passenger = &passenger;
        this->row = row;
        this->column = column;
    }
    void displayCoordinates()
    {
        cout << "Row: " << row << ", Column: " << column << endl;
    }
    void displaySeat()
    {
        passenger->displayPassenger();
        cout << "Row: " << row << ", Column: " << column << endl;
    }
    bool operator==(const Seat &s) const
    {
        return (this->row == s.row) && (this->column == s.column);
    }
};

class SeatHash
{
public:
    size_t operator()(const Seat &s) const
    {
        return (long)&s;
    }
};

class Bus
{
public:
    bool ac;
    bool food;
    bool sleeper;
    bool toilet;
    bool tv;
    char type;
    unordered_set<Seat, SeatHash> seats;

    virtual void displayVacantSeats() = 0;
    virtual Seat bookSeat() = 0;
    virtual void cancelSeat(Seat seat) = 0;
};

class Tier1 : public Bus
{
private:
    static const int rows = 5;
    static const int columns = 2;

public:
    Tier1()
    {
        ac = true;
        food = true;
        sleeper = true;
        toilet = true;
        tv = true;
        type = '1';
    }
    void displayVacantSeats()
    {
        cout << "Seats range, Rows: " << rows << ", Columns: " << columns << endl;
        cout << "Non-vacant seats:-" << endl;
        if (seats.empty())
        {
            cout << "All vacant" << endl;
        }
        else
        {
            for (Seat seat : seats)
            {
                seat.displayCoordinates();
            }
        }
    }
    Seat bookSeat()
    {
        cout << "Enter seat co-ordinates:-" << endl;
        int row;
        cout << "Row: ";
        cin >> row;
        int column;
        cout << "Column: ";
        cin >> column;
        Seat seat = *new Seat(*new Passenger(), row, column);
        seats.emplace(seat);
        cout << "Seat booked!" << endl;
        cout << endl;
        return seat;
    }
    void cancelSeat(Seat seat)
    {
        seats.erase(seat);
        cout << "Seat cancelled!" << endl;
        cout << endl;
    }
};

class Tier2 : public Bus
{
private:
    static const int rows = 10;
    static const int columns = 4;

public:
    Tier2()
    {
        ac = true;
        food = true;
        sleeper = false;
        toilet = false;
        tv = false;
        type = '2';
    }
    void displayVacantSeats()
    {
        cout << "Seats range, Rows: " << rows << ", Columns: " << columns << endl;
        cout << "Non-vacant seats:-" << endl;
        if (seats.empty())
        {
            cout << "All vacant" << endl;
        }
        else
        {
            for (Seat seat : seats)
            {
                seat.displayCoordinates();
            }
        }
    }
    Seat bookSeat()
    {
        cout << "Enter seat co-ordinates:-" << endl;
        int row;
        cout << "Row: ";
        cin >> row;
        int column;
        cout << "Column: ";
        cin >> column;
        Seat seat = *new Seat(*new Passenger(), row, column);
        seats.emplace(seat);
        cout << "Seat booked!" << endl;
        cout << endl;
        return seat;
    }
    void cancelSeat(Seat seat)
    {
        seats.erase(seat);
        cout << "Seat cancelled!" << endl;
        cout << endl;
    }
};

class Tier3 : public Bus
{
private:
    static const int rows = 10;
    static const int columns = 4;

public:
    Tier3()
    {
        ac = false;
        food = false;
        sleeper = false;
        toilet = false;
        tv = false;
        type = '3';
    }
    void displayVacantSeats()
    {
        cout << "Seats range, Rows: " << rows << ", Columns: " << columns << endl;
        cout << "Non-vacant seats:-" << endl;
        if (seats.empty())
        {
            cout << "All vacant" << endl;
        }
        else
        {
            for (Seat seat : seats)
            {
                seat.displayCoordinates();
            }
        }
    }
    Seat bookSeat()
    {
        cout << "Enter seat co-ordinates:-" << endl;
        int row;
        cout << "Row: ";
        cin >> row;
        int column;
        cout << "Column: ";
        cin >> column;
        Seat seat = *new Seat(*new Passenger(), row, column);
        seats.emplace(seat);
        cout << "Seat booked!" << endl;
        cout << endl;
        return seat;
    }
    void cancelSeat(Seat seat)
    {
        seats.erase(seat);
        cout << "Seat cancelled!" << endl;
        cout << endl;
    }
};

class Trip
{
private:
    Bus *bus;
    string startDay;
    string startTime;
    string endDay;
    string endTime;
    int fare;

public:
    Trip(Bus *bus, string startDay, string startTime, string endDay, string endTime, int fare)
    {
        this->bus = bus;
        this->startDay = startDay;
        this->startTime = startTime;
        this->endDay = endDay;
        this->endTime = endTime;
        this->fare = fare;
    }
    Seat bookTrip()
    {
        cout << endl;
        return bus->bookSeat();
    }
    void cancelTrip(Seat seat)
    {
        cout << endl;
        bus->cancelSeat(seat);
    }
    void displayTrip()
    {
        cout << "Bus tier: " << bus->type << endl;
        cout << "Start day: " << startDay << endl;
        cout << "Start time: " << startTime << endl;
        cout << "End day: " << endDay << endl;
        cout << "End time: " << endTime << endl;
        bus->displayVacantSeats();
        cout << "Orignal fare: " << fare << endl;
    }
    int discount()
    {
        cout << "You have been selected for a discount round wherein you will have to perform a simple task and on the basis of that you will be awarded a discount on fare" << endl;
        cout << "Enter two numbers from 1 to 10:-" << endl;
        int a;
        cout << "Enter first number: ";
        cin >> a;
        int b;
        cout << "Enter second number: ";
        cin >> b;
        int discount;
        int prevFare = fare;
        int c = a | b;
        if (c > 13)
        {
            cout << "Congratulations! You have got a flat 10% reduction in fares" << endl;
            discount = 10;
            prevFare = fare * (100 - discount) / 100;
        }
        else if (c<13 | c> 9)
        {
            cout << "Congratulations! You have got a flat 7% reduction in fares" << endl;
            discount = 7;
            prevFare = fare * (100 - discount) / 100;
        }
        else if (c<9 | c> 5)
        {
            cout << "Congratulations! You have got a flat 5% reduction in fares" << endl;
            discount = 5;
            prevFare = fare * (100 - discount) / 100;
        }
        else if (c<5 & c> 0)
        {
            cout << "You have got no reduction in fares! Better luck next time!" << endl;
        }
        cout << endl;
        return prevFare;
    }
};

class Ticket
{
private:
    static const string source;
    string destination;
    Trip *trip;
    Seat *seat;
    int fare;

public:
    Ticket(string destination, Trip trip, Seat seat)
    {
        this->destination = destination;
        this->trip = &trip;
        this->seat = &seat;
        setFare();
    }
    void displayTicket()
    {
        cout << "Source: " << source << endl;
        cout << "Destination: " << destination << endl;
        trip->displayTrip();
        cout << "Discounted fare: " << fare << endl;
        seat->displaySeat();
        cout << endl;
    }
    void cancelTicket()
    {
        trip->cancelTrip(*seat);
    }
    void setFare()
    {
        fare = trip->discount();
    }
};
const string Ticket::source = "Delhi";

class Log
{
private:
    unordered_map<unsigned long, Ticket> mapTicket;
    unordered_map<string, vector<Trip>> mapTrips;

    vector<Trip> mumbaiList()
    {
        vector<Trip> trips;
        trips.push_back(*(new Trip(new Tier1(), "Tuesday", "1200", "Thursday", "1200", 5000)));
        trips.push_back(*(new Trip(new Tier2(), "Saturday", "1200", "Monday", "1200", 3000)));
        trips.push_back(*(new Trip(new Tier3(), "Thursday", "1800", "Saturday", "1800", 1700)));
        return trips;
    }
    vector<Trip> jaipurList()
    {
        vector<Trip> trips;
        trips.push_back(*(new Trip(new Tier1(), "Wednesday", "1200", "Thursday", "1200", 3500)));
        trips.push_back(*(new Trip(new Tier2(), "Sunday", "1200", "Monday", "1200", 2500)));
        trips.push_back(*(new Trip(new Tier3(), "Friday", "1800", "Saturday", "1800", 1000)));
        return trips;
    }
    vector<Trip> chennaiList()
    {
        vector<Trip> trips;
        trips.push_back(*(new Trip(new Tier1(), "Thursday", "1200", "Sunday", "1200", 7500)));
        trips.push_back(*(new Trip(new Tier2(), "Tuesday", "1800", "Friday", "1800", 5000)));
        trips.push_back(*(new Trip(new Tier3(), "Saturday", "1800", "Tuesday", "1800", 3500)));
        return trips;
    }
    vector<Trip> kolkataList()
    {
        vector<Trip> trips;
        trips.push_back(*(new Trip(new Tier1(), "Friday", "1200", "Sunday", "1200", 5500)));
        trips.push_back(*(new Trip(new Tier2(), "Wednesday", "1800", "Friday", "1800", 4000)));
        trips.push_back(*(new Trip(new Tier3(), "Sunday", "1800", "Tuesday", "1800", 2500)));
        return trips;
    }

public:
    Log()
    {
        mapTrips.emplace("Mumbai", mumbaiList());
        mapTrips.emplace("Jaipur", jaipurList());
        mapTrips.emplace("Chennai", chennaiList());
        mapTrips.emplace("Kolkata", kolkataList());
    }
    void booking()
    {
        string location;
        cout << "Enter destination: ";
        cin >> location;
        cout << "Available choices:-" << endl;
        displayTrips(location);
        int tier;
        cout << "Enter your bus tier: ";
        cin >> tier;
        Trip trip = mapTrips.at(location).at(tier - 1);
        Seat seat = trip.bookTrip();
        Ticket ticket(location, trip, seat);
        srand(time(NULL));
        unsigned long ticketNumber = rand();
        mapTicket.emplace(ticketNumber, ticket);
        cout << "Ticket number: " << ticketNumber << endl;
        ticket.displayTicket();
        cout << endl;
    }
    void cancelling()
    {
        displayTickets();
        unsigned long ticketNumber;
        cout << "Please enter the ticket number: ";
        cin >> ticketNumber;
        if (mapTicket.find(ticketNumber) != mapTicket.end())
        {
            char choice;
            cout << "Are you sure, You want to cancel the trip? Press Y or N: ";
            cin >> choice;
            if (choice == 'Y' || choice == 'y')
            {
                Ticket ticket = mapTicket.at(ticketNumber);
                ticket.cancelTicket();
                mapTicket.erase(ticketNumber);
            }
            else if (choice == 'N' || choice == 'n')
            {
                cout << "Ticket not cancelled!" << endl;
            }
        }
        else
        {
            cout << "Ticket number does not exist in our database!" << endl;
        }
        cout << endl;
    }
    void rescheduling()
    {
    }
    void displayTrips(string location)
    {
        vector<Trip> trips = mapTrips.at(location);
        for (Trip trip : trips)
        {
            trip.displayTrip();
            cout << endl;
        }
    }
    void displayTickets()
    {
        cout << "Tester" << endl;
        for (auto pairs : mapTicket)
        {
            pairs.second.displayTicket();
        }
    }
    void deleteMemory()
    {
        for (auto& pairs : mapTrips)
        {
            vector<Trip> trips = pairs.second;
            for (Trip trip : trips)
            {
                delete &trip;
            }
        }
    }
};

int main()
{
    Log log;
    int choice;
    do
    {
        cout << "1. Booking" << endl;
        cout << "2. Cancelling" << endl;
        cout << "3. Re-scheduling" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
            log.booking();
            break;
        case 2:
            log.cancelling();
            break;
        case 3:
            log.rescheduling();
            break;
        case 4:
            // log.deleteMemory();
            cout << "Exited" << endl;
            break;
        default:
            cout << "Choice doesn't match options, try again" << endl;
            break;
        }
    } while (choice != 4);
}