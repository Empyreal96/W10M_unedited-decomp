// PopPowerRequestCompare 
 
int __fastcall PopPowerRequestCompare(int a1, int a2, int a3)
{
  int v3; // r3
  int v4; // r2

  v3 = *(_DWORD *)(a2 + 4);
  v4 = *(_DWORD *)(a3 + 4);
  if ( v3 < v4 )
    return 0;
  if ( v3 <= v4 )
    return 2;
  return 1;
}
