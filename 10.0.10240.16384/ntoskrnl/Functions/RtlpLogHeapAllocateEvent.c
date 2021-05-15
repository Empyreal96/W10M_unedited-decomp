// RtlpLogHeapAllocateEvent 
 
int *__fastcall RtlpLogHeapAllocateEvent(int a1, int a2, int a3, int a4)
{
  _DWORD v5[4]; // [sp+8h] [bp-30h] BYREF
  int v6[8]; // [sp+18h] [bp-20h] BYREF

  v5[2] = a2;
  v5[3] = a4;
  v6[0] = (int)v5;
  v6[1] = 0;
  v6[2] = 16;
  v6[3] = 0;
  v5[0] = a1;
  v5[1] = a3;
  return EtwTraceKernelEvent(v6, 1, 0x40000020u, 4129, 272636162);
}
