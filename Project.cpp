#include <iostream>
#include <string>
using namespace std;

// Constants
const int MAX_MEMBERS = 100;
const double PERSONAL_TRAINER_FEE = 1000;
const double LOCKER_FEE = 500;
const double NUTRITION_AND_WORKOUT_COST = 500;
const double FRIEND_DISCOUNT_PERCENTAGE = 0.1;

// Membership Plans
class MembershipPlan {  // Encapsulation: Class wrapping data and methods
public:
    string name;
    double monthlyCost;

    MembershipPlan(string n, double mCost) {
        name = n;
        monthlyCost = mCost;
    }

    double applyDiscount() {
        if (name == "Premium") {
            return 0.9 * monthlyCost;  // Apply a 10% discount for Premium plan
        }
        return monthlyCost;
    }
};

// Member
class Member {  // Encapsulation: Class wrapping data and methods
public:
    string name;
    int age;
    string contactNumber;
    MembershipPlan* plan;
    bool hasPersonalTrainer;
    bool hasLocker;
    bool hasNutritionAndWorkout;

    Member(string name, int age, string contactNumber, MembershipPlan* plan) {
        this->name = name;
        this->age = age;
        this->contactNumber = contactNumber;
        this->plan = plan;
        hasPersonalTrainer = false;
        hasLocker = false;
        hasNutritionAndWorkout = false;
    }

    double calculateTotalCost() {
        double totalCost = plan->applyDiscount();

        if (hasPersonalTrainer) {
            totalCost += PERSONAL_TRAINER_FEE;
        }

        if (hasLocker) {
            totalCost += LOCKER_FEE;
        }

        if (hasNutritionAndWorkout) {
            totalCost += NUTRITION_AND_WORKOUT_COST;
        }

        return totalCost;
    }
};

// Gym Membership Management System
class GymMembershipManagementSystem {  // Encapsulation: Class wrapping data and methods
private:
    Member* members[MAX_MEMBERS];
    int membersCount;
    MembershipPlan* plans[3];

public:
    GymMembershipManagementSystem() {
        membersCount = 0;
        plans[0] = new MembershipPlan("Basic", 2000);
        plans[1] = new MembershipPlan("Standard", 4000);
        plans[2] = new MembershipPlan("Premium", 6000);
    }

    void displayPlans() {
        cout << "Choose a Membership Plan:" << endl;
        for (int i = 0; i < 3; i++) {
            cout << i + 1 << ". " << plans[i]->name << " - Rs" << plans[i]->monthlyCost << endl;
        }
    }

    int getPlanChoice() {
        int choice;
        cout << "Enter the number corresponding to your choice: ";
        cin >> choice;
        return choice;
    }

    void displayBenefits(MembershipPlan* plan) {
        cout << "Membership Benefits for " << plan->name << " Plan:" << endl;
        if (plan->name == "Basic") {
            cout << "- Access to basic gym facilities" << endl;
            cout << "- Personalized workout plan: Starter Workout" << endl;
        } else if (plan->name == "Standard") {
            cout << "- Access to gym facilities and group classes" << endl;
            cout << "- Personalized workout plan: Intermediate Workout" << endl;
        } else if (plan->name == "Premium") {
            cout << "- Unlimited access to all facilities, group classes, and personal training sessions" << endl;
            cout << "- Personalized workout plan: Advanced Workout" << endl;
        }
    }

    void displayWeeklyGymRoutine(MembershipPlan* plan, int age) {
        cout << "Weekly Gym Routine for " << plan->name << " Plan:" << endl;
        if (age < 18) {
            cout << "- Monday: Light Cardio" << endl;
            cout << "- Wednesday: Stretching" << endl;
            cout << "- Friday: Bodyweight Exercises" << endl;
        } else if (age >= 18 && age < 28) {
            cout << "- Monday: Cardio and Stretching" << endl;
            cout << "- Wednesday: Strength Training" << endl;
            cout << "- Friday: Full-body Workout" << endl;
        } else if (age >= 28 && age < 36) {
            cout << "- Monday: Cardio and Strength Training" << endl;
            cout << "- Wednesday: High-Intensity Interval Training (HIIT)" << endl;
            cout << "- Friday: Core Exercises" << endl;
        } else if (age >= 36 && age < 45) {
            cout << "- Monday: Cardio and Strength Training" << endl;
            cout << "- Wednesday: Functional Training" << endl;
            cout << "- Friday: Flexibility Exercises" << endl;
        } else {
            cout << "- Monday: Low-Impact Cardio" << endl;
            cout << "- Wednesday: Gentle Strength Training" << endl;
            cout << "- Friday: Balance and Stability Exercises" << endl;
        }
    }

    void displayWeeklyFoodRoutine(MembershipPlan* plan) {
        cout << "Weekly Food Routine for " << plan->name << " Plan:" << endl;
        if (plan->name == "Basic") {
            cout << "- Balanced meals with a focus on lean proteins, whole grains, and vegetables" << endl;
        } else if (plan->name == "Standard") {
            cout << "- Balanced meals with a mix of proteins, carbohydrates, and healthy fats" << endl;
            cout << "- Adequate hydration throughout the day" << endl;
        } else if (plan->name == "Premium") {
            cout << "- Personalized nutrition plan based on individual goals and preferences" << endl;
            cout << "- Regular consultations with a nutritionist" << endl;
            cout << "- Hydration plan tailored to individual needs" << endl;
        }
    }

