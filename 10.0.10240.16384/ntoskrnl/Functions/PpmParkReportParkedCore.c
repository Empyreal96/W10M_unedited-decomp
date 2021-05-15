// PpmParkReportParkedCore 
 
int __fastcall PpmParkReportParkedCore(int a1)
{
  int v2; // r3
  unsigned int v3; // r4
  int v4; // r2

  KeTransitionProcessorParkState();
  *(_BYTE *)(a1 + 3222) = 1;
  v2 = *(_DWORD *)(a1 + 20);
  __dmb(0xBu);
  do
    v3 = __ldrex((unsigned int *)&dword_616318);
  while ( __strex(v3 | (1 << v2), (unsigned int *)&dword_616318) );
  __dmb(0xBu);
  if ( (__get_CPSR() & 0x80) != 0 )
  {
    v4 = 0;
  }
  else
  {
    __disable_irq();
    v4 = 1;
  }
  *(_DWORD *)(a1 + 1784) = 0;
  *(_DWORD *)(a1 + 1780) = *(_DWORD *)(a1 + 2304);
  if ( v4 )
    __enable_irq();
  return PpmEventCoreParkingStateChange(a1, 1);
}
