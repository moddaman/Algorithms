import java.util.Scanner;
import java.util.Scanner;



public class AngryGrammar {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub



		/**
		 * @param args
		 */

		Scanner s = new Scanner(System.in);
		String test = s.nextLine();
		int tC = Integer.parseInt(test);
		for(int k = 0; k < tC; k++ ) {
			String sent = s.nextLine();
			String[] ord = sent.split(" ");
			int ant = 0;
			for(int i = 0; i < ord.length; i++) {

				String o = ord[i];
				if(o.equals("u") || o.equals("ur")) {
					ant += 10;
				}
				if(o.equals("would") || o.equals("should")) {
					if((i + 1) <= (ord.length -1)){
						if(ord[i+1].equals("of")) {
							ant += 10;
						}
					}
				}
				if(o.contains("lol"))
					ant += 10;
			}

			System.out.println(ant);
		}

	}


}
