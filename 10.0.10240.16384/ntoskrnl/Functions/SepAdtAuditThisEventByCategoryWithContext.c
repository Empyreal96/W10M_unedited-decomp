// SepAdtAuditThisEventByCategoryWithContext 
 
int __fastcall SepAdtAuditThisEventByCategoryWithContext(int a1, int a2)
{
  int v2; // r3
  int v3; // r4

  v2 = SeAuditingStateByCategory[a1];
  if ( !v2 )
    return 0;
  if ( (v2 & a2) != 0 )
    return 1;
  v3 = 0;
  if ( SepTokenPolicyCounterByCategory[a1] )
    return sub_7DC5CC();
  return v3;
}
