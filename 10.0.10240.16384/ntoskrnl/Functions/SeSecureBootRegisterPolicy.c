// SeSecureBootRegisterPolicy 
 
int __fastcall SeSecureBootRegisterPolicy(_DWORD *a1, unsigned int a2)
{
  unsigned int v4; // r0
  unsigned int v5; // r2
  int v7; // r1
  int v8; // r2
  int v9; // r3
  int v10; // r4
  int v11; // r0
  int v12; // r0
  unsigned int v13; // r5
  int v14; // r0
  int v15; // r3
  int v16; // r4

  if ( a2 < 0x10 )
    goto LABEL_20;
  v4 = a1[2];
  v5 = a1[3];
  if ( (v4 == 0) != (v5 == 0) || v4 >= a2 || v5 >= a2 )
    goto LABEL_20;
  if ( v5 < 0x40 )
    return sub_96D994();
  if ( v5 + v4 > a2 )
  {
LABEL_20:
    v16 = -1069350909;
    v13 = dword_641874;
  }
  else
  {
    v7 = a1[1];
    v8 = a1[2];
    v9 = a1[3];
    v10 = 0;
    g_SecureBootPolicyBlobHeader = *a1;
    dword_641868 = v7;
    unk_64186C = v8;
    unk_641870 = v9;
    if ( a1[3] )
      v10 = (int)a1 + a1[2];
    v11 = SepSecureBootSetRegistryKey(v10);
    if ( (dword_641868 & 8) != 0 )
      SepSecureBootCheckForUpdates(v11);
    if ( !v10 )
      return 0;
    v12 = ExAllocatePoolWithTag(512, a1[3], 1649632595);
    v13 = v12;
    if ( !v12 )
    {
      v16 = -1073741670;
      v13 = dword_641874;
LABEL_22:
      if ( v13 )
      {
        ExFreePoolWithTag(v13);
        dword_641874 = 0;
      }
      KeBugCheck2(325, v16, (unsigned int)a1, a2, 0, 0);
    }
    v14 = memmove(v12, v10, a1[3]);
    v15 = *(unsigned __int16 *)(v10 + 36);
    dword_641874 = v13;
    if ( !v15 && !*(_WORD *)(v10 + 38) )
      return 0;
    dword_64185C = *(_DWORD *)(v13 + 52) + v13 + 60;
    v16 = SepSecureBootBuildRules(v14);
  }
  if ( v16 < 0 )
    goto LABEL_22;
  return v16;
}
