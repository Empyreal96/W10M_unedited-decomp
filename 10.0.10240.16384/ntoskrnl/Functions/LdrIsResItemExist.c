// LdrIsResItemExist 
 
int __fastcall LdrIsResItemExist(int a1, _DWORD *a2, int a3, int a4)
{
  int v5; // r0
  int v6; // r4
  int result; // r0
  int v8; // [sp+0h] [bp-10h]
  int v9; // [sp+4h] [bp-Ch]

  v9 = a4;
  v8 = 0;
  v5 = LdrpGetRcConfig(a1, (int)a2, 1, 1);
  v6 = v5;
  if ( !v5 )
    return 0x80000;
  if ( LdrRscIsTypeExist(v5, *a2) < 0 )
    return 393216;
  if ( (*(_DWORD *)(v6 + 20) & 0x100) != 0 )
    return sub_54DCEC();
  result = v8;
  if ( (*(_DWORD *)(v6 + 16) & 0x10) != 0 )
    result = v8 | 0x200000;
  return result;
}
