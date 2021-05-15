// SepSecureBootUpdateBcdDataForRule 
 
int __fastcall SepSecureBootUpdateBcdDataForRule(int a1, int a2)
{
  int v3; // r2
  unsigned int v4; // r5
  int v5; // r4
  __int16 *v6; // r8
  char *v8; // r9
  int v9; // r0
  int v10; // r1
  int v11; // r0
  int v12; // r2
  int v13; // r2
  int v15; // [sp+8h] [bp-28h] BYREF
  int v16; // [sp+Ch] [bp-24h] BYREF
  char v17[32]; // [sp+10h] [bp-20h] BYREF

  v3 = *(_DWORD *)(a1 + 8);
  v4 = 0;
  v5 = 0;
  v6 = (__int16 *)(v3 + dword_64185C);
  if ( (*(_WORD *)(v3 + dword_64185C) & 0x1F) == 8 )
  {
    if ( !v6[1] )
    {
      v5 = BcdDeleteElement(a2);
      if ( v5 == -1073741275 )
        v5 = 0;
    }
  }
  else
  {
    v15 = 8;
    v8 = v17;
    v9 = BcdGetElementDataWithFlags(a2, *(_DWORD *)(a1 + 4), v3, (int)v17, &v15);
    v5 = v9;
    if ( v9 != -1073741789 && v9 != -2147483643 )
      goto LABEL_19;
    v11 = ExAllocatePoolWithTag(1, v15, 1649632595);
    v4 = v11;
    if ( !v11 )
      return -1073741670;
    v8 = (char *)v11;
    v5 = BcdGetElementDataWithFlags(a2, *(_DWORD *)(a1 + 4), v12, v11, &v15);
    if ( v5 >= 0 )
    {
LABEL_19:
      if ( v5 < 0 || (v5 = SepSecureBootValidateBcdDataAgainstBcdRule(a1, v8, v15), v5 < 0) )
      {
        v5 = SepSecureBootGetPolicyDefaultValue(v6, v10, &v16, &v15);
        if ( v5 >= 0 )
          v5 = BcdSetElementDataWithFlags(a2, *(_DWORD *)(a1 + 4), v13, v16, v15);
      }
    }
    if ( v4 )
      ExFreePoolWithTag(v4);
  }
  return v5;
}
