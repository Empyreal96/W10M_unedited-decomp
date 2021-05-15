// PopUserIsAdmin 
 
int __fastcall PopUserIsAdmin(int a1, int a2, int a3, int a4)
{
  int v4; // r0
  int v5; // r4
  int v7[6]; // [sp+0h] [bp-18h] BYREF

  SeCaptureSubjectContext(v7, a2, a3, a4);
  SeLockSubjectContext(v7);
  v4 = v7[0];
  if ( !v7[0] )
    v4 = v7[2];
  v5 = SeTokenIsAdmin(v4);
  SeUnlockSubjectContext(v7);
  SeReleaseSubjectContext((int)v7);
  return v5;
}
