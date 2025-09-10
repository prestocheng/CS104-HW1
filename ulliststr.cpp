#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
void ULListStr::push_back(const std::string& val)
{
  // Check if list is empty
  if (head_ == NULL and tail_ == NULL)  {
    Item* newItem = new Item();
    newItem->val[0] = val;
    newItem->first = 0;
    newItem->last = 1;
    head_ = newItem;
    tail_ = newItem;
  }

  // Tail node is full, make new node
  // must set new node to tail
  else if (tail_->last == 10) {
    Item* newItem = new Item();
    newItem->val[0] = val;
    newItem->last = 1;
    newItem->prev = tail_;

    tail_->next = newItem;
    tail_ = newItem;
  }

  // Can place val at end of array
  else {
    tail_->val[tail_->last] = val;
    tail_->last += 1;
  }

  size_ += 1;
}


void ULListStr::pop_back()
{
  // Remove value
  tail_->last -= 1;

  // If tail is empty, DELETE NODE
  if (tail_->last - tail_->first == 0)  {
    Item* temp = tail_;
    tail_ = tail_->prev;
    delete temp;

    // Edge case: Check if list has been completely deleted
    if (tail_ == NULL)  {
      head_ = NULL;
    }
    else  {
      tail_->next = NULL;
    }
  }
  
  size_ -= 1;
}


void ULListStr::push_front(const std::string& val)  
{
  // Check if list is empty
  if (head_ == NULL and tail_ == NULL)  {
    Item* newItem = new Item();
    newItem->val[9] = val;
    newItem->first = 9;
    newItem->last = 10;
    head_ = newItem;
    tail_ = newItem;
  }

  // Make new item if head item has no space
  else if (head_->first == 0)  {
    Item* newItem = new Item();
    newItem->val[9] = val;
    newItem->first = 9;
    newItem->last = 10;
    newItem->next = head_;

    head_->prev = newItem;

    head_ = newItem;
  }

  // Else add item
  else  {
    head_->val[head_->first - 1] = val;
    head_->first -= 1;
  }

  size_ += 1;
}


void ULListStr::pop_front()
{
  // Remove value
  head_->first += 1;

  // If head is empty, DELETE NODE
  if (head_->last == head_->first)  {
    Item* temp = head_;
    head_ = head_->next;
    delete temp;

  // Edge case: check if list has been completely deleted
    if (head_ == NULL)  {
      tail_ = NULL;
    }
    else  {
      head_->prev = NULL;
    }
  }
  size_ -= 1;
}


std::string const & ULListStr::back() const
{
  int last = tail_->last;
  return tail_->val[last - 1];
}


std::string const & ULListStr::front() const
{
  int first = head_->first;
  return head_->val[first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const
{
  std::string* ptr = NULL;

  // Location is out of bounds
  if (loc >= size_)  {
    return ptr;
  }

  // Else step through nodes
  else  {
    Item* temp = head_;
    size_t currSize = temp->last - temp->first;

    // While loop to step through nodes
    // Compare loc and currSize to find which node to stop on
    while (loc > (currSize - 1))  {
      temp = temp->next;
      loc -= currSize;
      currSize = temp->last - temp->first;
    }

    // Edge case: on head node where starting elements
    // are still blank
    if (temp == head_)  {
      int findStart = loc + head_->first;
      ptr = &temp->val[findStart];
      return ptr;
    }

    ptr = &temp->val[loc];
    return ptr;
  }
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
