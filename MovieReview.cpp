#include "MovieReview.h"

MovieReview::MovieReview(std::string userName, float rating, std::string reviewText)
{
    this->userName = userName;
    this->rating = rating;
    this->reviewText = reviewText;
}

float MovieReview::getRating()
{
    return this->rating;
}

void MovieReview::setRating(float rating)
{
    this->rating = rating;
}

std::string MovieReview::getUserName()
{
    return this->userName;
}

void MovieReview::setUserName(std::string userName)
{
    this->userName = userName;
}