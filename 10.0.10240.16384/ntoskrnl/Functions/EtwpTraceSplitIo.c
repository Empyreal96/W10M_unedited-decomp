// EtwpTraceSplitIo 
 
int *__fastcall EtwpTraceSplitIo(int a1, int a2, int a3)
{
  int v4[12]; // [sp+8h] [bp-30h] BYREF

  v4[0] = a1;
  v4[1] = 0;
  v4[2] = 4;
  v4[3] = 0;
  v4[4] = a2;
  v4[5] = 0;
  v4[6] = 4;
  v4[7] = 0;
  return EtwTraceKernelEvent(v4, 2, 0x200000u, a3, 4200450);
}
