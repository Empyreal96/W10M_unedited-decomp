// SeAuditingWithTokenForSubcategory 
 
int __fastcall SeAuditingWithTokenForSubcategory(int a1)
{
  int result; // r0

  result = SepAuditingForSubCategory(a1, 1);
  if ( SepTokenPolicyCounter[a1 - 100] )
    result = sub_7F5370();
  return result;
}
