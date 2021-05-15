// ViGetAdapterInformationInternal 
 
int *__fastcall ViGetAdapterInformationInternal(int a1, int a2)
{
  unsigned int v4; // r0
  int v5; // r8
  unsigned int v6; // r1
  int *i; // r5
  int vars4; // [sp+2Ch] [bp+4h]

  if ( !a1 )
    return 0;
  v4 = KeGetCurrentIrql(a1);
  if ( v4 > 2 )
  {
    if ( ViVerifyDma )
      VF_ASSERT_MAX_IRQL(v4);
    return 0;
  }
  if ( !ViVerifyDma && ViEnableAfterHibernate == 1 )
    return 0;
  v5 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)&dword_908C58);
  }
  else
  {
    do
      v6 = __ldrex((unsigned int *)&dword_908C58);
    while ( __strex(1u, (unsigned int *)&dword_908C58) );
    __dmb(0xBu);
    if ( v6 )
      KxWaitForSpinLockAndAcquire((unsigned int *)&dword_908C58);
  }
  for ( i = (int *)ViAdapterList; ; i = (int *)*i )
  {
    if ( &ViAdapterList == i )
    {
      if ( (dword_682604 & 0x10000) != 0 )
      {
        KiReleaseSpinLockInstrumented(&dword_908C58, vars4);
      }
      else
      {
        __dmb(0xBu);
        dword_908C58 = 0;
      }
      KfLowerIrql(v5);
      return 0;
    }
    if ( a1 == i[2] )
      break;
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&dword_908C58, vars4);
  }
  else
  {
    __dmb(0xBu);
    dword_908C58 = 0;
  }
  KfLowerIrql(v5);
  if ( a2 && i[5] <= 0 )
  {
    ViHalPreprocessOptions(
      &dword_6187C8,
      "Driver has attempted to access an adapter (%p) that has already been released",
      (const void *)0x18);
    VfReportIssueWithOptions(230, 24, a1, (int)i, 0, &dword_6187C8);
  }
  return i;
}
