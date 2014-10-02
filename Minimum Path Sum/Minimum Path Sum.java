public class Solution {
    public int minPathSum(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int[][] cost = new int[n][m];
        Queue<Node> list = new PriorityQueue<Node>();
        Node node = new Node(0, 0, grid[0][0]);
        int x = node.x;
        int y = node.y;
        while (x != n - 1 || y != m - 1) {
            if (x < n - 1) {
                int newCost = node.cost + grid[y][x + 1];
                if (cost[x + 1][y] == 0 || cost[x + 1][y] > newCost) {
                    Node right = new Node(x + 1, y, newCost);
                    cost[x + 1][y] = newCost;
                    list.add(right);
                }
            }
            if (y < m - 1) {
                int newCost = node.cost + grid[y + 1][x];
                if (cost[x][y + 1] == 0 || cost[x][y + 1] > newCost) {
                    Node down = new Node(x, y + 1, newCost);
                    cost[x][y + 1] = newCost;
                    list.add(down);
                }
            }
            node = list.poll();
            x = node.x;
            y = node.y; 
        }
        return node.cost;
    }
    private class Node implements Comparable<Node> {
        int x;
        int y;
        int cost;
		public Node(int x, int y, int cost) {
			this.x = x;
			this.y = y;
			this.cost = cost;
		}
		@Override
		public int compareTo(Node o) {
			return this.cost - o.cost;
		}
    }
}
// public class Solution {
//     public int minPathSum(int[][] grid) {
//         if (grid == null || grid.length == 0 || grid[0].length == 0) {
//             return 0;
//         }

//         int M = grid.length;
//         int N = grid[0].length;
//         int[][] sum = new int[M][N];

//         sum[0][0] = grid[0][0];

//         for (int i = 1; i < M; i++) {
//             sum[i][0] = sum[i - 1][0] + grid[i][0];
//         }

//         for (int i = 1; i < N; i++) {
//             sum[0][i] = sum[0][i - 1] + grid[0][i];
//         }

//         for (int i = 1; i < M; i++) {
//             for (int j = 1; j < N; j++) {
//                 sum[i][j] = Math.min(sum[i - 1][j], sum[i][j - 1]) + grid[i][j];
//             }
//         }

//         return sum[M - 1][N - 1];
//     }
// }