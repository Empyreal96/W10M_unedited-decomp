// MiInitializeTransitionPfn 
 
int __fastcall MiInitializeTransitionPfn(int a1, int *a2)
{
  int v4; // r4
  unsigned int v5; // r3
  unsigned int v6; // r7
  unsigned int v7; // r3
  unsigned int v8; // r2
  int v9; // r3
  char v10; // r3
  char v11; // r3
  unsigned int v12; // r6
  int v13; // r1
  int v14; // r2
  int v15; // r4
  unsigned __int8 *v16; // r5
  unsigned int v17; // r0
  unsigned int *v18; // r1
  unsigned int v19; // r2
  int result; // r0
  int v21; // r3
  unsigned int v22; // r2
  int v23; // r0

  v4 = MmPfnDatabase + 24 * a1;
  v5 = *(_DWORD *)((((unsigned int)a2 >> 10) & 0x3FFFFC) - 0x40000000);
  if ( (v5 & 2) == 0 )
    sub_53A9A8();
  *(_DWORD *)v4 = 0;
  v6 = v5 >> 12;
  v7 = *a2;
  v8 = *(_DWORD *)(v4 + 20) & 0xFFF00000 | v6 & 0xFFFFF | 0x8000000;
  *(_DWORD *)(v4 + 4) = a2;
  *(_DWORD *)(v4 + 8) = v7;
  v9 = *(_DWORD *)(v4 + 12);
  *(_DWORD *)(v4 + 20) = v8;
  LOBYTE(v8) = *(_BYTE *)(v4 + 18);
  *(_DWORD *)(v4 + 12) = v9 & 0xBFFFFFFF;
  v10 = v8 & 0xF8;
  if ( (v8 & 0x10) != 0 )
    v11 = v10 | 3;
  else
    v11 = v10 | 2;
  *(_BYTE *)(v4 + 18) = v11;
  if ( (*a2 & 0x400) != 0 )
    v12 = (*(unsigned __int16 *)((*a2 & 0xFFFFF800 | (2 * (*a2 & 0x3FC))) + 0x10) >> 1) & 0x1F;
  else
    v12 = ((unsigned int)*a2 >> 5) & 0x1F;
  v13 = 1;
  if ( v12 >> 3 == 3 && (v12 & 7) != 0 )
  {
    v13 = 2;
  }
  else if ( v12 >> 3 == 1 )
  {
    v13 = 0;
  }
  MiFinalizePageAttribute(v4, v13, 1);
  *(_DWORD *)(v4 + 12) &= 0xC0000000;
  v14 = 32 * (v12 & 0x1F | (a1 << 7) | 0x40);
  if ( (unsigned int)(a2 + 0x10000000) <= 0x3FFFFF )
  {
    __dmb(0xBu);
    *a2 = v14;
    if ( (unsigned int)(a2 + 267649024) <= 0xFFF )
    {
      v23 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v23, v23 + 4 * ((unsigned __int16)a2 & 0xFFF), v14);
    }
  }
  else
  {
    *a2 = v14;
  }
  v15 = MmPfnDatabase + 24 * v6;
  v16 = (unsigned __int8 *)(v15 + 15);
  do
    v17 = __ldrex(v16);
  while ( __strex(v17 | 0x80, v16) );
  __dmb(0xBu);
  if ( v17 >> 7 )
  {
    do
    {
      do
      {
        __dmb(0xAu);
        __yield();
        v21 = *(_DWORD *)(v15 + 12);
        __dmb(0xBu);
      }
      while ( v21 < 0 );
      do
        v22 = __ldrex(v16);
      while ( __strex(v22 | 0x80, v16) );
      __dmb(0xBu);
    }
    while ( v22 >> 7 );
  }
  *(_DWORD *)(v15 + 12) = *(_DWORD *)(v15 + 12) & 0xC0000000 | (*(_DWORD *)(v15 + 12) + 1) & 0x3FFFFFFF;
  __dmb(0xBu);
  v18 = (unsigned int *)(v15 + 12);
  do
  {
    v19 = __ldrex(v18);
    result = v19 & 0x7FFFFFFF;
  }
  while ( __strex(v19 & 0x7FFFFFFF, v18) );
  return result;
}
