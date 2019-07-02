import java.io.BufferedOutputStream;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.PrintWriter;

public class spoj_IOIPALIN {
	static int get(int count, int val) {
		count = count + 3 + val;
		if (count >= 3) {
			count -= 3;
		}
		return count;
	}

	public static void main(String[] args) {
		Reader cin = new Reader();
		PrintWriter cout = new PrintWriter(new BufferedOutputStream(System.out));
		int n = 0;
		String str = "";
		try {
			n = Integer.valueOf(cin.readLine(0));
			str = cin.readLine(n);
			cin.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

		int[][] T = new int[n + 2][3];
		int count = 0;
		for (int l = 1; l < n; l++) {
			count = (count < 2) ? count + 1 : 0;
			for (int i = 0; i < n; i++) {
				if (i + l < n && str.charAt(i) == str.charAt(i + l)) {
					if (i + 1 < n && l - 2 >= 0) {
						T[i][count] = T[i + 1][get(count, -2)];
					}
				} else if (i + l < n && l - 1 >= 0) {
					T[i][count] = 1 + Math.min(T[i][get(count, -1)], T[(i + 1)][get(count, -1)]);
				}

			}
		}
		cout.println(T[0][count]);
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

		public String readLine(int n) throws IOException {
			byte[] buf;
			if (n == 0) {
				buf = new byte[6]; // line length
			} else {
				buf = new byte[n + 4];
			}
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
