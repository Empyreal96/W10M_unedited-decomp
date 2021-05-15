// AslEnvExpandStrings2 
 
int __fastcall AslEnvExpandStrings2(int a1, unsigned __int16 *a2, _WORD *a3, unsigned int a4, _DWORD *a5, int a6)
{
  unsigned __int16 *v7; // r4
  unsigned __int16 *v8; // r5
  unsigned int v9; // r0
  unsigned int v10; // r10
  int v11; // r4
  int v12; // r7
  unsigned int v13; // r0
  int v14; // r0
  int v15; // r0
  int v17; // [sp+8h] [bp-28h] BYREF
  unsigned int v18; // [sp+Ch] [bp-24h]
  int v19; // [sp+10h] [bp-20h]

  v18 = a4;
  v19 = a1;
  v17 = 0;
  v7 = a2;
  v8 = 0;
  v9 = wcslen(a2);
  v10 = v9 + 1;
  if ( a3 )
    *a3 = 0;
  if ( a5 )
    *a5 = 0;
  if ( AslEnvResolveVars(v7, v9 + 1, 0, 0, a6, &v17) != -1073741789 )
  {
    v11 = -1073741595;
    AslLogCallPrintf(1, (int)"AslEnvExpandStrings2", 704, "AslEnvResolveVars failed to fail properly for null buffer");
    return v11;
  }
  v12 = v17;
  if ( v10 == v17 )
    goto LABEL_14;
  v8 = (unsigned __int16 *)AslAlloc(-1073741789, 2 * v17);
  if ( !v8 )
  {
    v11 = -1073741801;
    AslLogCallPrintf(1, (int)"AslEnvExpandStrings2", 712, "Out of memory");
    return v11;
  }
  v13 = wcslen(v7);
  v11 = AslEnvResolveVars(v7, v13 + 1, v8, v12, a6, &v17);
  if ( v11 >= 0 )
  {
    v7 = v8;
LABEL_14:
    v14 = wcslen(v7);
    v15 = AslEnvExpandStrings(v19, v7, v14, a3, v18, a5);
    v11 = v15;
    if ( v15 < 0 && v15 != -1073741789 )
      AslLogCallPrintf(1, (int)"AslEnvExpandStrings2", 738, "AslEnvExpandStrings failed [%x]", v15);
    goto LABEL_17;
  }
  AslLogCallPrintf(1, (int)"AslEnvExpandStrings2", 723, "AslEnvResolveVars failed [%x]", v11);
LABEL_17:
  if ( v8 )
    ExFreePoolWithTag((unsigned int)v8);
  return v11;
}
