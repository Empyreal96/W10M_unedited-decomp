// MiPurgeFileExtentPage 
 
int __fastcall MiPurgeFileExtentPage(int a1, int a2)
{
  int v2; // r3
  int v3; // r1
  int v4; // r2
  int v5; // r3

  v2 = a2 - *(_DWORD *)(a1 + 4);
  v3 = *(_DWORD *)(a1 + 12);
  v4 = (v2 >> 2) + 1;
  v5 = *(_DWORD *)(v3 + 4 * v4);
  if ( v5 < 0 )
    return 0;
  *(_DWORD *)(v3 + 4 * v4) = v5 | 0x80000000;
  return 1;
}
