// SepAdtInitializeCrashOnFail 
 
int SepAdtInitializeCrashOnFail()
{
  int result; // r0
  char v1; // r2
  unsigned int v2; // [sp+8h] [bp-8h] BYREF

  v2 = 0;
  result = 0;
  if ( !SepAdtRegNotifyHandle )
    goto LABEL_4;
  result = SepRegQueryValue(SepAdtRegNotifyHandle, L"CrashOnAuditFail", 4, 4u, &v2);
  if ( v2 > 2 )
    return result;
  if ( v2 == 1 )
    v1 = 1;
  else
LABEL_4:
    v1 = 0;
  SepCrashOnAuditFail = v1;
  return result;
}
