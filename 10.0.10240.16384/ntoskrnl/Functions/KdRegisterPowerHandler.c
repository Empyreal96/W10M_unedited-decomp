// KdRegisterPowerHandler 
 
int __fastcall KdRegisterPowerHandler(int a1, int a2, int **a3)
{
  int *v6; // r5
  int v8; // r7
  unsigned int v9; // r2
  int **v10; // r1
  int vars4; // [sp+1Ch] [bp+4h]

  v6 = (int *)ExAllocatePoolWithTag(512, 16);
  if ( !v6 )
    return -1073741670;
  v6[2] = a1;
  v6[3] = a2;
  v8 = KfRaiseIrql(15);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)&KdpPowerSpinLock);
  }
  else
  {
    do
      v9 = __ldrex((unsigned int *)&KdpPowerSpinLock);
    while ( __strex(1u, (unsigned int *)&KdpPowerSpinLock) );
    __dmb(0xBu);
    if ( v9 )
      KxWaitForSpinLockAndAcquire((unsigned int *)&KdpPowerSpinLock);
  }
  v10 = (int **)dword_627874;
  *v6 = (int)&KdpPowerListHead;
  v6[1] = (int)v10;
  if ( *v10 != &KdpPowerListHead )
    __fastfail(3u);
  *v10 = v6;
  dword_627874 = (int)v6;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&KdpPowerSpinLock, vars4);
  }
  else
  {
    __dmb(0xBu);
    KdpPowerSpinLock = 0;
  }
  KfLowerIrql(v8);
  *a3 = v6;
  return 0;
}
