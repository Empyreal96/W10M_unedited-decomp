// ExpWnfCheckCallerAccess 
 
int __fastcall ExpWnfCheckCallerAccess(int a1, int a2)
{
  int v5; // [sp+18h] [bp-20h] BYREF
  char v6[4]; // [sp+1Ch] [bp-1Ch] BYREF
  char v7[24]; // [sp+20h] [bp-18h] BYREF

  if ( !a2 )
    return 0;
  SeCaptureSubjectContext(v7);
  SeAccessCheck(a1, (int)v7, 0, a2, 0, 0, (int)ExpWnfNotificationMapping, 1, (int)v6, (int)&v5);
  SeReleaseSubjectContext(v7);
  return v5;
}
