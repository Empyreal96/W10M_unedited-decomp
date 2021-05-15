// MiBuildForkPageTable 
 
int __fastcall MiBuildForkPageTable(int a1, int a2, int *a3, int a4, int a5)
{
  int v7; // r5
  int v8; // r6
  int v9; // r4
  int v11; // r10
  unsigned __int8 *v12; // lr
  unsigned int v13; // r4
  unsigned int i; // r3
  int v15; // r3
  unsigned int v16; // r2
  unsigned int *v17; // r2
  unsigned int v18; // r0
  unsigned __int8 *v19; // r1
  unsigned int v20; // r2
  int v21; // r3
  char v22; // r3
  unsigned int *v23; // r2
  unsigned int v24; // r0
  int result; // r0
  int v26; // r2
  int v27; // r0

  v7 = MmPfnDatabase + 24 * a1;
  v8 = MmPfnDatabase + 24 * a4;
  *(_BYTE *)(v7 + 18) |= 0x10u;
  v9 = *(_DWORD *)(v7 + 20);
  *(_DWORD *)(v7 + 8) = 128;
  *(_DWORD *)(v7 + 20) = v9 & 0xFFF00000 | a4 & 0xFFFFF;
  v11 = KfRaiseIrql(2);
  v12 = (unsigned __int8 *)(v8 + 15);
  do
    v13 = __ldrex(v12);
  while ( __strex(v13 | 0x80, v12) );
  __dmb(0xBu);
  for ( i = v13 >> 7; i; i = v16 >> 7 )
  {
    do
    {
      __dmb(0xAu);
      __yield();
      v15 = *(_DWORD *)(v8 + 12);
      __dmb(0xBu);
    }
    while ( (v15 & 0x80000000) != 0 );
    do
      v16 = __ldrex(v12);
    while ( __strex(v16 | 0x80, v12) );
    __dmb(0xBu);
  }
  *(_DWORD *)(v8 + 12) = *(_DWORD *)(v8 + 12) & 0xC0000000 | (*(_DWORD *)(v8 + 12) + 1) & 0x3FFFFFFF;
  __dmb(0xBu);
  v17 = (unsigned int *)(v8 + 12);
  do
    v18 = __ldrex(v17);
  while ( __strex(v18 & 0x7FFFFFFF, v17) );
  v19 = (unsigned __int8 *)(v7 + 15);
  do
    v20 = __ldrex(v19);
  while ( __strex(v20 | 0x80, v19) );
  while ( 1 )
  {
    __dmb(0xBu);
    if ( !(v20 >> 7) )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
      v21 = *(_DWORD *)(v7 + 12);
      __dmb(0xBu);
    }
    while ( (v21 & 0x80000000) != 0 );
    do
      v20 = __ldrex(v19);
    while ( __strex(v20 | 0x80, v19) );
  }
  if ( (*(_BYTE *)(v7 + 18) & 0xC0) != 64 )
    MiChangePageAttribute(v7, 1, 1);
  *(_DWORD *)(v7 + 12) = *(_DWORD *)(v7 + 12) & 0xC0000000 | 1;
  *(_WORD *)(v7 + 16) = 1;
  v22 = *(_BYTE *)(v7 + 18);
  *(_DWORD *)(v7 + 4) = a2;
  *(_BYTE *)(v7 + 18) = v22 & 0xF8 | 6;
  MiAddLockedPageCharge(v7, 1);
  __dmb(0xBu);
  v23 = (unsigned int *)(v7 + 12);
  do
    v24 = __ldrex(v23);
  while ( __strex(v24 & 0x7FFFFFFF, v23) );
  result = KfLowerIrql(v11);
  if ( a5 != 1 )
  {
    v26 = (a1 << 12) | 0x880;
    if ( (unsigned int)(a3 + 0x10000000) > 0x3FFFFF )
    {
      *a3 = v26;
    }
    else
    {
      __dmb(0xBu);
      *a3 = v26;
      if ( (unsigned int)(a3 + 267649024) <= 0xFFF )
      {
        v27 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
        result = MiArmWriteConvertedHardwarePde(v27, (_DWORD *)(v27 + 4 * ((unsigned __int16)a3 & 0xFFF)), v26);
      }
    }
  }
  return result;
}
