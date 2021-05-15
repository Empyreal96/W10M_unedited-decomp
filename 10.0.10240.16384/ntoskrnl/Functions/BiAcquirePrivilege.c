// BiAcquirePrivilege 
 
int __fastcall BiAcquirePrivilege(int a1, int a2, int a3, int a4)
{
  int v6; // r0
  char v7; // r5
  int v8; // r4
  char v10; // r3
  _DWORD v11[6]; // [sp+0h] [bp-18h] BYREF

  v11[0] = a3;
  v11[1] = a4;
  v6 = BiIsImpersonating();
  v7 = v6;
  if ( v6 || (v8 = RtlImpersonateSelfEx(2, 0, 0), v8 >= 0) )
  {
    v8 = BiAdjustPrivilege(a1, 1, v11);
    if ( v8 < 0 )
      return sub_81462C();
    v10 = v11[0];
    *(_BYTE *)(a2 + 5) = v7;
    *(_DWORD *)a2 = a1;
    *(_BYTE *)(a2 + 4) = v10;
  }
  return v8;
}
