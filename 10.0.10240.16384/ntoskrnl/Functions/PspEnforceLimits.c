// PspEnforceLimits 
 
int __fastcall PspEnforceLimits(int a1, int a2, int a3, int a4, int a5)
{
  unsigned int v6; // r1
  unsigned int v7; // r1
  int result; // r0
  int i; // r4
  unsigned int *v10; // r2
  unsigned int v11; // r0
  char v12[80]; // [sp+18h] [bp-50h] BYREF

  __dmb(0xBu);
  do
  {
    v6 = __ldrex((unsigned int *)&PspEnforcementSequenceNumber);
    v7 = v6 + 1;
  }
  while ( __strex(v7, (unsigned int *)&PspEnforcementSequenceNumber) );
  __dmb(0xBu);
  if ( !a1 && PspNoWakeChargeReferencedProcess )
    return sub_7C279C(0, v7, (int)&PspEnforcementSequenceNumber, PspNoWakeChargeReferencedProcess, a5);
  result = PspGetNextJob(0);
  for ( i = result; result; i = result )
  {
    if ( !*(_DWORD *)(i + 572) && (!a1 || (*(_DWORD *)(i + 744) & 0x100000) != 0) )
    {
      __dmb(0xBu);
      v10 = (unsigned int *)(i + 744);
      do
        v11 = __ldrex(v10);
      while ( __strex(v11 & 0xFFEFFFFF, v10) );
      __dmb(0xBu);
      memset(v12, 0, 56);
      PspEnumJobsAndProcessesInJobHierarchy(
        i,
        PspEnforceLimitsJobPreCallback,
        PspEnforceLimitsJobPostCallback,
        PspEnforceLimitsProcessCallback,
        v12,
        6);
    }
    result = PspGetNextJob(i);
  }
  return result;
}
