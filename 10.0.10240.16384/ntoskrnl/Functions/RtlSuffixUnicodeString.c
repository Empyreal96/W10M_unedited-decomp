// RtlSuffixUnicodeString 
 
int __fastcall RtlSuffixUnicodeString(unsigned __int16 *a1, unsigned __int16 *a2, int a3)
{
  unsigned int v4; // r3
  unsigned int v5; // r4
  unsigned __int16 *v8; // r1
  unsigned int v9; // r2
  int v10; // r0
  unsigned __int16 *v11; // r4
  int v12; // r7
  unsigned int v13; // r0
  int v14; // r5
  unsigned int v15; // r0
  int v16; // r0
  int v17; // r2
  int v18; // t1

  v4 = *a2;
  v5 = *a1;
  if ( v4 < v5 )
    return 0;
  v8 = (unsigned __int16 *)*((_DWORD *)a1 + 1);
  v9 = (v4 - v5) >> 1;
  v10 = *((_DWORD *)a2 + 1);
  v11 = &v8[v5 >> 1];
  if ( a3 )
  {
    if ( v8 < v11 )
    {
      v12 = 2 * v9 - (_DWORD)v8 + v10;
      while ( 1 )
      {
        v13 = *v8;
        if ( v13 >= 0x61 )
        {
          if ( v13 > 0x7A )
            LOWORD(v13) = *(_WORD *)(Nls844UnicodeUpcaseTable
                                   + 2
                                   * ((v13 & 0xF)
                                    + *(unsigned __int16 *)(Nls844UnicodeUpcaseTable
                                                          + 2
                                                          * (((unsigned __int8)v13 >> 4)
                                                           + *(unsigned __int16 *)(Nls844UnicodeUpcaseTable
                                                                                 + 2 * (v13 >> 8))))))
                        + v13;
          else
            LOWORD(v13) = v13 - 32;
        }
        v14 = (unsigned __int16)v13;
        v15 = *(unsigned __int16 *)((char *)v8 + v12);
        if ( v15 >= 0x61 )
        {
          if ( v15 > 0x7A )
            LOWORD(v15) = *(_WORD *)(Nls844UnicodeUpcaseTable
                                   + 2
                                   * ((v15 & 0xF)
                                    + *(unsigned __int16 *)(Nls844UnicodeUpcaseTable
                                                          + 2
                                                          * (((unsigned __int8)v15 >> 4)
                                                           + *(unsigned __int16 *)(Nls844UnicodeUpcaseTable
                                                                                 + 2 * (v15 >> 8))))))
                        + v15;
          else
            LOWORD(v15) = v15 - 32;
        }
        if ( v14 != (unsigned __int16)v15 )
          break;
        if ( ++v8 >= v11 )
          return 1;
      }
      return 0;
    }
  }
  else if ( v8 < v11 )
  {
    v16 = v10 + 2 * v9 - (_DWORD)v8;
    while ( 1 )
    {
      v17 = *(unsigned __int16 *)((char *)v8 + v16);
      v18 = *v8++;
      if ( v18 != v17 )
        break;
      if ( v8 >= v11 )
        return 1;
    }
    return 0;
  }
  return 1;
}
