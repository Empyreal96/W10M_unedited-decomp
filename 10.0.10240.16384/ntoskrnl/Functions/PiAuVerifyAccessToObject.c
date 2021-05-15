// PiAuVerifyAccessToObject 
 
int __fastcall PiAuVerifyAccessToObject(int a1, int a2, int a3, char *a4, _BYTE *a5)
{
  char v6; // r4
  char *v7; // r6
  char *v10; // r1
  int v12; // [sp+18h] [bp-38h] BYREF
  char v13[4]; // [sp+1Ch] [bp-34h] BYREF
  char v14[48]; // [sp+20h] [bp-30h] BYREF

  v6 = 1;
  v7 = a4;
  if ( !a2 || !a5 )
    return -1073741811;
  *a5 = 0;
  if ( a4 )
  {
    v10 = a4;
  }
  else
  {
    SeCaptureSubjectContext(v14);
    v6 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
    v10 = v14;
  }
  *a5 = SeAccessCheck(a2, (int)v10, 0, a1, 0, 0, a3, v6, (int)v13, (int)&v12);
  if ( !v7 )
    SeReleaseSubjectContext((int)v14);
  if ( v12 < 0 )
    *a5 = 0;
  return 0;
}
