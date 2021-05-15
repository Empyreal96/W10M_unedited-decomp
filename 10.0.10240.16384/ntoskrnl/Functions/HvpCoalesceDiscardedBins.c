// HvpCoalesceDiscardedBins 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall HvpCoalesceDiscardedBins(int a1, unsigned int a2, int a3)
{
  int v3; // r10
  int *v5; // r4
  int v6; // r8
  __int64 v7; // kr00_8
  int v8; // r0
  _DWORD *v9; // r0
  _DWORD *v10; // r5
  int v11; // r1 OVERLAPPED
  _DWORD *v12; // r2 OVERLAPPED
  unsigned int i; // r7
  int **v14; // r0
  int v15; // r2
  __int64 v16; // kr08_8
  int v17; // r0
  int v18; // r0
  _DWORD *v19; // r5
  int v20; // r1 OVERLAPPED
  _DWORD *v21; // r2 OVERLAPPED
  unsigned int j; // r7
  int **v23; // r0

  v3 = a1 + 412 * a3;
  v5 = *(int **)(v3 + 1352);
  v6 = v3 + 1352;
  if ( v5 == (int *)(v3 + 1352) )
    return 0;
  while ( 1 )
  {
    if ( (v5[4] & 1) == 0 )
    {
      v7 = *((_QWORD *)v5 + 1);
      if ( (unsigned int)(HIDWORD(v7) + v7) <= *(_DWORD *)(v3 + 952) )
      {
        if ( !HvpGetCellMap(a1, HIDWORD(v7)) )
          KeBugCheckEx(81, 1, a1, v5[3], 1568);
        if ( HIDWORD(v7) )
        {
          do
          {
            v8 = HvpGetCellMap(a1, v5[3] - 4096);
            if ( !v8 )
              KeBugCheckEx(81, 1, a1, v5[3] - 4096, 1575);
            v9 = (_DWORD *)HvpMapEntryGetFreeBin(v8);
            v10 = v9;
            if ( !v9 || (v9[4] & 1) != 0 || !HvpCheckViewBoundary(v9[3], v9[2] + v5[2] + v9[3] - 1) )
              break;
            *(_QWORD *)&v11 = *(_QWORD *)v10;
            if ( *(_DWORD **)(*v10 + 4) != v10 || (_DWORD *)*v12 != v10 )
              __fastfail(3u);
            *v12 = v11;
            *(_DWORD *)(v11 + 4) = v12;
            for ( i = 0; i < v10[2]; i += 4096 )
            {
              v14 = (int **)HvpGetCellMap(a1, i + v10[3]);
              if ( !v14 )
                KeBugCheckEx(81, 1, a1, v10[3] + i, 1611);
              *v14 = v5;
            }
            v15 = v5[2];
            v5[3] = v10[3];
            v5[2] = v10[2] + v15;
            (*(void (__fastcall **)(_DWORD *, int))(a1 + 16))(v10, 20);
          }
          while ( v5[3] );
        }
        if ( (unsigned int)(v5[3] + v5[2]) < *(_DWORD *)(v3 + 952) )
        {
          do
          {
            v16 = *((_QWORD *)v5 + 1);
            v17 = HvpGetCellMap(a1, HIDWORD(v16) + v16);
            if ( !v17 )
              KeBugCheckEx(81, 1, a1, v5[2] + v5[3], 1626);
            v18 = HvpMapEntryGetFreeBin(v17);
            v19 = (_DWORD *)v18;
            if ( !v18
              || (*(_DWORD *)(v18 + 16) & 1) != 0
              || !HvpCheckViewBoundary(SHIDWORD(v16), *(_DWORD *)(v18 + 8) + HIDWORD(v16) + v16 - 1) )
            {
              break;
            }
            *(_QWORD *)&v20 = *(_QWORD *)v19;
            if ( *(_DWORD **)(*v19 + 4) != v19 || (_DWORD *)*v21 != v19 )
              __fastfail(3u);
            *v21 = v20;
            *(_DWORD *)(v20 + 4) = v21;
            for ( j = 0; j < v19[2]; j += 4096 )
            {
              v23 = (int **)HvpGetCellMap(a1, v19[3] + j);
              if ( !v23 )
                KeBugCheckEx(81, 1, a1, v19[3] + j, 1656);
              *v23 = v5;
            }
            v5[2] += v19[2];
            (*(void (__fastcall **)(_DWORD *, int))(a1 + 16))(v19, 20);
          }
          while ( (unsigned int)(v5[3] + v5[2]) < *(_DWORD *)(v3 + 952) );
          v6 = v3 + 1352;
        }
        if ( v5[2] >= a2 )
          break;
      }
    }
    v5 = (int *)*v5;
    if ( v5 == (int *)v6 )
      return 0;
  }
  return 1;
}
