// PpmPerfResetHistory 
 
_DWORD *__fastcall PpmPerfResetHistory(_DWORD *result)
{
  unsigned int *v1; // r1
  unsigned int v2; // r2
  unsigned int v3; // r4
  int v4; // r5
  unsigned int *v5; // r2
  int v6; // r3

  v1 = (unsigned int *)result[804];
  if ( v1 )
  {
    v2 = *v1;
    v1[1] = 0;
    v1[3] = 0;
    v3 = 0;
    v1[2] = result[810] * v2;
    v4 = result[807];
    v1[4] = v4 * v2;
    v1[5] = 0;
    v1[6] = 0;
    if ( *v1 )
    {
      v5 = v1;
      do
      {
        *((_WORD *)v5 + 15) = 0;
        v6 = result[810];
        *((_BYTE *)v5 + 32) = v4;
        ++v3;
        *((_WORD *)v5 + 14) = v6;
        *(_WORD *)((char *)v5 + 33) = 0;
        v5 += 2;
      }
      while ( v3 < *v1 );
    }
  }
  return result;
}
