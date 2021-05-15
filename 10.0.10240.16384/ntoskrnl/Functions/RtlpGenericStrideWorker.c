// RtlpGenericStrideWorker 
 
int __fastcall RtlpGenericStrideWorker(int a1, int a2, int a3, unsigned int a4)
{
  int v4; // r6
  unsigned int v8; // r4
  unsigned int v9; // r5
  int v10; // r2
  _DWORD *i; // r3
  int v12; // r2

  v4 = 0;
  v8 = (a4 >> 2) - 12 * ((unsigned int)((2863311531u * (unsigned __int64)(a4 >> 2)) >> 32) >> 3);
  v9 = a4 + 4096;
  while ( 1 )
  {
    v10 = v8 > 2 * v4 ? 2 * v4 - v8 + 12 : 2 * v4 - v8;
    for ( i = (_DWORD *)(a4 + 4 * v10); (unsigned int)i < v9; i += 12 )
    {
      *i = a1;
      i[1] = a1;
    }
    KeInvalidateRangeAllCaches(a4, 4096);
    RtlpFillMemoryWithInverseStride(a2, v4, v12, a4);
    KeInvalidateRangeAllCaches(a4, 4096);
    if ( !RtlpTestMemoryWithStride(a1, v4) )
      break;
    if ( (unsigned int)++v4 >= 6 )
      return 1;
  }
  return 0;
}
