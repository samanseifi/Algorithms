import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdIn;

public class WeightedQuickUnionUF {
    
    private int[] id;
    private int[] sz;
    
    public WeightedQuickUnionUF(int N) {        
        id = new int[N];
        sz = new int[N];
        for (int i = 0; i < N; i++)
            id[i] = i;
        for (int j = 0; j < N; j++)
            sz[j] = 1;   
    }
    
    public int root(int i) {
        while (i != id[i])
            i = id[i];
        return i;
    }
    
    public boolean find(int p, int q) {
        return root(p) == root(q);
    }
    
    public void union(int p, int q) {
        int i = root(p);
        int j = root(q);
        if (i == j) return;
        if ( sz[i] > sz[j]) {
            id[j] = i;
            sz[i] += sz[j];
        } else {
            id[i] = j;
            sz[j] += sz[i];
        }
    }
    public static void main(String[] args)
    {
        int N = StdIn.readInt();
        WeightedQuickUnionUF uf = new WeightedQuickUnionUF(N);
        while (!StdIn.isEmpty())
        {
            int p = StdIn.readInt();
            int q = StdIn.readInt();
            if (!uf.find(p, q))
            {
                uf.union(p, q);
                StdOut.println("connecting " + p + " to " + q);
            } else {
                StdOut.println(p + " is already connected to " + q);
            }
                
        }
    }
}
