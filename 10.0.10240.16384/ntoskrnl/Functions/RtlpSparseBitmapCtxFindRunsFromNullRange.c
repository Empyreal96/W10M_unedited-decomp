// RtlpSparseBitmapCtxFindRunsFromNullRange 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall RtlpSparseBitmapCtxFindRunsFromNullRange(_DWORD *a1, int a2, unsigned int a3, int a4, int a5, int a6, unsigned int a7, _BYTE *a8)
{
  int v9; // r5
  int v10; // r4
  unsigned int v12; // r9 OVERLAPPED
  unsigned int v13; // r10 OVERLAPPED
  unsigned int v14; // r4
  unsigned int v15; // r3
  unsigned int v17; // [sp+0h] [bp-28h]
  int v18; // [sp+4h] [bp-24h]

  v17 = a3;
  v18 = a5 + 16 * a4;
  v9 = a5;
  if ( (a1[12] & 1) != 0 )
  {
    v10 = a1[8];
    v13 = ((unsigned int)(v10 * a6) + (unsigned __int64)a7) >> 32;
    v12 = v10 * a6 + a7;
    v14 = v10 - a7;
    do
    {
      v15 = v14;
      if ( v14 >= a3 )
        v15 = a3;
      *(_QWORD *)v9 = *(_QWORD *)&v12;
      v13 = (__PAIR64__(v13, v12) + v15) >> 32;
      v12 += v15;
      v14 -= v15;
      *(_DWORD *)(v9 + 8) = v15;
      if ( a8 )
      {
        memset(a8, 0, a1[11]);
        a3 = v17;
        a8 += a1[11];
      }
      v9 += 16;
    }
    while ( v9 != v18 && v14 );
  }
  return (v9 - a5) >> 4;
}
