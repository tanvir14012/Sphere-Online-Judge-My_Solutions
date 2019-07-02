package spoj;

import java.io.BufferedOutputStream;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author TANVIR
 */
public class Spoj_ALCATRAZ1 {

    public static void main(String[] args) {
        DataInputStream din = new DataInputStream(System.in);
        PrintWriter cout = new PrintWriter(new BufferedOutputStream(System.out));
        byte[] nums = new byte[64];
        int t,count;
        long sum;
        try {
             t = din.readByte() - 48;
             din.readByte();
             for(int l = 0; l < t; l++) {
             sum = 0;
             count = din.read(nums, 0, 64);
             for(int i = 0; i < count-1; i++) {
                sum += (nums[i]-48);
             }
             cout.println(sum);
             }
             cout.close();
        } catch (IOException ex) {
            Logger.getLogger(Spoj_ALCATRAZ1.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    
}
/**
 * TLE
 */