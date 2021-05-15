// PnpDeviceCompletionQueueRemoveCompletedRequest 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PnpDeviceCompletionQueueRemoveCompletedRequest(int a1, int a2)
{
  int v3; // r6
  unsigned int v5; // r1
  int v6; // r1 OVERLAPPED
  _DWORD *v7; // r2 OVERLAPPED

  KeWaitForSingleObject((unsigned int)&byte_6306F4, 0, 0, 0, 0);
  v3 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_5188BC();
  do
    v5 = __ldrex((unsigned int *)&dword_630708);
  while ( __strex(1u, (unsigned int *)&dword_630708) );
  __dmb(0xBu);
  if ( v5 )
    KxWaitForSpinLockAndAcquire((unsigned int *)&dword_630708);
  *(_QWORD *)&v6 = *(_QWORD *)a2;
  if ( *(_DWORD *)(*(_DWORD *)a2 + 4) != a2 || *v7 != a2 )
    __fastfail(3u);
  *v7 = v6;
  *(_DWORD *)(v6 + 4) = v7;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&dword_630708);
  }
  else
  {
    __dmb(0xBu);
    dword_630708 = 0;
  }
  KfLowerIrql(v3);
  return a2;
}
