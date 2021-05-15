// SmcCacheCleanup 
 
int __fastcall SmcCacheCleanup(_DWORD *a1)
{
  int *v2; // r5
  int v3; // r6

  v2 = a1 + 31;
  v3 = 16;
  do
  {
    if ( *v2 != -1 )
    {
      SmStoreDelete(v2[1] & 3, *v2);
      ST_STORE<SM_TRAITS>::StDmSparseBitmapFree(v2[2]);
    }
    v2 += 4;
    --v3;
  }
  while ( v3 );
  if ( a1[10] && a1[11] )
    SmKmStoreFileDelete(a1 + 10);
  SmKmFileInfoCleanup(a1 + 10);
  return StEtaCleanup((int)(a1 + 18));
}
