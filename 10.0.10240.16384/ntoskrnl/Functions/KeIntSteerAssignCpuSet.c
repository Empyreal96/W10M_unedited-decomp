// KeIntSteerAssignCpuSet 
 
int __fastcall KeIntSteerAssignCpuSet(int a1, int a2, int a3)
{
  int v3; // r5
  int v6; // r5
  int v7; // r9
  unsigned int v8; // r2
  int v9; // r0
  int vars4; // [sp+1Ch] [bp+4h]

  v3 = *(_DWORD *)(a1 + 100);
  if ( !v3 )
    return -1073741637;
  v7 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)&KiIntTrackSpinlock);
  }
  else
  {
    do
      v8 = __ldrex((unsigned int *)&KiIntTrackSpinlock);
    while ( __strex(1u, (unsigned int *)&KiIntTrackSpinlock) );
    __dmb(0xBu);
    if ( v8 )
      KxWaitForSpinLockAndAcquire((unsigned int *)&KiIntTrackSpinlock);
  }
  v9 = *(_DWORD *)(v3 + 8);
  if ( a3 )
  {
    v6 = KiIntSteerAssignCpuSet(v9, a2, a3);
  }
  else
  {
    KiIntSteerClearCpuSetAssignment(v9);
    v6 = 0;
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&KiIntTrackSpinlock, vars4);
  }
  else
  {
    __dmb(0xBu);
    KiIntTrackSpinlock = 0;
  }
  KfLowerIrql(v7);
  return v6;
}
