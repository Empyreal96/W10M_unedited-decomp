// SepAdtAuditObjectAccessWithContext 
 
int __fastcall SepAdtAuditObjectAccessWithContext(int a1, int a2, int a3, int a4, int a5, int a6, _WORD *a7)
{
  int v7; // r1
  int result; // r0

  v7 = 0;
  *a7 = 118;
  if ( a3 )
    v7 = 3;
  if ( a4 )
    v7 |= 0x30u;
  if ( SepAdtAuditThisEventByCategoryWithContext(2, v7, a5) )
    result = sub_7DC21C();
  else
    result = 0;
  return result;
}
