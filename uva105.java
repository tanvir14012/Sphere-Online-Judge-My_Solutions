import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.StringTokenizer;


public class uva105 {
	
	public static Scanner scan;

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		scan = new Scanner(System.in);
		int l,h,r,temp;
		int height[] = new int[10000];
		for (int x = 0; x<8; x++)
		{
			l = scan.nextInt(); h = scan.nextInt(); r = scan.nextInt();
			for(int i = l; i<=r; i++)
			{
				if(height[i] <= h)
				{
					height[i] = h;
				}
			}
		}
		temp = -1;
		for(int i = 0; i<10000; i++)
		{
			if(height[i] > temp)
			{
				System.out.print(i + " " + height[i]);
				temp = height[i];
			}
		}
		System.out.println();

	}
}
	