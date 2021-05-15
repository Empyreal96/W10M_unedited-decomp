// FsRtlpRemoveAndCompleteWaitingIrp 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall FsRtlpRemoveAndCompleteWaitingIrp(int a1)
{
  int v2; // r1 OVERLAPPED
  _DWORD *v3; // r2 OVERLAPPED
  int v4; // r5
  unsigned int *v5; // r2
  unsigned int v6; // r1
  int v7; // r3

  *(_QWORD *)&v2 = *(_QWORD *)a1;
  if ( *(_DWORD *)(*(_DWORD *)a1 + 4) != a1 || *v3 != a1 )
    __fastfail(3u);
  *v3 = v2;
  *(_DWORD *)(v2 + 4) = v3;
  v4 = *(_DWORD *)(a1 + 8);
  if ( v4 )
  {
    *(_BYTE *)(v4 + 37) = KeAcquireQueuedSpinLock(7);
    __dmb(0xBu);
    v5 = (unsigned int *)(v4 + 56);
    do
      v6 = __ldrex(v5);
    while ( __strex(0, v5) );
    __dmb(0xBu);
    KeReleaseQueuedSpinLock(7, *(unsigned __int8 *)(v4 + 37));
    *(_DWORD *)(v4 + 28) = *(_DWORD *)(a1 + 24);
    if ( *(_BYTE *)(v4 + 36) )
      v7 = -1073741536;
    else
      v7 = 0;
    *(_DWORD *)(v4 + 24) = v7;
  }
  (*(void (__fastcall **)(_DWORD, int))(a1 + 12))(*(_DWORD *)(a1 + 16), v4);
  return ExFreePoolWithTag(a1);
}
