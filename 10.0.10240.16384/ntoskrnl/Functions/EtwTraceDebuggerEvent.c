// EtwTraceDebuggerEvent 
 
int *__fastcall EtwTraceDebuggerEvent(int a1, int a2, int a3)
{
  int v3; // r3
  int v5[4]; // [sp+8h] [bp-30h] BYREF
  int v6[8]; // [sp+18h] [bp-20h] BYREF

  v3 = *(_DWORD *)(a1 + 176);
  v5[2] = a3;
  v5[0] = v3;
  v5[1] = *(_DWORD *)(a2 + 880);
  v6[0] = (int)v5;
  v6[1] = 0;
  v6[2] = 12;
  v6[3] = 0;
  return EtwTraceKernelEvent(v6, 1, 0x400000u, 880, 4200962);
}
