// SepAuditingForSubCategory 
 
int __fastcall SepAuditingForSubCategory(int a1, int a2)
{
  _BYTE *v2; // r3

  v2 = SeAuditingState;
  if ( !a2 )
    v2 = &SeAuditingState[1];
  return (unsigned __int8)v2[2 * a1 - 200];
}
