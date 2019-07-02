package mypack;///discard it when submittin in oj
import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.StringTokenizer;
 
 class spoj_PT07Y {//in oj, class name must be Main
	 class graph
	{
		private int V,t;
		private boolean[] visited;
		private ArrayList<LinkedList<Integer>> adj;
		graph(int V)
		{
			this.V = V;
			adj =new ArrayList<LinkedList<Integer>>();
			visited = new boolean[V];
			for(int i = 0; i<V; i++)
			{
				visited[i] = false;
			}
			for(int i = 0; i<V; i++)
			{
				adj.add(new LinkedList<Integer>());
			}
		}
		void addEdge(int u, int v)
		{
			adj.get(u).add(v);
			adj.get(v).add(u);
		}
		void check()
		{
			for(int i = 0; i<V; i++)
			{
				for(int j = 0; j<adj.get(i).size(); j++)
				{
					System.out.println(i + " " + adj.get(i).get(j));
				}
			}
		}
		boolean isCycle(int v,int parent)
		{
			visited[v] = true;
			for(int i = 0; i<adj.get(v).size(); i++)
			{
				t = adj.get(v).get(i);
				if(t != parent )
				{
					if(visited[t] == true)
					{
						return true;
					}
					else
					{
						if(isCycle(t,v)==true)
						{
							return true;
						}
					}
				}
			}
			return false;
		}
		boolean isTree()
		{
			
			if(isCycle(0,-1)==true)
			{
				return false;
			}
			for(int i = 0; i<V; i++)
			{
				if(visited[i] == false)
				{
					return false;
				}
			}
			return true;
		}
	}
	 void solve(MyScanner cin)
	{
		PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
		int V,e,u,v;
		boolean ans=false;
		V = cin.nextInt();
		graph g = new graph(V);
		e = cin.nextInt();
		for(int i = 0; i<e; i++)
		{
			u = cin.nextInt();
			v = cin.nextInt();
			g.addEdge(u-1, v-1);
		}
		ans = g.isTree();
		//g.check();
		if(ans)
		{
			System.out.println("YES");
		}
		else
		{
			System.out.println("NO");
		}
	}
 
	public static void main(String[] args) {
		MyScanner cin = new MyScanner();
	    new spoj_PT07Y().solve(cin);
	}
 
 static class MyScanner {
    BufferedReader br;
    StringTokenizer st;
 
    public MyScanner() {
       br = new BufferedReader(new InputStreamReader(System.in));
    }
 
    String next() {
        while (st == null || !st.hasMoreElements()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return st.nextToken();
    }
 
    int nextInt() {
        return Integer.parseInt(next());
    }
 
    long nextLong() {
        return Long.parseLong(next());
    }
 
    double nextDouble() {
        return Double.parseDouble(next());
    }
 
    String nextLine(){
        String str = "";
	  try {
	     str = br.readLine();
	  } catch (IOException e) {
	     e.printStackTrace();
	  }
	  return str;
    }
 
 }
}
 
