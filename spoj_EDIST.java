import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class spoj_EDIST {

	public static void main(String[] args) throws IOException {
		String x, y;
		int t,count;
		int[][] T;
		MyScanner cin = new MyScanner();
		PrintWriter cout = new PrintWriter(new BufferedOutputStream(System.out));
		t = cin.nextInt();
		for (;t>0; t--) {
			x = cin.next();
			y = cin.next();
			T = new int[2001][2001];
			// ------- Algorithm ----------
			count = 0;
			for (int i = 0; i < x.length(); i++) {
				if (x.charAt(i) == y.charAt(0)) {
					T[0][i] = i;
					count = 1;
				} else {
					T[0][i] = i+1-count;
				}
			}
			count = 0;
			for (int j = 0; j < y.length(); j++) {
				if (x.charAt(0) == y.charAt(j)) {
					T[j][0] = j;
					count = 1;
				} else {
					T[j][0] = j+1-count;
				}
			}
			for (int i = 1; i < y.length(); i++) {
				for (int j = 1; j < x.length(); j++) {
					if (x.charAt(j) == y.charAt(i)) {
						T[i][j] =  Math.min(Math.min(T[i - 1][j], T[i][j - 1]) + 1, T[i - 1][j - 1]);
					} else {
						T[i][j] = Math.min(Math.min(T[i - 1][j], T[i][j - 1]), T[i - 1][j - 1]) + 1;
					}

				}
			}
			cout.println(T[y.length() - 1][x.length() - 1]);
			/*
			for (int i = 0; i < y.length(); i++) {
				for (int j = 0; j < x.length(); j++) {
					System.out.print(T[i][j] + " ");
				}
				System.out.println();
			}*/
		}
	cout.close();
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
/**
3
food
money
qwert
ertqw
hello
world
*/