// PiUEventApplyAdditionalFilters 
 
int __fastcall PiUEventApplyAdditionalFilters(_DWORD *a1, int a2)
{
  int v3; // r3
  int v5; // r0
  int v6; // r4
  int v8; // r1
  int v9; // r0
  char v10[4]; // [sp+8h] [bp-28h] BYREF
  int v11; // [sp+Ch] [bp-24h] BYREF
  int v12[8]; // [sp+10h] [bp-20h] BYREF

  v3 = a1[15];
  v10[0] = 1;
  if ( v3 == 2 )
  {
    v5 = PiPnpRtlApplyMandatoryFilters(PiPnpRtlCtx, (int)(a1 + 24), 3, 0, (int *)(a2 + 32), v10);
  }
  else
  {
    if ( v3 != 3 )
      return sub_7EA88C();
    v5 = PiPnpRtlApplyMandatoryFilters(PiPnpRtlCtx, (int)(a1 + 20), 1, 0, (int *)(a2 + 32), v10);
  }
  if ( v5 >= 0 )
    return (unsigned __int8)v10[0];
  if ( v5 != -1073741772 )
    goto LABEL_18;
  v8 = a1[6];
  v6 = 1;
  if ( !v8
    || (v12[0] = 131073,
        v12[1] = 0x20000,
        v12[2] = 0x20000,
        v12[3] = 983041,
        PiAuVerifyAccessToObject(1, v8, (int)v12, (char *)(a2 + 32), v10) < 0)
    || (v6 = (unsigned __int8)v10[0], v10[0]) )
  {
    if ( a1[8] != -1 )
    {
      v9 = *(_DWORD *)(a2 + 32);
      if ( !v9 )
        v9 = *(_DWORD *)(a2 + 40);
      SeQuerySessionIdTokenEx(v9, &v11, v10);
      if ( !v10[0] && v11 != a1[8] )
LABEL_18:
        v6 = 0;
    }
  }
  return v6;
}
