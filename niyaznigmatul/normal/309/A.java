import java.io.InputStreamReader;
import java.io.IOException;
import java.util.InputMismatchException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Reader;
import java.io.Writer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Niyaz Nigmatullin
 */
public class Main {
  public static void main(String[] args) {
    InputStream inputStream = System.in;
    OutputStream outputStream = System.out;
    FastScanner in = new FastScanner(inputStream);
    FastPrinter out = new FastPrinter(outputStream);
    TaskA solver = new TaskA();
    solver.solve(1, in, out);
    out.close();
  }
}

class TaskA {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        long len = in.nextInt();
        long time = in.nextInt() * 2;
        long[] a = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        double ans = solve1(n) * (time / len);
        ans += solve2(a, len, time % len);
        out.println(ans);
    }

    static double solve1(int n) {
        return 1. * n * (n - 1) * .25;
    }

    static double solve2(long[] a, long len, long t) {
        long pairs = getPairs(a, t, len);
        return pairs * .25;
    }

    static long getPairs(long[] a, long dist, long len) {
        int j = 0;
        int n = a.length;
        long ans = 0;
        for (int i = 0; i < n; i++) {
            while (true) {
                int ne = (j + 1);
                if (ne == n) ne = 0;
                if (ne == i) break;
                long d = a[ne] - a[i];
                if (d < 0) d += len;
                if (d > dist) break;
                j = ne;
            }
            ans += j < i ? (j + n - i) : j - i;
            if (i == j) ++j;
        }
        return ans;
    }
}

class FastScanner extends BufferedReader {

    public FastScanner(InputStream is) {
        super(new InputStreamReader(is));
    }

    public int read() {
        try {
            int ret = super.read();
//            if (isEOF && ret < 0) {
//                throw new InputMismatchException();
//            }
//            isEOF = ret == -1;
            return ret;
        } catch (IOException e) {
            throw new InputMismatchException();
        }
    }

    static boolean isWhiteSpace(int c) {
        return c >= 0 && c <= 32;
    }

    public int nextInt() {
        int c = read();
        while (isWhiteSpace(c)) {
            c = read();
        }
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int ret = 0;
        while (c >= 0 && !isWhiteSpace(c)) {
            if (c < '0' || c > '9') {
                throw new NumberFormatException("digit expected " + (char) c
                        + " found");
            }
            ret = ret * 10 + c - '0';
            c = read();
        }
        return ret * sgn;
    }

    public String readLine() {
        try {
            return super.readLine();
        } catch (IOException e) {
            return null;
        }
    }

    }

class FastPrinter extends PrintWriter {

    public FastPrinter(OutputStream out) {
        super(out);
    }

    public FastPrinter(Writer out) {
        super(out);
    }


}