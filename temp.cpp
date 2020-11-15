#include <boost/serialization/boost_unordered_map.hpp>
#include <boost/serialization/string.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <bits/stdc++.h>
using namespace std;

int seatCount = 0;

class Passenger
{
private:
    string name;
    int age;
    string gender;
    string phone;
    string email;

    friend class boost::serialization::access;
    template <typename Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        ar &name;
        ar &age;
        ar &gender;
        ar &email;
    }

public:
    Passenger()
    {
    }

    void acceptDetails()
    {
        cout << "Enter your details:-" << endl;
        cout << "Name: ";
        getline(cin, name);
        cout << "Age: ";
        cin >> age;
        cout << "Gender: ";
        getline(cin, gender);
        cout << "Phone No: ";
        getline(cin, phone);
        cout << "E-mail: ";
        getline(cin, email);
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
    Passenger passenger;
    int row;
    int column;

    friend class boost::serialization::access;
    template <typename Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        ar &passenger;
        ar &row;
        ar &column;
    }

public:
    int count;

    Seat()
    {
    }

    Seat(Passenger passenger, int row, int column)
    {
        seatCount++;

        count = seatCount;
        this->passenger = passenger;
        this->row = row;
        this->column = column;
    }

    void displayCoordinates()
    {
        cout << "Row: " << row << ", Column: " << column << endl;
    }

    void displaySeat()
    {
        passenger.displayPassenger();
        cout << "Row: " << row << ", Column: " << column << endl;
    }
    bool operator==(const Seat &s) const
    {
        return this->count == s.count;
    }
};

class SeatHash
{
public:
    size_t operator()(const Seat &s) const
    {
        return s.count;
    }
};

class Bus
{
public:
    static int tier;
    static bool ac;
    static bool food;
    static bool sleeper;
    static bool toilet;
    static bool tv;

    unordered_set<Seat, SeatHash> seats;

    virtual void displayVacantSeats() = 0;
    virtual Seat bookSeat() = 0;
    virtual void cancelSeat(Seat seat) = 0;
    virtual void clearBus() = 0;
};

class Tier1 : public Bus
{
private:
    static const int rows = 5;
    static const int columns = 2;

    friend class boost::serialization::access;
    template <typename Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        ar &rows;
        ar &columns;
        ar &tier;
        ar &ac;
        ar &food;
        ar &sleeper;
        ar &toilet;
        ar &tv;
    }

public:
    Tier1()
    {
        tier = 1;
        ac = true;
        food = true;
        sleeper = true;
        toilet = true;
        tv = true;
    }

    static void printInfo()
    {
        cout << "Number of rows: " << rows << endl;
        cout << "Number of columns: " << columns << endl;
        cout << "AC: " << ac << endl;
        cout << "Food: " << food << endl;
        cout << "Sleeper: " << sleeper << endl;
        cout << "Toilet: " << toilet << endl;
        cout << "TV: " << tv << endl;
    }

    static void changeBus()
    {
        cout << "Enter new details:-" << endl;
        cout << "AC: ";
        cin >> ac;
        cout << "Food: ";
        cin >> food;
        cout << "Sleeper: ";
        cin >> sleeper;
        cout << "Toilet: ";
        cin >> toilet;
        cout << "TV: ";
        cin >> tv;
        cout << "Bus updated!" << endl;
    }

    void clearBus()
    {
        seats.clear();
        cout << "Bus reseted!" << endl;
    }

    void displayVacantSeats()
    {
        cout << "Seats range, Rows: " << rows << ", Columns: " << columns << endl;
        cout << "Non-vacant seats:-" << endl;
        if (seats.empty())
        {
            cout << "All vacant!" << endl;
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
        cout << "Enter seat coordinates:-" << endl;
        cout << "Row: ";
        int row;
        cin >> row;
        cout << "Column: ";
        int column;
        cin >> column;
        Passenger passenger;
        passenger.acceptDetails();
        Seat seat(passenger, row, column);
        seats.emplace(seat);
        cout << "Seat booked!" << endl;
        return seat;
    }

    void cancelSeat(Seat seat)
    {
        seats.erase(seat);
        cout << "Seat cancelled!" << endl;
    }
};

