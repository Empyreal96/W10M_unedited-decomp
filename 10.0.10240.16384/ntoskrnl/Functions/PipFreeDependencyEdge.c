// PipFreeDependencyEdge 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PipFreeDependencyEdge(int a1, int a2)
{
  __int64 **v4; // r4
  __int64 v5; // r2
  int v6; // r8
  unsigned int v7; // r2
  int v8; // r1 OVERLAPPED
  _DWORD *v9; // r2 OVERLAPPED
  __int64 v10; // kr00_8
  int vars4; // [sp+1Ch] [bp+4h]

  v4 = (__int64 **)(a1 + 28);
  while ( *v4 != (__int64 *)v4 )
  {
    v5 = **v4;
    if ( (__int64 **)HIDWORD(v5) != v4 || *(__int64 **)(v5 + 4) != *v4 )
      __fastfail(3u);
    *v4 = (__int64 *)v5;
    *(_DWORD *)(v5 + 4) = v4;
    PipFreeBindingRequestEntry();
  }
  v6 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)&PiDependencyEdgeWriteLock);
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
  if ( a2 )
    *(_DWORD *)(a2 + 24) |= *(_DWORD *)(a1 + 24);
  *(_QWORD *)&v8 = *(_QWORD *)a1;
  if ( *(_DWORD *)(*(_DWORD *)a1 + 4) != a1 || *v9 != a1 )
    __fastfail(3u);
  *v9 = v8;
  *(_DWORD *)(v8 + 4) = v9;
  v10 = *(_QWORD *)(a1 + 8);
  if ( *(_DWORD *)(v10 + 4) != a1 + 8 || *(_DWORD *)HIDWORD(v10) != a1 + 8 )
    __fastfail(3u);
  *(_DWORD *)HIDWORD(v10) = v10;
  *(_DWORD *)(v10 + 4) = HIDWORD(v10);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&PiDependencyEdgeWriteLock, vars4);
  }
  else
  {
    __dmb(0xBu);
    PiDependencyEdgeWriteLock = 0;
  }
  KfLowerIrql(v6);
  PipNotifyDependenciesChanged(*(_DWORD *)(a1 + 20), *(_DWORD *)(a1 + 16));
  PipDereferenceDependencyNode(*(_DWORD *)(a1 + 16));
  PipDereferenceDependencyNode(*(_DWORD *)(a1 + 20));
  return ExFreePoolWithTag(a1);
}
