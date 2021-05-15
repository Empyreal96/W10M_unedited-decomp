// PspRemoveProperty 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PspRemoveProperty(int a1, int a2, _DWORD *a3)
{
  unsigned int *v4; // r5
  int v7; // r9
  unsigned int v9; // r2
  _DWORD *v10; // r0
  _DWORD *v11; // r4
  int v12; // r1 OVERLAPPED
  _DWORD *v13; // r2 OVERLAPPED

  v4 = (unsigned int *)(a1 + 8);
  v7 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_51F75C();
  do
    v9 = __ldrex(v4);
  while ( __strex(1u, v4) );
  __dmb(0xBu);
  if ( v9 )
    KxWaitForSpinLockAndAcquire(v4);
  v10 = (_DWORD *)PspFindPropertySetEntry(a1, a2);
  v11 = v10;
  if ( v10 )
  {
    if ( a3 )
      *a3 = v10[3];
    *(_QWORD *)&v12 = *(_QWORD *)v10;
    if ( *(_DWORD **)(*v10 + 4) != v10 || (_DWORD *)*v13 != v10 )
      __fastfail(3u);
    *v13 = v12;
    *(_DWORD *)(v12 + 4) = v13;
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(v4);
  }
  else
  {
    __dmb(0xBu);
    *v4 = 0;
  }
  KfLowerIrql(v7);
  if ( v11 )
  {
    ObfDereferenceObjectWithTag(v11[3]);
    ExFreePoolWithTag(v11, 1349742672);
  }
  return 0;
}
