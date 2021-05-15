// RtlpLogHeapCreateEvent 
 
int *__fastcall RtlpLogHeapCreateEvent(int a1, int a2, int a3, int a4)
{
  int v4; // r2
  int v5; // r3
  _DWORD v7[6]; // [sp+8h] [bp-38h] BYREF
  int v8[8]; // [sp+20h] [bp-20h] BYREF

  v7[2] = a3;
  v7[3] = a4;
  v4 = *(_DWORD *)(a1 + 116);
  v5 = *(_DWORD *)(a1 + 484);
  v7[0] = a1;
  v7[1] = a2;
  v7[4] = v5 - 8 * v4;
  v8[0] = (int)v7;
  v8[1] = 0;
  v8[2] = 20;
  v8[3] = 0;
  return EtwTraceKernelEvent(v8, 1, 0x40000020u, 4128, 272636163);
}
