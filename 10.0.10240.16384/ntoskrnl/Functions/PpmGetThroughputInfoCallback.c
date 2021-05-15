// PpmGetThroughputInfoCallback 
 
int __fastcall PpmGetThroughputInfoCallback(int a1, _DWORD *a2)
{
  char v4; // r0
  unsigned int v5; // r1
  unsigned int v6; // r3
  unsigned int v7; // r2
  unsigned int v8; // r1
  unsigned int v9; // r3
  unsigned int v10; // r2
  unsigned int v11; // r1
  __int64 v13[12]; // [sp+8h] [bp-60h] BYREF

  memset(v13, 0, 80);
  PpmSnapPerformanceAccumulation(a1, 0, 0, 0, (int)v13);
  if ( *(_DWORD *)(a1 + 3112) == 3 )
    v4 = PpmHvPerformanceCounterShift;
  else
    v4 = PpmPerformanceCounterShift;
  v5 = HIDWORD(v13[4]);
  a2[2] = (unsigned __int64)v13[4] >> v4;
  v6 = v13[5];
  v7 = v5 >> v4;
  v8 = HIDWORD(v13[5]);
  a2[3] = v7;
  a2[4] = __PAIR64__(v8, v6) >> v4;
  v9 = v13[0];
  v10 = v8 >> v4;
  v11 = HIDWORD(v13[0]);
  a2[5] = v10;
  *a2 = __PAIR64__(v11, v9) >> v4;
  a2[1] = (unsigned __int64)v13[1] >> v4;
  return 0;
}
