// CcCoherencyFlushAndPurgeCache 
 
int __fastcall CcCoherencyFlushAndPurgeCache(int a1, int a2, int a3, int *a4, char a5)
{
  int v9; // r6
  BOOL v10; // r5
  int v11; // r0
  int result; // r0

  v9 = 0;
  v10 = 0;
  v11 = MmTrimSection(a1, a2);
  *a4 = v11;
  if ( v11 == 277 )
    v9 = 1;
  result = CcFlushCachePriv(a1, a2, a3);
  if ( *a4 >= 0 )
  {
    if ( (a5 & 1) == 0 )
    {
      result = CcPurgeCacheSection(a1, a2, a3, 4);
      v10 = result == 0;
    }
    if ( *a4 >= 0 && (v9 || v10) )
      *a4 = 277;
  }
  return result;
}
