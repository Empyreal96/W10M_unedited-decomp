// KiGenerateHeteroSets 
 
int __fastcall KiGenerateHeteroSets(int a1, int a2, int a3, int *a4, int *a5)
{
  int v5; // r0
  int v6; // r4
  int v7; // r2
  int result; // r0

  v5 = a1 + 8 * a3;
  v6 = *(_DWORD *)(v5 + 292) & a2;
  v7 = *(_DWORD *)(v5 + 296) & a2;
  if ( v7 )
  {
    result = 0;
    if ( !v6 )
      v6 = v7;
  }
  else
  {
    v7 = a2;
    v6 = a2;
    result = 1;
  }
  *a4 = v6;
  if ( v7 )
    *a5 = v7;
  return result;
}
