// SepRmGlobalSaclSetWrkr 
 
unsigned int __fastcall SepRmGlobalSaclSetWrkr(int a1, int a2)
{
  int v3; // r5
  unsigned int result; // r0
  unsigned int v5[2]; // [sp+0h] [bp-30h] BYREF
  _DWORD v6[2]; // [sp+8h] [bp-28h] BYREF
  __int16 v7; // [sp+10h] [bp-20h] BYREF
  __int16 v8; // [sp+12h] [bp-1Eh]
  int v9; // [sp+14h] [bp-1Ch]

  v8 = *(_WORD *)(a1 + 28);
  v7 = v8;
  v5[1] = 0;
  v6[0] = 0;
  v6[1] = 0;
  v5[0] = 0;
  v9 = a1 + 30;
  v3 = SepRmFetchGlobalSacl(&v7, v6, v5);
  if ( v3 >= 0 )
    return sub_8168DC();
  result = v5[0];
  if ( v5[0] )
    result = ExFreePoolWithTag(v5[0]);
  *(_DWORD *)(a2 + 24) = v3;
  return result;
}
