import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class spoj_INVCNT { //It must be Main in spoj
	
	public static MyScanner cin;
	public static Long  ans;
	public static PrintWriter cout;
	
	static void mergesortLike(int[] a, int l, int r)
	{
		if(l < r)
		{
			int mid = (l+r)/2;
			mergesortLike(a,l,mid);
			mergesortLike(a,mid+1,r);
			merge(a,l,mid,r);
		}
	}
	static void merge(int[] a,int l,int mid,int r)
	{
		if(l >= r)
		{
			return ;
		}
		int i,j,left,count;
		i =left = l;
		j = mid + 1;
		count = 0;
		
		int[] temp = new int[r-l+1];
		
		while(i<=mid || j<=r)
		{
			if(i<=mid && j<=r)
			{
				if(a[i] > a[j])
				{
					ans += mid - i + 1;
					temp[count++] = a[j];
					j++;
				}
				else
				{
					temp[count++] = a[i];
					i++;
				}
			}
			else if(i > mid)
			{
				while(j <= r)
				{
					temp[count++] = a[j];
					j++;
				}
			}
			else if(j > r)
			{
				while(i <= mid)
				{
					temp[count++] = a[i];
					i++;
				}
			}
		}
		for(i = 0; i<count; i++)
		{
			a[left + i] = temp[i];
		}
		
	}

	public static void main(String[] args) {
		cin = new MyScanner();
		cout = new PrintWriter(new BufferedOutputStream(System.out));
		int t,n;
		t = cin.nextInt();
		while(t > 0)
		{
			t--;
			n = cin.nextInt();
			int[] a = new int[n];
			for(int i = 0; i<n; i++)
			{
				a[i] = cin.nextInt();
			}
			ans = 0L;
			mergesortLike(a,0,n-1);
			cout.println(ans);
		}
		cout.close();//u'll get bamboo if you forget.
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
Learned from geeksforgeeks, the video is awesome. 
ans += mid - i, is what i failed to discover/invent
**/
