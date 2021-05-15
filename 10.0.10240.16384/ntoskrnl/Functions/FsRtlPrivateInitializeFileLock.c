// FsRtlPrivateInitializeFileLock 
 
int __fastcall FsRtlPrivateInitializeFileLock(_DWORD *a1, int a2)
{
  int v4; // r5
  int v5; // r9
  unsigned int v6; // r2
  _DWORD *v7; // r0
  unsigned __int8 v8; // r5
  unsigned int v9; // r1
  unsigned __int8 v11; // [sp+0h] [bp-28h]

  v4 = KeAbPreAcquire((unsigned int)&FsRtlCreateLockInfo, 0, 0);
  v5 = KfRaiseIrql(1);
  do
    v6 = __ldrex((unsigned __int8 *)&FsRtlCreateLockInfo);
  while ( __strex(v6 & 0xFE, (unsigned __int8 *)&FsRtlCreateLockInfo) );
  __dmb(0xBu);
  if ( (v6 & 1) == 0 )
    ExpAcquireFastMutexContended((int)&FsRtlCreateLockInfo, v4);
  if ( v4 )
    *(_BYTE *)(v4 + 14) |= 1u;
  dword_631EA4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  dword_631EBC = v5;
  if ( a1[3] )
    goto LABEL_13;
  v7 = (_DWORD *)ExAllocateFromNPagedLookasideList((int)&FsRtlLockInfoLookasideList);
  if ( v7 )
  {
    *v7 = -1;
    v7[1] = -1;
    v7[4] = 0;
    v7[5] = 0;
    v7[6] = 0;
    v7[7] = 0;
    v7[8] = 0;
    v7[2] = *a1;
    v7[3] = a1[1];
    a1[10] = 0;
    a1[14] = 0;
    a1[3] = v7;
LABEL_13:
    v11 = 1;
    goto LABEL_14;
  }
  if ( !a2 )
    RtlRaiseStatus(-1073741670);
  v11 = 0;
LABEL_14:
  dword_631EA4 = 0;
  v8 = dword_631EBC;
  __dmb(0xBu);
  do
    v9 = __ldrex((unsigned int *)&FsRtlCreateLockInfo);
  while ( !v9 && __strex(1u, (unsigned int *)&FsRtlCreateLockInfo) );
  if ( v9 )
    ExpReleaseFastMutexContended((unsigned int *)&FsRtlCreateLockInfo, v9);
  KfLowerIrql(v8);
  KeAbPostRelease((unsigned int)&FsRtlCreateLockInfo);
  return v11;
}
