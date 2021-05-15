// MiPteBinsNeedTrimming 
 
BOOL __fastcall MiPteBinsNeedTrimming(int a1)
{
  unsigned int v2; // r0

  v2 = MiGetNumberOfCachedPtes();
  return v2 >= 0x400 && v2 + *(_DWORD *)(a1 + 48) > *(_DWORD *)(a1 + 36) / 0xAu;
}
