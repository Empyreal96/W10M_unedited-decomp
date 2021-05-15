// RtlComputeLfnChecksum 
 
int __fastcall RtlComputeLfnChecksum(unsigned __int16 *a1)
{
  __int16 *v1; // r4
  int v2; // r5
  __int16 *v3; // r2
  unsigned int v4; // r3
  unsigned int v5; // r0
  unsigned int v6; // r1
  __int16 v7; // t1

  v1 = (__int16 *)*((_DWORD *)a1 + 1);
  v2 = 0;
  v3 = &v1[*a1 >> 1];
  v4 = 2 * (*a1 >> 1) + 1;
  v5 = 0;
  if ( v1 > v3 )
    v6 = 0;
  else
    v6 = v4 >> 1;
  if ( v6 )
  {
    do
    {
      v7 = *v1++;
      ++v5;
      v2 = (unsigned __int16)(v7 + 37 * v2);
    }
    while ( v5 < v6 );
  }
  return (unsigned __int16)((int)abs32(314159269 * v2) % 1000000007);
}
