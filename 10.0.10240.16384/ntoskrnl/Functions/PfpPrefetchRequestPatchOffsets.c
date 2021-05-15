// PfpPrefetchRequestPatchOffsets 
 
int __fastcall PfpPrefetchRequestPatchOffsets(int result)
{
  unsigned int v1; // r1
  int v2; // r4
  unsigned int v3; // r6
  _DWORD *v4; // r7
  int v5; // r5
  _DWORD *v6; // r2
  int v7; // r3

  v1 = 0;
  *(_DWORD *)(result + 32) += result;
  if ( *(_DWORD *)(result + 8) )
  {
    v2 = 0;
    do
    {
      v3 = 0;
      v4 = (_DWORD *)(v2 + *(_DWORD *)(result + 32));
      v4[6] += result;
      v4[4] += result;
      if ( (v4[3] & 0xFFFFFFFE) != 0 )
      {
        v5 = 0;
        do
        {
          v6 = (_DWORD *)(v4[4] + v5);
          v7 = v6[6];
          if ( v7 )
            v6[6] = v7 + result;
          if ( v6[4] )
            v6[5] += result;
          ++v3;
          v5 += 32;
        }
        while ( v3 < v4[3] >> 1 );
      }
      ++v1;
      v2 += 32;
    }
    while ( v1 < *(_DWORD *)(result + 8) );
  }
  *(_DWORD *)(result + 44) += result;
  if ( *(_DWORD *)(result + 20) )
    result = sub_80F194();
  return result;
}
