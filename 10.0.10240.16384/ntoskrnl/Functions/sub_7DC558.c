// sub_7DC558 
 
// positive sp value has been detected, the output may be wrong!
int __fastcall sub_7DC558(int a1, int a2)
{
  int v2; // r5
  int v3; // r6
  int v4; // r7

  if ( v3 )
    a2 = 1;
  if ( v4 )
    a2 |= 0x10u;
  return SepAdtAuditThisEventByCategoryWithContext(v2, a2);
}
