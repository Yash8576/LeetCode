class Heap(){
    public:
        vector<int> heap;

        int peek(){
            return heap[0];
        }

        int pop(){
            if (heap.empty()) {
                return -1;
            }
            int root = heap[0];
            heap[0] = heap.back();
            heap.pop_back();
            if (!heap.empty()) {
                heapify(0);
            }
            return root;
        }

        void push(int val){ 
            heap.push_back(val);
            int i = heap.size() - 1;
            while (i > 0) {
                int parent = (i - 1) / 2;
                if (heap[i] < heap[parent]) {
                    swap(heap[i], heap[parent]);
                    i = parent;
                } else {
                    break;
                }
            }
        }
    
        void heapify(int i){
            int smallest = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            
            if (left < heap.size() && heap[left] < heap[smallest]) {
                smallest = left;
            }
            if (right < heap.size() && heap[right] < heap[smallest]) {
                smallest = right;
            }
            
            if (smallest != i) {
                swap(heap[i], heap[smallest]);
                heapify(smallest);
            }
        }
};
