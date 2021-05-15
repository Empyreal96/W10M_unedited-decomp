// SeCreateClientSecurityEx 
 
int __fastcall SeCreateClientSecurityEx(int a1, int a2, int a3, int a4)
{
  int v8; // r9
  int v9; // r4
  int result; // r0
  int v11; // r5
  unsigned __int8 v12; // [sp+20h] [bp-28h] BYREF
  unsigned __int8 v13; // [sp+21h] [bp-27h] BYREF
  char v14[2]; // [sp+22h] [bp-26h] BYREF
  int v15; // [sp+24h] [bp-24h] BYREF
  int v16; // [sp+28h] [bp-20h] BYREF
  int v17[7]; // [sp+2Ch] [bp-1Ch] BYREF

  v12 = 0;
  v15 = 0;
  v8 = PsReferenceEffectiveToken(a1, v17, v14, &v16, &v13);
  SepReconcileTrustSidWithProcessProtection(*(_DWORD *)(v8 + 640), &v13, &v12, &v15);
  v9 = SepCreateClientSecurityEx(v8, a2, a3, v17[0], (unsigned __int8)v14[0], v16, 1, a1, v12, v15, a4);
  if ( v9 >= 0 && *(_BYTE *)(a4 + 8) )
  {
    if ( *(_DWORD *)(a1 + 336) == PsInitialSystemProcess )
    {
      v11 = PsGetCurrentServerSilo();
      if ( !PsIsHostSilo(v11) )
        return sub_7F9B14();
      if ( v11 )
        PspDereferenceSiloObject(v11);
    }
    result = v9;
  }
  else
  {
    ObfDereferenceObject(v8);
    result = v9;
  }
  return result;
}
