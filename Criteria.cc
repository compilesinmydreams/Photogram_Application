#include "Criteria.h"


ostream& operator<<(ostream& os, const Criteria& criteria) {
    criteria.print(os);
    return os;
}
Cat_Criteria::Cat_Criteria(const string& category): category(category) {}


Date_Criteria::Date_Criteria(const Date& start, const Date& end) : start(start), end(end) {}
CandD_Criteria::CandD_Criteria(const Date& start, const Date& end, const string& category): Cat_Criteria(category), Date_Criteria(start, end) {}

