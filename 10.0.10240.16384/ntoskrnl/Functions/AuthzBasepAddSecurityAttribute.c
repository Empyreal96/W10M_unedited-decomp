// AuthzBasepAddSecurityAttribute 
 
int __fastcall AuthzBasepAddSecurityAttribute(int a1, int a2, int a3, int a4)
{
  _BYTE *v7; // r0
  _BYTE *v8; // r4
  int v9; // [sp+0h] [bp-18h] BYREF
  int v10; // [sp+4h] [bp-14h]
  int v11; // [sp+8h] [bp-10h]

  v9 = a2;
  v10 = a3;
  v11 = a4;
  if ( !*(_DWORD *)(a2 + 16) )
    return -1073741811;
  LOWORD(v9) = *(_WORD *)a2;
  HIWORD(v9) = v9;
  v10 = *(_DWORD *)(a2 + 4);
  if ( AuthzBasepFindSecurityAttribute(a1, (int)&v9) )
    return sub_52ABD4();
  v7 = AuthzBasepAllocateSecurityAttribute(&v9);
  v8 = v7;
  if ( !v7 )
    return -1073741670;
  *((_DWORD *)v7 + 7) = *(_DWORD *)(a2 + 12);
  *((_WORD *)v7 + 12) = *(_WORD *)(a2 + 8);
  AuthzBasepAddSecurityAttributeToLists(a1, v7, 0, 1);
  return AuthzBasepAddSecurityAttributeValues(v8, a2);
}
