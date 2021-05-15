// EtwTraceFreezeThawProcess 
 
int *__fastcall EtwTraceFreezeThawProcess(int a1, int a2)
{
  int *v3; // r2
  int v4; // r3
  int v6; // [sp+8h] [bp-30h] BYREF
  int v7[10]; // [sp+10h] [bp-28h] BYREF

  v6 = *(_DWORD *)(a1 + 176);
  v7[0] = (int)&v6;
  v7[1] = 0;
  v7[2] = 4;
  v7[3] = 0;
  v7[4] = a1 + 200;
  v7[5] = 0;
  v7[6] = 8;
  v7[7] = 0;
  if ( (dword_61AD48 & 2) != 0 )
  {
    if ( a2 )
      v3 = ProcessFreezeEvent;
    else
      v3 = ProcessThawEvent;
    EtwWrite(EtwpPsProvRegHandle, dword_61A934, (int)v3, 0);
  }
  if ( a2 )
    v4 = 804;
  else
    v4 = 805;
  return EtwTraceKernelEvent(v7, 1, 0x40000002u, v4, 5249282);
}
