#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <iostream>

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

  void trickle_down(int index);

  void trickle_up(int index);

  void print_heap();

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> heapvec_;
  PComparator comp_;
  size_t size_;
  int arity_;

};

// Add implementation of member functions here

// template <typename T, typename PComparator>
// void Heap<T,PComparator>::print_heap(){
//   for(size_t i = 0; i < size_; ++i){
//     std::cout << heapvec_[i] << ' ';
//   }
//   std::cout << std::endl;
// }

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
    throw std::out_of_range("Heap is empty");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return heapvec_[0];
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::out_of_range("Heap is empty");

  }
  T temp = heapvec_[0];
  heapvec_[0] = heapvec_[size_ - 1];
  heapvec_.pop_back();
  size_--;

  trickle_down(0);
  return;
}

template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c){
  size_ = 0;
  arity_ = m;
  comp_ = c;
}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap() {}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const{
  return size_ == 0;
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const{
  return size_;
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item){
  heapvec_.push_back(item);
  size_++;
  // std::cout << "just about to call trickle up and pass one less than this index: " << size_ << std::endl;
  // std::cout << "just about to call trickle up and pass this index: " << size_ -1 << std::endl;
  trickle_up(size_ - 1);
  return;
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::trickle_down(int index){
  //find index of "most" child
  if(((arity_ * index) + 1) >= size_) return;
  // std::cout << "- in the trickle_down function, made it past my little sanity check, index=" << index << std::endl 
  // << " first child index = " << (arity_ * index) + 1 << std::endl
  // << " comparing the two gives this: " << std::boolalpha << comp_(heapvec_[index], heapvec_[(arity_ * index) + 1])
  // << std::endl;
  int schild_index = (arity_ * index) + 1; 
  for(size_t i = 1; i <= arity_; ++i){
    if(comp_(heapvec_[(arity_ * index) + i], heapvec_[schild_index]) && ((arity_ * index) + i) < size_){
      schild_index = (arity_ * index) + i;
    }
    //std::cout << "inside the loop that should loop through all CHILDREN only and find optimal one, schild_index = " << schild_index << std::endl;
  }
  //std::cout << "- optimal child index after search: " << schild_index << std::endl;
  //switch
  if(!comp_(heapvec_[index], heapvec_[schild_index])){
    //std::cout << "- swapping parents and child (aka trickling down once), and recursing" << std::endl;
    T temp = heapvec_[index];
    heapvec_[index] = heapvec_[schild_index];
    heapvec_[schild_index] = temp;
    trickle_down(schild_index);
  }
  //std::cout << std::endl << std::endl << std::endl;
  return;
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::trickle_up(int index){ //let index equal to 1 and the vector at start is 10 4
  if(((index-1) / arity_) < 0 || index == 0) return;
  //std::cout << "in the trickle_up function, made it past my little sanity check, index=" << index << " parent index = " << ((index-1) / arity_) << std::endl;
  if(!(comp_(heapvec_[((index-1) / arity_)], heapvec_[index]))){
    //std::cout << "switching, former parent = " << heapvec_[((index-1) / arity_)] << std::endl;
    T temp = heapvec_[index];
    heapvec_[index] = heapvec_[((index-1) / arity_)];
    heapvec_[((index-1) / arity_)] = temp;
    trickle_up((index-1) / arity_);
  }
  return;
}


#endif

