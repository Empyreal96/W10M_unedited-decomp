// CmpTransMgrSyncHive 
 
int __fastcall CmpTransMgrSyncHive(_DWORD *a1)
{
  int v2; // r2
  int v3; // r3
  unsigned int v4; // r6
  unsigned int v5; // r7
  int v6; // r0
  int v7; // r5
  unsigned int v8; // r2
  int v9; // r0
  unsigned int *v10; // r5
  int v11; // r6
  unsigned int v12; // r1
  int v13; // r5

  CmpLockRegistry();
  ExAcquireResourceExclusiveLite(a1[468], 1, v2, v3);
  if ( (*(_DWORD *)(a1[8] + 144) & 1) == 0 )
  {
    v4 = a1[467];
    v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v6 = KeAbPreAcquire(v4, 0, 0);
    v7 = v6;
    do
      v8 = __ldrex((unsigned __int8 *)v4);
    while ( __strex(v8 & 0xFE, (unsigned __int8 *)v4) );
    __dmb(0xBu);
    if ( (v8 & 1) == 0 )
      ExpAcquireFastMutexContended(v4, v6);
    if ( v7 )
      *(_BYTE *)(v7 + 14) |= 1u;
    *(_DWORD *)(v4 + 4) = v5;
    v9 = HvpMarkDirty((int)a1, 0, 0x20u);
    v10 = (unsigned int *)a1[467];
    v11 = v9;
    v10[1] = 0;
    __dmb(0xBu);
    do
      v12 = __ldrex(v10);
    while ( !v12 && __strex(1u, v10) );
    if ( v12 )
      ExpReleaseFastMutexContended(v10, v12);
    KeAbPostRelease((unsigned int)v10);
    if ( !v11 )
    {
      v13 = -1073741670;
      ExReleaseResourceLite(a1[468]);
      CmpUnlockRegistry();
      return v13;
    }
    *(_DWORD *)(a1[8] + 144) |= 1u;
  }
  ExReleaseResourceLite(a1[468]);
  CmpUnlockRegistry();
  v13 = CmpFlushHive((int)a1, 0);
  if ( v13 < 0 )
    v13 = -1073741670;
  return v13;
}
