import java.io.*;
import java.util.*;
import java.math.*;

public class C implements Runnable {

	void solve() {
		int k = nextInt();
		char[] c = nextToken().toCharArray();
		for (int i = 0, j = c.length - 1; i < j; i++, j--) {
			if (c[i] != '?' && c[j] != '?' && c[i] != c[j]) {
				out.println("IMPOSSIBLE");
				return;
			}
		}
		int q = 0;
		TreeSet<Character> ts = new TreeSet<Character>();
		for (int i = 0; i < k; i++) {
			ts.add((char) ('a' + i));
		}
		for (int i = 0, j = c.length - 1; i <= j; i++, j--) {
			if (c[i] == '?' && c[j] == '?') {
				q++;
			}
			if (c[i] != '?') {
				ts.remove(c[i]);
			}
			if (c[j] != '?') {
				ts.remove(c[j]);
			}
		}
		for (int i = (c.length - 1) / 2, j = c.length - i - 1; i >= 0; i--, j++) {
			if (c[i] == '?' && c[j] == '?') {
				if (!ts.isEmpty()) {
					c[i] = c[j] = ts.pollLast();
				} else {
					c[i] = c[j] = 'a';
				}
			}
		}
		if (!ts.isEmpty()) {
			out.println("IMPOSSIBLE");
			return;
		}
		for (int i = 0, j = c.length - 1; i < j; i++, j--) {
			if (c[i] == '?') {
				c[i] = c[j];
			} else if (c[j] == '?') {
				c[j] = c[i];
			}
		}
		out.println(new String(c));
	}

	FastScanner sc;
	PrintWriter out;

	public void run() {
		Locale.setDefault(Locale.US);
		try {
			sc = new FastScanner(System.in);
			out = new PrintWriter(System.out);
			solve();
			sc.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	int nextInt() {
		return sc.nextInt();
	}

	String nextToken() {
		return sc.nextToken();
	}

	long nextLong() {
		return sc.nextLong();
	}

	double nextDouble() {
		return sc.nextDouble();
	}

	BigInteger nextBigInteger() {
		return sc.nextBigInteger();
	}

	class FastScanner extends BufferedReader {
		StringTokenizer st;
		boolean eof;
		String buf;
		String curLine;
		boolean createST;

		public FastScanner(String fileName) throws FileNotFoundException {
			this(fileName, true);
		}

		public FastScanner(String fileName, boolean createST)
				throws FileNotFoundException {
			super(new FileReader(fileName));
			this.createST = createST;
			nextToken();
		}

		public FastScanner(InputStream stream) {
			this(stream, true);
		}

		public FastScanner(InputStream stream, boolean createST) {
			super(new InputStreamReader(stream));
			this.createST = createST;
			nextToken();
		}

		String nextLine() {
			String ret = curLine;
			if (createST) {
				st = null;
			}
			nextToken();
			return ret;
		}

		String nextToken() {
			if (!createST) {
				try {
					curLine = readLine();
				} catch (Exception e) {
					eof = true;
				}
				return null;
			}
			while (st == null || !st.hasMoreTokens()) {
				try {
					curLine = readLine();
					st = new StringTokenizer(curLine);
				} catch (Exception e) {
					eof = true;
					break;
				}
			}
			String ret = buf;
			buf = eof ? "-1" : st.nextToken();
			return ret;
		}

		int nextInt() {
			return Integer.parseInt(nextToken());
		}

		long nextLong() {
			return Long.parseLong(nextToken());
		}

		double nextDouble() {
			return Double.parseDouble(nextToken());
		}

		BigInteger nextBigInteger() {
			return new BigInteger(nextToken());
		}

		public void close() {
			try {
				buf = null;
				st = null;
				curLine = null;
				super.close();
			} catch (Exception e) {

			}
		}

		boolean isEOF() {
			return eof;
		}
	}

	public static void main(String[] args) {
		new C().run();
	}
}