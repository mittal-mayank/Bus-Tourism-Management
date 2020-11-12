package entities;

public class Seat {
	private Passenger passenger;
	private int row;
	private int column;

	Seat(Passenger passenger, int row, int column) {
		this.passenger = passenger;
		this.row = row;
		this.column = column;
	}

	void displayCoordinates() {
		System.out.println("Row: " + row + ", Column: " + column);
	}

	public void displaySeat() {
		passenger.displayPassenger();
		System.out.println("Row: " + row + ", Column: " + column);
	}
}
