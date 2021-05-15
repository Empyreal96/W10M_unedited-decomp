// KdRegisterDebuggerDataBlock 
 
int __fastcall KdRegisterDebuggerDataBlock(int a1, int *a2)
{
  int v3; // r6
  unsigned int v5; // r2
  int *v6; // r1
  int *v7; // r3
  int **v8; // r1
  int vars4; // [sp+14h] [bp+4h]

  v3 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_903E28();
  do
    v5 = __ldrex((unsigned int *)&KdpDataSpinLock);
  while ( __strex(1u, (unsigned int *)&KdpDataSpinLock) );
  __dmb(0xBu);
  if ( v5 )
    KxWaitForSpinLockAndAcquire((unsigned int *)&KdpDataSpinLock);
  v6 = (int *)KdpDebuggerDataListHead;
  while ( v6 != &KdpDebuggerDataListHead )
  {
    v7 = v6;
    v6 = (int *)*v6;
    if ( v7 == a2 || v7[4] == 1195525195 )
    {
      if ( (dword_682604 & 0x10000) != 0 )
      {
        KiReleaseSpinLockInstrumented(&KdpDataSpinLock, vars4);
      }
      else
      {
        __dmb(0xBu);
        KdpDataSpinLock = 0;
      }
      KfLowerIrql(v3);
      return 0;
    }
  }
  a2[4] = 1195525195;
  a2[5] = 864;
  v8 = (int **)dword_62786C;
  *a2 = (int)&KdpDebuggerDataListHead;
  a2[1] = (int)v8;
  if ( *v8 != &KdpDebuggerDataListHead )
    __fastfail(3u);
  *v8 = a2;
  dword_62786C = (int)a2;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&KdpDataSpinLock, vars4);
  }
  else
  {
    __dmb(0xBu);
    KdpDataSpinLock = 0;
  }
  KfLowerIrql(v3);
  return 1;
}
