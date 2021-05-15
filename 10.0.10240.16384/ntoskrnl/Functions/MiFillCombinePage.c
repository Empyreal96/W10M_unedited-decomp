// MiFillCombinePage 
 
int __fastcall MiFillCombinePage(int a1, int a2, int a3, int a4)
{
  unsigned int v6; // r4
  unsigned int v7; // r1
  int v8; // r0
  unsigned int v9; // r5
  int v10; // r4

  v6 = (int)((unsigned __int64)(715827883i64 * (a2 - MmPfnDatabase)) >> 32) >> 2;
  v7 = *(unsigned __int8 *)(a3 + 18);
  if ( *(unsigned __int8 *)(a2 + 18) >> 6 != v7 >> 6 )
    MiChangePageAttribute(a2, v7 >> 6, 2);
  v8 = MiMapSinglePage(0, v6 + (v6 >> 31), 1073741840);
  v9 = v8;
  if ( !v8 )
    return 0;
  v10 = 1;
  memmove(v8, a4, 0x1000u);
  KeSweepIcacheRange(1, v9, 0x1000u);
  MiReleasePtes(&dword_634D58, ((v9 >> 10) & 0x3FFFFC) - 0x40000000, 1u);
  return v10;
}
