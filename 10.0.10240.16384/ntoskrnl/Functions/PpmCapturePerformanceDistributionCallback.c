// PpmCapturePerformanceDistributionCallback 
 
int __fastcall PpmCapturePerformanceDistributionCallback(int a1, _DWORD *a2)
{
  unsigned int v3; // r5
  int result; // r0
  unsigned int v6; // r6
  unsigned int v7; // r9
  unsigned int v8; // r8
  unsigned __int64 v9; // kr00_8
  unsigned __int64 v10; // kr08_8
  char v11; // r1
  __int64 v12[14]; // [sp+8h] [bp-70h] BYREF

  v3 = a2[2];
  result = 0;
  if ( v3 + 7 >= v3 )
    v3 = (v3 + 7) & 0xFFFFFFF8;
  if ( *(_DWORD *)(a1 + 3204) )
    v6 = 2;
  else
    v6 = 0;
  v7 = 16 * v6 + 8 + v3;
  if ( v7 <= a2[1] )
  {
    v8 = v3 + *a2;
    if ( v6 >= 2 )
    {
      memset(v12, 0, 80);
      if ( !PpmSnapPerformanceAccumulation(a1, 0, a1 != ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408, 0, (int)v12) )
        return -1073741823;
      v9 = v12[3];
      v10 = 255 * v12[1] - v12[3];
      if ( *(_DWORD *)(a1 + 3112) == 3 )
        v11 = PpmHvPerformanceDistributionShift;
      else
        v11 = PpmPerformanceDistributionShift;
      *(_DWORD *)(v8 + 8) = v10 >> v11;
      *(_BYTE *)(v8 + 16) = 0;
      *(_DWORD *)(v8 + 12) = HIDWORD(v10) >> v11;
      *(_DWORD *)(v8 + 24) = v9 >> v11;
      *(_BYTE *)(v8 + 32) = -1;
      *(_DWORD *)(v8 + 28) = HIDWORD(v9) >> v11;
    }
    *(_DWORD *)(*a2 + 4 * a2[3]++ + 4) = v3;
    *(_DWORD *)v8 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594);
    *(_DWORD *)(v8 + 4) = v6;
    result = 0;
  }
  a2[2] = v7;
  return result;
}
