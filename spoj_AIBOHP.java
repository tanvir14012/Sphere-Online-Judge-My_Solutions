import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.StringTokenizer;
 
public class spoj_AIBOHP {
	 
	static int[][] T;
	private static int topDown(String str, int i, int j){
		if(T[i][j] != 0) {
			return T[i][j];
		}
		int result = 0;
		if(i == j){
			result = 0;
		}
		else if(Math.abs(i-j) == 1) {
			result = (str.charAt(i) == str.charAt(j)) ? 0 : 1;		
		}
		else {
			if(str.charAt(i) == str.charAt(j)){
				result = topDown(str, i+1, j-1);
			}
			else {
				result = 1 + Math.min(topDown(str,i+1,j), topDown(str,i,j-1));
			}
		}
		T[i][j] = result;
		return result;
	}
	public static void main(String[] args) {
		MyScanner cin = new MyScanner();
		PrintWriter cout = new PrintWriter(new BufferedOutputStream(System.out));
		int n = cin.nextInt();
		while(n>0){
			n--;
		String str = cin.next();
		T = new int[str.length()][str.length()];
		cout.println(topDown(str,0,str.length()-1));
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
   