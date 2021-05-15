// CmpCompareTwoCompressedNames 
 
int __fastcall CmpCompareTwoCompressedNames(unsigned __int8 *a1, unsigned __int16 a2, unsigned __int8 *a3, unsigned __int16 a4)
{
  int v4; // r8
  int v7; // r5
  unsigned int v8; // r0
  unsigned int v9; // t1
  unsigned int v10; // r4
  unsigned int v11; // t1
  int result; // r0
  int v13; // r10

  v4 = a2;
  v7 = a4;
  if ( a2 )
  {
    while ( v7 )
    {
      v9 = *a1++;
      v8 = v9;
      v11 = *a3++;
      v10 = v11;
      if ( v8 != v11 )
      {
        if ( v8 >= 0x61 )
        {
          if ( v8 > 0x7A )
            LOWORD(v8) = RtlUpcaseUnicodeChar(v8);
          else
            LOWORD(v8) = v8 - 32;
        }
        v13 = (unsigned __int16)v8;
        if ( v10 >= 0x61 )
        {
          if ( v10 > 0x7A )
            LOWORD(v10) = RtlUpcaseUnicodeChar(v10);
          else
            LOWORD(v10) = v10 - 32;
        }
        result = v13 - (unsigned __int16)v10;
        if ( v13 != (unsigned __int16)v10 )
          return result;
      }
      v4 = (unsigned __int16)(v4 - 1);
      v7 = (unsigned __int16)(v7 - 1);
      if ( !v4 )
        return v4 - v7;
    }
  }
  return v4 - v7;
}
