// RtlpSparseBitmapCtxPrepareRanges 
 
int __fastcall RtlpSparseBitmapCtxPrepareRanges(int a1, int *a2, unsigned int a3, unsigned int a4, int a5, int a6)
{
  int result; // r0
  int v10; // r2
  int v11; // r3

  result = RtlpSparseBitmapCtxCheckRangeArray(a1, a2);
  if ( result >= 0 )
  {
    v10 = *(_DWORD *)(a1 + 48);
    if ( (a6 || (v10 & 1) != 0) && (a6 != 1 || (v10 & 1) == 0) )
    {
      while ( a3 < a4 )
      {
        v11 = *(_DWORD *)(a1 + 4);
        if ( (!v11 || !*(_DWORD *)(v11 + 4 * a3)) && !RtlSparseBitmapCtxAllocateRange(a1, a3) )
          return -1073741670;
        ++a3;
      }
    }
    result = 0;
  }
  return result;
}
