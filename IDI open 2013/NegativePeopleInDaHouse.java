import java.util.Scanner;


public class NegativePeopleInDaHouse {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int tC = s.nextInt();
		for(int i = 0; i < tC; i++ ) {
			int min = 0;
			int inne = 0;
			int iHuset = 0;
			int event = s.nextInt();
			for(int j = 0; j < event; j++) {
				int inn = s.nextInt();
				int ut = s.nextInt();
				inne += inn;
				inne -= ut;
				if(inne < 0) {
					min += (inne * -1);
					inne = 0;
				}
				
				
			}
			System.out.println(min);
		}

	}

}
