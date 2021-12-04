// Queue using array
// TC O(q) SC O(q)  Where q is the number of queries
class Queue{
public:
	int qfront,rear,size,qsize;
	int q[100010];
	Queue()
	{
		// Initialize the queue with 0 elements
		rear=0;
		qfront=0;
		size=0;
		qsize=100010;
	}
	// Function to check if the queue is empty
	bool isEmpty()
	{
		if(qfront==rear)
			return true;
		return false;
	}
	void enqueue(int data)
	{
		// Push the current element in the queue
		q[rear] =data;
		rear=rear+1;
		// Increase the value of size
		size++;
	}

	int dequeue(){
		// Check if the queue is empty
		if(isEmpty())
			return -1;
		int ans =q[qfront];
		qfront++;
		size--;
		if(qfront==rear){
			qfront=0;
			rear=0;
		}
		return ans;
	}

	int front(){
		// Check if the queue is empty
		if(isEmpty())
			return -1;

		// Return the element at front
		return q[qfront];
	}
};