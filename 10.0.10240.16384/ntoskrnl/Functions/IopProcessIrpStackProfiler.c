// IopProcessIrpStackProfiler 
 
unsigned int __fastcall IopProcessIrpStackProfiler(unsigned int result)
{
  unsigned int v1; // r7
  int v2; // lr
  unsigned int v3; // r5
  unsigned int v4; // r1
  int v5; // r6
  unsigned int v6; // r8
  unsigned int v7; // r4
  unsigned int v8; // r3
  unsigned int *v9; // r2
  unsigned int v10; // r7
  unsigned int v11; // r10
  unsigned int v12; // lr
  _QWORD *v13; // r5
  unsigned __int64 v14; // kr08_8
  unsigned __int64 v15; // kr10_8

  v1 = 0;
  v2 = IopLargeIrpStackLocations;
  v3 = 0;
  v4 = 0;
  v5 = IopMediumIrpStackLocations;
  v6 = result;
  v7 = IopLargeIrpStackLocations;
  if ( (IopIrpStackProfilerFlags & 1) != 0 )
  {
    v8 = 10;
    v9 = (unsigned int *)(result + 80);
    do
    {
      result = v9[1];
      if ( *(_QWORD *)v9 > __PAIR64__(v3, v1) )
      {
        v7 = v8;
        v1 = *v9;
        v3 = v9[1];
      }
      ++v8;
      v9 += 2;
    }
    while ( v8 < 0x14 );
    if ( !v3 && v1 < IopIrpStackProfilerMinSizeThreshold )
      v7 = IopLargeIrpStackLocations;
    v4 = 0;
  }
  if ( (IopIrpStackProfilerFlags & 2) != 0 )
  {
    result = 2;
    if ( v7 > 2 )
    {
      v10 = 0;
      v11 = 0;
      v12 = 0;
      v13 = (_QWORD *)(v6 + 16);
      do
      {
        v14 = __PAIR64__(v4, v12) + *v13;
        v4 = HIDWORD(v14);
        v12 = v14;
        v15 = result - (unsigned __int64)v7;
        if ( (__int64)(v15 * v14) < __SPAIR64__(v11, v10) )
        {
          v5 = result;
          v10 = v15 * v14;
          v11 = (v15 * v14) >> 32;
        }
        ++result;
        ++v13;
      }
      while ( result < v7 );
      v2 = IopLargeIrpStackLocations;
    }
  }
  if ( v2 != v7 )
    IopLargeIrpStackLocations = v7;
  if ( IopMediumIrpStackLocations != v5 )
    IopMediumIrpStackLocations = v5;
  return result;
}
