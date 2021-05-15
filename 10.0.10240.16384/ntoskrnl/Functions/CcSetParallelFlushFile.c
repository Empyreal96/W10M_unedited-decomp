// CcSetParallelFlushFile 
 
int __fastcall CcSetParallelFlushFile(int a1, int a2)
{
  int v3; // r5
  int v4; // r0
  int v5; // r3
  unsigned int v6; // r3

  v3 = *(_DWORD *)(*(_DWORD *)(a1 + 20) + 4);
  v4 = KeAcquireQueuedSpinLock(5);
  v5 = *(_DWORD *)(v3 + 96);
  if ( a2 )
    v6 = v5 | 0x40000;
  else
    v6 = v5 & 0xFFFBFFFF;
  *(_DWORD *)(v3 + 96) = v6;
  return KeReleaseQueuedSpinLock(5, v4);
}
