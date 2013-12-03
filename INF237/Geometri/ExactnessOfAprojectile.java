import java.awt.geom.Line2D;
import java.util.Scanner;


public class Main {

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int superMax = 3000;
		int xHit = s.nextInt();
		int yHit = s.nextInt();
		int n = s.nextInt();
		int cross = 0;
		double startX = s.nextDouble();
		double startY = s.nextDouble();
		double forsteX = startX;
		double forsteY = startY;
		double dist = Double.MAX_VALUE;
		double minste = Double.MAX_VALUE;
		for(int i = 0; i<n-1;i++) {
			double sluttX = s.nextDouble();
			double sluttY = s.nextDouble();
			if(Line2D.linesIntersect(xHit, yHit, superMax, superMax, startX, startY, sluttX, sluttY)) cross+=1;
			dist = Line2D.ptSegDist(startX, startY, sluttX, sluttY, xHit, yHit);
			if(dist < minste) minste = dist;
			startX = sluttX;
			startY = sluttY;
		}
		dist = Line2D.ptSegDist( startX, startY,forsteX,forsteY, xHit, yHit);
		if(Line2D.linesIntersect(xHit, yHit, superMax, superMax, startX, startY, forsteX, forsteY)) cross+=1;
		if(dist < minste) minste = dist;
		if(cross%2 != 0) System.out.printf("%.3f",0.000);
		else System.out.printf("%.3f",minste*2);
	}

}
