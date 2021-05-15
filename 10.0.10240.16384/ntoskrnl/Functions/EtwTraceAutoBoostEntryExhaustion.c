// EtwTraceAutoBoostEntryExhaustion 
 
int *__fastcall EtwTraceAutoBoostEntryExhaustion(int a1, int a2)
{
  int v2; // r3
  _DWORD v4[2]; // [sp+8h] [bp-28h] BYREF
  int v5[8]; // [sp+10h] [bp-20h] BYREF

  v2 = *(_DWORD *)(a1 + 880);
  v4[0] = a2;
  v4[1] = v2;
  v5[0] = (int)v4;
  v5[1] = 0;
  v5[2] = 8;
  v5[3] = 0;
  return EtwTraceKernelEvent(v5, 1, 0x20000200u, 1348, 5249538);
}
