#ifndef MOVIEREVIEW_H
#define MOVIEREVIEW_H
#include <string>
#include "User.h"

class MovieReview
{
private:
    User *user;
    float rating;
    std::string reviewText;
    std::string movieName;

public:
    MovieReview(User *user,
                float rating,
                std::string reviewText,
                std::string name);
    ~MovieReview();

    User *getUser();
    void setUser(User *user);
    float getRating();
    void setRating(float rating);
    void setName(std::string name);
    std::string getName();
    void setReviewText(std::string reviewText);
    std::string getReviewText();
    void printReview();
};

#endif