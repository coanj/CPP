/**
 *	My implementation of a generic linked list as well as a menu
 *	to test out the list object
 */

#include <iostream>
#include <sstream>

using namespace std;

template <typename T>

/**
 * @brief linkedList
 * @details linkedList class
 * 
 */
class linkedList{
	private:
		struct node{
			T x;
			node *next;
		};
		node *head;
		int size;

	public:
		/**
		 * @brief linkedList
		 * @details constructor for the linkedList
		 */
		linkedList(){
			head = NULL;
			size = 0;
		}
		
		/**
		 * @brief addVal
		 * @details adds an element to the list
		 * 
		 * @param val element to be added
		 */
		void addVal(T val){
			size++;
			node *n = new node();
			n->x = val;
			n->next = head;
			head = n;
		}
		
		/**
		 * @brief pop
		 * @details removes last element from the list
		 */
		void pop(){
			size--;
			node *n = head;
			head = head->next;
			delete n;
		}
		
		/**
		 * @brief rDisplay
		 * @details prints out all elements in the list FILO style
		 */
		void rDisplay(){
			int count = size;
			node *show = head;
			while (show != NULL){
				cout << show->x << ' ';
				show = show->next;
				count--;
			}
			cout << endl;
		}
		
		/**
		 * @brief find
		 * @details find element in the list
		 * 
		 * @param value element to be found
		 * @return true if found or false if not found
		 */
		bool find(T value){
			node *find = head;
			int count = size;
			while (find != NULL){
				if (find->x == value){
					return true;
				}
				count--;
				find = find->next;
			}
			return false;
		}
		
		/**
		 * @brief remove
		 * @details finds and removes the target from the list
		 * 
		 * @param target element to be removed
		 * @return true if removed or false if not removed
		 */
		bool remove(T target){
			node *current = head;
			node *previous = head;

			while (current != NULL){
				if (current->x == target){
                    if(size == 1 || current == head){
                        pop();
                    }
                    else{
                        previous->next = current->next;
                    	size--;
                        delete current;
                    }
                    cout << target << " <- found. " << endl;
                    return true;
				}
				previous = current;
				current = current->next;
			}
			return false;
		}
		
		/**
		 * @brief clear
		 * @details removes all elements from the list
		 */
		void clear(){
			while (size > 0){
				pop();
			}
		}
		
		/**
		 * @brief sizeOf
		 * @details Returns the size of the list
		 * @return size integer
		 */
		int sizeOf(){
			return size;
		}
		
		/**
		 * @brief display
		 * @details prints out all elements in the list LIFO style
		 */
		void display(){
			int count = size;
			node *show = head;
			for(int i = size; i > 0; i--){
				for(int x = 1; x < count; x++ ){
					show = show->next;
				}
				cout << show->x << ' ';
				show = head;
				count--;
			}
			cout << endl;
		}
};

/**
 * @brief cls
 * @details clears the console window
 */
void cls(){
	for(int i = 0; i < 100; i++){cout << endl;}
};

template <typename T>
/**
 * @brief menu
 * @details displays a menu to test the linked list class
 * 
 * @param list linked list to be tested
 */
void menu(linkedList<T> list){
	
	cls();
	bool cont = true;
	char select;
	T input;
	
	do{
		cout << "\nPlease choose a command to test on the linked list.\n"
				"\t0 to quit\n"
				"\t1 - add value\t\t5 - remove value\n"
				"\t2 - remove top\t\t6 - clear list\n"
				"\t3 - reverse display\t7 - size of list\n"
				"\t4 - find value\t\t8 - display list" << endl;
		cout << '>';
		cin >> select;
		
		switch(select){
			case '1':
				cls();
				cout << "Please enter a value to add to the list." << endl;
				cout << '>';
				cin >> input;
				list.addVal(input);
				break;
			case '2':
				cls();
				list.pop();
				cout << "Top value removed." << endl;
				break;
			case '3':
				cls();
				list.rDisplay();
				break;
			case '4':
				cls();
				cout << "Please enter a value to find in the list." << endl;
				cout << '>';
				cin >> input;
				cls();
				if(list.find(input)){
					cout << input << " found in the list.." << endl;
				}
				else{
					cout << input << " not found.." << endl;
				}
				break;
			case '5':
				cls();
				cout << "Please enter a value to remove from the list." << endl;
				cout << '>';
				cin >> input;
				cls();
				if(list.remove(input)){
					cout << input << " removed from the list.." << endl;
				}
				else{
					cout << input << " not found.." << endl;
				}
				break;
			case '6':
				cls();
				list.clear();
				break;
			case '7':
				cls();
				cout << list.sizeOf() << endl;
				break;
			case '8':
				cls();
				list.display();
				break;
			default:
				cont = false;
				break;
		}
		
	}while(cont);
};

int main(){
	
	linkedList<string> list;
	
	menu(list);
	
	return 0;
}

