// PerfInfoLogVirtualFree 
 
int *__fastcall PerfInfoLogVirtualFree(int a1, int a2, int a3, int a4)
{
  int v4; // r2
  int v6[4]; // [sp+8h] [bp-30h] BYREF
  int v7[8]; // [sp+18h] [bp-20h] BYREF

  v6[3] = a4;
  v7[0] = (int)v6;
  v7[1] = 0;
  v7[2] = 16;
  v4 = *(_DWORD *)(a3 + 176);
  v7[3] = 0;
  v6[1] = a2;
  v6[2] = v4;
  v6[0] = a1;
  return EtwTraceKernelEvent(v7, 1, 0x20008000u, 611, 5249282);
}
