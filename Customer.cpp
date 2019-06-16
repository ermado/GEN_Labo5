// Customer.cpp
#include <sstream>
#include <vector>
#include "Statement.h"

using std::ostringstream;
using std::vector;

using namespace std;

string Customer::statement() {

    Statement st(this);
    return st.toString();
}