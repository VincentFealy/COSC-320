#ifndef PROCESSREQUESTRECORD_CLASS
#define PROCESSREQUESTRECORD_CLASS

#include <iostream>
#include <string>

using namespace std;

class procReqRec
{
	public:
		// default constructor
		procReqRec()
			{name = " ";
			priority = 0;}
		
	

		// constructor
		procReqRec(const string& nm, int p){
			name = nm;
			priority = p;
		}

		// access functions
		int getPriority(){
			return priority;
		}
		string getName(){
			return name;
		}

		// update functions
		void setPriority(int p){
			priority = p;
		}

		void setName(const string& nm){
			name = nm;
		}

		// for maintenance of a minimum priority queue
		friend bool operator> (const procReqRec& left, const procReqRec& right){
			if(right.priority > left.priority){
				return true;
			}
			else{
				return false;
			}
		}

		// output a process request record in the format
		//   name: priority
		friend ostream& operator<< (ostream& ostr, const procReqRec& obj){
			ostr << obj.name << " " << obj.priority;
			return ostr;
		}

	private:
		string name;	// process name
		int priority;	// process priority
};

#endif	// PROCESSREQUESTRECORD_CLASS