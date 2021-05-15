// FsRtlpRemoveAndBreakRHIrp 
 
int __fastcall FsRtlpRemoveAndBreakRHIrp(_DWORD *a1, int a2, int a3, int a4, int a5, int a6)
{
  int v8; // r7
  unsigned int *v10; // r4
  unsigned int v11; // r5
  int v12; // r4
  int v13; // r2
  int v14; // r3
  unsigned int v16; // r2
  int v17; // r3

  v8 = a1[2];
  a1[2] = 0;
  if ( a3 )
  {
    *(_BYTE *)(v8 + 37) = KeAcquireQueuedSpinLock(7);
    __dmb(0xBu);
    v10 = (unsigned int *)(v8 + 56);
    do
      v11 = __ldrex(v10);
    while ( __strex(0, v10) );
    __dmb(0xBu);
    KeReleaseQueuedSpinLock(7, *(unsigned __int8 *)(v8 + 37));
  }
  FsRtlpOplockDequeueRH(a1);
  if ( *(_BYTE *)(v8 + 36) )
  {
    ObfDereferenceObjectWithTag(a1[3]);
    if ( a1[5] )
      FsRtlpClearOwnerThread(a2, a1);
    ExFreePoolWithTag(a1, 0);
  }
  else
  {
    v12 = *(_DWORD *)(v8 + 12);
    memset((_BYTE *)v12, 0, 24);
    *(_WORD *)v12 = 1;
    *(_WORD *)(v12 + 2) = 24;
    *(_DWORD *)(v12 + 4) = 3;
    if ( (a5 & 0x4000) != 0 )
      v13 = 4;
    else
      v13 = 0;
    if ( (a5 & 0x2000) != 0 )
      v14 = 2;
    else
      v14 = 0;
    *(_DWORD *)(v12 + 8) = v14 | v13 | ((a5 & 0x1000) != 0);
    *(_DWORD *)(v12 + 12) = a6;
    if ( (a6 & 2) != 0 )
      return sub_529E70();
    if ( (a6 & 1) != 0 )
    {
      v16 = a1[6] & 0xFF0FFFFF;
      a1[6] = v16;
      if ( a5 )
        v17 = 0x100000;
      else
        v17 = 0x800000;
      a1[6] = v17 | v16;
      FsRtlpOplockEnqueueRH(a2 + 36, a1);
      FsRtlpModifyThreadPriorities(a2, a1, 1);
      FsRtlpOplockSendModernAppTermination(a2, a1);
    }
    else
    {
      ObfDereferenceObjectWithTag(a1[3]);
      if ( a1[5] )
        FsRtlpClearOwnerThread(a2, a1);
      ExFreePoolWithTag(a1, 0);
    }
    *(_DWORD *)(v8 + 28) = 24;
  }
  if ( *(_BYTE *)(v8 + 36) )
    a4 = -1073741536;
  *(_DWORD *)(v8 + 24) = a4;
  return pIofCompleteRequest(v8, 1);
}
