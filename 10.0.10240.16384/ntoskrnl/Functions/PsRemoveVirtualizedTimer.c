// PsRemoveVirtualizedTimer 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PsRemoveVirtualizedTimer(int a1, int a2)
{
  unsigned int *v2; // r4
  int v4; // r6
  unsigned int v6; // r2
  int v7; // r1 OVERLAPPED
  _DWORD *v8; // r2 OVERLAPPED

  v2 = (unsigned int *)(a1 + 692);
  v4 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_53EF9C();
  do
    v6 = __ldrex(v2);
  while ( __strex(1u, v2) );
  __dmb(0xBu);
  if ( v6 )
    KxWaitForSpinLockAndAcquire(v2);
  *(_QWORD *)&v7 = *(_QWORD *)a2;
  if ( *(_DWORD *)(*(_DWORD *)a2 + 4) != a2 || *v8 != a2 )
    __fastfail(3u);
  *v8 = v7;
  *(_DWORD *)(v7 + 4) = v8;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(v2);
  }
  else
  {
    __dmb(0xBu);
    *v2 = 0;
  }
  return KfLowerIrql(v4);
}
