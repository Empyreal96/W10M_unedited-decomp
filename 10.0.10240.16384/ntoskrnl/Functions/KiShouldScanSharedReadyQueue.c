// KiShouldScanSharedReadyQueue 
 
BOOL __fastcall KiShouldScanSharedReadyQueue(int a1)
{
  return *(_DWORD *)(a1 + 3464) || (*(_BYTE *)(a1 + 19) & 2) != 0 && *(_DWORD *)(a1 + 3456);
}
