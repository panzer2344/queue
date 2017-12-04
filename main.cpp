#include <iostream>
#include "queue.h"

using namespace std;

void main() {
	TQueue<int> tq;
	int tmp;

	while (true) {
		cout << "1 = add, 0 = pop, -1 = exit: ";
		cin >> tmp;
		if (tmp == 1) {
			cout << "input: ";
			cin >> tmp;
			tq.push(tmp);
			continue;
		}
		if (tmp == 0) {
			cout << "element: " << tq.pop();
			continue;
		}
		if (tmp == -1) {
			break;
		}
	}
}