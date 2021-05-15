// PnpDeviceCompletionQueueGetCompletedRequest 
 
// local variable allocation has failed, the output may be wrong!
int PnpDeviceCompletionQueueGetCompletedRequest()
{
  int v0; // r6
  unsigned int v2; // r1
  int v3; // r5
  int v4; // r1 OVERLAPPED

  KeWaitForSingleObject((unsigned int)&byte_6306F4, 0, 0, 0, 0);
  v0 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_528458();
  do
    v2 = __ldrex((unsigned int *)&dword_630708);
  while ( __strex(1u, (unsigned int *)&dword_630708) );
  __dmb(0xBu);
  if ( v2 )
    KxWaitForSpinLockAndAcquire((unsigned int *)&dword_630708);
  v3 = dword_6306EC;
  *(_QWORD *)&v4 = *(_QWORD *)dword_6306EC;
  if ( *(int **)(dword_6306EC + 4) != &dword_6306EC || *(_DWORD *)(v4 + 4) != dword_6306EC )
    __fastfail(3u);
  dword_6306EC = v4;
  *(_DWORD *)(v4 + 4) = &dword_6306EC;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&dword_630708);
  }
  else
  {
    __dmb(0xBu);
    dword_630708 = 0;
  }
  KfLowerIrql(v0);
  return v3;
}
