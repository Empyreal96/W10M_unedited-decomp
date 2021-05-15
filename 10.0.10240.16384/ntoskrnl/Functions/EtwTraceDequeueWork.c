// EtwTraceDequeueWork 
 
int *__fastcall EtwTraceDequeueWork(int a1, int a2, int a3)
{
  _DWORD v4[4]; // [sp+8h] [bp-40h] BYREF
  int v5[12]; // [sp+18h] [bp-30h] BYREF

  v4[0] = *(_DWORD *)(a1 + 880);
  v4[1] = a3;
  v5[0] = (int)v4;
  v5[1] = 0;
  v5[2] = 8;
  v5[3] = 0;
  v5[4] = a2;
  v5[5] = 0;
  v5[6] = 4 * a3;
  v5[7] = 0;
  return EtwTraceKernelEvent(v5, 2, 0x21000000u, 1343, 22027778);
}
