// CmpRemoveFromDelayedDeref 
 
int __fastcall CmpRemoveFromDelayedDeref(_DWORD *a1)
{
  int v2; // r8
  int v3; // r5
  int v4; // r7
  unsigned int v5; // r2
  _DWORD *v6; // r2
  __int64 v7; // r0
  unsigned int v8; // r1

  v2 = 0;
  v3 = KeAbPreAcquire((unsigned int)CmpDelayDerefKCBLock, 0, 0);
  v4 = KfRaiseIrql(1);
  do
    v5 = __ldrex(CmpDelayDerefKCBLock);
  while ( __strex(v5 & 0xFE, CmpDelayDerefKCBLock) );
  __dmb(0xBu);
  if ( (v5 & 1) == 0 )
    ExpAcquireFastMutexContended((int)CmpDelayDerefKCBLock, v3);
  if ( v3 )
    *(_BYTE *)(v3 + 14) |= 1u;
  dword_632324 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  dword_63233C = v4;
  if ( (a1[2] & 1) != 0 )
  {
    v6 = a1 + 29;
    v7 = *(_QWORD *)(a1 + 29);
    if ( *(_DWORD **)(v7 + 4) != a1 + 29 || *(_DWORD **)HIDWORD(v7) != v6 )
      sub_8061A0();
    *(_DWORD *)HIDWORD(v7) = v7;
    *(_DWORD *)(v7 + 4) = HIDWORD(v7);
    *v6 = v6;
    a1[30] = a1 + 29;
    __dmb(0xFu);
    v2 = 1;
    a1[2] &= 0xFFFFFFFE;
    LOBYTE(v4) = dword_63233C;
  }
  dword_632324 = 0;
  __dmb(0xBu);
  do
    v8 = __ldrex((unsigned int *)CmpDelayDerefKCBLock);
  while ( !v8 && __strex(1u, (unsigned int *)CmpDelayDerefKCBLock) );
  if ( v8 )
    ExpReleaseFastMutexContended((unsigned int *)CmpDelayDerefKCBLock, v8);
  KfLowerIrql((unsigned __int8)v4);
  KeAbPostRelease((unsigned int)CmpDelayDerefKCBLock);
  return v2;
}
