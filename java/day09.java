// Source: https://usaco.guide/general/io

import java.io.*;
import java.util.*;
import java.util.StringTokenizer;

public class Main {

	public static int calculateNext(ArrayList<ArrayList<Integer>> diffs, boolean partOne) {
		ArrayList<Integer> outest = diffs.get(0);
		if (partOne) {
			int last=outest.get(outest.size()-1);
			for (int i=1;i<diffs.size();i++) {
				ArrayList<Integer> current = diffs.get(i);
				last+=current.get(current.size()-1);
			}
			return last;
		}
		int first=outest.get(0);
		for (int i=1;i<diffs.size();i++) {
			ArrayList<Integer> current = diffs.get(i);
			first+=(i%2==0?1:-1)*current.get(0);
		}
		return first;
	}

	public static void main(String[] args) throws IOException {
		long start = System.currentTimeMillis();
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		StringTokenizer st;
		boolean partOne=false;
		long answer=0L;
		while (r.ready()) {
			st=new StringTokenizer(r.readLine());
			ArrayList<Integer> list = new ArrayList<>();
			int a=0;
			while (st.hasMoreTokens()) {
				a=Integer.parseInt(st.nextToken());
				list.add(a);
			}
			ArrayList<ArrayList<Integer>> diffs = new ArrayList<>();
			diffs.add(list);
			boolean is_zeroes=false;
			int level=0;
			while (!is_zeroes) {
				boolean cur_zeroes=true;
				ArrayList<Integer> curDiff=new ArrayList<>(), curLevel=diffs.get(level);
				for (int i=0;i<curLevel.size()-1;i++) {
					int d=curLevel.get(i+1)-curLevel.get(i);
					curDiff.add(d);
					if (d!=0) cur_zeroes=false;
				}
				if (cur_zeroes) is_zeroes=true;
				diffs.add(curDiff);
				level++;
			}
			answer+=calculateNext(diffs,partOne);
		}
		pw.println(answer);
		long total = System.currentTimeMillis() - start;
		pw.println(total+" ms");
		pw.close();
	}
}