class Tier2 : public Bus
{
private:
    static const int rows = 10;
    static const int columns = 4;

    friend class boost::serialization::access;
    template <typename Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        ar &rows;
        ar &columns;
        ar &tier;
        ar &ac;
        ar &food;
        ar &sleeper;
        ar &toilet;
        ar &tv;
    }

public:
    Tier2()
    {
        tier = 2;
        ac = true;
        food = true;
        sleeper = false;
        toilet = false;
        tv = false;
    }

    static void printInfo()
    {
        cout << "Number of rows: " << rows << endl;
        cout << "Number of columns: " << columns << endl;
        cout << "AC: " << ac << endl;
        cout << "Food: " << food << endl;
        cout << "Sleeper: " << sleeper << endl;
        cout << "Toilet: " << toilet << endl;
        cout << "TV: " << tv << endl;
    }

    static void changeBus()
    {
        cout << "Enter new details:-" << endl;
        cout << "AC: ";
        cin >> ac;
        cout << "Food: ";
        cin >> food;
        cout << "Sleeper: ";
        cin >> sleeper;
        cout << "Toilet: ";
        cin >> toilet;
        cout << "TV: ";
        cin >> tv;
        cout << "Bus updated!" << endl;
    }

    void clearBus()
    {
        seats.clear();
        cout << "Bus reseted!" << endl;
    }

    void displayVacantSeats()
    {
        cout << "Seats range, Rows: " << rows << ", Columns: " << columns << endl;
        cout << "Non-vacant seats:-" << endl;
        if (seats.empty())
        {
            cout << "All vacant!" << endl;
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
        cout << "Enter seat coordinates:-" << endl;
        cout << "Row: ";
        int row;
        cin >> row;
        cout << "Column: ";
        int column;
        cin >> column;
        Passenger passenger;
        passenger.acceptDetails();
        Seat seat(passenger, row, column);
        seats.emplace(seat);
        cout << "Seat booked!" << endl;
        return seat;
    }

    void cancelSeat(Seat seat)
    {
        seats.erase(seat);
        cout << "Seat cancelled!" << endl;
    }
};

class Tier3 : public Bus
{
private:
    static const int rows = 10;
    static const int columns = 4;

    friend class boost::serialization::access;
    template <typename Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        ar &rows;
        ar &columns;
        ar &tier;
        ar &ac;
        ar &food;
        ar &sleeper;
        ar &toilet;
        ar &tv;
    }

