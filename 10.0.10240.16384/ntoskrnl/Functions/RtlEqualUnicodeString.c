// RtlEqualUnicodeString 
 
int __fastcall RtlEqualUnicodeString(unsigned __int16 *a1, unsigned __int16 *a2, int a3)
{
  unsigned int v3; // r4
  char *v5; // r0
  _DWORD *v6; // r5
  char *i; // r7
  int v8; // r5
  unsigned int v9; // r1
  unsigned int v10; // r4
  int v11; // r2
  int v12; // t1
  int v13; // t1

  v3 = *a1;
  if ( v3 != *a2 )
    return 0;
  v5 = (char *)*((_DWORD *)a1 + 1);
  v6 = (_DWORD *)*((_DWORD *)a2 + 1);
  for ( i = &v5[v3]; v3 >= 4; ++v6 )
  {
    if ( *(_DWORD *)v5 != *v6 )
      break;
    v3 -= 4;
    if ( !v3 )
      return 1;
    v5 += 4;
  }
  if ( !a3 )
  {
    while ( v5 < i )
    {
      v12 = *(unsigned __int16 *)v6;
      v6 = (_DWORD *)((char *)v6 + 2);
      v11 = v12;
      v13 = *(unsigned __int16 *)v5;
      v5 += 2;
      if ( v13 != v11 )
        return 0;
    }
    return 1;
  }
  if ( v5 >= i )
    return 1;
  v8 = (char *)v6 - v5;
  while ( 1 )
  {
    v9 = *(unsigned __int16 *)v5;
    v10 = *(unsigned __int16 *)&v5[v8];
    if ( v9 == v10 )
      goto LABEL_11;
    if ( v9 >= 0x61 )
      break;
LABEL_14:
    if ( v10 >= 0x61 )
    {
      if ( v10 > 0x7A )
        v10 = (unsigned __int16)(*(_WORD *)(Nls844UnicodeUpcaseTable
                                          + 2
                                          * ((v10 & 0xF)
                                           + *(unsigned __int16 *)(Nls844UnicodeUpcaseTable
                                                                 + 2
                                                                 * (((unsigned __int8)v10 >> 4)
                                                                  + *(unsigned __int16 *)(Nls844UnicodeUpcaseTable
                                                                                        + 2 * BYTE1(v10))))))
                               + v10);
      else
        v10 -= 32;
    }
    if ( v9 != v10 )
      return 0;
LABEL_11:
    v5 += 2;
    if ( v5 >= i )
      return 1;
  }
  if ( v9 <= 0x7A )
  {
    v9 -= 32;
    goto LABEL_14;
  }
  return sub_7C58F0();
}
