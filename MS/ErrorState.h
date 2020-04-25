// Milestone 5
// Name: Nicholas Defranco
// Student #: 106732183
// Course: OOP244 Winter 2019
// File: ErrorState.h

#ifndef AMA_ERRORSTATE_H
#define AMA_ERRORSTATE_H

#include <iostream>

namespace ama {

	class ErrorState {

		// resource holding the address of the
		// message
		char *msg;
		
		public:

		// optional single argument constructor
		explicit ErrorState(const char * = nullptr);

		// copy constructor and copy assignment
		// operator are illegal to perform with the
		// object
		ErrorState(const ErrorState&) = delete;
		ErrorState& operator=(const ErrorState&) = delete;

		// deallocates memory from old message
		// allocates memory for new message and copies
		// the argument passed by the client.
		ErrorState& operator=(const char *);

		// destructor - deallocates the message
		virtual ~ErrorState();

		// changes the message to argument passed
		// by client
		void message(const char *);

		// returns message if valid;
		const char *message() const;

		// returns true if msg is not nullptr
		operator bool() const;
	};

	// prints the error message stored in an object if valid
	std::ostream& operator<<(std::ostream&, const ErrorState&);

}

#endif
