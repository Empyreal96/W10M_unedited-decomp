// MmInSwapVirtualAddresses 
 
int __fastcall MmInSwapVirtualAddresses(int a1, unsigned int a2)
{
  __int16 *v3; // r4
  int v4; // r1

  EtwTraceWorkingSetSwap();
  v3 = MiGetThreadPartition();
  MiProcessWsInSwapSupport(a2, v4);
  ExFreePoolWithTag(a2);
  MiContractWsSwapPageFile((int)v3);
  EtwTraceWorkingSetSwap();
  return 0;
}
