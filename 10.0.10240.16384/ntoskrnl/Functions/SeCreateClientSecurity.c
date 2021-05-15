// SeCreateClientSecurity 
 
int __fastcall SeCreateClientSecurity(int a1, int a2, int a3, int a4)
{
  _DWORD *v7; // r8
  int result; // r0
  int v9; // r4
  unsigned __int8 v10; // [sp+20h] [bp-28h] BYREF
  unsigned __int8 v11; // [sp+21h] [bp-27h] BYREF
  char v12[2]; // [sp+22h] [bp-26h] BYREF
  int v13; // [sp+24h] [bp-24h] BYREF
  int v14; // [sp+28h] [bp-20h] BYREF
  int v15[7]; // [sp+2Ch] [bp-1Ch] BYREF

  v10 = 0;
  v13 = 0;
  v7 = (_DWORD *)PsReferenceEffectiveToken(a1, v15, v12, &v14, &v11);
  SepReconcileTrustSidWithProcessProtection(v7[160], &v11, &v10, &v13);
  result = SepCreateClientSecurityEx(v7, a2, a3, v15[0], v12[0], v14, 0, 0, v10, v13, a4);
  v9 = result;
  if ( result < 0 || !*(_BYTE *)(a2 + 8) )
  {
    ObfDereferenceObject((int)v7);
    result = v9;
  }
  return result;
}
