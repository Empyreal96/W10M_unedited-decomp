// MiDecayPfnFullyInitialized 
 
int __fastcall MiDecayPfnFullyInitialized(int a1, int a2, int a3, int a4)
{
  int v5; // r6
  int v6; // r5
  int result; // r0
  _DWORD v8[6]; // [sp+0h] [bp-18h] BYREF

  v8[1] = a3;
  v8[2] = a4;
  v5 = (a1 - MmPfnDatabase) / 24;
  v6 = 0;
  KeAcquireInStackQueuedSpinLock(algn_63FD74, v8);
  if ( (*(_BYTE *)(a1 + 19) & 8) != 0 )
  {
    if ( *(_DWORD *)(a1 + 8) >> 12 != v5 )
      goto LABEL_3;
    MiUnlinkPageFromList(a1, 1);
    MiRemoveDecayClusterTimer(a1);
  }
  v6 = 1;
LABEL_3:
  *(_BYTE *)(a1 + 19) &= 0xF7u;
  result = KeReleaseInStackQueuedSpinLock(v8);
  if ( v6 == 1 )
    result = RtlpInterlockedPushEntrySList((unsigned __int64 *)&dword_634698, (_DWORD *)a1);
  return result;
}
