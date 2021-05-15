// KeIntSteerAssignCpuSetForGsiv 
 
int __fastcall KeIntSteerAssignCpuSetForGsiv(int a1, int a2, int a3)
{
  int v3; // r5
  int v7; // r10
  unsigned int v8; // r2
  int *v9; // r2
  int *i; // r0
  int vars4; // [sp+24h] [bp+4h]

  if ( a1 == -1 )
    v3 = 0;
  if ( a1 != -1 )
    v3 = -1073741275;
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
  v9 = &KiIntTrackRootList;
  for ( i = (int *)KiIntTrackRootList; i != v9; i = (int *)*i )
  {
    if ( a1 == -1 )
    {
      i = (int *)KiIntSteerClearCpuSetAssignment(i);
    }
    else if ( i[4] == a1 )
    {
      v3 = KiIntSteerAssignCpuSet(i, a2, a3);
      break;
    }
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
  return v3;
}
