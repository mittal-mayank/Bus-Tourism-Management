package intermidiate;

import client.Bus;
import java.util.*;

public class Trip {
	private Bus bus;
	private String startDay;
	private String startTime;
	private String endDay;
	private String endTime;
	private int fares;
	private int discount_fares;
	private int discount;
	// fares

	public Trip(Bus bus, String startDay, String startTime, String endDay, String endTime , int fares) {
		this.bus = bus;
		this.startDay = startDay;
		this.startTime = startTime;
		this.endDay = endDay;
		this.endTime = endTime;
		this.fares = fares;
	}

	public Bus getBus() {
		return bus;
	}
	
	public void discount() {
		Scanner sc = new Scanner (System.in);
		
		System.out.println("You have been selected for a Discount round wherein you will have to perform a simple task and on the basis of that you will be awarded a discount on Fares");
		System.out.println("Please enter 2 numbers from 1 to 10 : ");
		
		
		int a = sc.nextInt();
		int b = sc.nextInt();
		
		
		if(!((a < 0 | b<0 )| (a>=10 | b>=10) ) ){
			
			int c = a | b;
			
			if(c>13) {
				
				System.out.println("Congratulations! You have got a flat 10% reduction in fares.");
				discount = 10;
				discount_fares = fares*(100-discount)/100 ;
				
			}
			else if(c<13 | c>9) {
				
				System.out.println("Congratulations! You have got a flat 7% reduction in fares.");
				discount = 7;
				discount_fares = fares*(100-discount)/100 ;
				
			}
			else if(c<9 | c>5) {
				
				System.out.println("Congratulations! You have got a flat 5% reduction in fares.");
				discount = 5;
				discount_fares = fares*(100-discount)/100 ;
				
			}
			else if(c < 5 & c > 0) {
				
				System.out.println("You have got no reduction in fares! Better luck next time!");
				discount_fares = fares;
			}
			
		}
		else {
			System.out.println("Ahh!! Wrong input. Try again.");
		}
		
		
		
	}

	public void display() {
		String busClass = bus.getClass().toString();
		System.out.println("Bus tier: " + busClass.charAt(busClass.length() - 1));
		System.out.println();
		System.out.println("Start day: " + startDay);
		System.out.println();
		System.out.println("Start time: " + startTime);		
		System.out.println();
		System.out.println("End day: " + endDay);
		System.out.println();
		System.out.println("End time: " + endTime);
		System.out.println();
		bus.seatsVacant();
		System.out.println();
		System.out.println("fares: "+ Integer.toString(fares));
		System.out.println();
		System.out.println("After the Discount, Your final fare is: " + Integer.toString(discount_fares));
		System.out.println();
	}
}
