// PiDmGetCachedKeyIndex 
 
int __fastcall PiDmGetCachedKeyIndex(unsigned int *a1, unsigned int a2, unsigned int a3)
{
  int v4; // r4
  int v7; // r8
  unsigned int v8; // r1
  unsigned int v9; // t1

  v4 = 0;
  if ( !a2 )
    return -1;
  v7 = *(_DWORD *)(a3 + 16);
  while ( 1 )
  {
    v9 = *a1;
    a1 += 4;
    v8 = v9;
    if ( v7 == *(_DWORD *)(v9 + 16) && !memcmp(a3, v8, 16) )
      break;
    if ( ++v4 >= a2 )
      return -1;
  }
  return v4;
}
