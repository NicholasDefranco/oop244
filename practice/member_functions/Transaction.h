class Transaction {

	int acct;
	char type;
	double amount;
	
	public:
	void enter();
	void display() const;

};

// data members are private 
// client code cannot directly access data members that represent its state
// client code cannot also directly access internally directed member function
//
// client code can only access member functions that behave as indirect links
// to the data members(also known as communication links)
//
// By creating indirect links, we are to validate incoming data from the 
// client which may request to modify the data members. If the incoming 
// data is invalid we can reject it and not allow the data member to 
// get reassigned based off args passed by the client code. 
