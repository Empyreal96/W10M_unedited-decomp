// PpmTracePerfIdleRundown 
 
int __fastcall PpmTracePerfIdleRundown(_DWORD *a1)
{
  int v2; // r3
  int v4[6]; // [sp+8h] [bp-30h] BYREF
  int v5[6]; // [sp+20h] [bp-18h] BYREF

  if ( a1[800] )
  {
    memset(v4, 0, sizeof(v4));
    PpmPerfGetCurrentState(a1, &v4[1], 0, 0, v4, 0);
    v4[2] = v4[1];
    v4[4] = a1[262];
    v4[5] = 0;
    v5[0] = (int)v4;
    v5[1] = 0;
    v5[2] = 24;
    v5[3] = 0;
    EtwTraceKernelEvent(v5, 1, 0x80008000, 4659, 4200450);
  }
  v2 = a1[736];
  if ( v2 )
    PpmEventIdleStateChange(*(_DWORD *)(v2 + 12), *(_DWORD *)(v2 + 12));
  return 0;
}
