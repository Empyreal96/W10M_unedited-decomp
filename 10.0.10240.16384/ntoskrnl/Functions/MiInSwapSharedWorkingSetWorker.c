// MiInSwapSharedWorkingSetWorker 
 
int __fastcall MiInSwapSharedWorkingSetWorker(unsigned int *a1)
{
  int v2; // r6
  unsigned int *v3; // r4
  unsigned int v4; // r1
  unsigned int v5; // r2
  __int16 *v6; // r0
  char v8[40]; // [sp+18h] [bp-28h] BYREF

  v2 = a1[6];
  KiStackAttachProcess(v2, 0, (int)v8);
  EtwTraceWorkingSetSwap();
  __dmb(0xBu);
  v3 = (unsigned int *)(v2 + 792);
  do
    v4 = __ldrex(v3);
  while ( __strex(0x3E8u, v3) );
  __dmb(0xBu);
  MiProcessWsInSwapSupport(a1[1], 1);
  __dmb(0xBu);
  do
    v5 = __ldrex(v3);
  while ( __strex(0, v3) );
  __dmb(0xBu);
  EtwTraceWorkingSetSwap();
  KiUnstackDetachProcess((unsigned int)v8, 0);
  v6 = MiGetThreadPartition();
  a1[6] = 0;
  MiFreeWorkingSetSwapContext((int)v6, a1);
  return ObfDereferenceObjectWithTag(v2);
}
