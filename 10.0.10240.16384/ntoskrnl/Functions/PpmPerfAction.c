// PpmPerfAction 
 
int __fastcall PpmPerfAction(int a1, int a2)
{
  unsigned int *v3; // r2
  int result; // r0
  unsigned int v5; // r4
  unsigned int v6; // r1
  unsigned int v7; // r1
  int v8; // r2

  __dmb(0xBu);
  v3 = (unsigned int *)(a2 + 3192);
  result = 0;
  do
    v5 = __ldrex(v3);
  while ( __strex(0, v3) );
  __dmb(0xBu);
  if ( (v5 & 1) != 0 )
    result = PpmPerfSnapUtility(a2);
  if ( (v5 & 2) != 0 )
    result = PpmParkReportUnparkedCore(a2);
  if ( (v5 & 4) != 0 )
  {
    v8 = *(_DWORD *)(a2 + 3204);
    if ( *(_BYTE *)(v8 + 72) )
    {
      *(_BYTE *)(v8 + 72) = 0;
      PpmPerfApplyProcessorState(a2, 1);
    }
    result = PpmPerfApplyProcessorState(a2, 0);
  }
  if ( (v5 & 8) != 0 )
    result = PpmParkReportParkedCore(a2);
  __dmb(0xBu);
  do
  {
    v6 = __ldrex((unsigned int *)&PpmCheckCount);
    v7 = v6 - 1;
  }
  while ( __strex(v7, (unsigned int *)&PpmCheckCount) );
  __dmb(0xBu);
  if ( !v7 )
    result = KiInsertQueueDpc((int)&PpmCheckDpc, 0, 0, 0, 0);
  return result;
}
