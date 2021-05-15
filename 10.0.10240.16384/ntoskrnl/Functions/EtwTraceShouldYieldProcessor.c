// EtwTraceShouldYieldProcessor 
 
int *__fastcall EtwTraceShouldYieldProcessor(int a1, int a2, int a3)
{
  _DWORD v4[4]; // [sp+8h] [bp-30h] BYREF
  int v5[8]; // [sp+18h] [bp-20h] BYREF

  v5[0] = (int)v4;
  v5[1] = 0;
  v5[2] = 12;
  v5[3] = 0;
  v4[0] = a1;
  v4[1] = a2;
  v4[2] = a3;
  return EtwTraceKernelEvent(v5, 1, 0x24000000u, 3949, 4196866);
}
