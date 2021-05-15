// AslFileFreeAttributes 
 
_BYTE *__fastcall AslFileFreeAttributes(_BYTE *result)
{
  _BYTE *v1; // r5
  _DWORD *v2; // r4
  int v3; // r6
  int v4; // r2
  unsigned int v5; // r0

  v1 = result;
  if ( result )
  {
    v2 = result;
    v3 = 32;
    do
    {
      v4 = v2[4];
      if ( (v4 & 1) != 0 && *v2 == 4 && (v4 & 4) != 0 )
      {
        v5 = v2[2];
        if ( v5 )
          ExFreePoolWithTag(v5);
      }
      v2 += 6;
      --v3;
    }
    while ( v3 );
    result = memset(v1, 0, 768);
  }
  return result;
}
