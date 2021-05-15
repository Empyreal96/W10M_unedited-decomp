// RtlPrefixUnicodeString 
 
int __fastcall RtlPrefixUnicodeString(unsigned __int16 *a1, unsigned __int16 *a2, int a3)
{
  unsigned __int16 *v3; // r4
  unsigned int v4; // r0
  int v5; // r5
  unsigned __int16 *v6; // r7
  int v7; // lr
  unsigned int v8; // r6
  unsigned int v9; // r5
  int v11; // r1
  int v12; // r2
  int v13; // t1

  v3 = (unsigned __int16 *)*((_DWORD *)a1 + 1);
  v4 = *a1;
  v5 = *((_DWORD *)a2 + 1);
  if ( *a2 < v4 )
    return 0;
  v6 = (unsigned __int16 *)((char *)v3 + v4);
  if ( !a3 )
  {
    if ( v3 >= v6 )
      return 1;
    v11 = v5 - (_DWORD)v3;
    while ( 1 )
    {
      v12 = *(unsigned __int16 *)((char *)v3 + v11);
      v13 = *v3++;
      if ( v13 != v12 )
        break;
      if ( v3 >= v6 )
        return 1;
    }
    return 0;
  }
  if ( v3 >= v6 )
    return 1;
  v7 = v5 - (_DWORD)v3;
  while ( 1 )
  {
    v8 = *v3;
    v9 = *(unsigned __int16 *)((char *)v3 + v7);
    if ( v8 == v9 )
      goto LABEL_6;
    if ( v8 >= 0x61 )
      break;
LABEL_14:
    if ( v9 >= 0x61 )
    {
      if ( v9 > 0x7A )
        v9 = (unsigned __int16)(*(_WORD *)(Nls844UnicodeUpcaseTable
                                         + 2
                                         * (*(unsigned __int16 *)(Nls844UnicodeUpcaseTable
                                                                + 2
                                                                * (*(unsigned __int16 *)(Nls844UnicodeUpcaseTable
                                                                                       + 2 * BYTE1(v9))
                                                                 + ((unsigned __int8)v9 >> 4)))
                                          + (v9 & 0xF)))
                              + v9);
      else
        v9 -= 32;
    }
    if ( v8 != v9 )
      return 0;
LABEL_6:
    if ( ++v3 >= v6 )
      return 1;
  }
  if ( v8 <= 0x7A )
  {
    v8 -= 32;
    goto LABEL_14;
  }
  return sub_7C6B50();
}
