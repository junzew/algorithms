#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// A request record
class request {
public:
	int start;
	int end;
};
// comparator function
bool finish_earlier(request r1, request r2) {
	return r1.end < r2.end;
}
// schedule n requests
int schedule(int n, vector<request> requests) {
	// sort the n requests in order of finishing time
	sort(requests.begin(), requests.end(), finish_earlier);
	int num_scheduled = 1; // number of scheduled requests
	int last_f = requests[0].end; // finishing time of most recent scheduled interval
	for (auto it = requests.begin()+1; it != requests.end(); it++) {
		if(it->start >= last_f) { 
		// compatible if start time > finish time of last schedule request
			num_scheduled++;
			last_f = it->end;
		}
	}
	return num_scheduled;
}
int main() {
	// Input format:
	// There are multiple test cases. Each test case starts with an integer n,
	// the number of requests to schedule. Each of the following n lines in the test case
	// contains 2 integers, si and fi, which are the start and finishing time for a request.
	// n = 0 indicates the end of input.
	// Output:
	// Maximum number of compatible scheduled requests
	// http://acm.hdu.edu.cn/showproblem.php?pid=2037
	int n;
	while(cin >> n && n) {
		vector<request> requests(n);
		for (int i = 0; i < n; i++) {
			cin >> requests[i].start >> requests[i].end;
		}
		cout << schedule(n, requests) << endl;
	}
	return 0;
}