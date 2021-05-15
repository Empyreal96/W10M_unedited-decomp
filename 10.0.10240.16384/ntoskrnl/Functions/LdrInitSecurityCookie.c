// LdrInitSecurityCookie 
 
int __fastcall LdrInitSecurityCookie(int a1, int a2, int a3, int a4)
{
  int v5; // r0
  int v6; // r3
  int v7; // r2
  _DWORD *v9; // [sp+0h] [bp-10h] BYREF
  _DWORD v10[3]; // [sp+4h] [bp-Ch] BYREF

  v10[0] = a3;
  v10[1] = a4;
  v9 = 0;
  v5 = LdrpFetchAddressOfSecurityCookie(a1, a2, v10, &v9);
  if ( v9 && *v9 >= 0x5Cu && (v9[22] & 0x800) != 0 )
    return 1;
  if ( v5 && *(_DWORD *)v5 == -1153374642 )
  {
    v6 = KeTickCount;
    __dmb(0xBu);
    v7 = v6 ^ v5 ^ a4;
    if ( !v7 || v7 == *(_DWORD *)v5 )
      v7 = -1153374641;
    *(_DWORD *)v5 = v7;
    return 1;
  }
  return 0;
}
