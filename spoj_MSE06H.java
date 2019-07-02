import java.io.BufferedOutputStream;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
 
public class spoj_MSE06H{
	static class road {
		int x,y;
		
		public road(int a,int b)
		{
			x = a; y = b;
		}
		public road(road a)
		{
			this.x = a.x;
			this.y = a.y;
		}
		public int getX() {
			return x;
		}
		public int getY() {
			return y;
		}
	}
	static class cp implements Comparator<road> {
		public int compare(road p,road q)
		{
			
			if(p.getX() < q.getX())
			{
				return -1;
			}
			else if((p.getX() == q.getX()) && (p.getY() < q.getY()) )
			{
				return -1;
			}
			return 1;
		}
	}
	static class BIT {
		int[] a;
		int sz;
		
		public BIT(int sz)
		{
			this.sz = sz;
			a = new int[sz+1];
		}
		public int getSum(int index)
		{
			int sum = 0;
			while(index > 0)
			{
				sum += a[index];
				index -= (index & (-index));
			}
			return sum;
		}
		public void update(int index, int val)
		{
			while(index <= sz)
			{
				a[index] += val;
				index += (index & (-index));
			}
		}
	}
	
	public static void main(String[] args) throws IOException{
		Reader cin = new Reader();
		PrintWriter cout = new PrintWriter(new BufferedOutputStream(System.out));
		int t,m,n,k,u,v;
		t = cin.nextInt();
		for(int c = 1; c<=t; c++)
	    {
			m = cin.nextInt();n= cin.nextInt();
			k = cin.nextInt();
			road[] a = new road[k];
			for(int i = 0; i<k; i++)
			{
				u = cin.nextInt();
				v = cin.nextInt();
				a[i] = new road(u,v);
			}
			Arrays.sort(a,new cp());
			BIT q = new BIT(n);
			Long inversion_count = 0L;
			for(int i = k-1; i >=0 ; i--)
			{
				q.update(a[i].getY(), 1);
				inversion_count += q.getSum(a[i].getY() - 1);
			}
			//cout.printf("Test case %d: %lld\n",c,inversion_count);
			cout.println("Test case "+ c + ": " + inversion_count);
	    }
		cout.close();
	}
	//-----------Reader class for fastest input I know about----------
		static class Reader
	    {
	        final private int BUFFER_SIZE = 1 << 16;
	        private DataInputStream din;
	        private byte[] buffer;
	        private int bufferPointer, bytesRead;
	 
	        public Reader()
	        {
	            din = new DataInputStream(System.in);
	            buffer = new byte[BUFFER_SIZE];
	            bufferPointer = bytesRead = 0;
	        }
	 
	        public Reader(String file_name) throws IOException
	        {
	            din = new DataInputStream(new FileInputStream(file_name));
	            buffer = new byte[BUFFER_SIZE];
	            bufferPointer = bytesRead = 0;
	        }
	 
	        public String readLine() throws IOException
	        {
	            byte[] buf = new byte[64]; // line length
	            int cnt = 0, c;
	            while ((c = read()) != -1)
	            {
	                if (c == '\n')
	                    break;
	                buf[cnt++] = (byte) c;
	            }
	            return new String(buf, 0, cnt);
	        }
	 
	        public int nextInt() throws IOException
	        {
	            int ret = 0;
	            byte c = read();
	            while (c <= ' ')
	                c = read();
	            boolean neg = (c == '-');
	            if (neg)
	                c = read();
	            do
	            {
	                ret = ret * 10 + c - '0';
	            }  while ((c = read()) >= '0' && c <= '9');
	 
	            if (neg)
	                return -ret;
	            return ret;
	        }
	 
	        public long nextLong() throws IOException
	        {
	            long ret = 0;
	            byte c = read();
	            while (c <= ' ')
	                c = read();
	            boolean neg = (c == '-');
	            if (neg)
	                c = read();
	            do {
	                ret = ret * 10 + c - '0';
	            }
	            while ((c = read()) >= '0' && c <= '9');
	            if (neg)
	                return -ret;
	            return ret;
	        }
	 
	        public double nextDouble() throws IOException
	        {
	            double ret = 0, div = 1;
	            byte c = read();
	            while (c <= ' ')
	                c = read();
	            boolean neg = (c == '-');
	            if (neg)
	                c = read();
	 
	            do {
	                ret = ret * 10 + c - '0';
	            }
	            while ((c = read()) >= '0' && c <= '9');
	 
	            if (c == '.')
	            {
	                while ((c = read()) >= '0' && c <= '9')
	                {
	                    ret += (c - '0') / (div *= 10);
	                }
	            }
	 
	            if (neg)
	                return -ret;
	            return ret;
	        }
	 
	        private void fillBuffer() throws IOException
	        {
	            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
	            if (bytesRead == -1)
	                buffer[0] = -1;
	        }
	 
	        private byte read() throws IOException
	        {
	            if (bufferPointer == bytesRead)
	                fillBuffer();
	            return buffer[bufferPointer++];
	        }
	 
	        public void close() throws IOException
	        {
	            if (din == null)
	                return;
	            din.close();
	        }
	    }
 
}
/**
 A road(x,y) u can think x is on X-axis(x,0) and y is on Y-axis(0,y).
one road (x,y) will intersect other road (a,b) if  x < a && y > b (or) x > a && y < b.
 
Idea- If you follow brute force approach then for finding number of roads crossed by road#i ,
you will compare road#i with all the roads starting from road#i+1 to road#k (not starting from road
#1 otherwise crossings will get counted twice). Sum of counts for all the roads will be the final
answer. O(k^2),TLE.
 
Let's sort the roads array in increasing order of x value.
Now, for each road i,
crossings are those(index from 0 to n, != i) whose y value i.e. whose.y > i.y because array is already sorted, i.x < those.x.
Notice, it is called inversion on y value,see spoj INVRCNT.
If you count inversion and resort by MergeSort based on y value in ascending order
(small to big), you will get total inversions = total crossings.
Gotcha: In first sort, if x==x then sort based on y value in ascending to make
2nd merge sort working.
 
Use pen-paper for better understanding.
BIT : Inversion can be calculated also by BIT or fenwick tree. BIT input-array index should store 0 or 1, where
index = y value, 0 = not visited, 1 = visited.Initially, all = 0.
After first sort,
for(int  i= k-1; i >= 0; i--)
{
    update(a[i].y, 1);
    ans += sum (a[i].y - 1 );
}
How this works:
Problem input : 1
3 4 4
1 4
2 3
3 1
3 2
 
After first sort:
1 4
2 3
3 1
3 2
steps:
we start from last,
3 2, bit-internal-array[2] = 1, sum[0..1] = 0, ans = 0
3 1, bit-internal-array[1] = 1, sum[0..0] = 0, ans = 0
2 3, bit-internal-array[3] = 1, sum[0..2] = 1+1 = 2, ans = 2
1 4, bit-internal-array[4] = 1, sum[0..3] = 1+1+1=3, ans = 5
output = ans = 5.
 
 */