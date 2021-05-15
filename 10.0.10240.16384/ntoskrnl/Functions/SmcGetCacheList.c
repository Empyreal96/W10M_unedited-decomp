// SmcGetCacheList 
 
int __fastcall SmcGetCacheList(_DWORD *a1, int a2)
{
  char v2; // r4
  unsigned int v3; // r2
  int v4; // r5

  v2 = 0;
  v3 = 0;
  v4 = a2;
  do
  {
    if ( *a1 )
    {
      ++v2;
      *(_DWORD *)(v4 + 4) = v3 | (16 * (a1[3] & 0xFFF));
      v4 += 4;
    }
    ++v3;
    a1 += 4;
  }
  while ( v3 < 0x10 );
  *(_BYTE *)(a2 + 1) = v2;
  return 0;
}
