// PspSetJobBackgroundCountCallback 
 
int __fastcall PspSetJobBackgroundCountCallback(int a1, _BYTE *a2)
{
  int v2; // r3
  int v3; // r3

  v2 = *(_DWORD *)(a1 + 412);
  if ( *a2 )
    v3 = v2 + 1;
  else
    v3 = v2 - 1;
  *(_DWORD *)(a1 + 412) = v3;
  return 0;
}
