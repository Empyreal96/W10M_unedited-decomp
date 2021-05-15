// sub_52EC14 
 
void __fastcall sub_52EC14(int a1, int a2, int a3)
{
  int v3; // r4
  int v4; // r5
  unsigned int v5; // r1
  int v6; // r3

  if ( v3 )
  {
    ExReleaseRundownProtectionCacheAwareEx(*(_DWORD **)(a3 + 4 * v4), 1);
    v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v6 = (__int16)(*(_WORD *)(v5 + 0x134) + 1);
    *(_WORD *)(v5 + 308) = v6;
    if ( !v6 && *(_DWORD *)(v5 + 100) != v5 + 100 && !*(_WORD *)(v5 + 310) )
      JUMPOUT(0x47E8B8);
  }
  JUMPOUT(0x47E844);
}
