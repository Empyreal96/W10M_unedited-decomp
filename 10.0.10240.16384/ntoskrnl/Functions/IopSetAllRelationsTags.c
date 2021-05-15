// IopSetAllRelationsTags 
 
int __fastcall IopSetAllRelationsTags(int result)
{
  _DWORD *v1; // r2
  unsigned int v2; // r4
  int v3; // r1
  _DWORD *v4; // r2

  v1 = *(_DWORD **)result;
  v2 = 0;
  if ( **(_DWORD **)result )
  {
    v3 = 0;
    do
    {
      v4 = &v1[v3];
      ++v2;
      v3 += 4;
      v4[7] &= 0xFFFFFFFE;
      v1 = *(_DWORD **)result;
    }
    while ( v2 < **(_DWORD **)result );
  }
  *(_DWORD *)(*(_DWORD *)result + 8) = 0;
  return result;
}
