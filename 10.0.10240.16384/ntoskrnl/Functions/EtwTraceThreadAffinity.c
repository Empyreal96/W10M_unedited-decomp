// EtwTraceThreadAffinity 
 
int *__fastcall EtwTraceThreadAffinity(int a1, int a2)
{
  int v3[2]; // [sp+8h] [bp-30h] BYREF
  __int16 v4; // [sp+10h] [bp-28h]
  __int16 v5; // [sp+12h] [bp-26h]
  int v6[8]; // [sp+18h] [bp-20h] BYREF

  v3[1] = *(_DWORD *)(a1 + 880);
  v3[0] = *(_DWORD *)a2;
  v4 = *(_WORD *)(a2 + 4);
  v5 = 0;
  v6[0] = (int)v3;
  v6[1] = 0;
  v6[2] = 12;
  v6[3] = 0;
  return EtwTraceKernelEvent(v6, 1, 0x20001000u, 1333, 5249282);
}
