#include "Contact.hpp"

void Contact::setFirstName(const std::string &name)
{
    first_name = name;
}

void Contact::setLastName(const std::string &name)
{
    last_name = name;
}

void Contact::setNickname(const std::string &name)
{
    nickname = name;
}

void Contact::setPhoneNum(const std::string &num)
{
    phonenum = num;
}

void Contact::setDarkestSecret(const std::string &secret)
{
    darkest_scret = secret;
}

std::string Contact::getFirstName() const
{
    return first_name;
}

std::string Contact::getLastName() const
{
    return last_name;
}

std::string Contact::getNickname() const
{
    return nickname;
}

std::string Contact::getPhoneNum() const
{
    return phonenum;
}

std::string Contact::getDarkestSecret() const
{
    return darkest_scret;
}
