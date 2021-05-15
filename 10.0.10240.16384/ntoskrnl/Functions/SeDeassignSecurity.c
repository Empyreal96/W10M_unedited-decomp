// SeDeassignSecurity 
 
int __fastcall SeDeassignSecurity(unsigned int *a1)
{
  unsigned int v2; // r0

  v2 = *a1;
  if ( v2 )
    ExFreePoolWithTag(v2);
  *a1 = 0;
  return 0;
}
