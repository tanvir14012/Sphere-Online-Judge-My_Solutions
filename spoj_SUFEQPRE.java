package spoj;
import java.io.BufferedOutputStream;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.PrintWriter;
/**
 *
 * @author TANVIR
 */
public class spoj_SUFEQPRE {
    public static void main(String[] args)throws IOException {
        PrintWriter cout = new PrintWriter(new BufferedOutputStream(System.out));
        Reader cin = new Reader();
        String s;
        int[] z;
        int t,count,l,r,k;
        t= cin.nextInt();
        for(int it = 1; it <= t; it++) {
            s  = cin.readLine();
            z = new int[s.length()];
            count = l = r = k = 0;
            for(int i = 1; i<s.length(); i++) {
                if(i > r) {
                    l = r = i;
                    while(r < s.length() && s.charAt(r-l) == s.charAt(r)) {
                        r++;
                    }
                    r--;
                    z[i] = r-l+1;
                }
                else {
                    k = i-l;
                    if(z[k] < r-i+1) {
                        z[i] = z[k];
                    }
                    else {
                        l = i;
                        while(r < s.length() && s.charAt(r-l) == s.charAt(r)) {
                            r++;
                        }
                        r--;
                        z[i] = r-l+1;
                    }
                }
                if(z[i] == s.length()-i) {
                    count++;
                }
            }
            cout.println("Case "+it+": "+count);
        }
        cin.close();
        cout.close();
    }
    
    static class Reader {
		final private int BUFFER_SIZE = 1 << 20;
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
			byte[] buf = new byte[1000009]; // line length
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
