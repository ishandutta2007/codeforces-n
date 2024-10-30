import java.io.*;
import java.util.*;


public class Main {
    static int inf = (int) (1e9 + 7);
    static int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        int b[][] = new int [n][n];
        int a[] = new int [n];
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) b[i][j] = sc.nextInt();
        }

        for(int i = 0;i < n;i++) {
            int prev = (i - 1 + n) % n;
            int to = (i + 1) % n;
            a[i] = (int) Math.sqrt((long)b[i][prev] * b[i][to] / b[prev][to]);
        }

        for(int i = 0;i < n;i++) pw.print(a[i] + " ");

        pw.close();
    }

    static Scanner sc;
    static PrintWriter pw;

    static class Scanner {
        BufferedReader br;
        StringTokenizer st = new StringTokenizer("");

        Scanner(InputStream in) throws FileNotFoundException {
            br = new BufferedReader(new InputStreamReader(in));
        }

        Scanner(String in) throws FileNotFoundException {
            br = new BufferedReader(new FileReader(in));
        }

        String next() throws IOException {
            while (!st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
            return st.nextToken();
        }

        int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }
    }

}