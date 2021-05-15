// PiDevCfgResolveVariableSwitchCase 
 
int __fastcall PiDevCfgResolveVariableSwitchCase(int a1, int a2, int a3)
{
  int v6; // r5
  unsigned int v7; // r4
  unsigned int v8; // r3
  int v11; // r0
  bool v12; // zf
  unsigned int v13; // r3
  unsigned __int16 *v14; // r1
  int v15; // r0
  unsigned int v16; // r3
  unsigned __int16 *v19; // r1
  int v20; // r0
  unsigned int v22; // r3
  int v25; // r0
  _DWORD *v26; // [sp+0h] [bp-48h] BYREF
  unsigned int *v27; // [sp+4h] [bp-44h] BYREF
  unsigned int *v28; // [sp+8h] [bp-40h] BYREF
  _WORD v29[28]; // [sp+10h] [bp-38h] BYREF

  v26 = 0;
  v27 = 0;
  v28 = 0;
  v6 = IopGetRegistryValue(a2, L"Switch", 0, (int *)&v26);
  if ( v6 < 0 )
    goto LABEL_41;
  v7 = (unsigned int)v26;
  if ( v26[1] != 1 )
    goto LABEL_11;
  v8 = v26[3];
  if ( v8 < 2 || *(_WORD *)((char *)v26 + 2 * (v8 >> 1) + v26[2] - 2) )
    goto LABEL_11;
  v11 = PiDevCfgResolveVariable(a1, (unsigned __int16 *)((char *)v26 + v26[2]), &v27);
  v6 = v11;
  if ( v11 < 0 )
  {
    v12 = v11 == -1073741772;
    goto LABEL_14;
  }
  ExFreePoolWithTag(v7);
  v26 = 0;
  v13 = v27[4];
  if ( !v13 )
    goto LABEL_21;
  if ( v13 <= 2 )
  {
LABEL_31:
    v14 = (unsigned __int16 *)v27[6];
LABEL_22:
    if ( !v14 )
      goto LABEL_38;
    goto LABEL_23;
  }
  if ( v13 != 4 )
  {
    if ( v13 != 7 )
    {
LABEL_21:
      v14 = 0;
      goto LABEL_22;
    }
    goto LABEL_31;
  }
  if ( RtlStringCchPrintfW(v29, 0xBu, (int)L"%u", *(_DWORD *)v27[6]) < 0 )
    goto LABEL_38;
  v14 = v29;
LABEL_23:
  v15 = IopGetRegistryValue(a2, v14, 0, (int *)&v26);
  v6 = v15;
  if ( v15 != -1073741772 )
  {
    if ( v15 >= 0 )
    {
      v7 = (unsigned int)v26;
      if ( v26[1] != 1 )
        goto LABEL_11;
      v16 = v26[3];
      if ( v16 < 2 || *(_WORD *)((char *)v26 + 2 * (v16 >> 1) + v26[2] - 2) )
        goto LABEL_11;
      v19 = (unsigned __int16 *)((char *)v26 + v26[2]);
      if ( v19 )
        goto LABEL_55;
      goto LABEL_38;
    }
LABEL_41:
    v7 = (unsigned int)v26;
    goto LABEL_42;
  }
LABEL_38:
  v20 = IopGetRegistryValue(a2, L"Default", 0, (int *)&v26);
  v6 = v20;
  if ( v20 < 0 )
  {
    if ( v20 == -1073741772 )
      v6 = -1073741823;
    goto LABEL_41;
  }
  v7 = (unsigned int)v26;
  if ( v26[1] != 1 )
    goto LABEL_11;
  v22 = v26[3];
  if ( v22 < 2 || *(_WORD *)((char *)v26 + 2 * (v22 >> 1) + v26[2] - 2) )
    goto LABEL_11;
  v19 = (unsigned __int16 *)((char *)v26 + v26[2]);
LABEL_55:
  v25 = PiDevCfgResolveVariable(a1, v19, &v28);
  v6 = v25;
  if ( v25 >= 0 )
  {
    v6 = PiDevCfgCopyVariableData(a3, v28);
    goto LABEL_42;
  }
  v12 = v25 == -1073741772;
LABEL_14:
  if ( v12 )
LABEL_11:
    v6 = -1073741823;
LABEL_42:
  if ( v7 )
    ExFreePoolWithTag(v7);
  return v6;
}