public:
    Tier3()
    {
        tier = 3;
        ac = false;
        food = false;
        sleeper = false;
        toilet = false;
        tv = false;
    }

    static void printInfo()
    {
        cout << "Number of rows: " << rows << endl;
        cout << "Number of columns: " << columns << endl;
        cout << "AC: " << ac << endl;
        cout << "Food: " << food << endl;
        cout << "Sleeper: " << sleeper << endl;
        cout << "Toilet: " << toilet << endl;
        cout << "TV: " << tv << endl;
    }

    static void changeBus()
    {
        cout << "Enter new details:-" << endl;
        cout << "AC: ";
        cin >> ac;
        cout << "Food: ";
        cin >> food;
        cout << "Sleeper: ";
        cin >> sleeper;
        cout << "Toilet: ";
        cin >> toilet;
        cout << "TV: ";
        cin >> tv;
        cout << "Bus updated!" << endl;
    }

    void clearBus()
    {
        seats.clear();
        cout << "Bus reseted!" << endl;
    }

    void displayVacantSeats()
    {
        cout << "Seats range, Rows: " << rows << ", Columns: " << columns << endl;
        cout << "Non-vacant seats:-" << endl;
        if (seats.empty())
        {
            cout << "All vacant!" << endl;
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
        cout << "Enter seat coordinates:-" << endl;
        cout << "Row: ";
        int row;
        cin >> row;
        cout << "Column: ";
        int column;
        cin >> column;
        Passenger passenger;
        passenger.acceptDetails();
        Seat seat(passenger, row, column);
        seats.emplace(seat);
        cout << "Seat booked!" << endl;
        return seat;
    }

    void cancelSeat(Seat seat)
    {
        seats.erase(seat);
        cout << "Seat cancelled!" << endl;
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

    friend class boost::serialization::access;
    template <typename Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        ar &bus;
        ar &startDay;
        ar &startTime;
        ar &endDay;
        ar &endTime;
        ar &fare;
    }

public:
    Trip()
    {
    }

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
        return bus->bookSeat();
    }

    void cancelTrip(Seat seat)
    {
        bus->cancelSeat(seat);
    }

    void displayTrip()
    {
        cout << "Bus tier: " << bus->tier << endl;
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
        cout << "Enter 2 numbers from 1 to 10:-" << endl;
        cout << "First number: ";
        int a;
        cin >> a;
        cout << "Second number: ";
        int b;
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
        return prevFare;
    }

    void editTrip()
    {
        cout << "Enter start day: ";
        getline(cin, startDay);
        cout << "Enter start time: ";
        getline(cin, startTime);
        cout << "Enter end day: ";
        getline(cin, endDay);
        cout << "Enter end time: ";
        getline(cin, endTime);
        cout << "Enter fare: ";
        cin >> fare;
        cout << "Trip edited!" << endl;
    }

    void clearTrip()
    {
        bus->clearBus();
    }
};

class Ticket
{
private:
    static const string source;

    string destination;
    Trip trip;
    Seat seat;
    int fare;

    void setFare()
    {
        fare = trip.discount();
    }

    friend class boost::serialization::access;
    template <typename Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        ar &source;
        ar &destination;
        ar &trip;
        ar &seat;
        ar &fare;
    }

public:
    Ticket()
    {
    }

    Ticket(string destination, Trip trip, Seat seat)
    {
        this->destination = destination;
        this->trip = trip;
        this->seat = seat;
        setFare();
    }

    void displayTicket()
    {
        cout << "Source: " << source << endl;
        cout << "Destination: " << destination << endl;
        trip.displayTrip();
        cout << "Discounted fare: " << fare << endl;
        seat.displaySeat();
    }

    void cancelTicket()
    {
        trip.cancelTrip(seat);
    }
};
string const Ticket::source = "Delhi";

class Storage
{
private:
    unordered_map<unsigned long, Ticket> mapTicket;
    unordered_map<string, vector<Trip>> mapTrips;

