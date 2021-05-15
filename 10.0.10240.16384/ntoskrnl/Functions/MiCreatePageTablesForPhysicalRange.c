// MiCreatePageTablesForPhysicalRange 
 
_WORD *__fastcall MiCreatePageTablesForPhysicalRange(_WORD *result, int a2)
{
  unsigned int v3; // r8
  unsigned int v4; // r4
  unsigned int *v5; // r10
  int v6; // r2
  int i; // r6
  unsigned int v8; // r5
  int v9; // r3
  unsigned int v10; // t1
  int v11; // r0
  unsigned __int8 *v12; // r3
  unsigned int v13; // r1
  unsigned __int8 *v14; // r1
  int v15; // r3
  unsigned int v16; // r2
  unsigned int *v17; // r2
  unsigned int v18; // r0

  v3 = *((_DWORD *)result + 3) << 12;
  v4 = ((4 * *((_DWORD *)result + 3)) & 0x3FFFFC) - 0x40000000;
  v5 = (unsigned int *)(((v4 >> 10) & 0x3FFFFC) - 0x40000000);
  v6 = *((_DWORD *)result + 4) & 0xFFFFF;
  for ( i = v6 - 0xFFFFFFF; v4 < 4 * i; v3 += v8 << 12 )
  {
    MiMakeSystemAddressValid(v4, 0, v6, a2, 1);
    v8 = 1024 - ((v4 >> 2) & 0x3FF);
    v9 = 4 * i - v4;
    if ( v8 > v9 >> 2 )
      v8 = v9 >> 2;
    v10 = *v5++;
    v11 = MmPfnDatabase + 24 * (v10 >> 12);
    v12 = (unsigned __int8 *)(v11 + 15);
    do
      v13 = __ldrex(v12);
    while ( __strex(v13 | 0x80, v12) );
    __dmb(0xBu);
    if ( v13 >> 7 )
    {
      v14 = (unsigned __int8 *)(v11 + 15);
      do
      {
        do
        {
          __dmb(0xAu);
          __yield();
          v15 = *(_DWORD *)(v11 + 12);
          __dmb(0xBu);
        }
        while ( v15 < 0 );
        do
          v16 = __ldrex(v14);
        while ( __strex(v16 | 0x80, v14) );
        __dmb(0xBu);
      }
      while ( v16 >> 7 );
    }
    *(_DWORD *)(v11 + 12) = *(_DWORD *)(v11 + 12) & 0xC0000000 | (*(_DWORD *)(v11 + 12) + 1) & 0x3FFFFFFF;
    __dmb(0xBu);
    v17 = (unsigned int *)(v11 + 12);
    do
      v18 = __ldrex(v17);
    while ( __strex(v18 & 0x7FFFFFFF, v17) );
    result = MI_INCREMENT_USED_PTES_BY_HANDLE_CLUSTER((_WORD *)(2 * ((v3 >> 22) - 534769440)), 1u);
    v4 += 4 * v8;
  }
  return result;
}
