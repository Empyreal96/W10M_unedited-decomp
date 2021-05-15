// PpmIdleWaitForDependentTransitions 
 
int __fastcall PpmIdleWaitForDependentTransitions(int a1)
{
  unsigned int v1; // r5
  unsigned int v2; // r2
  int v3; // r4
  int v4; // r7
  int v5; // r1
  int v6; // r2
  int v8[14]; // [sp+8h] [bp-38h] BYREF

  v1 = *(_DWORD *)(a1 + 8);
  while ( v1 )
  {
    v2 = __clz(__rbit(v1));
    v1 &= ~(1 << v2);
    if ( v2 >= KeNumberProcessors_0 )
      v3 = 0;
    else
      v3 = (int)*(&KiProcessorBlock + v2);
    v4 = *(_DWORD *)(v3 + 2944);
    memset(v8, 0, 32);
    LOBYTE(v8[6]) = 1;
    v8[4] = v3;
    v8[2] = PopIdleTransitionTimeout;
    v8[3] = MEMORY[0x6824EC];
    while ( !(*(int (__fastcall **)(_DWORD))(v4 + 112))(*(_DWORD *)(v4 + 120)) )
    {
      if ( (*(_DWORD *)(v3 + 3000) & 0xFF000000) != 83886080 )
        return -1073741782;
      PpmIdleTransitionStall((int)v8, v5, v6, 83886080);
    }
  }
  return 0;
}
