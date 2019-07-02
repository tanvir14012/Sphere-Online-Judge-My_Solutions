    import java.util.Scanner;
     
    public class spoj_LINESEG {
    	private static class point
    	{
    		public int x,y;
    		
    		public point(int x,int y) {
    			this.x = x;
    			this.y  = y;
    		}
    		public boolean equals(point p)
    		{
    			return (this.x==p.x)&&(this.y==p.y);
    		}
    		
    	}
    	static int orientation(point a,point b,point c)
    	{
    		int v = ((a.y-b.y)*(b.x-c.x))-((b.y-c.y)*(a.x-b.x));
    		if(v == 0)
    		{
    			return 0;
    		}
    		return (v > 0) ? 1:2;
    	}
    	static boolean onSegment(point p,point q,point r)
    	{
    		if( ((r.x)<=Math.max(p.x, q.x))&&((r.x)>=Math.min(p.x, q.x))
    			&& ((r.y)<=Math.max(p.y, q.y))&&((r.y)>=Math.min(p.y, q.y))
    			)
    		{
    			return true;
    		}
    		return false;
    	}
    	static void solve(point p,point q,point r,point s)
    	{
    		int o1,o2,o3,o4;
    		boolean flag;
    		o1 = orientation(p,q,r);
    		o2 = orientation(p,q,s);
    		o3 = orientation(r,s,p);
    		o4 = orientation(r,s,q);
    		
    		//general case
    		if(o1 != o2 && o3 != o4)
    		{
    			System.out.println("POINT");
    			return ;
    		}
    		flag = false;
    		if(o1 == 0 && onSegment(p,q,r)==true) {
    			flag = true;
    		}
    		if(o2 == 0 && onSegment(p,q,s)==true) {
    			flag = true;
    		}
    		if(o3 == 0 && onSegment(r,s,p)==true) {
    			flag = true;
    		}
    		if(o4 == 0 && onSegment(r,s,q)==true) {
    			flag = true;
    		}
    		if(flag)
    		{
    			System.out.println("SEGMENT");
    			return ;
    		}
    		System.out.println("NO");
    	}
    	public static void main(String[] args) {
    		Scanner cin = new Scanner(System.in);
    		point p,q,r,s;
    		int n,a,b;
    		n = cin.nextInt();
    		for(int i= 0; i<n; i++)
    		{
    			p = new point(cin.nextInt(),cin.nextInt());
    			q = new point(cin.nextInt(),cin.nextInt());
    			r = new point(cin.nextInt(),cin.nextInt());
    			s = new point(cin.nextInt(),cin.nextInt());
    			
    			solve(p,q,r,s);
    		}		
    	}
    } 