    friend class boost::serialization::access;
    template <typename Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        ar &mapTicket;
        ar &mapTrips;
    }

    vector<Trip> mumbaiList()
    {
        vector<Trip> trips;
        trips.push_back(Trip(new Tier1(), "Tuesday", "1200", "Thursday", "1200", 5000));
        trips.push_back(Trip(new Tier2(), "Saturday", "1200", "Monday", "1200", 3000));
        trips.push_back(Trip(new Tier3(), "Thursday", "1800", "Saturday", "1800", 1700));
        return trips;
    }

    vector<Trip> jaipurList()
    {
        vector<Trip> trips;
        trips.push_back(Trip(new Tier1(), "Wednesday", "1200", "Thursday", "1200", 3500));
        trips.push_back(Trip(new Tier2(), "Sunday", "1200", "Monday", "1200", 2500));
        trips.push_back(Trip(new Tier3(), "Friday", "1800", "Saturday", "1800", 1000));
        return trips;
    }

    vector<Trip> chennaiList()
    {
        vector<Trip> trips;
        trips.push_back(Trip(new Tier1(), "Thursday", "1200", "Sunday", "1200", 7500));
        trips.push_back(Trip(new Tier2(), "Tuesday", "1800", "Friday", "1800", 5000));
        trips.push_back(Trip(new Tier3(), "Saturday", "1800", "Tuesday", "1800", 3500));
        return trips;
    }

    vector<Trip> kolkataList()
    {
        vector<Trip> trips;
        trips.push_back(Trip(new Tier1(), "Friday", "1200", "Sunday", "1200", 5500));
        trips.push_back(Trip(new Tier2(), "Wednesday", "1800", "Friday", "1800", 4000));
        trips.push_back(Trip(new Tier3(), "Sunday", "1800", "Tuesday", "1800", 2500));
        return trips;
    }

    vector<Trip> destinationList()
    {
        vector<Trip> trips;
        for (int i = 1; i <= 3; i++)
        {
            cout << "Enter details for tier: " << i << endl;
            cout << "Enter start day: ";
            string startDay;
            getline(cin, startDay);
            cout << "Enter start time: ";
            string startTime;
            getline(cin, startTime);
            cout << "Enter end day: ";
            string endDay;
            getline(cin, endDay);
            cout << "Enter end time: ";
            string endTime;
            getline(cin, endTime);
            cout << "Enter fare: ";
            int fare;
            cin >> fare;
            trips.push_back(Trip(getTierBus(i), startDay, startTime, endDay, endTime, fare));
            cout << "Trip added!" << endl;
            cout << endl;
        }
        return trips;
    }

    Bus *getTierBus(int tier)
    {
        Bus *bus;
        if (tier == 1)
        {
            bus = new Tier1();
        }
        else if (tier == 2)
        {
            bus = new Tier2();
        }
        bus = new Tier3();
        return bus;
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

public:
    Storage()
    {
        mapTrips.emplace("Mumbai", mumbaiList());
        mapTrips.emplace("Jaipur", jaipurList());
        mapTrips.emplace("Chennai", chennaiList());
        mapTrips.emplace("Kolkata", kolkataList());
    }

    void booking()
    {
        cout << "Enter destination: ";
        string location;
        getline(cin, location);
        cout << "Available choices:-" << endl;
        displayTrips(location);
        cout << endl;
        cout << "Enter your bus tier: ";
        int tier;
        cin >> tier;
        Trip trip = mapTrips.at(location).at(tier - 1);
        Seat seat = trip.bookTrip();
        cout << endl;
        Ticket ticket(location, trip, seat);
        cout << endl;
        srand(time(NULL));
        unsigned long ticketNumber = rand();
        mapTicket.emplace(ticketNumber, ticket);
        cout << "Ticket Number: " << ticketNumber << endl;
        ticket.displayTicket();
        cout << endl;
    }

    void cancelling()
    {
        cout << "Please enter the ticket number: ";
        unsigned long ticketNumber;
        cout << "Please enter the ticket number: ";
        cin >> ticketNumber;
        if (mapTicket.find(ticketNumber) != mapTicket.end())
        {
            cout << "Are you sure, You want to cancel the trip? Press Y or N: ";
            char choice;
            cin >> choice;
            if (choice == 'Y')
            {
                Ticket ticket = mapTicket.at(ticketNumber);
                ticket.cancelTicket();
                cout << endl;
                mapTicket.erase(ticketNumber);
            }
            else if (choice == 'N')
            {
                cout << "Ticket not cancelled!" << endl;
            }
        }
        else
        {
            cout << "The ticket number does not exist in our database!" << endl;
        }
        cout << endl;
    }

    void rescheduling()
    {
        cout << "Your previous ticket will be cancelled and new ticket will be booked" << endl;
        unsigned long ticketNumber;
        cout << "Please enter the ticket number: ";
        cin >> ticketNumber;
        if (mapTicket.find(ticketNumber) != mapTicket.end())
        {
            cout << "Are you sure, You want to re-schedule the trip? Press Y or N: ";
            char choice;
            cin >> choice;
            if (choice == 'Y')
            {
                Ticket ticket = mapTicket.at(ticketNumber);
                ticket.cancelTicket();
                cout << endl;
                mapTicket.erase(ticketNumber);
                booking();
            }
            else if (choice == 'N')
            {
                cout << "Ticket not re-scheduled!" << endl;
            }
        }
        else
        {
            cout << "The ticket number does not exist in our database!" << endl;
        }
        cout << endl;
    }

    void printBus()
    {
        cout << "Enter bus tier: ";
        int tier;
        cin >> tier;
        if (tier == 1)
        {
            Tier1::printInfo();
        }
        else if (tier == 2)
        {
            Tier2::printInfo();
        }
        else if (tier == 3)
        {
            Tier3::printInfo();
        }
        else
        {
            cout << "Tier does not exist!" << endl;
        }
        cout << endl;
    }

    void printTrip()
    {
        cout << "Enter destination: ";
        string location;
        getline(cin, location);
        cout << "Enter bus tier: ";
        int tier;
        cin >> tier;
        vector<Trip> trips = mapTrips.at(location);
        Trip trip = trips.at(tier - 1);
        trip.displayTrip();
        cout << endl;
    }

    void printTrips()
    {
        cout << "Enter destination: ";
        string location;
        getline(cin, location);
        displayTrips(location);
    }

    void printLogs()
    {
        for (auto &pair : mapTrips)
        {
            string location = pair.first;
            cout << "Destination: " << location << endl;
            displayTrips(location);
        }
    }

    void printTicket()
    {
        cout << "Please enter the ticket number: ";
        unsigned long ticketNumber;
        cout << "Please enter the ticket number: ";
        cin >> ticketNumber;
        if (mapTicket.find(ticketNumber) != mapTicket.end())
        {
            Ticket ticket = mapTicket.at(ticketNumber);
            ticket.displayTicket();
        }
        else
        {
            cout << "The ticket number does not exist in our database!" << endl;
        }
        cout << endl;
    }

    void editBus()
    {
        cout << "Enter tier: ";
        int tier;
        cin >> tier;
        if (tier == 1)
        {
            Tier1::changeBus();
        }
        else if (tier == 2)
        {
            Tier2::changeBus();
        }
        else if (tier == 3)
        {
            Tier3::changeBus();
        }
        else
        {
            cout << "Tier does not exist!" << endl;
        }
        cout << endl;
    }

    void resetTrip()
    {
        cout << "Enter destination: ";
        string location;
        getline(cin, location);
        cout << "Enter bus tier: ";
        int tier;
        cin >> tier;
        vector<Trip> trips = mapTrips.at(location);
        Trip trip = trips.at(tier - 1);
        trip.clearTrip();
        cout << endl;
    }

    void addDestination()
    {
        cout << "Enter destination: ";
        string destination;
        getline(cin, destination);
        mapTrips.emplace(destination, destinationList());
        cout << "Destination added!" << endl;
        cout << endl;
    }

    void removeDestination()
    {
        cout << "Enter destination: ";
        string location;
        getline(cin, location);
        if (mapTrips.find(location) != mapTrips.end())
        {
            mapTrips.erase(location);
            cout << "Destination removed!" << endl;
        }
        else
        {
            cout << "Destination not present!" << endl;
        }
        cout << endl;
    }

    void editTrip()
    {
        cout << "Enter destination: ";
        string location;
        getline(cin, location);
        cout << "Enter bus tier: ";
        int tier;
        cin >> tier;
        vector<Trip> trips = mapTrips.at(location);
        Trip trip = trips.at(tier - 1);
        trip.editTrip();
        cout << endl;
    }
};

