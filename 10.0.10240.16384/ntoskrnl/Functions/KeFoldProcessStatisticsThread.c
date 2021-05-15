// KeFoldProcessStatisticsThread 
 
int __fastcall KeFoldProcessStatisticsThread(int result)
{
  int v1; // r5
  int v2; // r2
  int v3; // r3
  _QWORD *v4; // r4
  int v5; // r7
  int v6; // r5
  int v7; // r6
  __int64 v8; // kr10_8

  v1 = *(_DWORD *)(result + 336);
  v2 = *(_DWORD *)(v1 + 156);
  *(_DWORD *)(v1 + 152) += *(_DWORD *)(result + 404);
  *(_DWORD *)(v1 + 156) = *(_DWORD *)(result + 448) + v2;
  *(_QWORD *)(v1 + 128) += *(_QWORD *)(result + 48);
  *(_QWORD *)(v1 + 136) += *(unsigned int *)(result + 128);
  v3 = *(_DWORD *)(result + 1084);
  if ( v3 )
  {
    v4 = *(_QWORD **)(v1 + 796);
    v5 = v3 - (_DWORD)v4;
    v6 = 4;
    do
    {
      v7 = 2;
      do
      {
        v8 = *(_QWORD *)((char *)v4 + v5);
        result = HIDWORD(v8);
        *v4++ += v8;
        --v7;
      }
      while ( v7 );
      --v6;
    }
    while ( v6 );
  }
  return result;
}
