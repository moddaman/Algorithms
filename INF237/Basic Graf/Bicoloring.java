class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
			while(true) {			
				int n = scanner.nextInt();
				if(n == 0) 
					break;
				Queue<Integer> q = new LinkedList<Integer>();
				boolean f = true;
				int k = scanner.nextInt();
				@SuppressWarnings("unchecked")
				LinkedList<Integer>[] g = new LinkedList[n];
				int[] d = new int[n];
				for(int i = 0; i <= n-1; i++)
					g[i] = new LinkedList<Integer>();

				int x = 0;
				for(int i = 0; i <= k-1; i++) {
					x = scanner.nextInt();
					int t = scanner.nextInt();
					g[x].add(t);
					g[t].add(x);
				}


				d[x] = 1;
				int v = x;
				q.add(v);
				while(!q.isEmpty()) {
					q.poll();
					while(!g[v].isEmpty() && f){
						int a = (Integer) g[v].poll();
						if(d[v] == d[a]) {
							f = false;
							break;
						}
						else {
							if(d[v] == 1)
								d[a] = 2;
							else
								d[a] = 1;
							q.add(a);
						}
					}
					if(!q.isEmpty())
						v = q.poll();
				}
				if(!f) 
					System.out.println("NOT BICOLORABLE.");

				else
					System.out.println("BICOLORABLE.");
			}

		}
	}
}