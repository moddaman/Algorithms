//10099 - The Tourist Guide

import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;
import java.util.Comparator;



class TheTouristGuide {


	public static <E> void main(String[] args) {
		int ru = 1;
		Scanner s = new Scanner(System.in);

		while(true) {		
			int n = s.nextInt();
			int k = s.nextInt(); 
			if(n == 0 && k == 0) 
				break;		
			n++;
			N[] g = new N[n];
			int[] m = new int[n];
			boolean[] b = new boolean[n];
			PriorityQueue<Edge> pq = new PriorityQueue<Edge>(n, new MyComparator());

			for(int i = 0; i <= n-1;i++) {
				g[i] = new N(i);
			}

			for(int i = 0; i <= k-1; i++) {
				int f = s.nextInt();
				int t = s.nextInt();
				int r = s.nextInt();
				g[f].add(t, r);
				g[t].add(f, r);
			}

			int st = s.nextInt();
			int sl = s.nextInt();
			double ps = s.nextDouble();

			pq.add(new Edge(st, Integer.MAX_VALUE));
			m[st] = Integer.MAX_VALUE;
			while(!pq.isEmpty()) {
				Queue<Edge> ku = g[pq.remove().k()].nq();
				while(!ku.isEmpty()) {
					Edge e = ku.poll();
					if(!b[e.k()]) {
						if(e.d() < m[ur]) {
							if(e.d() > m[e.k()] ) {
								m[e.k()] = e.d();
							}
						}
						else {
							m[e.k()] = m[ur];
						}				
						pq.add(e);
					}
				}
				b[ur] = true;
			}
			int fg = (int) -ps;
			if(m[sl] > 1)
				fg = (int) Math.ceil(ps /( m[sl]-1));
			System.out.println("Scenario #" + ru);
			System.out.println("Minimum Number of Trips = " + fg);
			System.out.println();
			ru++;
		}
	}
}

class N {


	private Queue<Edge> al = new LinkedList<Edge>();
	private int i;

	public N(int i) {
		this.i = i;
	}

	public int id(){return i;}

	public void add(int k, int d) {
		al.add(new Edge(k, d));
	}

	public Queue<Edge> nq() {return al;}

}
class Edge {

	private int k;
	private int d;

	public Edge(int k, int d) {
		this.k = k;
		this.d = d;
	}
	public int k(){return k;}
	public int d(){return d;}

}
class MyComparator implements Comparator<Edge>
{	
	@Override
	public int compare(Edge e1, Edge e2) {
		return e2.d() - e1.d();
	}
}

