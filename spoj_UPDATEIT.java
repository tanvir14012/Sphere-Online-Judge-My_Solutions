import java.io.BufferedOutputStream;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.PrintWriter;

public class spoj_UPDATEIT {

	public static void main(String[] args) throws IOException {
		Reader cin = new Reader();
		PrintWriter cout = new PrintWriter(new BufferedOutputStream(System.out));
		int t,n,u,l,r,val,q,index,ans;
		t = cin.nextInt();
		while(t > 0)
		{
			t--;
			n = cin.nextInt();
			u = cin.nextInt();
			int BIT[] = new int[n+1];
			for(int i = 0; i<u; i++)
			{
				l = cin.nextInt();;
				r = cin.nextInt();
				val = cin.nextInt();
				update(BIT,n,l,val);
				if(r+1 < n) update(BIT,n,r+1,-val);
			}
			q = cin.nextInt();
			while(q > 0)
			{
				q--;
				index = cin.nextInt();
				ans = getSum(BIT,index+1);
				cout.println(ans);
			}
			BIT = null;
		}
		cout.close();
		
	
	}
	static void update(int BIT[],int n,int idx,int val)
	{
		idx ++;
	    while(idx <= n)
	    {
	        BIT[idx] += val;
	        idx += (idx & (-idx));
	    }
	}
	static int getSum(int BIT[],int idx)
	{
	    int val = 0;
	    while(idx > 0)
	    {
	        val += BIT[idx];
	        idx -=  (idx & (-idx));
	    }
	    return val;
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
This is solved by BIT.
I learned from (topcoder,pdf of Ibrahim saad,pdf of kartikkukreja.wordpress.com,geeksforgeeks, tusher roy)
Uses the idea : Range Updates and Point queries.
update(BIT,n,l,val);line add values from l to n.
update(BIT,n,r+1,-val); line discards side-effects of prev. line.It
reverts update from r+1 to n done by previous line.
**/
