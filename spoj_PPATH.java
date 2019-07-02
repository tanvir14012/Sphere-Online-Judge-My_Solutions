package spoj;

import java.io.BufferedOutputStream;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Collection;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Queue;

public class spoj_PPATH {

    static boolean[] isNonPrime = new boolean[5001];
    static final int MAX = 9999;

    static void buildSieve() {
        isNonPrime[0] = true;
        int sqN = (int) Math.sqrt(MAX);
        for (int j = 3; j <= sqN; j += 2) { //checking from odd 
            if (!isNonPrime[j >> 1]) {
                for (int i = j * j; i <= MAX; i += (j+j)) {
                        isNonPrime[i >> 1] = true;
                }
            }
        }
    }
    static boolean checkPrime(int n) {
        return ((n&1) == 1) && (!isNonPrime[n>>1]);
    }
    static void toDigit(int n, int[] digits) {
        for(int i = 3; i >= 0; i--) {
            digits[i] = n % 10;
            n /= 10;
        }
    }
    static int toNumber(int[] digits) {
        int ans = 0;
        for(int i = 0; i < 4; i++) {
            ans = ans*10 + digits[i];
        }
        return ans;
    }
    public static void main(String[] args) throws IOException {
        int t, src, des, n, cur;
        int[] digits = new int[4];
        HashMap<Integer,Integer> distance = new HashMap<>();
        Queue<Integer> q = new LinkedList<Integer>();
        Reader cin = new Reader();
        PrintWriter cout = new PrintWriter(new BufferedOutputStream(System.out));
        buildSieve();
        t = cin.nextInt();
        while(t > 0) {
            t--;
            src = cin.nextInt();
            des = cin.nextInt();
            distance.clear();
            q.clear();
            
            q.add(src);
            distance.put(src,0);
            while(! q.isEmpty()) {
                n = q.poll();
                toDigit(n, digits);
                for(int i = 0; i < 4; i++) {
                    for(int j = 0; j <= 9; j++) {
                        digits[i] = j;
                        cur = toNumber(digits);
                        if(checkPrime(cur) && cur > 1000 && distance.get(cur) == null) {
                            distance.put(cur,distance.get(n) + 1);
                            q.add(cur);
                            //cout.println("debug :" + cur);
                        }
                    }
                    toDigit(n, digits);
                }
            }
            if(distance.get(des) != null) {
                cout.println(distance.get(des));
            }
            else {
                cout.println("Impossible");
            }
            
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

        public int nextInt() throws IOException {
            int ret = 0;
            byte c = read();
            while (c <= ' ') {
                c = read();
            }
            boolean neg = (c == '-');
            if (neg) {
                c = read();
            }
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');

            if (neg) {
                return -ret;
            }
            return ret;
        }

        private void fillBuffer() throws IOException {
            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
            if (bytesRead == -1) {
                buffer[0] = -1;
            }
        }

        private byte read() throws IOException {
            if (bufferPointer == bytesRead) {
                fillBuffer();
            }
            return buffer[bufferPointer++];
        }

        public void close() throws IOException {
            if (din == null) {
                return;
            }
            din.close();
        }
    }
}
/**
 * BSF tag ... What is the graph ?
The graph is conceptual and you can't see all vertices & edges as a first snapshot like
many other problems.But the graph is describeable in gradual order. As first snapshot
 : you know the source vertex and it's neighbour vertices, destination vertex. Each vertex's
 neighbour verties are = all prime number from the Set {All numbers i.e. each one is 
a permutation of source number with only one digit difference} . 
Cost of each edge = 1. 
So, neighbour vertices of 1033 is = Prime numbers among( 1033...9033, 1133..1933, 
1003...1093, 1030....1039) , for clearity (1_ _ _ ... 9 _ _ _, _0_ _ ... _9_ _, _ _ 0 _..._ _ 9_, _ _ _ 0... _ _ _ 9), '_' remain unchanged in the permutation.

Task : Find shortest path between source and destination vertex, if no path exists 
print "Impossible". 
 */