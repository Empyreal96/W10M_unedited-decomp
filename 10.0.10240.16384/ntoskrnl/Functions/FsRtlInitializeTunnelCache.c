// FsRtlInitializeTunnelCache 
 
int __fastcall FsRtlInitializeTunnelCache(int a1)
{
  int result; // r0

  *(_DWORD *)a1 = 1;
  *(_DWORD *)(a1 + 4) = 0;
  *(_DWORD *)(a1 + 8) = 0;
  result = KeInitializeEvent(a1 + 12, 1, 0);
  *(_DWORD *)(a1 + 32) = 0;
  *(_DWORD *)(a1 + 36) = a1 + 36;
  *(_DWORD *)(a1 + 40) = a1 + 36;
  *(_WORD *)(a1 + 44) = 0;
  return result;
}
