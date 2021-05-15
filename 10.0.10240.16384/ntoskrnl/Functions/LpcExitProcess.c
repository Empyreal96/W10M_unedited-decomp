// LpcExitProcess 
 
int __fastcall LpcExitProcess(int a1, int a2, int a3, int a4)
{
  int v4; // r3
  unsigned int v7; // r1

  v4 = *(_DWORD *)(a1 + 668);
  __dmb(0xBu);
  if ( v4 )
  {
    v7 = *(_DWORD *)(a1 + 668);
    __dmb(0xBu);
    PsReturnProcessPagedPoolQuota(a1, v7);
    __dmb(0xBu);
    *(_DWORD *)(a1 + 668) = 0;
  }
  return AlpcpCleanupProcessViews(a1, a2, a3, a4);
}
