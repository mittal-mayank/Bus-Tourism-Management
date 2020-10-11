package intermidiate;

public class Seat {
	private Passenger passenger;
	private  int row;
	private int column;

	public Seat(Passenger passenger, int row, int column) {
		this.passenger = passenger;
		this.row = row;
		this.column = column;
	}

	public int getRow() {
		return row;
	}

	public int getColumn() {
		return column;
	}

	public void display() {
		passenger.display();
		System.out.println("Row: " + row + " Column: " + column);
	}
}
