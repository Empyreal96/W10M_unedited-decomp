// SmCrEncCleanup 
 
int __fastcall SmCrEncCleanup(int *a1)
{
  int v2; // r0
  int v3; // r0
  int v4; // r0
  int v5; // r0
  int result; // r0

  v2 = a1[2];
  if ( v2 )
    ST_STORE<SM_TRAITS>::StDmSparseBitmapFree(v2);
  v3 = a1[4];
  if ( v3 )
    BCryptDestroyKey(v3);
  v4 = a1[5];
  if ( v4 )
    ST_STORE<SM_TRAITS>::StDmSparseBitmapFree(v4);
  v5 = a1[6];
  if ( v5 )
    ST_STORE<SM_TRAITS>::StDmSparseBitmapFree(v5);
  result = *a1;
  if ( *a1 )
    result = BCryptCloseAlgorithmProvider(result);
  return result;
}
