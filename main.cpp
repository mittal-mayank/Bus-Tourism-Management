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
        cout << "Enter your details:-\n";
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
        cout << "Name: " << name << "\n";
        cout << "Age: " << age << "\n";
        cout << "Gender: " << gender << "\n";
        cout << "Phone No: " << phone << "\n";
        cout << "E-mail: " << email << "\n";
    }
};

class Seat
{
private:
    Passenger *passenger;
    int row;
    int column;

public:
    Seat(Passenger *passenger, int row, int column)
    {
        this->passenger = passenger;
        this->row = row;
        this->column = column;
    }
    void displayCoordinates()
    {
        cout << "Row: " << row << ", Column: " << column << "\n";
    }
    void displaySeat()
    {
        passenger->displayPassenger();
        cout << "Row: " << row << ", Column: " << column << "\n";
    }
    bool operator==(const Seat &s) const
    {
        return (this == &s);
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
    virtual Seat *bookSeat() = 0;
    virtual void cancelSeat(Seat *seat) = 0;
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
        cout << "Seats range, Rows: " << rows << ", Columns: " << columns << "\n";
        cout << "Non-vacant seats:-\n";
        if (seats.empty())
        {
            cout << "All vacant\n";
        }
        else
        {
            for (Seat seat : seats)
            {
                seat.displayCoordinates();
            }
        }
    }
    Seat *bookSeat()
    {
        cout << "Enter seat co-ordinates:-\n";
        int row;
        cout << "Row: ";
        cin >> row;
        int column;
        cout << "Column: ";
        cin >> column;
        Seat *seat = new Seat(new Passenger(), row, column);
        seats.emplace(*seat);
        cout << "Seat booked!\n";
        cout << "\n";
        return seat;
    }
    void cancelSeat(Seat *seat)
    {
        seats.erase(*seat);
        cout << "Seat cancelled!\n";
        cout << "\n";
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
        cout << "Seats range, Rows: " << rows << ", Columns: " << columns << "\n";
        cout << "Non-vacant seats:-\n";
        if (seats.empty())
        {
            cout << "All vacant\n";
        }
        else
        {
            for (Seat seat : seats)
            {
                seat.displayCoordinates();
            }
        }
    }
    Seat *bookSeat()
    {
        cout << "Enter seat co-ordinates:-\n";
        int row;
        cout << "Row: ";
        cin >> row;
        int column;
        cout << "Column: ";
        cin >> column;
        Seat *seat = new Seat(new Passenger(), row, column);
        seats.emplace(*seat);
        cout << "Seat booked!\n";
        cout << "\n";
        return seat;
    }
    void cancelSeat(Seat *seat)
    {
        seats.erase(*seat);
        cout << "Seat cancelled!\n";
        cout << "\n";
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
        cout << "Seats range, Rows: " << rows << ", Columns: " << columns << "\n";
        cout << "Non-vacant seats:-\n";
        if (seats.empty())
        {
            cout << "All vacant\n";
        }
        else
        {
            for (Seat seat : seats)
            {
                seat.displayCoordinates();
            }
        }
    }
    Seat *bookSeat()
    {
        cout << "Enter seat co-ordinates:-\n";
        int row;
        cout << "Row: ";
        cin >> row;
        int column;
        cout << "Column: ";
        cin >> column;
        Seat *seat = new Seat(new Passenger(), row, column);
        seats.emplace(*seat);
        cout << "Seat booked!\n";
        cout << "\n";
        return seat;
    }
    void cancelSeat(Seat *seat)
    {
        seats.erase(*seat);
        cout << "Seat cancelled!\n";
        cout << "\n";
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
    Seat *bookTrip()
    {
        cout << "\n";
        return bus->bookSeat();
    }
    void cancelTrip(Seat *seat)
    {
        cout << "\n";
        bus->cancelSeat(seat);
    }
    void displayTrip()
    {
        cout << "Bus tier: " << bus->type << "\n";
        cout << "Start day: " << startDay << "\n";
        cout << "Start time: " << startTime << "\n";
        cout << "End day: " << endDay << "\n";
        cout << "End time: " << endTime << "\n";
        bus->displayVacantSeats();
        cout << "Orignal fare: " << fare << "\n";
    }
    int discount()
    {
        cout << "You have been selected for a discount round wherein you will have to perform a simple task and on the basis of that you will be awarded a discount on fare\n";
        cout << "Enter two numbers from 1 to 10:-\n";
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
            cout << "Congratulations! You have got a flat 10% reduction in fares\n";
            discount = 10;
            prevFare = fare * (100 - discount) / 100;
        }
        else if (c<13 | c> 9)
        {
            cout << "Congratulations! You have got a flat 7% reduction in fares\n";
            discount = 7;
            prevFare = fare * (100 - discount) / 100;
        }
        else if (c<9 | c> 5)
        {
            cout << "Congratulations! You have got a flat 5% reduction in fares\n";
            discount = 5;
            prevFare = fare * (100 - discount) / 100;
        }
        else if (c<5 & c> 0)
        {
            cout << "You have got no reduction in fares! Better luck next time!\n";
        }
        cout << "\n";
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
    Ticket(string destination, Trip *trip, Seat *seat)
    {
        this->destination = destination;
        this->trip = trip;
        this->seat = seat;
        setFare();
    }
    void displayTicket()
    {
        cout << "Source: " << source << "\n";
        cout << "Destination: " << destination << "\n";
        trip->displayTrip();
        cout << "Discounted fare: " << fare << "\n";
        seat->displaySeat();
        cout << "\n";
    }
    void cancelTicket()
    {
        trip->cancelTrip(seat);
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
        cout << "Available choices:-\n";
        displayTrips(location);
        int tier;
        cout << "Enter your bus tier: ";
        cin >> tier;
        Trip trip = mapTrips.at(location).at(tier - 1);
        Seat *seat = trip.bookTrip();
        Ticket ticket(location, &trip, seat);
        srand(time(NULL));
        unsigned long ticketNumber = rand();
        mapTicket.emplace(ticketNumber, ticket);
        cout << "Ticket number: " << ticketNumber << "\n";
        ticket.displayTicket();
        cout << "\n";
    }
    void cancelling()
    {
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
                cout << "Ticket not cancelled!\n";
            }
        }
        else
        {
            cout << "Ticket number does not exist in our database!\n";
        }
        cout << "\n";
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
            cout << "\n";
        }
    }
    void deleteMemory()
    {
        for (auto pairs : mapTrips)
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
        cout << "1. Booking\n";
        cout << "2. Cancelling\n";
        cout << "3. Re-scheduling\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << "\n";
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
            log.deleteMemory();
            cout << "Exited\n";
            break;
        default:
            cout << "Choice doesn't match options, try again\n";
            break;
        }
    } while (choice != 4);
}