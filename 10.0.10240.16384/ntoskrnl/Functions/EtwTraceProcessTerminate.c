// EtwTraceProcessTerminate 
 
int __fastcall EtwTraceProcessTerminate(int a1)
{
  int v2; // [sp+8h] [bp-28h] BYREF
  int v3[8]; // [sp+10h] [bp-20h] BYREF

  v2 = *(_DWORD *)(a1 + 176);
  v3[0] = (int)&v2;
  v3[1] = 0;
  v3[2] = 4;
  v3[3] = 0;
  return EtwTraceKernelEvent(v3, 1, 1, 779, 5249282);
}
