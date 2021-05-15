// PiDqSameUserHive 
 
int __fastcall PiDqSameUserHive(int *a1, int *a2, _BYTE *a3)
{
  int v4; // r0
  int v7; // r0
  unsigned __int16 v9[36]; // [sp-4h] [bp-98h] BYREF
  unsigned __int16 v10[40]; // [sp+44h] [bp-50h] BYREF

  v4 = *a1;
  if ( !v4 )
    v4 = a1[2];
  SeQueryUserSidToken(v4, (int)v10, 0x44u, 0);
  v7 = *a2;
  if ( !*a2 )
    v7 = a2[2];
  SeQueryUserSidToken(v7, (int)v9, 0x44u, 0);
  *a3 = RtlEqualSid(v10, v9);
  return 0;
}
