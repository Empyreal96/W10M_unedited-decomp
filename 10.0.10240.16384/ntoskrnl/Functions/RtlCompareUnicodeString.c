// RtlCompareUnicodeString 
 
unsigned int __fastcall RtlCompareUnicodeString(unsigned __int16 *a1, unsigned __int16 *a2, int a3)
{
  unsigned int v3; // r9
  unsigned __int16 *v4; // r4
  unsigned int v5; // r8
  int v6; // r5
  unsigned int v7; // r3
  unsigned __int16 *v8; // lr
  int v9; // r7
  unsigned int v10; // r5
  unsigned int v11; // r6
  int v13; // r1
  int v14; // r3
  int v15; // r2

  v3 = *a2;
  v4 = (unsigned __int16 *)*((_DWORD *)a1 + 1);
  v5 = *a1 >> 1;
  v6 = *((_DWORD *)a2 + 1);
  if ( v5 > v3 >> 1 )
    v7 = v3 >> 1;
  else
    v7 = *a1 >> 1;
  v8 = &v4[v7];
  if ( a3 )
  {
    if ( v4 < v8 )
    {
      v9 = v6 - (_DWORD)v4;
      while ( 1 )
      {
        v10 = *v4;
        v11 = *(unsigned __int16 *)((char *)v4 + v9);
        if ( v10 != v11 )
        {
          if ( v10 >= 0x61 )
          {
            if ( v10 > 0x7A )
              v10 = (unsigned __int16)(*(_WORD *)(Nls844UnicodeUpcaseTable
                                                + 2
                                                * (*(unsigned __int16 *)(Nls844UnicodeUpcaseTable
                                                                       + 2
                                                                       * (*(unsigned __int16 *)(Nls844UnicodeUpcaseTable
                                                                                              + 2 * BYTE1(v10))
                                                                        + ((unsigned __int8)v10 >> 4)))
                                                 + (v10 & 0xF)))
                                     + v10);
            else
              v10 -= 32;
          }
          if ( v11 >= 0x61 )
          {
            if ( v11 <= 0x7A )
              v11 -= 32;
            else
              v11 = (unsigned __int16)(*(_WORD *)(Nls844UnicodeUpcaseTable
                                                + 2
                                                * (*(unsigned __int16 *)(Nls844UnicodeUpcaseTable
                                                                       + 2
                                                                       * (*(unsigned __int16 *)(Nls844UnicodeUpcaseTable
                                                                                              + 2 * BYTE1(v11))
                                                                        + ((unsigned __int8)v11 >> 4)))
                                                 + (v11 & 0xF)))
                                     + v11);
          }
          if ( v10 != v11 )
            break;
        }
        if ( ++v4 >= v8 )
          return v5 - (v3 >> 1);
      }
      return v10 - v11;
    }
    return v5 - (v3 >> 1);
  }
  if ( v4 >= v8 )
    return v5 - (v3 >> 1);
  v13 = v6 - (_DWORD)v4;
  while ( 1 )
  {
    v14 = *v4;
    v15 = *(unsigned __int16 *)((char *)v4 + v13);
    if ( v14 != v15 )
      break;
    if ( ++v4 >= v8 )
      return v5 - (v3 >> 1);
  }
  return v14 - v15;
}
