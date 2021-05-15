// HvClearBinTrimStatus 
 
int __fastcall HvClearBinTrimStatus(int result, int a2)
{
  unsigned int v2; // r4
  int v3; // r6
  unsigned int v4; // r5

  v2 = *(_DWORD *)(a2 + 4);
  v3 = result;
  v4 = *(_DWORD *)(a2 + 8) + v2;
  while ( v2 < v4 )
  {
    result = HvpGetCellMap(v3, v2);
    v2 += 4096;
    *(_DWORD *)(result + 4) &= 0xFFFFFFFB;
  }
  return result;
}
