import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class spoj_ACODE {

	public static void main(String[] args) {
		MyScanner cin = new MyScanner();
		PrintWriter cout = new PrintWriter(new BufferedOutputStream(System.out));
		String str;
		while(true)
		{
			str = cin.nextLine();
			if(str.equals("0"))
			{
				break;
			}
			Long[] ans = new Long[str.length()+1];
			for(int i = 0; i<=str.length(); i++) ans[i] = 0L;
			ans[0] = 1L;
			ans[1] = 1L;
			for(int i = 2; i<=str.length(); i++)
			{
				if( (Character.getNumericValue(str.charAt(i-2))==1)||
						((Character.getNumericValue(str.charAt(i-2))==2 &&
								Character.getNumericValue(str.charAt(i-1)) <=6))  )
						{
							ans[i] += ans[i-2];
						}
				if(Character.getNumericValue(str.charAt(i-1)) != 0)
						{
							ans[i] += ans[i-1];
						}
				
			}
			cout.println(ans[str.length()]);
		}
		cout.close();
	}
	//-----------MyScanner class for faster input----------
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
This is a dynamic programming problem.

If we take a single number a, the problem will be in a single state. If you want to add another number b to the problem, the problem could be in one of two states:

    1.The two numbers printed one after another, ab
    2.The two numbers combined to form a different single number, c=(a*10+b)

One or both of the above states may be valid. If the first one 
remains valid, 
 Formula = only (1) is valid:ans[i] = ans[i-1];
           (2) is valid:ans[i] = ans[i-1] + ans[i-2];
 But the formula is modified,as the problem statement is ambiguous 
 for having 0 in inputs. Formula used in the code gets ac.

*/