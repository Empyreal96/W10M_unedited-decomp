// HvpIsMetadataArrayCoherent 
 
int __fastcall HvpIsMetadataArrayCoherent(unsigned int *a1, unsigned int *a2, unsigned int a3)
{
  int v3; // r7
  unsigned int v4; // lr
  int v5; // r5
  unsigned int v7; // r4
  unsigned int v8; // r1
  unsigned int v9; // t1

  v4 = (8 * a1[5] + __PAIR64__(a1[5] >> 29, 40)) >> 32;
  v3 = 8 * a1[5] + 40;
  v5 = 0;
  if ( !a3 )
    return 1;
  while ( 1 )
  {
    v7 = a2[1];
    if ( !v7 )
      break;
    if ( (v7 & 0xFFF) != 0 )
      break;
    v9 = *a2;
    a2 += 2;
    v8 = v9;
    if ( (v9 & 0xFFF) != 0 || v8 + v7 < v8 || v8 + v7 > a1[4] || v5 && v8 <= *(a2 - 3) + *(a2 - 4) )
      break;
    v4 = (__PAIR64__(v4, v3) + v7) >> 32;
    v3 += v7;
    if ( __PAIR64__(v4, v3) > a1[1] )
      break;
    if ( ++v5 >= a3 )
      return 1;
  }
  return 0;
}
