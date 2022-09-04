/*
    Imagine you have a call center with three levels of employees: respondents, manager and director. An incoming
    telephone call must be first allocated to a respondant who is free. If the respondant can't handle the call, he or
    she must escalate the call to a manager. If the manager is not free or not able to handle it, then the call should
    be escalated to a director.

    1. Design the classes and data structures for this problem.
    2. Implement a method `dispatchCall()` which assigns a call to the first available employee.
*/

#include <iostream>
#include <queue>

using namespace std;

enum Rank {
    RESPONDENT,
    MANAGER,
    DIRECTOR
};

class Call {
    private:
        Rank required_rank;
        string caller_name;
    public:
        Call() {
            required_rank = RESPONDENT;
            caller_name = "Generic";
        }

        Call(Rank required_rank) {
            this->required_rank = required_rank;
            caller_name = "Generic";
        }

        Call(string caller_name) {
            required_rank = RESPONDENT;
            this->caller_name = caller_name;
        }

        Call(Rank required_rank, string caller_name) {
            this->required_rank = required_rank;
            this->caller_name = caller_name;
        }

        string getCallerName() {
            return caller_name;
        }

        Rank getRequiredRank() {
            return required_rank;
        }

        void setCallerName(string new_caller_name) {
            caller_name = new_caller_name;
        }

        void setRequiredRank(Rank new_rank) {
            required_rank = new_rank;
        }
};

class Employee {
    private:
        int number;
        string name;
        float salary;
        bool is_free;
        Rank rank;
        Call current_call;

    public:
        Employee() {
            this->number = -1;
            this->name = "Generic";
            this->salary = -1;
            this->rank = RESPONDENT;
            this->is_free = true;
        }

        Employee(int number, string name, float salary, Rank rank) {
            this->number = number;
            this->name = name;
            this->salary = salary;
            this->rank = rank;
            this->is_free = true;
        }

        void setNumber(int number) {
            this->number = number;
        }

        void setName(string name) {
            this->name = name;
        }

        void setSalary(float salary) {
            this->salary = salary;
        }

        void setRank(Rank rank) {
            this->rank = rank;
        }

        void setAvailability(bool is_free) {
            this->is_free = is_free;
        }

        int getNumber() {
            return this->number;
        }

        string getName() {
            return this->name;
        }

        float setSalary() {
            return this->salary;
        }

        Rank getRank() {
            return this->rank;
        }

        bool getAvailability() {
            return this->is_free;
        }

        void assignCall(Call incoming_call) {
            this->current_call = incoming_call;
            setAvailability(false);
        }

        void endCall() {
            setAvailability(true);
        }

        void escalateCall() {
            // Implemmentation
        }
};

class Respondent : public Employee {
    public:
        Respondent(int number, string name, float salary, Rank rank) {
            setNumber(number);
            setName(name);
            setSalary(salary);
            setRank(RESPONDENT);
            setAvailability(true);
        }

        Respondent() {
            setNumber(-1);
            setName("Generic");
            setSalary(-1);
            setRank(RESPONDENT);
            setAvailability(true);
        }
};

class Manager : public Employee {
    public:
        Manager(int number, string name, float salary, Rank rank) {
            setNumber(number);
            setName(name);
            setSalary(salary);
            setRank(MANAGER);
            setAvailability(true);
        }

        Manager() {
            setNumber(-1);
            setName("Generic");
            setSalary(-1);
            setRank(MANAGER);
            setAvailability(true);
        }
};

class Director : public Employee {
    public:
        Director(int number, string name, float salary, Rank rank) {
            setNumber(number);
            setName(name);
            setSalary(salary);
            setRank(DIRECTOR);
            setAvailability(true);
        }

        Director() {
            setNumber(-1);
            setName("Generic");
            setSalary(-1);
            setRank(DIRECTOR);
            setAvailability(true);
        }
};

class CallCenter {
    private:
        static constexpr int NUM_RESPONDENTS = 10;
        static constexpr int NUM_MANAGERS = 2;
        static constexpr int NUM_DIRECTORS = 1;
        Respondent respondents[NUM_RESPONDENTS];
        Manager managers[NUM_MANAGERS];
        Director director;
        queue<Call> call_queue; // For calls that cannot be allocated at the moment
    public:
        CallCenter() {}

        bool dispatchCall(Call incoming_call) {
            if (incoming_call.getRequiredRank() == RESPONDENT) {
                for (int i = 0; i < NUM_RESPONDENTS; i++) {
                    if (respondents[i].getAvailability()) {
                        respondents[i].assignCall(incoming_call);
                        return true;    // The call was succesfully dispatched
                    }
                }

                // If all respondents are busy, the required rank is increased to manager
                incoming_call.setRequiredRank(MANAGER);
            }

            if (incoming_call.getRequiredRank() == MANAGER) {
                for (int i = 0; i < NUM_MANAGERS; i++) {
                    if (managers[i].getAvailability()) {
                        managers[i].assignCall(incoming_call);
                        return true;    // The call was succesfully dispatched
                    }
                }

                incoming_call.setRequiredRank(DIRECTOR);
            }

            if (incoming_call.getRequiredRank() == DIRECTOR) {
                if (director.getAvailability()) {
                    director.assignCall(incoming_call);
                    return true;    // The call was succesfully dispatched
                }
            }

            // If the method reaches this point, it means the call could not be dispatched to any available employee
            // The call will need to be placed in a waiting queue
            call_queue.push(incoming_call);

            return false;   // The call was not dispatched, it's in the waiting queue
        }
};

int main() {

}
