#ifndef CRITERIA_H
#define CRITERIA_H
#include "Photo.h"
class Criteria{
    friend ostream& operator<<(ostream&, const Criteria&);
    public:
        virtual bool matches(const Photo&)const = 0;
        virtual void print(ostream&) const = 0;
};

class Cat_Criteria : virtual public Criteria {
    private:
        string category;
    public:
        Cat_Criteria(const string& category);
        bool matches(const Photo& photo) const {
            return photo.getCategory() == category;
        }
        void print(std::ostream& os) const {
            os << "Category Criteria: " << category;
        }
};

class Date_Criteria : virtual public Criteria {
private:
    Date start;
    Date end;
public:
    Date_Criteria(const Date& start, const Date& end);
    bool matches(const Photo& photo) const{
        return photo.getDate() >= start && photo.getDate() <= end;
    }
    void print(ostream& os) const{
        os << "Start Date  " << start << " - End Date " << end;
    }
};
class CandD_Criteria : public Cat_Criteria, public Date_Criteria {
public:
    CandD_Criteria(const Date& start, const Date& end, const string& category);
    virtual bool matches(const Photo& photo) const{
        return Cat_Criteria::matches(photo) && Date_Criteria::matches(photo);
    }
    virtual void print(ostream& os) const {
        os << "Category is ";
        Cat_Criteria::print(os);
        os << "Dates are: ";
        Date_Criteria::print(os);
    }
};



#endif
