// TraitsCompare 
 
int __fastcall TraitsCompare(int a1, int a2)
{
  unsigned int v2; // r0
  unsigned int v3; // r2
  unsigned int v4; // t1
  unsigned int v5; // r1
  unsigned int v6; // t1
  bool v7; // cc

  v4 = *(unsigned __int16 *)(a1 + 16);
  v2 = a1 + 16;
  v3 = v4;
  v6 = *(unsigned __int16 *)(a2 + 16);
  v5 = a2 + 16;
  v7 = v3 > v6;
  if ( v3 < v6 )
    return -1;
  if ( v7 )
    return 1;
  return memcmp(v2, v5, v3);
}
