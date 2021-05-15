// MiLogPerfMemoryEvent 
 
int *__fastcall MiLogPerfMemoryEvent(int a1, unsigned int a2, int a3, int a4, int a5)
{
  int v6[8]; // [sp+8h] [bp-20h] BYREF

  v6[0] = a3;
  v6[1] = 0;
  v6[2] = a4;
  v6[3] = 0;
  return EtwTraceKernelEvent(v6, 1, a2, a1, a5 | 0x11000200);
}
