// VerifierExInterlockedAddLargeInteger 
 
_DWORD *__fastcall VerifierExInterlockedAddLargeInteger(_DWORD *a1, int a2, int a3, int a4)
{
  _DWORD *result; // r0
  int v6; // [sp+8h] [bp-10h] BYREF
  int v7; // [sp+Ch] [bp-Ch]
  _DWORD *varg_r0; // [sp+20h] [bp+8h]
  int varg_r1; // [sp+24h] [bp+Ch]
  int varg_r2; // [sp+28h] [bp+10h]
  int varg_r3; // [sp+2Ch] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  v6 = a3;
  v7 = a4;
  varg_r2 = a3;
  varg_r3 = a4;
  pXdvExInterlockedAddLargeInteger(&v6);
  result = a1;
  *a1 = v6;
  a1[1] = v7;
  return result;
}
