// PiAuCheckTokenMembership 
 
int __fastcall PiAuCheckTokenMembership(int a1, _BYTE *a2)
{
  int v4; // r4
  _BYTE *v5; // r0
  _BYTE *v6; // r5
  int v7; // r4
  int v8; // r1
  int v9; // r2
  int v10; // r3
  char v12[4]; // [sp+18h] [bp-40h] BYREF
  char v13[4]; // [sp+1Ch] [bp-3Ch] BYREF
  int v14[4]; // [sp+20h] [bp-38h] BYREF
  _DWORD v15[10]; // [sp+30h] [bp-28h] BYREF

  v14[0] = 131073;
  v14[1] = 0x20000;
  v14[2] = 0x20000;
  v14[3] = 2031617;
  *a2 = 0;
  v4 = 3 * RtlLengthSid(a1);
  v5 = (_BYTE *)ExAllocatePoolWithTag(1, v4 + 40, 538996816);
  v6 = v5;
  if ( !v5 )
    return -1073741670;
  memset(v5, 0, v4 + 40);
  RtlCreateSecurityDescriptor(v6, 1);
  RtlSetOwnerSecurityDescriptor((int)v6, a1, 0);
  RtlSetGroupSecurityDescriptor((int)v6, a1, 0);
  v7 = RtlCreateAcl((int)(v6 + 20), v4 + 20, 2);
  if ( v7 >= 0 )
  {
    v7 = RtlAddAccessAllowedAce((int)(v6 + 20), 2, 1, a1);
    if ( v7 >= 0 )
    {
      v7 = RtlSetDaclSecurityDescriptor((int)v6, 1, (int)(v6 + 20), 0);
      if ( v7 >= 0 )
      {
        SeCaptureSubjectContext(v15, v8, v9, v10);
        *a2 = SeAccessCheck(
                (int)v6,
                (int)v15,
                0,
                1,
                0,
                0,
                (int)v14,
                *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A),
                (int)v13,
                (int)v12);
        SeReleaseSubjectContext((int)v15);
        v7 = 0;
      }
    }
  }
  ExFreePoolWithTag((unsigned int)v6);
  return v7;
}
