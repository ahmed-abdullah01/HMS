#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H
using namespace std;
template<typename t>

class Dynamic_array {
private:
  t *data;
  int len;
  int cap;

  // Doubles the current capacity when needed
  void double_capacity() {
    t* temp = new t[cap * 2];
    for (int i = 0; i < len; i++)
    {
      temp[i] = data[i];
    }
    delete[] data;
    data = temp;

  }

public:
  // Constructors & Destructor
  Dynamic_array():len(0),cap(30)
  {
    data = new t[cap];
  }                         // Default constructor
  Dynamic_array(int count, t value){
    len = count;
    cap = count * 2;
    data = new t[cap];
    for (int i = 0; i < len; i++)
    {
      data[i] = value;
    }
  }       // Fill constructor
  Dynamic_array(const Dynamic_array &other){
    len = other.len;
    cap = other.cap;
    data = new t[cap];
    for (int i = 0; i < len; i++)
    {
      data[i] = other.data[i];
    }
  } // Copy constructor
  ~Dynamic_array(){
    delete[] data;
  }
  // Operators
  Dynamic_array &operator=(const Dynamic_array &other){
    if (this != &other)
    {
      delete[] data;
      len = other.len;
      cap = other.cap;
      data = new t[cap];
      for (int i = 0; i < len; i++)
      {
        data[i] = other.data[i];
      }
    }
    return *this;
  }
  // Copy assignment
  t &operator[](int index)
  {
    return data[index];
  }
  // Subscript operator
  const t &operator[](int index) const
  {
    return data[index];
  }          // Const subscript operator
  bool operator==(const Dynamic_array &other)  const
  {
    if (len!=other.len){
      return false;
    }

    for (int i=0;i<len; i++){
      if (data[i]!=other.data[i])
      {
        return false;
      }
    }
    return true;
  }
  // Equality comparison
  bool operator!=(const Dynamic_array &other)  const
  {
    if (len != other.len)
    {
      return true;
    }
    for (int i = 0; i < len; i++)
    {
      if (data[i] != other.data[i])
      {
        return true;
      }
    }
    return false;
  }
  // Inequality comparison
  Dynamic_array operator+(const Dynamic_array &other) const
  {
    Dynamic_array result;
    result.len = len + other.len;
    result.cap=cap+other.cap;
    result.data=new t [result.cap];
    for (int i = 0; i < len; i++)
    {
      result.data[i] = data[i];
    }
    for (int i = 0; i < other.len; i++)
    {
      result.data[len + i] = other.data[i];
    }
    return result;
  }
  // Concatenation
  Dynamic_array &operator+=(const Dynamic_array &other){
    if (len + other.len > cap)
    {
      cap = len + other.len;
      t* newdata = new t[cap];
      for (int i = 0; i < len; i++)
      {
        newdata[i] = data[i];
      }
      delete[] data;
      data = newdata;
    }
    for (int i = 0; i < other.len; i++)
    {
      data[len + i] = other.data[i];
    }
    len = len + other.len;
    return *this;
  }

  // Modifiers
  void push(t value){
    t* newdata = new t[cap + 1];
    for (int i = 0; i < len; i++)
    {
      newdata[i] = data[i];
    }
    delete[] data;
    data = newdata;
    data[len] = value;
    len++;

  }
  // Adds an element to the end
  void pop(){
    if (len > 0)
    {
      len--;
    }
    data[len]='\0';
  }
  // Removes the last element
  void insert_at(int index, t value)
  {
    if (index < 0 || index > len)
    {
      cout << "out of bound\n";
    }

    for (int i = len; i > index; i--)
    {
      data[i] = data[i - 1];
    }
    data[index] = value;
    len++;
  }
  // Inserts value at index
  void delete_at(int index){
    if (index < 0 || index >= len)
    {
      cout << "out of bound index";
    }
    for (int i = index; i < len - 1; i++)
    {
      data[i] = data[i + 1];
    }
    len--;
  }            // Deletes value at index
  void reserve(int new_capacity){
    if (new_capacity > cap)
    {
      cap = new_capacity;
      int* newdata = new int[cap];
      for (int i = 0; i < len; i++){
        newdata[i] = data[i];
      }
      delete[] data;
      data = newdata;
    }
  }
  // Reserves a new capacity
  void clear(){
    data=nullptr;
    len = 0;
  }
  // Clears all elements
  void swap(Dynamic_array &other){
    t* tempdata = data;
    data = other.data;
    other.data = tempdata;

    int tempLen = len;
    len = other.len;
    other.len = tempLen;
    int tempCap = cap;
    cap = other.cap;
    other.cap = tempCap;
  }
  // Swaps with another array
  void shrink_to_fit(){
    cap = len;
    t* temp = new t[cap];
    for (int i = 0; i < len; i++){
      temp[i] = data[i];
    }
    delete[] data;
    data = temp;
  }
  // Reduces capacity to match size
  void reverse(){
    t *temp;
    for (int i = len; i < 0; i++)
    {
      temp[len-i]=data[i];

    }
    delete[]data;
    data=temp;
  }                       // Reverses the array elements

  // Accessors
  bool empty() const{
    if (len==0)return 0;
    else return 1;
  }
  // Checks if array is empty
  int size() const{
    return len;
  }
  // Returns current size

  t &at(int index){
    return data[index];
  }
  // Bounds-checked element access
  const t &at(int index) const{
    return data[index];
  }


  t &front(){
    return data[0];
  }
  // Returns first element
  const t &front() const{
    return data[0];
  }


  t &back(){
    return data[len - 1];
  }
  // Returns last element
  const t &back() const{
    return data[len - 1];
  }

};

#endif // DYNAMIC_ARRAY_H