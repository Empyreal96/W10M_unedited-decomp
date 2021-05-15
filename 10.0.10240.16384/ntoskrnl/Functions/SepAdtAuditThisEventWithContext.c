// SepAdtAuditThisEventWithContext 
 
int __fastcall SepAdtAuditThisEventWithContext(unsigned int a1, int a2, int a3, _DWORD *a4)
{
  int result; // r0
  unsigned int v9; // r5
  int v10; // r4
  _DWORD *v11; // r9
  unsigned __int8 v12; // [sp+8h] [bp-30h]
  _DWORD v13[10]; // [sp+10h] [bp-28h] BYREF

  if ( a1 <= 8 )
    return sub_7DC558();
  result = SepAuditingEnabledForSubcategory(a1);
  v9 = a1 - 100;
  v10 = result;
  v12 = result;
  if ( SepTokenPolicyCounter[v9] )
  {
    if ( a4 )
    {
      v11 = a4;
    }
    else
    {
      v11 = v13;
      v13[0] = 0;
      v13[1] = 0;
      v13[2] = 0;
      v13[3] = 0;
      SeCaptureSubjectContext(v13);
    }
    if ( *v11 || v11[2] )
    {
      SepAdtIncorporatePerUserPolicy(v9, a2, a3);
      v10 = v12;
    }
    else
    {
      SepAuditFailed(-1073741700);
    }
    if ( !a4 )
      SeReleaseSubjectContext((int)v11);
    result = v10;
  }
  return result;
}
