// PfpServiceMainThreadUnboost 
 
unsigned int __fastcall PfpServiceMainThreadUnboost(int a1)
{
  int v2; // r7
  int v3; // r9
  unsigned int v4; // r1
  unsigned int result; // r0
  int vars4; // [sp+1Ch] [bp+4h]

  v2 = 0;
  v3 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)&dword_6372D0);
  }
  else
  {
    do
      v4 = __ldrex((unsigned int *)&dword_6372D0);
    while ( __strex(1u, (unsigned int *)&dword_6372D0) );
    __dmb(0xBu);
    if ( v4 )
      KxWaitForSpinLockAndAcquire((unsigned int *)&dword_6372D0);
  }
  if ( !a1 || dword_6372D4 == *(_DWORD *)(a1 + 100) )
  {
    v2 = dword_6372C8;
    if ( dword_6372C8 )
    {
      dword_6372C8 = 0;
      KeSetActualBasePriorityThread(v2, dword_6372CC);
    }
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&dword_6372D0, vars4);
  }
  else
  {
    __dmb(0xBu);
    dword_6372D0 = 0;
  }
  result = KfLowerIrql(v3);
  if ( v2 )
    result = ObDereferenceObjectDeferDeleteWithTag(v2);
  if ( a1 )
    result = ExFreePoolWithTag(a1);
  return result;
}
