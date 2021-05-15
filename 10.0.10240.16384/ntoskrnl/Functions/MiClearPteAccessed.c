// MiClearPteAccessed 
 
int __fastcall MiClearPteAccessed(int a1, int a2, unsigned int a3, _DWORD *a4, int a5, int a6)
{
  unsigned __int8 *v7; // r1
  unsigned int v11; // r5
  int result; // r0
  unsigned int v13; // r1
  unsigned int v14; // r4
  int v15; // r5
  unsigned int *v16; // r2
  unsigned int v17; // r0
  int v18; // r4
  unsigned int *v19; // r2
  unsigned int v20; // r0
  int v21; // r0
  unsigned int *v22; // r2
  unsigned int v23; // r0

  v7 = (unsigned __int8 *)(a2 + 15);
  do
    v11 = __ldrex(v7);
  while ( __strex(v11 | 0x80, v7) );
  __dmb(0xBu);
  if ( v11 >> 7 )
    return sub_54F644();
  if ( ((*(_DWORD *)(a2 + 12) & 0x3FFFFFFFu) <= 1 || (*(_DWORD *)(a2 + 20) & 0x8000000) != 0)
    && ((*(_BYTE *)(a1 + 112) & 7) == 0 || *(unsigned __int16 *)(a2 + 16) <= 1u) )
  {
    if ( a5 )
    {
      v13 = *(_DWORD *)a3;
      v14 = *(_DWORD *)a3;
      if ( a3 < 0xC0300000 || a3 > 0xC0300FFF )
        v14 = v13 & 0xFFFFFFEF;
      if ( a3 + 0x40000000 > 0x3FFFFF )
      {
        *(_DWORD *)a3 = v14;
      }
      else
      {
        v15 = 0;
        __dmb(0xBu);
        *(_DWORD *)a3 = v14;
        if ( (v13 & 2) == 0 && (v14 & 2) != 0 )
          v15 = 1;
        if ( a3 >= 0xC0300000 && a3 <= 0xC0300FFF )
        {
          v21 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
          MiArmWriteConvertedHardwarePde(v21, (_DWORD *)(v21 + 4 * (a3 & 0xFFF)), v14);
        }
        if ( v15 == 1 )
        {
          __dsb(0xFu);
          __isb(0xFu);
        }
      }
      __dmb(0xBu);
      v16 = (unsigned int *)(a2 + 12);
      do
        v17 = __ldrex(v16);
      while ( __strex(v17 & 0x7FFFFFFF, v16) );
      v18 = (*a4 >> 9) & 7;
      if ( a6 && v18 != 7 )
        MiLogPageAccess(a1, a3);
      if ( !v18 )
      {
        MiSetWsleAge(*(_DWORD *)(a1 + 92), a4, 1);
        ++*(_DWORD *)(a1 + 20);
      }
      MiInsertTbFlushEntry(a5, *a4 & 0xFFFFF000, 1, 0);
    }
    else
    {
      __dmb(0xBu);
      v22 = (unsigned int *)(a2 + 12);
      do
        v23 = __ldrex(v22);
      while ( __strex(v23 & 0x7FFFFFFF, v22) );
    }
    result = 1;
  }
  else
  {
    __dmb(0xBu);
    v19 = (unsigned int *)(a2 + 12);
    do
      v20 = __ldrex(v19);
    while ( __strex(v20 & 0x7FFFFFFF, v19) );
    result = 0;
  }
  return result;
}
