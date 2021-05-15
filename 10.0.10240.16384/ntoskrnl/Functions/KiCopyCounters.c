// KiCopyCounters 
 
int __fastcall KiCopyCounters(_DWORD *a1)
{
  int v1; // r8
  int v3; // r5
  __int64 v4; // r6
  int v5; // r0
  __int64 v6; // r2

  v1 = a1[59];
  v3 = KfRaiseIrql(1);
  do
  {
    LODWORD(v4) = a1[13];
    HIDWORD(v4) = a1[12];
    __enable_irq();
    v5 = KiCopyCountersWorker(a1, v1);
    __disable_irq();
    if ( v5 )
      break;
    LODWORD(v6) = a1[13];
    HIDWORD(v6) = a1[12];
  }
  while ( v4 != v6 );
  return KfLowerIrql(v3);
}
