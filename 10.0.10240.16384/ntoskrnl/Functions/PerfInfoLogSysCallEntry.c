// PerfInfoLogSysCallEntry 
 
int __fastcall PerfInfoLogSysCallEntry(int a1)
{
  int v3; // [sp+8h] [bp-20h] BYREF
  int v4[6]; // [sp+10h] [bp-18h] BYREF

  v4[0] = (int)&v3;
  v4[1] = 0;
  v4[2] = 4;
  v4[3] = 0;
  v3 = a1;
  EtwTraceKernelEvent(v4, 1, 0x40000040u, 3891, 5249026);
  return a1;
}
