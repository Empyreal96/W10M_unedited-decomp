// PfpPrefetchVolumesCleanup 
 
_DWORD *__fastcall PfpPrefetchVolumesCleanup(_DWORD *result)
{
  _DWORD *v1; // r4
  unsigned int v2; // r6
  int v3; // r5
  int v4; // r2
  int *v5; // r0

  v1 = result;
  if ( result[2] )
  {
    v2 = 0;
    if ( *(_DWORD *)(*result + 8) )
    {
      v3 = 0;
      do
      {
        v4 = v3 + v1[2];
        if ( (*(_DWORD *)(v4 + 36) & 4) != 0 )
          PfpOpenHandleClose((int *)(v4 + 20), v1[5]);
        v5 = (int *)(v3 + v1[2]);
        if ( (v5[4] & 4) != 0 )
          PfpOpenHandleClose(v5, v1[5]);
        ++v2;
        v3 += 40;
      }
      while ( v2 < *(_DWORD *)(*v1 + 8) );
    }
    result = (_DWORD *)ExFreePoolWithTag(v1[2]);
    v1[2] = 0;
  }
  return result;
}
