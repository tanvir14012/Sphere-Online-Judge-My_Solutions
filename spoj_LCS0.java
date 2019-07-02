import java.io.BufferedOutputStream;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.PrintWriter;

public class spoj_LCS0 {

	public static void main(String[] args) throws IOException {
		String x,y;
		int idx = 0;
		Reader cin = new Reader();
		PrintWriter cout = new PrintWriter(new BufferedOutputStream(System.out));
		x = cin.readLine();
		y = cin.readLine();
		int[][] T = new int[2][50002];
		for(int i = 0; i<x.length(); i++){
			idx = i & 1;
			for(int j = 0; j<y.length(); j++) {
				if(x.charAt(i) == y.charAt(j)){
					T[idx][j+1] = T[1-idx][j] + 1;
				}
				else {
					T[idx][j+1] = Math.max(T[1-idx][j+1], T[idx][j]);
				}
			}
		}
		cout.println(T[idx][y.length()]);
		cin.close();
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
			byte[] buf = new byte[50001];
			int cnt = 0, c;
			while ((c = read()) != -1) {
				if (c == '\n')
					break;
				buf[cnt++] = (byte) c;
			}
			return new String(buf, 0, cnt - 1);
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
