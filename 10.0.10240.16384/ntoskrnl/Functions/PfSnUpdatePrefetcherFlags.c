// PfSnUpdatePrefetcherFlags 
 
int __fastcall PfSnUpdatePrefetcherFlags(int a1, int a2)
{
  int v4; // r9
  unsigned int v6; // r1
  int v7; // r5
  int v8; // r3

  v4 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_55500C();
  do
    v6 = __ldrex((unsigned int *)&dword_637378);
  while ( __strex(1u, (unsigned int *)&dword_637378) );
  __dmb(0xBu);
  if ( v6 )
    KxWaitForSpinLockAndAcquire((unsigned int *)&dword_637378);
  v7 = dword_637410;
  if ( a2 )
    v8 = dword_637410 | a1;
  else
    v8 = dword_637410 & ~a1;
  dword_637410 = v8;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&dword_637378);
  }
  else
  {
    __dmb(0xBu);
    dword_637378 = 0;
  }
  KfLowerIrql(v4);
  return v7;
}
