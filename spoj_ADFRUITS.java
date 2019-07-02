import java.io.BufferedOutputStream;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;
 
public class spoj_ADFRUITS {
	static int it;
	static PrintWriter cout;
	public static StringBuilder topDown(String x, String y, int i, int j) {
		StringBuilder sb = new StringBuilder(204);
		if (i == x.length() || j == y.length()) {
			if (i == x.length()) {
				it = j;
				while (it < y.length()) {
					sb.append(y.charAt(it));
					it++;
				}
				return sb;
			} else if (j == y.length()) {
				it = i;
				while (it < x.length()) {
					sb.append(x.charAt(it));
					it++;
				}
				return sb;
			} else {
				return sb;
			}
		} else if (x.charAt(i) == y.charAt(j)) {
 
			sb = topDown(x, y, i + 1, j + 1);
			sb.insert(0, x.charAt(i));
			return sb;
		} else {
			StringBuilder sb1 = topDown(x, y, i + 1, j);
			sb1.insert(0, x.charAt(i));
			StringBuilder sb2 = topDown(x, y, i, j + 1);
			sb2.insert(0, y.charAt(j));
			// System.out.println("fk : " + sb1 + " ;" + sb2);
			return sb1.length() < sb2.length() ? sb1 : sb2;
		}
	}
 
	public static void bottomUp(String x, String y) {
		int T[][] = new int[x.length()+1][y.length()+1];
		for (int i = 0; i < x.length(); i++) {
			T[i+1][0] = i + 1;
		}
		for (int j = 0; j < y.length(); j++) {
			T[0][j+1] = j + 1;
		}
		for (int i = 1; i <= x.length(); i++) {
			for (int j = 1; j <= y.length(); j++) {
				if (x.charAt(i - 1) == y.charAt(j - 1)) {
					T[i][j] = 1 + T[i - 1][j - 1];
				} else {
					T[i][j] = 1 + Math.min(T[i - 1][j], T[i][j - 1]);
				}
			}
		}
		/**
		for (int i = 0; i <= x.length(); i++) {
			for (int j = 0; j <= y.length(); j++){
					System.out.print(T[i][j] + " ");
			}
			System.out.println();
		}
		**/
		int i,j;
		StringBuilder sb = new StringBuilder(204);
		i = x.length();
		j = y.length();
		while(i>0 || j>0){
			while(i>0 && j>0){
				if(x.charAt(i-1) == y.charAt(j-1)){
					sb.insert(0, x.charAt(i-1));
					i--;
					j--;
				}
				else {
					if(T[i-1][j] < T[i][j-1]){
						sb.insert(0, x.charAt(i-1));
						i--;
					}
					else {
						sb.insert(0, y.charAt(j-1));
						j--;
					}
				}
			}
			while(i>0){
				sb.insert(0, x.charAt(i-1));
				i--;
			}
			while(j>0){
				sb.insert(0, y.charAt(j-1));
				j--;
			}
		}
		cout.println(sb);
	}
 
	public static void main(String[] args) throws IOException {
		Reader cin = new Reader();
		 cout = new PrintWriter(new BufferedOutputStream(System.out));
		String x, y, line;
		StringTokenizer st;
		while (true) {
			line = cin.readLine();
			if (line == null) {
				break;
			}
			st = new StringTokenizer(line);
			x = st.nextToken();
			y = st.nextToken();
 
			bottomUp(x,y);
			
		}
		cout.close();
	}
 
	static class Reader {
		final private int BUFFER_SIZE = 1 << 16;
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
			byte[] buf = new byte[205]; // line length
			int cnt = 0, c;
			c = read();
			if (c == -1) {
				return null;
			} else {
				buf[cnt++] = (byte) c;
			}
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