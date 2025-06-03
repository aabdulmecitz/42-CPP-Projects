#include <iostream>
#include <string>

class Contact{
    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phonenum;
        std::string darkest_scret;
    public:
        void setFirstName(const std::string& name);
        void setLastName(const std::string& name);
        void setNickname(const std::string& name);
        void setPhoneNum(const std::string& num);
        void setDarkestSecret(const std::string& secret);
        std::string getFirstName() const;
        std::string getLastName() const;
        std::string getNickname() const;
        std::string getPhoneNum() const;
        std::string getDarkestSecret() const;
};