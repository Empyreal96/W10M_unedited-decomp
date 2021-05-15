// FsRtlpOplockBreakToII 
 
int __fastcall FsRtlpOplockBreakToII(_DWORD *a1, int a2, int a3, int a4, int a5, int a6, int a7, _BYTE *a8, int a9)
{
  int v12; // r3
  int v13; // r2
  int v14; // r5
  unsigned int *v15; // r2
  unsigned int v16; // r1
  int v17; // r3
  int v18; // r3
  int v19; // r2
  int v23; // [sp+18h] [bp-28h] BYREF

  v12 = a1[18];
  if ( (v12 & 0x40) == 0
    || (v12 & 0x7000) != 0
    || (a4 & 8) == 0 && FsRtlpOplockKeysEqual(*(_DWORD *)(a2 + 28), a1[1], 0) )
  {
    return 0;
  }
  if ( (a4 & 0x10010000) != 0 )
    return -1073739511;
  v13 = a1[18];
  if ( (v13 & 0x1F00F80) == 0 )
  {
    v14 = *a1;
    *(_BYTE *)(v14 + 37) = KeAcquireQueuedSpinLock(7);
    __dmb(0xBu);
    v15 = (unsigned int *)(v14 + 56);
    do
      v16 = __ldrex(v15);
    while ( __strex(0, v15) );
    __dmb(0xBu);
    KeReleaseQueuedSpinLock(7, *(unsigned __int8 *)(v14 + 37));
    if ( *(_BYTE *)(v14 + 36) )
    {
      *(_DWORD *)(v14 + 28) = 8;
      FsRtlpModifyThreadPriorities(a1, 0, 0);
      FsRtlpClearOwnerThread(a1, 0);
      *((_BYTE *)a1 + 16) = 0;
      *(_DWORD *)(*a1 + 24) = -1073741536;
      pIofCompleteRequest(*a1, 1);
      *a1 = 0;
      ObfDereferenceObjectWithTag(a1[1]);
      a1[1] = 0;
      a1[18] = a1[18] & 0x20 | 1;
      while ( (_DWORD *)a1[11] != a1 + 11 )
        FsRtlpRemoveAndCompleteWaitingIrp(a1[11]);
      return 0;
    }
    v17 = a1[18];
    if ( (v17 & 6) != 0 )
    {
      v18 = v17 | 0x100;
      v19 = 7;
    }
    else
    {
      v18 = v17 | 0x200;
      v19 = 8;
    }
    a1[18] = v18;
    *(_DWORD *)(*a1 + 28) = v19;
    *(_DWORD *)(*a1 + 24) = 0;
    pIofCompleteRequest(*a1, 1);
    *a1 = 0;
    goto LABEL_20;
  }
  if ( (v13 & 0x80) == 0 )
  {
LABEL_20:
    if ( (a4 & 1) == 0 )
    {
      FsRtlpModifyThreadPriorities(a1, 0, 1);
      FsRtlpOplockSendModernAppTermination(a1, 0);
      *a8 = 0;
      return FsRtlpWaitOnIrp(a1, a3, a5, a6, a7, &v23, 0, a9, 0);
    }
    return 264;
  }
  a1[18] = a1[18] & 0x20 | 1;
  a1[1] = 0;
  return 0;
}
