/******************************************************************************
** uabytearray.h
**
** Copyright (c) 2006-2016 Unified Automation GmbH. All rights reserved.
**
** Software License Agreement ("SLA") Version 2.5
**
** Unless explicitly acquired and licensed from Licensor under another
** license, the contents of this file are subject to the Software License
** Agreement ("SLA") Version 2.5, or subsequent versions
** as allowed by the SLA, and You may not copy or use this file in either
** source code or executable form, except in compliance with the terms and
** conditions of the SLA.
**
** All software distributed under the SLA is provided strictly on an
** "AS IS" basis, WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED,
** AND LICENSOR HEREBY DISCLAIMS ALL SUCH WARRANTIES, INCLUDING WITHOUT
** LIMITATION, ANY WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
** PURPOSE, QUIET ENJOYMENT, OR NON-INFRINGEMENT. See the SLA for specific
** language governing rights and limitations under the SLA.
**
** The complete license agreement can be found here:
** http://unifiedautomation.com/License/SLA/2.5/
**
** Project: C++ OPC SDK base module
**
** OPC UA ByteArray class.
**
******************************************************************************/
#ifndef __UABYTEARRAY_H__
#define __UABYTEARRAY_H__

#include "uaplatformdefs.h"
#include "uabase.h"
#include "uachar.h"
#include "uabytestring.h"

class UABASE_EXPORT UaByteRef;
class UABASE_EXPORT UaByteArrayPrivate;
class UABASE_EXPORT UaString;


/** @ingroup CppBaseLibraryClass
 *  @brief The UaByteArray handles the access to an array of bytes.
 *  UaByteArray can be used to store both raw bytes (including \\0s) and traditional 8-bit \\0-terminated strings.
 *  Using UaByteArray is much more convenient than using const char *.
 *  Behind the scenes, it always ensures that the data is followed by a \\0 terminator,
 *  and uses implicit sharing (copy-on-write) to reduce memory usage and avoid needless copying of data.
 *  You don't need to care about resizing or cleaning up the memory.
 */
class UABASE_EXPORT UaByteArray
{
  UA_DECLARE_PRIVATE(UaByteArray)
public:
  UaByteArray();
  UaByteArray(const char *pData, int iSize);
  UaByteArray(const UaByteArray &other);
  UaByteArray(const OpcUa_ByteString &other);
  UaByteArray(const UaByteString &other);
  ~UaByteArray();

  UaByteArray& operator=(const UaByteArray &other);

  void attach(OpcUa_UInt32 length, OpcUa_Byte* data);
  void attach(OpcUa_Int32 length, OpcUa_Byte* data);
  OpcUa_Byte* detach();

  void resize(int iSize);
  int size() const;
  int capacity() const;
  char operator[](int i) const;
  char operator[](unsigned int i) const;

   /** This function is provided for convenience and behaves like the function above.
    *  @see operator[](int i)
    */
  UaByteRef operator[](int i);

   /** This function is provided for convenience and behaves like the function above.
    *  @see operator[](int i)
    */
  UaByteRef operator[](unsigned int i);

  const char* data() const;
  operator const char*() const;
  operator const UaUShort*() const;
  operator const void*() const;

  void copyTo(OpcUa_ByteString *) const;
  UaString toHex(bool bSeparateWithSpace = false) const;
  static UaByteArray fromHex(const UaString &src);

private:
  friend class UaByteRef;
};


/** UaByteRef
 *  @brief Helper class for modifying UaByteArray elements.
 */
class UaByteRef
{
  UaByteArray &a;
  int i;
  /* Private constructor. Only UaByteArray can construct this kind of object. */
  inline UaByteRef(UaByteArray &array, int idx)
    : a(array),i(idx) {}
  friend class UaByteArray;
public:
  operator char() const;
  UaByteRef &operator=(char c);
  UaByteRef &operator=(const UaByteRef &c);
  bool operator==(char c) const;
  bool operator!=(char c) const;
  bool operator>(char c) const;
  bool operator>=(char c) const;
  bool operator<(char c) const;
  bool operator<=(char c) const;
};

/** Returns the byte at index position i as a modifiable reference.
 *  If an assignment is made beyond the end of the byte array, the array is extended with resize()
 *  before the assignment takes place.
 *  <p>Example:
 *  <pre>
 *     UaByteArray ba;
 *     for (int i = 0; i < 10; ++i)
 *         ba[i] = 'A' + i;
 *     // ba == "ABCDEFGHIJ"
 *  </pre></p>
 *  The return value is of type UaByteRef, a helper class for UaByteArray.
 *  When you get an object of type UaByteRef, you can use it as if it were a char &.
 *  If you assign to it, the assignment will apply to the character in the UaByteArray
 *  from which you got the reference.
 *  @see operator[](unsigned int i)
 *  @param i a variable to compare with.
 *  @return a ByteRef reference.
 */
inline UaByteRef UaByteArray::operator[](int i)
{ UA_ASSERT(i >= 0); return UaByteRef(*this, i); }

/** This function is provided for convenience and behaves like the function above.
 *  @see operator[](int i)
 *  @param i a variable to compare with.
 *  @return ByteRef reference.
 */
inline UaByteRef UaByteArray::operator[](unsigned int i)
{ return UaByteRef(*this, i); }

#endif /*  __UABYTEARRAY_H__ */


