import java.io.BufferedOutputStream;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.PrintWriter;


public class spoj_DICT {
	static PrintWriter cout ;
	class radixTree {
		private node root;
		public radixTree() {
			root = new node(false);
		}
		public void insert(String word) {
			int i = 0,j, idx;
			StringBuilder label;
			node nd = root;
			while(i<word.length() && nd.child[word.charAt(i)-'a'] != null) {
				j = 0;
				idx = word.charAt(i) - 'a';
				label = nd.edge[word.charAt(i)-'a'];
				while(i<word.length() && j<label.length() &&
						word.charAt(i) == label.charAt(j)) {
					i++;
					j++;
				}
				if(j == label.length()) {
					nd = nd.child[idx];//error prone:it's 'idx' not 'i'.
				}
				else if(i == word.length()){ // prefix 
					node beforeCutChild = nd.child[idx];
					StringBuilder remaining = cutItFromIdx(j, nd.edge[idx]);
					nd.edge[idx].setLength(j);//cut
					
					node newChild = new node(true);
					nd.child[idx] = newChild;
					newChild.edge[remaining.charAt(0)-'a'] = remaining;
					newChild.child[remaining.charAt(0)-'a'] = beforeCutChild;
					return ;
					
				}
				else /*if(i < word.length() && word.charAt(i) != label.charAt(j)) */{ // partial match
					node beforeCutChild = nd.child[idx];
					StringBuilder remainingEdge = cutItFromIdx(j, nd.edge[idx]);
					StringBuilder remainingWord = cutItFromIdx(i, word);
					nd.edge[idx].setLength(j);//cut
					
					node newChild = new node(false);
					nd.child[idx] = newChild;
					newChild.edge[remainingEdge.charAt(0)-'a'] = remainingEdge;
					newChild.edge[remainingWord.charAt(0)-'a'] = remainingWord;
					newChild.child[remainingEdge.charAt(0)-'a'] = beforeCutChild;
					newChild.child[remainingWord.charAt(0)-'a']= new node(true);
					return;
				}
					
			}
			if(i < word.length()) {
				nd.edge[word.charAt(i)-'a'] = cutItFromIdx(i, word);
				nd.child[word.charAt(i)-'a'] = new node(true);
			}
			else {//duplicate
				nd.isEnd = true;
			}
		}
		StringBuilder cutItFromIdx(int idx, CharSequence word) {
			StringBuilder sb = new StringBuilder(30);
			while(idx < word.length()) {
				sb.append(word.charAt(idx));
				idx++;
			}
			return sb;
		}
		public void printUtil(node nd, StringBuilder sb) {
			if(nd.isEnd) {
				cout.println(sb);
			}
			for(int i = 0; i<node.sz; i++) {
				if(nd.child[i] != null) {
					StringBuilder temp = new StringBuilder(sb);			
					printUtil(nd.child[i], temp.append(nd.edge[i]));
					//sb.delete(sb.length()-nd.edge[i].length(), sb.length());
				}
			}
		}
		public void print() {
			node nd = root;
			for(int i = 0; i<node.sz; i++) {
				if(nd.child[i] != null) {
					StringBuilder sb = new StringBuilder(nd.edge[i]);
					printUtil(nd.child[i], sb);
				}
			}
		}
		public void dictSearch(String word) {
			node nd = root;
			int i = 0,j,idx = 0;
			StringBuilder label = null;
			StringBuilder cur = new StringBuilder();
			if(nd.child[word.charAt(0)-'a'] == null) {
				cout.println("No match.");
				return ;
			}
			while(i<word.length() && nd.child[word.charAt(i)-'a'] != null) {
				j = 0;
				idx = word.charAt(i) - 'a';
				label = nd.edge[word.charAt(i)-'a'];
				while(i<word.length() && j<label.length() &&
						word.charAt(i) == label.charAt(j)) {
					i++;
					j++;
				}
				if(j == label.length()) {
					cur.append(label);
					nd = nd.child[idx];//error prone:it's 'idx' not 'i'.
				}
				else {//prefix or partial match
					if(i == word.length()) {//prefix
						cur.append(label);
						nd = nd.child[idx];
						break;
					}
					else {//partial match
						cout.println("No match.");
						return;
					}
				}
			}
			if(i < word.length()) {
				cout.println("No match.");
				return;
			}
			boolean flag = false;
			if(word.length() < cur.length() && nd.isEnd) {
				cout.println(cur);
				flag = true;
			}
			for(int it = 0; it<node.sz; it++) {
				if(nd.child[it] != null) {
					flag = true;
					printUtil(nd.child[it], cur.append(nd.edge[it]));
					cur.delete(cur.length()-nd.edge[it].length(), cur.length());
				}
			}
			if(flag == false) {
				cout.println("No match.");
			}
		}

		class node {
			static final int sz = 26;
			boolean isEnd;
			StringBuilder[] edge;
			node[] child;
			public node(boolean isEnd) {
				this.isEnd = isEnd;
				edge = new StringBuilder[sz];
				child = new node[sz];
			}
		}

	}

	public static void main(String[] args) throws IOException {
			Reader cin = new Reader();
			cout = new PrintWriter(new BufferedOutputStream(System.out));
			radixTree ds = new spoj_DICT().new radixTree();
			int n = Integer.parseInt(cin.readLine());
			for(int i = 0; i<n; i++) {
				ds.insert(cin.readLine());
			}
			int k = Integer.parseInt(cin.readLine());
			for(int i = 1; i<=k; i++) {
				cout.println("Case #"+i+":");
				ds.dictSearch(cin.readLine());
			}
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
			byte[] buf = new byte[64]; // line length
			int cnt = 0, c;
			while ((c = read()) != -1) {
				if (c == '\n')
					break;
				buf[cnt++] = (byte) c;
			}
			return new String(buf, 0, cnt-1);
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
