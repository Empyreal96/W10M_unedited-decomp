// SeCodeIntegrityInitializePolicy 
 
int __fastcall SeCodeIntegrityInitializePolicy(int a1)
{
  int v3; // r4
  int v4; // r3
  int v5; // r0
  int v6; // [sp+8h] [bp-30h] BYREF
  int v7; // [sp+Ch] [bp-2Ch] BYREF
  int v8; // [sp+24h] [bp-14h]

  if ( !SeILSigningPolicy && ZwQuerySystemInformation() >= 0 && (v8 & 4) != 0 )
    return sub_96EDA8();
  v3 = SepEnableUMCIBySIPolicy();
  if ( v3 >= 0 )
  {
    SepInitializeDebugOptions();
    if ( dword_61D8B0 )
    {
      v4 = *(_DWORD *)(a1 + 132);
      v5 = 0;
      if ( v4 )
        v5 = *(_DWORD *)(v4 + 2300);
      v3 = dword_61D8B0(v5, dword_64A560, g_SiPolicyBlob, &v7, &v6);
      if ( dword_64A560 )
      {
        ExFreePoolWithTag(dword_64A560);
        g_SiPolicyBlob = 0;
        dword_64A560 = 0;
      }
      if ( v3 >= 0 )
      {
        SeCiStateElements = v7;
        SeCiStateElementCount = v6;
      }
    }
  }
  return v3;
}
