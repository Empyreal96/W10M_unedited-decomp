// PipCreateNewDependencyEdge 
 
int __fastcall PipCreateNewDependencyEdge(unsigned int a1, unsigned int a2)
{
  unsigned __int64 v2; // r6
  int v3; // r0
  _DWORD *v4; // r4
  int v6; // r9
  unsigned int v7; // r2
  _DWORD *v8; // r0
  _DWORD *v9; // r1
  _DWORD *v10; // r1

  v2 = __PAIR64__(a1, a2);
  v3 = ExAllocatePoolWithTag(512, 40);
  v4 = (_DWORD *)v3;
  if ( v3 )
  {
    *(_DWORD *)(v3 + 24) = 0;
    *(_QWORD *)(v3 + 16) = v2;
    *(_DWORD *)(v3 + 28) = v3 + 28;
    *(_DWORD *)(v3 + 32) = v3 + 28;
    *(_BYTE *)(v3 + 36) = 0;
    if ( !PipAddRequestToEdge() )
      return sub_550B3C();
    PipReferenceDependencyNode(HIDWORD(v2));
    PipReferenceDependencyNode(v2);
    v6 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented(&PiDependencyEdgeWriteLock);
    }
    else
    {
      do
        v7 = __ldrex((unsigned int *)&PiDependencyEdgeWriteLock);
      while ( __strex(1u, (unsigned int *)&PiDependencyEdgeWriteLock) );
      __dmb(0xBu);
      if ( v7 )
        KxWaitForSpinLockAndAcquire((unsigned int *)&PiDependencyEdgeWriteLock);
    }
    v8 = *(_DWORD **)(v2 + 20);
    v9 = v4 + 2;
    v4[2] = v2 + 16;
    v4[3] = v8;
    if ( *v8 != (_DWORD)v2 + 16 )
      __fastfail(3u);
    *v8 = v9;
    *(_DWORD *)(v2 + 20) = v9;
    v10 = *(_DWORD **)(HIDWORD(v2) + 12);
    *v4 = HIDWORD(v2) + 8;
    v4[1] = v10;
    if ( *v10 != HIDWORD(v2) + 8 )
      __fastfail(3u);
    *v10 = v4;
    *(_DWORD *)(HIDWORD(v2) + 12) = v4;
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(&PiDependencyEdgeWriteLock);
    }
    else
    {
      __dmb(0xBu);
      PiDependencyEdgeWriteLock = 0;
    }
    KfLowerIrql(v6);
    PipNotifyDependenciesChanged(HIDWORD(v2), v2);
  }
  return (int)v4;
}
