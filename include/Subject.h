#ifndef SUBJECT_H
#define SUBJECT_H

/**
 * @class Subject
 * @brief Abstract Subject base class managing observer registrations and notifications 
 * 
 * @details 
 * GoF Role: Subject 
 * Ownership policy: Stores non-owning pointers in observers, therefore it does not delete the observers but simply detaches them 
 * and allowing them to exist without any constraints other than those imposed by the Composite design pattern  
 * 
 */

#include <vector>
class Observer;
class Notice;

class Subject {

protected:
	std::vector<Observer*> observers;
public:
/**
 * @brief Registers an existing observer for updates
 * @details Prevents nullptr registration and duplicate additions
 * @param Observer non-owning pointer to the observer  	
 */
	void attach(Observer* observer);
/**
 * @brief Derigisters an observer 	
 * @details Safely ignores request to detach unregistered observer
 * @param Obsrver non-owning pointer to remove 
 */
	void detach(Observer* observer);
/**
* @brief Broadcasts a notice to all currently registered observers
* @param Notice Push-notification data payload
*/
	virtual void notify(const Notice& notice) = 0;

	virtual ~Subject();
};

#endif
