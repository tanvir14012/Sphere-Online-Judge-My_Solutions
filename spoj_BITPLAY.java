import java.io.BufferedOutputStream;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.BitSet;

public class spoj_BITPLAY {
	static long toDecimal(BitSet b) {
		long base = 1, dec = 0;
		for(int i = b.length()-1; i>=0; i--) {
			dec += (b.get(i))? base : 0;
			base *= 2;
		}
		return dec;
	}
	public static void main(String[] args) throws IOException {
		Reader cin  = new Reader();
		PrintWriter cout = new PrintWriter(new BufferedOutputStream(System.out));
		int t,k;
		long n;
		BitSet b;
		t = cin.nextInt();
		while(t>0) {
			t--;
			n = cin.nextLong();
			k = cin.nextInt();
			b = new BitSet(32);
			b.set(31);
			n--;
			if(k <= 0) {
				cout.println("-1");
			}
			else {
			k--;
			for(int i = 0; k>0 && i<32; i++) {
				b.set(i);
				//System.out.println("x="+toDecimal(b));
				if(toDecimal(b) > n) {
					b.flip(i);
				}
				else {
				k--;
				}
			}
			cout.println(toDecimal(b));
			}
		}
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
/***
 * A binary number is even if rightmost bit = 0, odd if rightmost bit = 1.
 * 
 * Bits of a binary number are ordered left-->right = high-->low. leftmost = highest ordered.
 * 
 * An unsigned binary number x > y(another), if x has at least one bit in higher order than y.
 * 
 * So, here, rightmost bit must be = 1, and k--.
 * 
 * Logic : check setting-flipping bits from left to right until you find the number which is < n.
 * 
 
 * 
 * **/
