// Vincent Fealy
// 4/5/23

#include "preqrec.h"
#include "d_except.h"
#include "d_heap.h"
#include "d_pqueue.h"
#include <string>
#include <ctime>
#include <iostream>
#include <cstdlib>
using namespace std;

int main(){

	procReqRec pa ("Process A", rand() % 39 + 1);
	procReqRec pb ("Process B", rand() % 39 + 1);
	procReqRec pc ("Process C", rand() % 39 + 1);
	procReqRec pd ("Process D", rand() % 39 + 1);
	procReqRec pe ("Process E", rand() % 39 + 1);
	procReqRec pf ("Process F", rand() % 39 + 1);
	procReqRec pg ("Process G", rand() % 39 + 1);
	procReqRec ph ("Process H", rand() % 39 + 1);
	procReqRec pi ("Process I", rand() % 39 + 1);
	procReqRec pj ("Process J", rand() % 39 + 1);

	miniPQ<procReqRec> mpq;

	mpq.push(pa);
	mpq.push(pb);
	mpq.push(pc);
	mpq.push(pd);
	mpq.push(pe);
	mpq.push(pf);
	mpq.push(pg);
	mpq.push(ph);
	mpq.push(pi);
	mpq.push(pj);

	while(!mpq.empty()){
		cout << mpq.top() << endl;
		mpq.pop();
	}

	return 0;
}