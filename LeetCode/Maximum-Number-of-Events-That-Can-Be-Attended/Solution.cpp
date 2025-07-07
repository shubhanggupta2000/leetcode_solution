class Solution {
    public int maxEvents(int[][] events) {
        Arrays.sort(events, (a, b) -> a[0] - b[0]);

        PriorityQueue<Integer> pq = new PriorityQueue<>();

        int count = 0;
        int day = 1;
        int i = 0;
        while(i < events.length || !pq.isEmpty()) {
            // Add all for current day
            while(i < events.length && events[i][0] <= day) {               
                pq.offer(events[i][1]);
                i++;
            }
            // Remove expired
            while(!pq.isEmpty() && pq.peek() < day) {
                pq.poll();
            }

            // If possible use the event with smallest end day
            if(!pq.isEmpty()) {
                pq.poll();
                count++;
            }

            // Move to next day
            day++;
        }

        return count;
    }
}