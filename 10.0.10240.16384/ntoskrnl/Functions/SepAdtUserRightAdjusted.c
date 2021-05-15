// SepAdtUserRightAdjusted 
 
int SepAdtUserRightAdjusted()
{
  int v0; // r1
  int result; // r0
  int v2[178]; // [sp+20h] [bp-2C8h] BYREF

  SeCaptureSubjectContext(v2);
  if ( v2[0] )
    v0 = v2[0];
  else
    v0 = v2[2];
  if ( SeAuditingWithTokenForSubcategory(140, v0) )
    result = sub_7F517C();
  else
    result = SeReleaseSubjectContext((int)v2);
  return result;
}
