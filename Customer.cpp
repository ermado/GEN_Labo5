// Customer.cpp
#include <sstream>
#include <vector>
#include "Customer.h"
#include "Statement.h"

using std::ostringstream;
using std::vector;

using namespace std;

string Customer::statement()
{
    Statement statement(this);

    return statement.toString();
}