Storage storage;

static void readLogs()
{
    ifstream file;
    file.open("logs.dat");
    if (!file.is_open())
    {
        return;
    }
    boost::archive::text_iarchive in(file);
    in >> ::storage;
    file.close();
}

void writeLogs()
{
    ofstream file;
    file.open("logs.dat", ios::trunc);
    boost::archive::text_oarchive out(file);
    out << ::storage;
    file.close();
}

void defaultPassword()
{
    fstream file;
    file.open("password.dat", ios::in);
    if (file.is_open())
    {
        file.close();
        return;
    }
    file.open("password.dat", ios::out);
    boost::archive::text_oarchive out(file);
    string password = "abcd";
    out << password;
    file.close();
}

static void changePassword()
{
    ofstream file;
    file.open("password.dat", ios::trunc);
    boost::archive::text_oarchive out(file);
    cout << "New password: ";
    string password;
    getline(cin, password);
    out << password;
    file.close();
    cout << "Password changed!" << endl;
    cout << endl;
}

string getPassword()
{
    ifstream file;
    file.open("password.dat");
    boost::archive::text_iarchive in(file);
    string password;
    in >> password;
    file.close();
    return password;
}

void customerMode()
{
    int choice;
    do
    {
        cout << endl;
        cout << "1. Booking" << endl;
        cout << "2. Cancelling" << endl;
        cout << "3. Re-schedule/edit details" << endl;
        cout << "4. Print bus information" << endl;
        cout << "5. Print a trip" << endl;
        cout << "6. Print all trips to a location" << endl;
        cout << "7. Print all logs" << endl;
        cout << "8. Print ticket" << endl;
        cout << "9. Log out" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
            ::storage.booking();
            break;
        case 2:
            ::storage.cancelling();
            break;
        case 3:
            ::storage.rescheduling();
            break;
        case 4:
            ::storage.printBus();
            break;
        case 5:
            ::storage.printTrip();
            break;
        case 6:
            ::storage.printTrips();
            break;
        case 7:
            ::storage.printLogs();
            break;
        case 8:
            ::storage.printTicket();
            break;
        case 9:
            cout << "Logged out" << endl;
            break;
        default:
            cout << "Choice doesn't match options, try again" << endl;
            break;
        }
    } while (choice != 9);
}

