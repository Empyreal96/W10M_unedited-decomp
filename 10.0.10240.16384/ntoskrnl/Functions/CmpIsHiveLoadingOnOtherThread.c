// CmpIsHiveLoadingOnOtherThread 
 
BOOL __fastcall CmpIsHiveLoadingOnOtherThread(int a1)
{
  return (*(_DWORD *)(a1 + 92) & 0x20) != 0 && *(_DWORD *)(a1 + 3268) != (__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
}
