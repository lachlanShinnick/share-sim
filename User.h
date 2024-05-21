#ifndef USER_H
#define USER_H

#include <string>

class User {
protected:
    bool is_logged_in;          // Indicates if the user is logged in
    unsigned int user_id;       // Unique User ID
    std::string user_role;      // String indicating the role of the user
    int active_year;            // The current active year for the user

public:
    // Constructor
    User();

    // Virtual destructor
    virtual ~User();

    // Function Returning User Role
    std::string GetUserRole() const;

    // Function Setting User Role
    void SetUserRole(const std::string& role);

    // Getters and Setters for other member variables
    bool IsLoggedIn() const;
    void SetLoggedIn(bool loggedIn);

    unsigned int GetUserId() const;
    void SetUserId(unsigned int id);

    int GetActiveYear() const;
    void SetActiveYear(int year);
};

#endif // USER_H
