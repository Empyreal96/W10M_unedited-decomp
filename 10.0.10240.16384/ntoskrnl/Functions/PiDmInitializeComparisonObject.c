// PiDmInitializeComparisonObject 
 
int __fastcall PiDmInitializeComparisonObject(unsigned __int16 *a1, int a2, _DWORD *a3)
{
  unsigned int v3; // r4
  unsigned __int16 *v4; // r6
  int v5; // r4
  unsigned __int16 *v6; // r5
  unsigned int *v9; // r8
  unsigned int v10; // r7
  unsigned int i; // r4
  unsigned int v12; // r5
  unsigned int v13; // t1

  v3 = 0;
  v4 = 0;
  a3[3] = a1;
  a3[5] = a2;
  if ( a1 )
  {
    v5 = 0x7FFF;
    v6 = a1;
    while ( *v6++ )
    {
      if ( !--v5 )
        return -1073741811;
    }
    v3 = (unsigned __int16)(2 * (0x7FFF - v5));
    v4 = a1;
  }
  if ( a2 == 3 )
  {
    if ( v3 <= 8 )
      return -1073741772;
    v3 = (unsigned __int16)(v3 - 8);
    v4 += 4;
  }
  v9 = a3 + 4;
  v10 = 0;
  if ( a3 == (_DWORD *)-16 )
    return -1073741811;
  *v9 = 0;
  for ( i = v3 >> 1; i; v10 = 65599 * v10 + v12 )
  {
    v13 = *v4++;
    v12 = v13;
    --i;
    if ( v13 >= 0x61 )
    {
      if ( v12 > 0x7A )
        v12 = (unsigned __int16)(*(_WORD *)(Nls844UnicodeUpcaseTable
                                          + 2
                                          * (*(unsigned __int16 *)(Nls844UnicodeUpcaseTable
                                                                 + 2
                                                                 * (*(unsigned __int16 *)(Nls844UnicodeUpcaseTable
                                                                                        + 2 * (v12 >> 8))
                                                                  + ((unsigned __int8)v12 >> 4)))
                                           + (v12 & 0xF)))
                               + v12);
      else
        v12 -= 32;
    }
  }
  *v9 = v10;
  return 0;
}
