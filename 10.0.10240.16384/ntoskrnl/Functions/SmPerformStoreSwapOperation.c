// SmPerformStoreSwapOperation 
 
int __fastcall SmPerformStoreSwapOperation(int a1, int a2)
{
  int result; // r0
  bool v3; // zf
  int v4; // r0

  if ( a1 == 3 )
  {
    RtlpSysVolFree(a2);
    result = 0;
  }
  else
  {
    v3 = a1 == 2;
    v4 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
    if ( v3 )
      result = MmInSwapVirtualAddresses(v4, a2);
    else
      result = MmOutSwapVirtualAddresses(v4, *(unsigned int **)(a2 + 4), *(_DWORD *)(a2 + 8), (int **)a2);
  }
  return result;
}
