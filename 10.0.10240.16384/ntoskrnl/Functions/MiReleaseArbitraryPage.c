// MiReleaseArbitraryPage 
 
int __fastcall MiReleaseArbitraryPage(int a1)
{
  int v2; // r6
  int v3; // r7
  unsigned __int8 *v4; // r1
  unsigned int v5; // r2
  unsigned int v7; // r4
  unsigned int *v8; // r2
  unsigned int v9; // r0
  int v10; // r0

  v2 = *(_DWORD *)(a1 + 24);
  v3 = KfRaiseIrql(2);
  v4 = (unsigned __int8 *)(v2 + 15);
  do
    v5 = __ldrex(v4);
  while ( __strex(v5 | 0x80, v4) );
  __dmb(0xBu);
  if ( v5 >> 7 )
    return sub_54F040();
  v7 = *(_DWORD *)(a1 + 28);
  *(_DWORD *)(a1 + 24) = 0;
  if ( v7 + 0x40000000 > 0x3FFFFF )
  {
    *(_DWORD *)v7 = 0;
  }
  else
  {
    __dmb(0xBu);
    *(_DWORD *)v7 = 0;
    if ( v7 >= 0xC0300000 && v7 <= 0xC0300FFF )
    {
      v10 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v10, (_DWORD *)(v10 + 4 * (v7 & 0xFFF)), 0);
    }
  }
  *(_DWORD *)(a1 + 28) = 0;
  __dmb(0xBu);
  v8 = (unsigned int *)(v2 + 12);
  do
    v9 = __ldrex(v8);
  while ( __strex(v9 & 0x7FFFFFFF, v8) );
  return KfLowerIrql(v3);
}
