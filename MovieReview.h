#ifndef MOVIEREVIEW_H
#define MOVIEREVIEW_H
#include <string>
#include "User.h"

class MovieReview
{
private:
    std::string userName; // who writes the review
    float rating;
    std::string reviewText;

public:
    MovieReview(std::string userName,
                float rating,
                std::string reviewText);
    ~MovieReview();

    std::string getUserName();
    void setUserName(std::string userName);
    float getRating();
    void setRating(float rating);
};

#endif