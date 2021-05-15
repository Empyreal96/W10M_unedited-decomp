// ReferenceVacbLevel 
 
int __fastcall ReferenceVacbLevel(int result, int a2, int a3, int a4, int a5)
{
  int v5; // r2
  _DWORD *v6; // r2

  if ( a3 || (*(_DWORD *)(result + 96) & 0x200) == 0 )
    v5 = 0;
  else
    v5 = 512;
  v6 = (_DWORD *)(v5 + a2 + 512);
  if ( a5 )
    v6[1] += a4;
  else
    *v6 += a4;
  return result;
}
