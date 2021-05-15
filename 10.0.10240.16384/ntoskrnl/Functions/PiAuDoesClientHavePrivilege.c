// PiAuDoesClientHavePrivilege 
 
int __fastcall PiAuDoesClientHavePrivilege(int a1, int a2, int a3)
{
  char v3; // r5
  int v4; // r4
  int v6[4]; // [sp-4h] [bp-30h] BYREF
  int v7[8]; // [sp+Ch] [bp-20h] BYREF

  v3 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v7[0] = 1;
  v7[1] = 1;
  v7[3] = 0;
  v7[4] = 0;
  v7[2] = a1;
  SeCaptureSubjectContext(v6, a2, a3, 0);
  v4 = SePrivilegeCheck(v7, v6, v3);
  SeReleaseSubjectContext((int)v6);
  return v4;
}
