// RtlpHeapLogRangeDestroy 
 
int *__fastcall RtlpHeapLogRangeDestroy(int a1)
{
  int v3; // [sp+8h] [bp-40h] BYREF
  int v4[9]; // [sp+Ch] [bp-3Ch] BYREF
  int v5[6]; // [sp+30h] [bp-18h] BYREF

  v3 = 0;
  memset(v4, 0, sizeof(v4));
  v5[0] = (int)&v3;
  v5[1] = 0;
  v5[2] = 40;
  v5[3] = 0;
  v4[7] = a1;
  return EtwTraceKernelEvent(v5, 1, 0x40000020u, 616, 272636162);
}
