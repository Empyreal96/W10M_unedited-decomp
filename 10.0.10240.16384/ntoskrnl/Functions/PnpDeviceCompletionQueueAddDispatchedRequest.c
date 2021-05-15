// PnpDeviceCompletionQueueAddDispatchedRequest 
 
int __fastcall PnpDeviceCompletionQueueAddDispatchedRequest(int a1, int *a2)
{
  int v3; // r7
  unsigned int v5; // r1
  BOOL v6; // r5
  int **v7; // r2

  v3 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_5188E8();
  do
    v5 = __ldrex((unsigned int *)&dword_630708);
  while ( __strex(1u, (unsigned int *)&dword_630708) );
  __dmb(0xBu);
  if ( v5 )
    KxWaitForSpinLockAndAcquire((unsigned int *)&dword_630708);
  v6 = PnpDeviceCompletionQueue == (_DWORD)&PnpDeviceCompletionQueue;
  v7 = (int **)dword_6306E4;
  *a2 = (int)&PnpDeviceCompletionQueue;
  a2[1] = (int)v7;
  if ( *v7 != &PnpDeviceCompletionQueue )
    __fastfail(3u);
  *v7 = a2;
  dword_6306E4 = (int)a2;
  ++dword_6306E8;
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
  return v6;
}
