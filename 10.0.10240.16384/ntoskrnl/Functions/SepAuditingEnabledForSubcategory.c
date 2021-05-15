// SepAuditingEnabledForSubcategory 
 
int __fastcall SepAuditingEnabledForSubcategory(int a1)
{
  int v1; // r0

  v1 = a1 - 100;
  if ( SeAuditingState[2 * v1] )
    return sub_51D664();
  if ( SeAuditingState[2 * v1 + 1] )
    JUMPOUT(0x51D66A);
  return 0;
}
