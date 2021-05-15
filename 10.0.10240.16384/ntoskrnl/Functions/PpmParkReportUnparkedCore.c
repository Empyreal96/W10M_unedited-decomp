// PpmParkReportUnparkedCore 
 
int __fastcall PpmParkReportUnparkedCore(int a1)
{
  int v2; // r3
  unsigned int v3; // r4

  KeTransitionProcessorParkState();
  *(_BYTE *)(a1 + 3222) = 0;
  v2 = *(_DWORD *)(a1 + 20);
  __dmb(0xBu);
  do
    v3 = __ldrex((unsigned int *)&dword_616318);
  while ( __strex(v3 & ~(1 << v2), (unsigned int *)&dword_616318) );
  __dmb(0xBu);
  return PpmEventCoreParkingStateChange(a1, 0);
}
