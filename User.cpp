#include "User.h"

// Constructor
User::User() : is_logged_in(0), user_id(0), user_role(""), active_year(2024) {}

// Virtual destructor
User::~User() {}

// Function Returning User Role
std::string User::GetUserRole() {
    return user_role;
}

// Function Setting User Role
void User::SetUserRole(const std::string& role) {
    user_role = role;
}

// Getters and Setters for other member variables
int User::IsLoggedIn() const {
    return is_logged_in;
}

void User::SetLoggedIn(int loggedIn) {
    is_logged_in = loggedIn;
}

int User::GetUserId() const {
    return user_id;
}

void User::SetUserId(int id) {
    user_id = id;
}

int User::GetActiveYear() const {
    return active_year;
}

void User::SetActiveYear(int year) {
    active_year = year;
}
