#include <iostream>
#include <list>
#include <unordered_map>
#include <math.h>
using namespace std;

class User {
    int userId;
    string name;
    string email;
    string mobile;
    
    public:
        User(int uId, string name, string email, string mob) {
            this->userId = uId;
            this->name = name;
            this->email = email;
            this->mobile = mob;
        }

        int getId() {
            return userId;
        }
        
        string getDetails() {
            string detail = "User name:" + name + ", email:" + email + ", mobile:" + mobile;
            return detail;
        }
};

enum class ExpenseType {
    EQUAL = 1, EXACT = 2, PERCENT = 3
};

class Split {
    protected:
        double amount;
        User* paidTo;
    public:
        Split(User* user) {
            paidTo = user;
        }
        double getAmount() {
            return amount;
        }
        void setAmount(double amt) {
            amount = amt;
        }
        User* getPaidTo() {
            return paidTo;
        }
};

class EqualSplit: public Split {
    public:
        EqualSplit(User* user, double amt): Split(user) {
            amount = amt;
        }
};

class ExactSplit: public Split {
    public:
        ExactSplit(User* user, double amt): Split(user) {
            amount = amt;
        }
};

class PercentSplit: public Split {
    double percent;
    public:
        PercentSplit(User* user, double perc): Split(user) {
            percent = perc;
        }
        double getPercent() {
            return percent;
        }
};

class ExpenseMetadata {
    string title;
    string description;
    string imgUrl;

    public:
        ExpenseMetadata(string t, string d, string img) {
            title = t;
            description = d;
            imgUrl = img;
        }
};

class Expense {
    protected:
        list<Split*> splits;
        User* owner;
        double amount;
        int expId;
        ExpenseMetadata* metadata;
        ExpenseType expenseType;

    public:
        virtual bool validateExpense(list<Split*> sp, double amt) = 0;
};

class EqualExpense: public Expense {
    public:
        EqualExpense(list<Split*> sp, User* user, double amt, int id, ExpenseMetadata* meta) {
            splits = sp;
            owner = user;
            amount = amt;
            expId = id;
            metadata = meta;
            expenseType = ExpenseType::EQUAL;
        }

        bool validateExpense(list<Split*> splits, double amt) {
            double splitAmt = 0;
            double finalAmt = 0;

            for(Split* sp: splits) {
                if(splitAmt == 0)
                    splitAmt = sp->getAmount();
                
                if(splitAmt != sp->getAmount()) return false;
                finalAmt += sp->getAmount();
            }

            if(finalAmt != amt) return false;

            return true;
        }
};

class ExactExpense: public Expense {
    public:
        ExactExpense(list<Split*> sp, User* user, double amt, int id, ExpenseMetadata* meta) {
            splits = sp;
            owner = user;
            amount = amt;
            expId = id;
            metadata = meta;
            expenseType = ExpenseType::EXACT;
        }

        bool validateExpense(list<Split*> splits, double amt) {
            double finalAmt = 0;

            for(Split* sp: splits) {
                finalAmt += sp->getAmount();
            }

            if(finalAmt != amt) return false;

            return true;
        }
};

class PercentExpense: public Expense {
    public:
        PercentExpense(list<Split*> sp, User* user, double amt, int id, ExpenseMetadata* meta) {
            splits = sp;
            owner = user;
            amount = amt;
            expId = id;
            metadata = meta;
            expenseType = ExpenseType::PERCENT;
        }
        bool validateExpense(list<Split*> splits, double amt) {
            double splitAmt = 0;
            double finalAmt = 0;
            double finalPercent = 0.0;

            for(Split* sp: splits) {
                PercentSplit* ps = (PercentSplit*)sp;
                if(splitAmt == 0)
                    splitAmt = ps->getAmount();
                
                if(splitAmt != ps->getAmount()) return false;
                finalAmt += ps->getAmount();
                finalPercent += ps->getPercent();
            }

            if(finalAmt != amt || finalPercent != 100.0) return false;

            return true;
        }
};

class SplitWise {
    list<Expense*> expenses;
    unordered_map<int,User*> userSheet;
    unordered_map<int,unordered_map<int, double>> balanceSheet;

