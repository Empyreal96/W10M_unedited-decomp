// EtwTraceDpcEnqueueEvent 
 
int *__fastcall EtwTraceDpcEnqueueEvent(int *result, int (*a2)(), int a3, int a4, int a5, char a6)
{
  int v6[4]; // [sp+8h] [bp-30h] BYREF
  char v7; // [sp+18h] [bp-20h]
  __int16 v8; // [sp+19h] [bp-1Fh]
  char v9; // [sp+1Bh] [bp-1Dh]
  int v10[6]; // [sp+20h] [bp-18h] BYREF

  if ( a2 != EtwpStackWalkDpc )
  {
    v6[1] = a3;
    v6[2] = a4;
    v6[0] = (int)result;
    v6[3] = a5;
    v7 = a6;
    v8 = 0;
    v9 = 0;
    v10[0] = (int)v6;
    v10[1] = 0;
    v10[2] = 20;
    v10[3] = 0;
    result = EtwTraceKernelEvent(v10, 1, 0x20040000u, 3940, 5250562);
  }
  return result;
}