void adminMode()
{
    defaultPassword();
    cout << "Enter admin password: ";
    string password;
    getline(cin, password);
    if (getPassword() != password)
    {
        cout << "Wrong password entered, entry denied!" << endl;
        return;
    }
    int choice;
    do
    {
        cout << endl;
        cout << "1. Booking" << endl;
        cout << "2. Cancelling" << endl;
        cout << "3. Re-schedule/edit details" << endl;
        cout << "4. Print bus information" << endl;
        cout << "5. Print a trip" << endl;
        cout << "6. Print all trips to a location" << endl;
        cout << "7. Print all logs" << endl;
        cout << "8. Print ticket" << endl;
        cout << "9. Change password" << endl;
        cout << "10. Edit bus information" << endl;
        cout << "11. Reset bus/trip" << endl;
        cout << "12. Add new destination" << endl;
        cout << "13. Remove destination" << endl;
        cout << "14. Reset logs" << endl;
        cout << "15. Edit trip" << endl;
        cout << "16. Log out" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
            ::storage.booking();
            break;
        case 2:
            ::storage.cancelling();
            break;
        case 3:
            ::storage.rescheduling();
            break;
        case 4:
            ::storage.printBus();
            break;
        case 5:
            ::storage.printTrip();
            break;
        case 6:
            ::storage.printTrips();
            break;
        case 7:
            ::storage.printLogs();
            break;
        case 8:
            ::storage.printTicket();
            break;
        case 9:
            changePassword();
            break;
        case 10:
            ::storage.editBus();
            break;
        case 11:
            ::storage.resetTrip();
            break;
        case 12:
            ::storage.addDestination();
            break;
        case 13:
            ::storage = Storage();
            break;
        case 14:
            ::storage.removeDestination();
            break;
        case 15:
            ::storage.editTrip();
            break;
        case 16:
            cout << "Logged out" << endl;
            break;
        default:
            cout << "Choice doesn't match options, try again" << endl;
            break;
        }
    } while (choice != 16);
}

int main()
{
    readLogs();
    int choice;
    do
    {
        cout << endl;
        cout << "Log in as:-" << endl;
        cout << "1. Admin" << endl;
        cout << "2. Customer" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
            adminMode();
            break;
        case 2:
            customerMode();
            break;
        case 3:
            writeLogs();
            cout << "Exited" << endl;
            break;
        default:
            cout << "Choice doesn't match options, try again" << endl;
            break;
        }
    } while (choice != 3);
}