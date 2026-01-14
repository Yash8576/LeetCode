class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        int n = (int)squares.size();
        if (n == 0) {
            return 0.0;
        }
        struct Event {
            double y;
            int delta;
            int l;
            int r;
        };
        struct SegTree {
            vector<int> cover;
            vector<double> coveredLen;
            vector<double> xs;
            int m;
            SegTree(vector<double>& xcoords) : xs(xcoords) {
                m = (int)xs.size() - 1;
                if (m <= 0) {
                    return;
                }
                cover.assign(4 * m + 10, 0);
                coveredLen.assign(4 * m + 10, 0.0);
            }
            void pull(int node, int start, int end) {
                if (cover[node] > 0) {
                    coveredLen[node] = xs[end + 1] - xs[start];
                } else {
                    if (start == end) {
                        coveredLen[node] = 0.0;
                    } else {
                        coveredLen[node] = coveredLen[2 * node] + coveredLen[2 * node + 1];
                    }
                }
            }
            void update(int node, int start, int end, int l, int r, int delta) {
                if (l > end || r < start) {
                    return;
                }
                if (l <= start && end <= r) {
                    cover[node] += delta;
                    pull(node, start, end);
                    return;
                }
                int mid = (start + end) / 2;
                update(2 * node, start, mid, l, r, delta);
                update(2 * node + 1, mid + 1, end, l, r, delta);
                pull(node, start, end);
            }
            double currentCovered() {
                if (m <= 0) {
                    return 0.0;
                }
                return coveredLen[1];
            }
        };
        vector<double> xs;
        xs.reserve(n * 2);
        double minY = 1e18;
        for (int i = 0; i < n; i++) {
            double x1 = squares[i][0];
            double y1 = squares[i][1];
            double len = squares[i][2];
            double x2 = x1 + len;
            xs.push_back(x1);
            xs.push_back(x2);
            minY = min(minY, y1);
        }
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        if ((int)xs.size() < 2) {
            return minY;
        }
        auto buildEvents = [&]() -> vector<Event> {
            vector<Event> events;
            events.reserve(n * 2);
            for (int i = 0; i < n; i++) {
                double x1 = squares[i][0];
                double y1 = squares[i][1];
                double len = squares[i][2];
                double x2 = x1 + len;
                double y2 = y1 + len;
                if (x1 >= x2 || y1 >= y2) {
                    continue;
                }
                int ix1 = (int)(lower_bound(xs.begin(), xs.end(), x1) - xs.begin());
                int ix2 = (int)(lower_bound(xs.begin(), xs.end(), x2) - xs.begin());
                if (ix2 <= ix1) {
                    continue;
                }
                events.push_back({y1, +1, ix1, ix2 - 1});
                events.push_back({y2, -1, ix1, ix2 - 1});
            }
            sort(events.begin(), events.end(), [&](const Event& a, const Event& b) {
                return a.y < b.y;
            });
            return events;
        };
        auto sweepTotalArea = [&]() -> double {
            vector<Event> events = buildEvents();
            if (events.empty()) {
                return 0.0;
            }
            SegTree st(xs);
            double area = 0.0;
            double prevY = events[0].y;
            int i = 0;
            while (i < (int)events.size()) {
                double y = events[i].y;
                area += (y - prevY) * st.currentCovered();
                while (i < (int)events.size() && events[i].y == y) {
                    if (st.m > 0) {
                        st.update(1, 0, st.m - 1, events[i].l, events[i].r, events[i].delta);
                    }
                    i++;
                }
                prevY = y;
            }
            return area;
        };
        double totalArea = sweepTotalArea();
        if (totalArea <= 0.0) {
            return minY;
        }
        double target = totalArea / 2.0;
        vector<Event> events = buildEvents();
        SegTree st(xs);
        double accumulated = 0.0;
        double prevY = events[0].y;
        int i = 0;
        while (i < (int)events.size()) {
            double y = events[i].y;
            double coveredX = st.currentCovered();
            double slabH = y - prevY;
            if (slabH > 0.0 && coveredX > 0.0) {
                double slabArea = slabH * coveredX;
                if (accumulated + slabArea >= target) {
                    double need = target - accumulated;
                    return prevY + need / coveredX;
                }
                accumulated += slabArea;
            }

            while (i < (int)events.size() && events[i].y == y) {
                if (st.m > 0) {
                    st.update(1, 0, st.m - 1, events[i].l, events[i].r, events[i].delta);
                }
                i++;
            }
            prevY = y;
        }

        return prevY;
    }
};