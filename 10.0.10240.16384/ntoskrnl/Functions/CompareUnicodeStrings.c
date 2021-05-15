// CompareUnicodeStrings 
 
int __fastcall CompareUnicodeStrings(unsigned __int16 *a1, unsigned __int16 *a2, unsigned int a3)
{
  unsigned int v5; // r6
  unsigned int v6; // r3
  unsigned int v7; // r7
  int result; // r0
  unsigned int v9; // r5
  unsigned int v10; // r1
  unsigned int v11; // r0
  unsigned int v12; // r4
  unsigned __int16 *v13; // lr
  unsigned __int16 *v14; // r8
  unsigned int v15; // t1
  unsigned int v16; // t1
  unsigned __int16 *v17; // lr
  int v18; // r3
  unsigned int v19; // t1

  v5 = *a1 >> 1;
  v6 = *a2;
  v7 = v6 >> 1;
  if ( v5 == 1 )
    return sub_7DD410();
  if ( v5 < v7 )
    v9 = *a1 >> 1;
  else
    v9 = v6 >> 1;
  if ( a3 > v9 )
    a3 = v9;
  v10 = 0;
  v11 = 0;
  v12 = 0;
  if ( a3 )
  {
    v17 = (unsigned __int16 *)*((_DWORD *)a2 + 1);
    v18 = *((_DWORD *)a1 + 1) - (_DWORD)v17;
    do
    {
      v10 = *(unsigned __int16 *)((char *)v17 + v18);
      v19 = *v17++;
      v11 = v19;
      if ( v10 != v19 )
        break;
      ++v12;
    }
    while ( v12 < a3 );
  }
  if ( v12 == a3 )
  {
    v13 = (unsigned __int16 *)(*((_DWORD *)a1 + 1) + 2 * v12);
    v14 = (unsigned __int16 *)(*((_DWORD *)a2 + 1) + 2 * v12);
    if ( v12 >= v9 )
      goto LABEL_24;
    do
    {
      v15 = *v13++;
      v10 = v15;
      v16 = *v14++;
      v11 = v16;
      if ( v10 != v16 )
      {
        if ( v10 >= 0x61 )
        {
          if ( v10 > 0x7A )
            LOWORD(v10) = *(_WORD *)(Nls844UnicodeUpcaseTable
                                   + 2
                                   * ((v10 & 0xF)
                                    + *(unsigned __int16 *)(Nls844UnicodeUpcaseTable
                                                          + 2
                                                          * (((unsigned __int8)v10 >> 4)
                                                           + *(unsigned __int16 *)(Nls844UnicodeUpcaseTable
                                                                                 + 2 * (v10 >> 8))))))
                        + v10;
          else
            LOWORD(v10) = v10 - 32;
        }
        v10 = (unsigned __int16)v10;
        if ( v11 >= 0x61 )
        {
          if ( v11 > 0x7A )
            LOWORD(v11) = *(_WORD *)(Nls844UnicodeUpcaseTable
                                   + 2
                                   * ((v11 & 0xF)
                                    + *(unsigned __int16 *)(Nls844UnicodeUpcaseTable
                                                          + 2
                                                          * (((unsigned __int8)v11 >> 4)
                                                           + *(unsigned __int16 *)(Nls844UnicodeUpcaseTable
                                                                                 + 2 * (v11 >> 8))))))
                        + v11;
          else
            LOWORD(v11) = v11 - 32;
        }
        v11 = (unsigned __int16)v11;
        if ( (unsigned __int16)v10 != (unsigned __int16)v11 )
          break;
      }
      ++v12;
    }
    while ( v12 < v9 );
  }
  if ( v12 < v9 )
  {
    if ( v10 == 92 )
      return 0;
    if ( v11 == 92 )
      return 3;
    if ( v10 < v11 )
      return 0;
    if ( v10 > v11 )
      return 3;
  }
LABEL_24:
  if ( v5 < v7 )
  {
    if ( *(_WORD *)(*((_DWORD *)a2 + 1) + 2 * v5) != 92 )
      return 0;
    result = 1;
  }
  else
  {
    if ( v5 > v7 )
      return 3;
    result = 2;
  }
  return result;
}
