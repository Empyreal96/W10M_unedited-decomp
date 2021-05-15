// PerfInfoLogUnexpectedInterrupt 
 
int *__fastcall PerfInfoLogUnexpectedInterrupt(int a1, int a2)
{
  int v3[7]; // [sp+8h] [bp-28h] BYREF
  _DWORD v4[2]; // [sp+28h] [bp-8h] BYREF

  v4[0] = a1;
  v4[1] = a2;
  v3[0] = (int)v4;
  v3[1] = 0;
  v3[2] = 2;
  v3[3] = 0;
  return EtwTraceKernelEvent(v3, 1, 0x20004000u, 3932, 4196866);
}
