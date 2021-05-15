// SepAuditFailed 
 
int SepAuditFailed()
{
  int result; // r0

  if ( SepCrashOnAuditFail )
    result = sub_81BC8C();
  return result;
}
