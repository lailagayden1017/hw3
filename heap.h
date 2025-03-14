#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
	std::vector<T> data_;
	int n; 
	PComparator compare;

	void trickleUp(int i);
	void trickleDown(int i);





};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) : n(m), compare(c){}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap(){}


template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item){
	data_.push_back(item);
	//trickle up
	trickleUp(data_.size()-1);
}



// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
		throw std::underflow_error("Empty Heap");


  }
	return data_.front();
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element


}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T, PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
		throw std::underflow_error("Empty Heap");
  }
	std::swap(data_.front(), data_.back());
	data_.pop_back();
	if(!empty()){
		//trickle down 
		trickleDown(0);
	}
}

template <typename T, typename PComparator> 
bool Heap<T, PComparator>::empty() const{
	return data_.empty();
}

template <typename T, typename PComparator> 
size_t Heap<T,PComparator>::size() const{
	return data_.size();
}

template <typename T, typename PComparator> 
void Heap<T, PComparator>::trickleUp(int i){
	while( i > 0){
		int p = (i-1)/ n;
		if(compare(data_[i], data_[p])){
			std::swap(data_[i], data_[p]);
			i = p;
		}
		else{
			break;
		}
	}
}

template <typename T, typename PComparator> 
void Heap<T, PComparator>::trickleDown(int i){
	while(true){
		int top = i;
		for(int j = 0; j < n; ++j){
			int child = n * i + j + 1;
			if(child <(int)data_.size() && compare(data_[child], data_[top])){
				top = child;
			}
		}
		if(top == i){
			break;
		}
		std::swap(data_[i], data_[top]);
		i = top;
} 
}







#endif

