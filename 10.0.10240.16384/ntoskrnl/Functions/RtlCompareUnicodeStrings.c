// RtlCompareUnicodeStrings 
 
unsigned int __fastcall RtlCompareUnicodeStrings(unsigned __int16 *a1, unsigned int a2, int a3, unsigned int a4, char a5)
{
  unsigned int v6; // r8
  unsigned int v8; // r0
  unsigned __int16 *v9; // r7
  int v10; // lr
  unsigned int v11; // r5
  unsigned int v12; // r6
  int v14; // r1
  int v15; // r3
  int v16; // r2

  v6 = a2;
  if ( a2 > a4 )
    v8 = a4;
  else
    v8 = a2;
  v9 = &a1[v8];
  if ( a5 )
  {
    if ( a1 < v9 )
    {
      v10 = a3 - (_DWORD)a1;
      while ( 1 )
      {
        v11 = *a1;
        v12 = *(unsigned __int16 *)((char *)a1 + v10);
        if ( v11 != v12 )
        {
          if ( v11 >= 0x61 )
          {
            if ( v11 > 0x7A )
              v11 = (unsigned __int16)(*(_WORD *)(Nls844UnicodeUpcaseTable
                                                + 2
                                                * (*(unsigned __int16 *)(Nls844UnicodeUpcaseTable
                                                                       + 2
                                                                       * (*(unsigned __int16 *)(Nls844UnicodeUpcaseTable
                                                                                              + 2 * BYTE1(v11))
                                                                        + ((unsigned __int8)v11 >> 4)))
                                                 + (v11 & 0xF)))
                                     + v11);
            else
              v11 -= 32;
          }
          if ( v12 >= 0x61 )
          {
            if ( v12 > 0x7A )
              v12 = (unsigned __int16)(*(_WORD *)(Nls844UnicodeUpcaseTable
                                                + 2
                                                * (*(unsigned __int16 *)(Nls844UnicodeUpcaseTable
                                                                       + 2
                                                                       * (*(unsigned __int16 *)(Nls844UnicodeUpcaseTable
                                                                                              + 2 * BYTE1(v12))
                                                                        + ((unsigned __int8)v12 >> 4)))
                                                 + (v12 & 0xF)))
                                     + v12);
            else
              v12 -= 32;
          }
          if ( v11 != v12 )
            break;
        }
        if ( ++a1 >= v9 )
          return a2 - a4;
      }
      return v11 - v12;
    }
    return v6 - a4;
  }
  if ( a1 >= v9 )
    return v6 - a4;
  v14 = a3 - (_DWORD)a1;
  while ( 1 )
  {
    v15 = *a1;
    v16 = *(unsigned __int16 *)((char *)a1 + v14);
    if ( v15 != v16 )
      break;
    if ( ++a1 >= v9 )
      return v6 - a4;
  }
  return v15 - v16;
}
