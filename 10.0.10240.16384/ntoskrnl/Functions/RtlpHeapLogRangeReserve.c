// RtlpHeapLogRangeReserve 
 
int *__fastcall RtlpHeapLogRangeReserve(int a1, int a2, int a3)
{
  int v7; // [sp+8h] [bp-50h] BYREF
  _DWORD v8[11]; // [sp+Ch] [bp-4Ch] BYREF
  int v9[8]; // [sp+38h] [bp-20h] BYREF

  v7 = 0;
  memset(v8, 0, sizeof(v8));
  v9[0] = (int)&v7;
  v9[1] = 0;
  v9[2] = 48;
  v9[3] = 0;
  v8[7] = a1;
  v8[8] = a2;
  v8[9] = a3;
  return EtwTraceKernelEvent(v9, 1, 0x40000020u, 614, 272636162);
}
