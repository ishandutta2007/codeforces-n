import java.io.*;
import java.lang.reflect.Array;
import java.math.BigDecimal;
import java.math.MathContext;
import java.math.RoundingMode;
import java.util.*;


public class Main {
    static int inf = (int) 1e9 + 7;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        char h[] = next().toCharArray();
        int ans = 0;
        int cnt = 0;
        for(int i = 0;i < n;i++) {
            if (h[i] == 'a') cnt++;
            else cnt--;
            if (cnt != 0 && i % 2 == 1) {
                cnt = 0;
                ans++;
                h[i] = (char) ('a' + 'b' - h[i]);
            }
        }
        pw.println(ans);
        for(char i : h) pw.print(i);
        pw.close();
    }

    static BufferedReader br;
    static StringTokenizer st = new StringTokenizer("");
    static PrintWriter pw;

    static String next() throws IOException {
        while (!st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
        return st.nextToken();
    }

    static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    static long nextLong() throws IOException {
        return Long.parseLong(next());
    }
}