    Expense* createExpense(User* user, double amount, list<Split*> splits, ExpenseMetadata* metadata, int id, ExpenseType eType) {
        Expense* exp;
        switch (eType) {
            case ExpenseType::EQUAL: {
                int splitSize = splits.size();
                double splitAmt = round(amount/(splitSize*1.0));
                for(Split* sp: splits) {
                    sp->setAmount(splitAmt);
                }
                splits.front()->setAmount(splitAmt + (amount - splitAmt*splitSize));
                exp = new EqualExpense(splits, user, amount, id, metadata);
                break;
            }
            case ExpenseType::EXACT: {
                exp = new ExactExpense(splits, user, amount, id, metadata);
                break;
            }
            case ExpenseType::PERCENT: {
                int splitSize = splits.size();
                for(Split* sp: splits) {
                    PercentSplit* split = (PercentSplit*)sp;
                    double currAmt = (split->getPercent()*amount)/100.0;
                    sp->setAmount(currAmt);
                }
                exp = new PercentExpense(splits, user, amount, id, metadata);
                break;
            }
            default:
                exp = NULL;
                break;
        }

        return exp;
    }

    public:
        void addExpense(User* user, double amount, list<Split*> splits, ExpenseMetadata* metadata, int id, ExpenseType eType) {
            bool isSuccess = true;
            Expense* expense = createExpense(user, amount, splits, metadata, id, eType);

            for(Split* split: splits) {
                balanceSheet[user->getId()][split->getPaidTo()->getId()] += split->getAmount();
                balanceSheet[split->getPaidTo()->getId()][user->getId()] -= split->getAmount();
            }

            expenses.push_back(expense);

            if(isSuccess) {
                cout<<"Expense added successfully\n";
            } else {
                cout<<"Error in adding expense\n";
            }
        }

        void addUser(User* user) {
            if(userSheet.find(user->getId()) == userSheet.end()) {
                userSheet[user->getId()] = user;
                balanceSheet[user->getId()] = {};
                cout<<user->getDetails()<<" created successfully\n";
            } else {
                cout<<"User already present\n";
            }
        }

        void showBalanceByUser(int uId) {
            if(balanceSheet.find(uId) == balanceSheet.end()) {
                cout<<"User is not present\n";
                return;
            }

            unordered_map<int, double> balances = balanceSheet[uId];

            for(auto balance: balances) {
                printBalance(uId, balance.first, balance.second);
            }
        }

        void showBalances() {
            for(auto row: balanceSheet) {
                int uId = row.first;
                unordered_map<int, double> balances = balanceSheet[uId];

                for(auto balance: balances) {
                    printBalance(uId, balance.first, balance.second);
                }
            }
        }

        void printBalance(int uId1, int uId2, double amt) {
            string paidBy = userSheet[uId1]->getDetails();
            string paidTo = userSheet[uId2]->getDetails();

            if(amt < 0) {
                cout<<paidBy<<" owes "<<paidTo<<" Rs."<<-amt<<" amount of money\n";
            } else if(amt > 0) {
                cout<<paidBy<<" is owed by "<<paidTo<<" Rs."<<amt<<" amount of money\n";
            } else {
                cout<<paidBy<<" and "<<paidTo<<" are balanced.\n";
            }
        }
};

int main() {
    User* u1 = new User(1, "Rohit", "rohit", "999");
    User* u2 = new User(2, "Mohit", "Mohit", "998");
    User* u3 = new User(3, "Sohit", "sohit", "997");
    User* u4 = new User(4, "Lohit", "lohit", "996");
    User* u5 = new User(5, "Pohit", "pohit", "995");

    SplitWise* splitWise = new SplitWise();

    splitWise->addUser(u1);
    splitWise->addUser(u2);
    splitWise->addUser(u3);
    splitWise->addUser(u4);
    splitWise->addUser(u5);

    // list<Split*> splits;

    // splits.push_back(new EqualSplit(u1,100));
    // splits.push_back(new EqualSplit(u2,50));
    // splits.push_back(new EqualSplit(u3,100));

    // splitWise->addExpense(u1, 100, splits, NULL, 1, ExpenseType::EQUAL);
    // splitWise->showBalances();

    // list<Split*> splits2;

    // splits2.push_back(new ExactSplit(u1,200));
    // splits2.push_back(new ExactSplit(u2,100));
    // splits2.push_back(new ExactSplit(u3,200));

    // splitWise->addExpense(u1, 500, splits2, NULL, 2, ExpenseType::EXACT);
    // splitWise->showBalances();


    list<Split*> splits3;

    splits3.push_back(new PercentSplit(u1,10));
    splits3.push_back(new PercentSplit(u2,20));
    splits3.push_back(new PercentSplit(u3,90));

    splitWise->addExpense(u1, 1000, splits3, NULL, 3, ExpenseType::PERCENT);
    splitWise->showBalances();

    return 0;
}