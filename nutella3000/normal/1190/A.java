import java.io.*;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        long n = nextLong();
        int m = nextInt();
        long a[] = new long [m];
        long k = nextLong();
        for(int i = 0;i < m;i++) a[i] = nextLong();
        int ans = 0;
        int id = 0;
        while(id != m) {
            int l = id - 1;
            int r = m;
            while(r - l > 1) {
                int mid = (l + r) / 2;
                if ((a[id] - id - 1) / k == (a[mid] - id - 1) / k) l = mid;
                else r = mid;
            }
            ans++;
            id = r;
        }
        pw.println(ans);
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