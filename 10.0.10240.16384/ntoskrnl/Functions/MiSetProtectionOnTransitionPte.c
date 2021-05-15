// MiSetProtectionOnTransitionPte 
 
int __fastcall MiSetProtectionOnTransitionPte(int a1, unsigned int a2, int a3, int a4)
{
  int v8; // r7
  int v9; // r0
  int v10; // r6
  int v11; // r9
  unsigned int v13; // r4
  char v14; // r0
  unsigned int v15; // r4
  int v16; // r3
  int v17; // r8
  unsigned int *v18; // r2
  unsigned int v19; // r4
  int v20; // r2
  unsigned int v21; // r2
  int v22; // r0

  v8 = 0;
  v9 = MiLockTransitionLeafPage(a2, 0, a3);
  v10 = v9;
  if ( !v9 )
    return 2;
  v11 = *(_DWORD *)a2;
  if ( !a4 )
    return sub_5234A4();
  if ( (a3 & 2) != 0 && (BYTE2(MiFlags) & 3u) > 1 )
  {
    v20 = 0;
    if ( (*(_BYTE *)(v9 + 23) & 7) != 3 )
      v20 = 2;
    if ( (a3 & 4) != 0 && (a3 & 5) != 5 )
      v20 |= 1u;
    if ( v20 )
      MiMarkPfnVerified(v9, v20 | 4);
  }
  v13 = *(_DWORD *)(v10 + 8);
  v14 = MiSanitizePfnProtection(a1, (v13 >> 5) & 0x1F, a3);
  *(_DWORD *)(v10 + 8) = v13 & 0xFFFFFC1F | (32 * (v14 & 0x1F));
  v15 = v11 & 0xFFFFFC1F | (32 * (v14 & 0x1F));
  if ( a2 + 0x40000000 > 0x3FFFFF )
  {
    *(_DWORD *)a2 = v15;
  }
  else
  {
    v16 = *(_DWORD *)a2;
    v17 = 0;
    __dmb(0xBu);
    *(_DWORD *)a2 = v15;
    if ( (v16 & 2) == 0 && (v15 & 2) != 0 )
      v17 = 1;
    if ( a2 >= 0xC0300000 && a2 <= 0xC0300FFF )
    {
      v21 = v11 & 0xFFFFFC1F | (32 * (v14 & 0x1F));
      v22 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v22, v22 + 4 * (a2 & 0xFFF), v21);
    }
    if ( v17 == 1 )
    {
      __dsb(0xFu);
      __isb(0xFu);
    }
  }
  __dmb(0xBu);
  v18 = (unsigned int *)(v10 + 12);
  do
    v19 = __ldrex(v18);
  while ( __strex(v19 & 0x7FFFFFFF, v18) );
  return v8;
}
