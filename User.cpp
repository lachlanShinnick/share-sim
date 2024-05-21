#include "User.h"

// Constructor
User::User() : is_logged_in(false), user_id(0), user_role(""), active_year(2024) {}

// Virtual destructor
User::~User() {}

// Function Returning User Role
std::string User::GetUserRole() const {
    return user_role;
}

// Function Setting User Role
void User::SetUserRole(const std::string& role) {
    user_role = role;
}

// Getters and Setters for other member variables
bool User::IsLoggedIn() const {
    return is_logged_in;
}

void User::SetLoggedIn(bool loggedIn) {
    is_logged_in = loggedIn;
}

unsigned int User::GetUserId() const {
    return user_id;
}

void User::SetUserId(unsigned int id) {
    user_id = id;
}

int User::GetActiveYear() const {
    return active_year;
}

void User::SetActiveYear(int year) {
    active_year = year;
}
