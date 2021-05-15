// EtwTraceAutoBoostClearFloor 
 
int *__fastcall EtwTraceAutoBoostClearFloor(int a1, int a2, __int16 a3)
{
  int v3; // r3
  _DWORD v5[2]; // [sp+8h] [bp-30h] BYREF
  __int16 v6; // [sp+10h] [bp-28h]
  __int16 v7; // [sp+12h] [bp-26h]
  int v8[8]; // [sp+18h] [bp-20h] BYREF

  v3 = *(_DWORD *)(a1 + 880);
  v6 = a3;
  v5[0] = a2;
  v5[1] = v3;
  v7 = 0;
  v8[0] = (int)v5;
  v8[1] = 0;
  v8[2] = 12;
  v8[3] = 0;
  return EtwTraceKernelEvent(v8, 1, 0x20000200u, 1347, 5249538);
}
