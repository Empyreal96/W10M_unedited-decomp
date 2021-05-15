// SmStoreSetProcessVaRanges 
 
int __fastcall SmStoreSetProcessVaRanges(int a1, int a2)
{
  unsigned int v4; // r4
  int v5; // r7
  int v6; // r0
  int v7; // r5

  v4 = 0;
  v5 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  if ( a2 )
  {
    v6 = SmAlloc(8 * a2, 1381395827);
    v4 = v6;
    if ( !v6 )
      return -1073741670;
    memmove(v6, a1, 8 * a2);
  }
  v7 = SmpKeyedStoreSetVaRanges(byte_636CC4, v5);
  if ( v7 >= 0 )
  {
    v4 = 0;
    v7 = 0;
  }
  if ( v4 )
    ExFreePoolWithTag(v4);
  return v7;
}
