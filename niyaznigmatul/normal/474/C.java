import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    static int[] x;
    static int[] y;
    static int[] a;
    static int[] b;
    static long[] d;
    static int ans;

    static void go(int cur, int n, int done) {
        if (done >= ans) return;
        if (cur == n) {
            int cn = 0;
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    long dx = x[i] - x[j];
                    long dy = y[i] - y[j];
                    d[cn++] = dx * dx + dy * dy;
                }
            }
            Arrays.sort(d);
            if (d[0] != d[3] || d[0] == 0) return;
            if (d[4] != d[5] || d[4] != 2 * d[0]) return;
            ans = done;
            return;
        }
        for (int i = 0; i < 4; i++) {
            go(cur + 1, n, done + i);
            int dx = x[cur] - a[cur];
            int dy = y[cur] - b[cur];
            x[cur] = a[cur] - dy;
            y[cur] = b[cur] + dx;
        }
    }

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int tests = in.nextInt();
        d = new long[6];
        for (int curTest = 0; curTest < tests; curTest++) {
            x = new int[4];
            y = new int[4];
            a = new int[4];
            b = new int[4];
            for (int i = 0; i < 4; i++) {
                x[i] = in.nextInt();
                y[i] = in.nextInt();
                a[i] = in.nextInt();
                b[i] = in.nextInt();
            }
            ans = 123;
            go(0, 4, 0);
            out.println(ans == 123 ? -1 : ans);
        }
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