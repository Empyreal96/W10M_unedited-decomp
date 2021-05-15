// ViXdvGetFuncAddress 
 
int __fastcall ViXdvGetFuncAddress(int a1, _DWORD *a2, int a3)
{
  unsigned int v3; // r2
  int result; // r0

  v3 = *(unsigned __int16 *)(a2[9] + 2 * a3 + a1);
  if ( v3 < a2[5] )
    result = a1 + *(_DWORD *)(a2[7] + 4 * v3 + a1);
  else
    result = 0;
  return result;
}
