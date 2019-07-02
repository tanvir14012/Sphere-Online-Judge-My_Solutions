import java.io.BufferedOutputStream;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.PrintWriter;

public class spoj_BALLSUM {
	static long gcd(long a, long b){
		long r;
		if(b>a) {	//Swap
			a = a^b;
			b = a^b;
			a = a^b;
		}
		while(b != 0) {
			r = a%b;
			a = b;
			b = r;
		}
		return a;
	}
	static long Combination(long n, long r) {
		int ans = 1;
		if(r > n/2) {
			r = n - r; // As, nCr = nCn-r 
		}
		for(int i = 1; i <= r; i++) {
			ans *= (n-r+i);
			ans /= i;
		}
		return ans;
	}
	
	public static void main(String[] args) throws IOException {
		long n, k, numerator, denumerator, x, temp;
		Reader cin = new Reader();
		PrintWriter cout = new PrintWriter(new BufferedOutputStream(System.out));
		while(true) {
			n = cin.nextLong();
			k = cin.nextLong();
			if(n == -1) {
				break;
			}
			else if(k < 3) { // If k is smaller than smallest sum(1+2). 
				cout.println("0");
				continue ;
			}
			else if (k >= (n + n-1)){ // if k is greater than largest sum(n + n-1) 
				cout.println("1");
				continue ;
			}
			denumerator = n*(n-1)/2; 
			// From (k/2 + 1) .... n , no further combination is less than k because (k/2)+(k/2 + 1) > k.
			// For k = odd, (k/2) + (k/2 + 1) = k, it is the largest sum <= k.
			 //For k = even, (k/2) + (k/2 - 1) is = k-1.
			k -=2;
			numerator = 0;
			while(k > 0) {
				numerator += k;
				k -= 2;
			}
			if(numerator == 0) {
				cout.println("0");
				continue ;
			}
			temp = gcd(numerator,denumerator);
			while(temp != 1) {
				numerator /= temp;
				denumerator /= temp;
				temp = gcd(numerator,denumerator);
			}
			cout.println(numerator + "/" + denumerator);
		}
		cin.close();
		cout.close();

	}
	//-----------Reader class for faster input----------
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
Probability = No. of events /All possible outcomes.
No. of all possible outcomes = nC2
If two or more sum equals, should be regarded as one event, e.g. 4+3=5+2=same=1 event, 
one is taken,other is discarded,discarded events goes to the opponent event/or, you can say a non-event.

How many pairwise distinct sums are there in a finite set of consecutive Integers?

You can solve this simply by looking at the smallest number you can form and the largest number you can
form. Let's say is ascending. Then let (a1 + a2 )be the smallest number you can form. Let (a_(n-1) + a_n)
be the largest number you can form. Then you can see that you can form every number in
between and (Hint: You can shift the sequence so that it looks like 1 2 3....n).
Therefore, you can create distinct numbers. Looking at our shifted values, we can create
distinct numbers

A set {1,2,3.....n}, we can form Sum = 3 in one way, 4 in one way, 5 in two ways, 6 in two ways, 7 in three
ways, 8 in three ways, etc. (see the pattern?) We find that we can create (n+1) in floor(n/2) ways (which is
the max), and after (n+1), the number of ways will decrease symmetrically (e.g. n and (n+2) will have the
same number of sums, (n-1) and (n+3) will have the same number of sums, etc)


For Sum less than or equal to 5,  the options are (1,4) (1,3) (1,2) (2,3),
 you can find that it is actually by this pattern :
 k-2 + k-4 + k-6 + k-8+.......0.


**/