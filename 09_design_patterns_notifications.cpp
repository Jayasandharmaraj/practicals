#include <iostream>
#include <vector>
#include <memory>
#include <string>
using namespace std;
class Observer {public: virtual void notify(const string& message)=0; virtual ~Observer()=default;};
class EmailNotification:public Observer {
    string email;
public: explicit EmailNotification(string e):email(std::move(e)){}
    void notify(const string& message)override{cout<<"Email sent to "<<email<<": "<<message<<endl;}
};
class SMSNotification:public Observer {
    string phoneNumber;
public: explicit SMSNotification(string number):phoneNumber(std::move(number)){}
    void notify(const string& message)override{cout<<"SMS sent to "<<phoneNumber<<": "<<message<<endl;}
};
class NotificationFactory {
public: static shared_ptr<Observer> createNotification(const string& type,const string& receiver){
    if(type=="EMAIL") return make_shared<EmailNotification>(receiver);
    if(type=="SMS") return make_shared<SMSNotification>(receiver);
    return nullptr;
}};
class EventManager {
    vector<shared_ptr<Observer>> observers;
    EventManager()=default;
public:
    EventManager(const EventManager&)=delete; EventManager& operator=(const EventManager&)=delete;
    static EventManager& getInstance(){static EventManager instance;return instance;}
    void subscribe(shared_ptr<Observer> observer){if(observer) observers.push_back(std::move(observer));}
    void triggerEvent(const string& message){cout<<"\nEvent Triggered: "<<message<<endl<<"Sending Notifications...\n";for(auto& observer:observers) observer->notify(message);}
};
int main(){
    EventManager& manager=EventManager::getInstance();
    auto emailUser=NotificationFactory::createNotification("EMAIL","student@gmail.com");
    auto smsUser=NotificationFactory::createNotification("SMS","9876543210");
    manager.subscribe(emailUser); manager.subscribe(smsUser);
    manager.triggerEvent("University examination starts tomorrow!");
    return 0;
}