    void addMember() {
        string name;
        int age;
        string contactNumber;

        cout << "Enter Member Details:" << endl;
        cout << "Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Age: ";
        cin >> age;

        cout << "Contact Number: ";
        cin >> contactNumber;

        displayPlans();
        int choice = getPlanChoice();

        if (choice < 1 || choice > 3) {
            cout << "Invalid choice. Exiting program." << endl;
            return;
        }

        MembershipPlan* selectedPlan = plans[choice - 1];
        Member* newMember = new Member(name, age, contactNumber, selectedPlan);

        cout << "You selected the " << selectedPlan->name << " Plan." << endl;
        displayBenefits(selectedPlan);
        displayWeeklyGymRoutine(selectedPlan, age);
        displayWeeklyFoodRoutine(selectedPlan);

        char personalTrainer;
        cout << "Do you want a personal trainer? (y/n): ";
        cin >> personalTrainer;
        if (tolower(personalTrainer) == 'y') {
            newMember->hasPersonalTrainer = true;
        }

        char locker;
        cout << "Do you want a locker? (y/n): ";
        cin >> locker;
        if (tolower(locker) == 'y') {
            newMember->hasLocker = true;
        }

        char nutritionAndWorkout;
        cout << "Do you want nutrition tracking and a personalized workout plan? (y/n): ";
        cin >> nutritionAndWorkout;
        if (tolower(nutritionAndWorkout) == 'y') {
            newMember->hasNutritionAndWorkout = true;
        }

        double totalCost = newMember->calculateTotalCost();
        cout << "Total Cost: Rs" << totalCost << endl;

        members[membersCount++] = newMember;

        cout << "Member added successfully!" << endl;
    }

    void displayMembers() {
        cout << "Current Members:" << endl;
        for (int i = 0; i < membersCount; i++) {
            cout << i + 1 << ". " << members[i]->name << endl;
        }
    }

    void displayMemberDetails(int index) {
        if (index < 1 || index > membersCount) {
            cout << "Invalid member index." << endl;
            return;
        }

        Member* member = members[index - 1];
        cout << "Member Details:" << endl;
        cout << "Name: " << member->name << endl;
        cout << "Age: " << member->age << endl;
        cout << "Contact Number: " << member->contactNumber << endl;
        cout << "Membership Plan: " << member->plan->name << endl;
        cout << "Personal Trainer: " << (member->hasPersonalTrainer ? "Yes" : "No") << endl;
        cout << "Locker: " << (member->hasLocker ? "Yes" : "No") << endl;
        cout << "Nutrition and Workout Plan: " << (member->hasNutritionAndWorkout ? "Yes" : "No") << endl;
    }

    void displayFitnessTracker(int index) {
        if (index < 1 || index > membersCount) {
            cout << "Invalid member index." << endl;
            return;
        }

        Member* member = members[index - 1];
        cout << "Fitness Tracker for " << member->name << ":" << endl;
        cout << "Blood Pressure: ";
        checkBloodPressure(member->age);
        cout << "Calories Burned: ";
        calculateCaloriesBurned(member->age, member->plan->name);
        cout << "Steps Walked: ";
        calculateStepsWalked();
        cout << "Body Temperature: ";
        checkBodyTemperature();
    }

    void checkBloodPressure(int age) {
        if (age < 18) {
            cout << "Low" << endl;
        } else if (age >= 18 && age < 28) {
            cout << "Normal" << endl;
        } else if (age >= 28 && age < 36) {
            cout << "High" << endl;
        } else if (age >= 36 && age < 45) {
            cout << "High" << endl;
        } else {
            cout << "High" << endl;
        }
    }

    void calculateCaloriesBurned(int age, string planName) {
        int calories = 0;
        if (planName == "Basic") {
            calories = 500;
        } else if (planName == "Standard") {
            calories = 800;
        } else if (planName == "Premium") {
            calories = 1200;
        }
        cout << calories << " calories" << endl;
    }

    void calculateStepsWalked() {
        int steps = rand() % 10001;
        cout << steps << " steps" << endl;
    }

    void checkBodyTemperature() {
        double temperature = 98.6 + (rand() % 3) - 1;
        cout << temperature << " °F" << endl;
    }
};

int main() {
    GymMembershipManagementSystem system;

    while (true) {
        cout << "Gym Membership Management System" << endl;
        cout << "1. Add Member" << endl;
        cout << "2. Display Members" << endl;
        cout << "3. Display Member Details" << endl;
        cout << "4. Display Fitness Tracker" << endl;
        cout << "5. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                system.addMember();
                break;
            case 2:
                system.displayMembers();
                break;
            case 3: {
                int index;
                cout << "Enter member index: ";
                cin >> index;
                system.displayMemberDetails(index);
                break;
            }
            case 4: {
                int index;
                cout << "Enter member index: ";
                cin >> index;
                system.displayFitnessTracker(index);
                break;
            }
            case 5:
                cout << "Exiting program..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    }
}