// PnpDeviceCompletionQueueDispatchedEntryCompleted 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PnpDeviceCompletionQueueDispatchedEntryCompleted(int a1, int *a2)
{
  int v3; // r6
  unsigned int v5; // r1
  int *v6; // r1 OVERLAPPED
  int **v7; // r2 OVERLAPPED
  int **v8; // r1

  v3 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_518968();
  do
    v5 = __ldrex((unsigned int *)&dword_630708);
  while ( __strex(1u, (unsigned int *)&dword_630708) );
  __dmb(0xBu);
  if ( v5 )
    KxWaitForSpinLockAndAcquire((unsigned int *)&dword_630708);
  *(_QWORD *)&v6 = *(_QWORD *)a2;
  if ( *(int **)(*a2 + 4) != a2 || *v7 != a2 )
    __fastfail(3u);
  *v7 = v6;
  v6[1] = (int)v7;
  --dword_6306E8;
  v8 = (int **)dword_6306F0;
  *a2 = (int)&dword_6306EC;
  a2[1] = (int)v8;
  if ( *v8 != &dword_6306EC )
    __fastfail(3u);
  *v8 = a2;
  dword_6306F0 = (int)a2;
  KeReleaseSemaphore((int)&byte_6306F4, 0, 1);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&dword_630708);
  }
  else
  {
    __dmb(0xBu);
    dword_630708 = 0;
  }
  return KfLowerIrql(v3);
}
