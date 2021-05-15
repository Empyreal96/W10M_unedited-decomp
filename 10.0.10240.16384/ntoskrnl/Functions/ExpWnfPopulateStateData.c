// ExpWnfPopulateStateData 
 
int __fastcall ExpWnfPopulateStateData(int a1)
{
  int v2; // r7
  int v3; // r4
  __int64 v4; // r0
  int v5; // r0
  int v6; // r5
  int v8; // r3
  unsigned __int16 v9[2]; // [sp+10h] [bp-50h] BYREF
  char *v10; // [sp+14h] [bp-4Ch]
  char v11; // [sp+18h] [bp-48h] BYREF

  if ( *(_DWORD *)(a1 + 52) || !*(_DWORD *)(a1 + 60) )
    return 0;
  v2 = *(_DWORD *)(a1 + 36);
  v3 = ExAllocatePoolWithTag(1, v2 + 16, 543583831);
  if ( !v3 )
    return -1073741670;
  v4 = *(_QWORD *)(a1 + 24);
  v9[1] = 34;
  v9[0] = 0;
  v10 = &v11;
  ExpWnfComposeValueName(v4, SHIDWORD(v4), v9, 0);
  v5 = ZwQueryValueKey();
  v6 = v5;
  if ( v5 == -1073741772 )
  {
    *(_DWORD *)v3 = 0;
    *(_DWORD *)(v3 + 4) = 0;
    *(_DWORD *)(v3 + 8) = 0;
    *(_DWORD *)(v3 + 12) = 0;
    *(_WORD *)v3 = 2308;
    *(_WORD *)(v3 + 2) = 16;
    goto LABEL_11;
  }
  if ( v5 == -1073741789 )
    return sub_8181C0();
  if ( v5 < 0 )
  {
LABEL_17:
    ExFreePoolWithTag(v3);
    return v6;
  }
  if ( *(_DWORD *)(v3 + 4) != 3 || *(_DWORD *)(v3 + 8) < 4u )
  {
    v6 = -1073741823;
    goto LABEL_17;
  }
  *(_WORD *)v3 = 2308;
  *(_WORD *)(v3 + 2) = 16;
  *(_DWORD *)(v3 + 8) -= 4;
LABEL_11:
  v8 = *(_DWORD *)(v3 + 12);
  *(_DWORD *)(v3 + 4) = v2;
  *(_DWORD *)(a1 + 52) = v3;
  *(_DWORD *)(a1 + 56) = v8;
  return 0;
}
