// SmKmGetStoreList 
 
int __fastcall SmKmGetStoreList(int a1, int a2)
{
  char v2; // r4
  unsigned int v3; // r2
  int v4; // r5

  v2 = 0;
  v3 = 0;
  v4 = a2;
  do
  {
    if ( *(_DWORD *)a1 )
    {
      ++v2;
      *(_DWORD *)(v4 + 4) = v3 | (32 * (*(_WORD *)(a1 + 12) & 0x7FF));
      v4 += 4;
    }
    ++v3;
    a1 += 96;
  }
  while ( v3 < 0x20 );
  *(_BYTE *)(a2 + 1) = v2;
  return 0;
}
