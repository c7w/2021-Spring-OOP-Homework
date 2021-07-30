#ifndef PALSTRING_H
#define PALSTRING_H
#include <iostream>
#include <cstring>
using namespace std;
class PalString
{
public:
   char *data_; //A character array that stores strings
   int size;
   //TODO [Optional] : define other useful variables

   //TODO: finish the constructor
   PalString(const char *pStr)
   {
      size = strlen(pStr);
      data_ = new char[size + 1];
      strcpy(data_, pStr);
   }

   //TODO: finish the destructor
   ~PalString()
   {
      if (data_)
         delete[] data_;
   }

   //TODO: finish the function getString
   char *getString() const
   {
      char *tmp = new char[2 * size + 1];
      for (int i = 0; i < size; i++)
      {
         tmp[i] = data_[i];
      }
      for (int j = size; j < 2 * size; j++)
      {
         tmp[j] = data_[2 * size - j - 1];
      }
      tmp[2 * size] = '\0';
      return tmp;
   }

   //TODO: finish the function changeString
   void changeString(const char *pStr)
   {
      size = strlen(pStr);
      if (data_)
         delete[] data_;
      data_ = new char[size + 1];
      strcpy(data_, pStr);
   }

   //TODO: finish the copy constructor
   PalString(const PalString &rhs)
   {
      size = rhs.size;
      if (data_)
         delete[] data_;
      data_ = new char[size + 1];
      strcpy(data_, rhs.data_);
   }
   friend std::ostream &operator<<(std::ostream &out, const PalString &it)
   {
      auto tmp = it.getString();
      string tmp2 = string(tmp);
      out << tmp2;
      delete[] tmp;
      return out;
   }
   //TODO: override the operator <<
};

#endif // #ifndef PALSTRING_H