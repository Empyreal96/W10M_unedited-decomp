// PerfLogExecutiveResourceInitialize 
 
int *__fastcall PerfLogExecutiveResourceInitialize(int a1, int a2, int a3, int a4)
{
  unsigned int v4; // r4
  _DWORD v6[12]; // [sp+8h] [bp-50h] BYREF
  int v7[8]; // [sp+38h] [bp-20h] BYREF

  v4 = (unsigned int)KeGetPcr();
  ++*(_DWORD *)((v4 & 0xFFFFF000) + 0x14B0);
  v6[8] = a2;
  v6[9] = a1;
  v6[6] = a3;
  v6[0] = 0;
  v6[1] = 0;
  v6[2] = 0;
  v6[3] = 0;
  v6[4] = 0;
  v6[5] = 0;
  v6[10] = a4;
  v6[7] = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x370);
  v7[0] = (int)v6;
  v7[1] = 0;
  v7[2] = 48;
  v7[3] = 0;
  return EtwTraceKernelEvent(v7, 1, 0x20020000u, 1323, 22026242);
}
