// EtwTraceEnqueueWork 
 
int *__fastcall EtwTraceEnqueueWork(int a1, int a2, int a3)
{
  int v3; // r3
  int v4; // r1
  _DWORD v6[2]; // [sp+8h] [bp-28h] BYREF
  int v7[8]; // [sp+10h] [bp-20h] BYREF

  v3 = *(_DWORD *)(a1 + 880);
  v6[0] = a2;
  v6[1] = v3;
  v4 = 5250562;
  if ( !a3 )
    v4 = 5244418;
  v7[0] = (int)v6;
  v7[1] = 0;
  v7[2] = 8;
  v7[3] = 0;
  return EtwTraceKernelEvent(v7, 1, 0x21000000u, 1342, v4);
}
