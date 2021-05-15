// sub_804E74 
 
void sub_804E74()
{
  _DWORD *v0; // r4
  int v1; // r7
  int v2; // r6
  int v3; // r8
  unsigned int v4; // r2
  int **v5; // r0
  unsigned __int8 v6; // r4
  unsigned int v7; // r1

  v1 = 0;
  v2 = KeAbPreAcquire((unsigned int)CmpDelayDerefKCBLock, 0, 0);
  v3 = KfRaiseIrql(1);
  do
    v4 = __ldrex(CmpDelayDerefKCBLock);
  while ( __strex(v4 & 0xFE, CmpDelayDerefKCBLock) );
  __dmb(0xBu);
  if ( (v4 & 1) == 0 )
    ExpAcquireFastMutexContended((int)CmpDelayDerefKCBLock, v2);
  if ( v2 )
    *(_BYTE *)(v2 + 14) |= 1u;
  dword_632324 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  dword_63233C = v3;
  v0[2] |= 1u;
  v5 = (int **)dword_63230C;
  v0[29] = &CmpDelayDerefKCBListHead;
  v0[30] = v5;
  if ( *v5 != &CmpDelayDerefKCBListHead )
    __fastfail(3u);
  *v5 = v0 + 29;
  dword_63230C = (int)(v0 + 29);
  if ( !CmpDelayDerefKCBWorkItemActive )
  {
    CmpDelayDerefKCBWorkItemActive = 1;
    v1 = 1;
  }
  dword_632324 = 0;
  v6 = dword_63233C;
  __dmb(0xBu);
  do
    v7 = __ldrex((unsigned int *)CmpDelayDerefKCBLock);
  while ( !v7 && __strex(1u, (unsigned int *)CmpDelayDerefKCBLock) );
  if ( v7 )
    ExpReleaseFastMutexContended((unsigned int *)CmpDelayDerefKCBLock, v7);
  KfLowerIrql(v6);
  KeAbPostRelease((unsigned int)CmpDelayDerefKCBLock);
  if ( v1 )
    CmpArmDelayDerefKCBWorker();
  JUMPOUT(0x74E67A);
}
