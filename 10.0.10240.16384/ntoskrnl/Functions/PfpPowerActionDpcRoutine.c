// PfpPowerActionDpcRoutine 
 
int __fastcall PfpPowerActionDpcRoutine(int a1, _DWORD *a2)
{
  _DWORD *v2; // r5
  int v3; // r7
  int result; // r0
  unsigned int v5; // r1
  int v6; // r2
  int vars4; // [sp+1Ch] [bp+4h]

  v2 = a2;
  v3 = a2[24];
  if ( (dword_682604 & 0x210000) != 0 )
  {
    result = KiAcquireSpinLockInstrumented((int)&dword_6372D0);
  }
  else
  {
    result = 1;
    do
      v5 = __ldrex((unsigned int *)&dword_6372D0);
    while ( __strex(1u, (unsigned int *)&dword_6372D0) );
    __dmb(0xBu);
    if ( v5 )
      result = KxWaitForSpinLockAndAcquire((unsigned int *)&dword_6372D0);
  }
  v6 = v2[25];
  if ( v3 )
  {
    if ( dword_6372D4 == v6 && dword_6372C8 )
    {
      v2[22] = PfpServiceMainThreadUnboost;
      v2[23] = v2;
      v2[20] = 0;
      result = ExQueueWorkItem(v2 + 20, 1);
      v2 = 0;
    }
  }
  else if ( dword_6372D8 == v6 )
  {
    __dmb(0xBu);
    do
      result = __ldrex((unsigned int *)&dword_643B6C);
    while ( __strex(result & 0xFFFFFFFE, (unsigned int *)&dword_643B6C) );
    __dmb(0xBu);
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    result = KiReleaseSpinLockInstrumented(&dword_6372D0, vars4);
  }
  else
  {
    __dmb(0xBu);
    dword_6372D0 = 0;
  }
  if ( v2 )
    result = ExFreePoolWithTag(v2);
  return result;
}
