// RtlHashUnicodeString 
 
int __fastcall RtlHashUnicodeString(unsigned __int16 *a1, int a2, unsigned int a3, unsigned int *a4)
{
  unsigned int v4; // r4
  unsigned __int16 *v5; // r5
  int v6; // r0
  unsigned int v7; // r1
  unsigned int v8; // t1

  v4 = 0;
  if ( !a1 )
    return -1073741811;
  if ( !a4 )
    return -1073741811;
  v5 = (unsigned __int16 *)*((_DWORD *)a1 + 1);
  *a4 = 0;
  v6 = *a1 >> 1;
  if ( a3 > 1 )
    return -1073741811;
  if ( !a2 )
    return sub_7C2308(v6);
  for ( ; v6; v4 = 65599 * v4 + v7 )
  {
    v8 = *v5++;
    v7 = v8;
    --v6;
    if ( v8 >= 0x61 )
    {
      if ( v7 > 0x7A )
        v7 = (unsigned __int16)(*(_WORD *)(Nls844UnicodeUpcaseTable
                                         + 2
                                         * ((v7 & 0xF)
                                          + *(unsigned __int16 *)(Nls844UnicodeUpcaseTable
                                                                + 2
                                                                * (((unsigned __int8)v7 >> 4)
                                                                 + *(unsigned __int16 *)(Nls844UnicodeUpcaseTable
                                                                                       + 2 * (v7 >> 8))))))
                              + v7);
      else
        v7 -= 32;
    }
  }
  *a4 = v4;
  return 0;
}
