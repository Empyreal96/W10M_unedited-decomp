// PnpDeviceCompletionQueueIsEmpty 
 
int PnpDeviceCompletionQueueIsEmpty()
{
  int v0; // r5
  int v1; // r7
  unsigned int v3; // r1

  v0 = 0;
  v1 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_518998();
  do
    v3 = __ldrex((unsigned int *)&dword_630708);
  while ( __strex(1u, (unsigned int *)&dword_630708) );
  __dmb(0xBu);
  if ( v3 )
    KxWaitForSpinLockAndAcquire((unsigned int *)&dword_630708);
  if ( (int *)PnpDeviceCompletionQueue == &PnpDeviceCompletionQueue && (int *)dword_6306EC == &dword_6306EC )
    v0 = 1;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&dword_630708);
  }
  else
  {
    __dmb(0xBu);
    dword_630708 = 0;
  }
  KfLowerIrql(v1);
  return v0;
}
