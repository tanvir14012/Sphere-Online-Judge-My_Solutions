
package spoj;

import java.io.BufferedOutputStream;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.PrintWriter;


public class spoj_FILRTEST {
    public static void main(String[] args) throws IOException {
            Reader cin = new Reader();
            PrintWriter cout = new PrintWriter(new BufferedOutputStream(System.out));
            int n,i,j,ans;
            String s;
            int[] lps = new int[1000009];
            while(true) {
                n = cin.nextInt();
                if(n == -1) {
                    break;
                }
                s = cin.readLine();
                i = 1 ;
                j = 0;
                lps[0] = 0;
                while(i < s.length()) {
                    if(s.charAt(i) == s.charAt(j)) {
                        j++;
                        lps[i] = j;
                        i++;
                    }
                    else {
                        if(j == 0) {
                            lps[i] = 0;
                            i++;
                        }
                        else {
                            j = lps[j-1];
                        }
                    }
                }
                if(s.length() > n) {
                     cout.println(0);
                     continue;
                }
                ans = (lps[s.length()-1] == 0 ? n/s.length() : 1 + (int)Math.floor((n-s.length())/(s.length()-lps[s.length()-1]))); 
                cout.println(ans);
            }
            cin.close();
            cout.close();
    }
    static class Reader {
		final private int BUFFER_SIZE = 1000009;
		private DataInputStream din;
		private byte[] buffer;
		private int bufferPointer, bytesRead;

		public Reader() {
			din = new DataInputStream(System.in);
			buffer = new byte[BUFFER_SIZE];
			bufferPointer = bytesRead = 0;
		}

		public Reader(String file_name) throws IOException {
			din = new DataInputStream(new FileInputStream(file_name));
			buffer = new byte[BUFFER_SIZE];
			bufferPointer = bytesRead = 0;
		}

		public String readLine() throws IOException {
			byte[] buf = new byte[1000005]; // line length
			int cnt = 0, c;
			while ((c = read()) != -1) {
				if (c == '\n')
					break;
				buf[cnt++] = (byte) c;
			}
			return new String(buf, 0, cnt);
		}

		public int nextInt() throws IOException {
			int ret = 0;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = (c == '-');
			if (neg)
				c = read();
			do {
				ret = ret * 10 + c - '0';
			} while ((c = read()) >= '0' && c <= '9');

			if (neg)
				return -ret;
			return ret;
		}

		public long nextLong() throws IOException {
			long ret = 0;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = (c == '-');
			if (neg)
				c = read();
			do {
				ret = ret * 10 + c - '0';
			} while ((c = read()) >= '0' && c <= '9');
			if (neg)
				return -ret;
			return ret;
		}

		public double nextDouble() throws IOException {
			double ret = 0, div = 1;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = (c == '-');
			if (neg)
				c = read();

			do {
				ret = ret * 10 + c - '0';
			} while ((c = read()) >= '0' && c <= '9');

			if (c == '.') {
				while ((c = read()) >= '0' && c <= '9') {
					ret += (c - '0') / (div *= 10);
				}
			}

			if (neg)
				return -ret;
			return ret;
		}

		private void fillBuffer() throws IOException {
			bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
			if (bytesRead == -1)
				buffer[0] = -1;
		}

		private byte read() throws IOException {
			if (bufferPointer == bytesRead)
				fillBuffer();
			return buffer[bufferPointer++];
		}

		public void close() throws IOException {
			if (din == null)
				return;
			din.close();
		}
	}
}
