// CmpCheckHivePrimaryFileReadWriteAccess 
 
int __fastcall CmpCheckHivePrimaryFileReadWriteAccess(int a1)
{
  char v2; // r4
  int v3; // r0
  int v4; // r0
  int v5; // r4
  char v7[4]; // [sp+18h] [bp-20h] BYREF
  char v8[4]; // [sp+1Ch] [bp-1Ch] BYREF
  char v9[24]; // [sp+20h] [bp-18h] BYREF

  v2 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v3 = SeCaptureSubjectContext(v9);
  v4 = IoGetFileObjectGenericMapping(v3);
  v5 = SeAccessCheck(a1, (int)v9, 0, 3, 0, 0, v4, v2, (int)v8, (int)v7);
  SeReleaseSubjectContext(v9);
  return v5;
}
