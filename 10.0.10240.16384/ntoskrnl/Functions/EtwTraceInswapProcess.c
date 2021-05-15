// EtwTraceInswapProcess 
 
int *__fastcall EtwTraceInswapProcess(int a1)
{
  int v2[2]; // [sp+8h] [bp-28h] BYREF
  int v3[8]; // [sp+10h] [bp-20h] BYREF

  v2[1] = *(_DWORD *)(a1 + 176);
  v2[0] = *(_DWORD *)(a1 + 24);
  v3[0] = (int)v2;
  v3[1] = 0;
  v3[2] = 8;
  v3[3] = 0;
  return EtwTraceKernelEvent(v3, 1, 0x20000800u, 803, 5249282);
}
