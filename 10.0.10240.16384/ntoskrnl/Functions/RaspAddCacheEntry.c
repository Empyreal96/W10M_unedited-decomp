// RaspAddCacheEntry 
 
int *__fastcall RaspAddCacheEntry(int *result, int *a2)
{
  int v2; // r2
  int v3; // r2
  int v4; // r3
  __int64 *v5; // r2
  __int64 v6; // kr00_8

  v2 = *result;
  *a2 = *result;
  a2[1] = (int)result;
  if ( *(int **)(v2 + 4) != result )
    sub_8DFD14();
  *(_DWORD *)(v2 + 4) = a2;
  *result = (int)a2;
  v3 = result[7];
  if ( v3 )
  {
    v4 = result[8];
    if ( v4 == v3 )
    {
      v5 = (__int64 *)result[1];
      v6 = *v5;
      if ( *(int **)v5 != result || *(__int64 **)HIDWORD(v6) != v5 )
        __fastfail(3u);
      result[1] = HIDWORD(v6);
      *(_DWORD *)HIDWORD(v6) = result;
      result = (int *)RaspDestroyCachedBitmap((int)v5, SHIDWORD(v6), (int)v5, v6);
    }
    else
    {
      result[8] = v4 + 1;
    }
  }
  return result;
}
