//***********************************************************************
// OOP244 Workshop 2: Dynamic Memory
// Filename:          Kingdom.h
// Date:	          2018/05/28
// Author:	          Sharan Shanmugaratnam
// Description:
// A workshop designed to help us with allocating memory at run-time 
// and deallocating that memory as soon as it is no longer required.
//***********************************************************************

#ifndef SICT_KINGDOM_H
#define SICT_KINGDOM_H

namespace sict {
	struct Kingdom {
		public:
			char m_name[34];
			int m_population;
	};
	void display(struct Kingdom a);
}

#endif