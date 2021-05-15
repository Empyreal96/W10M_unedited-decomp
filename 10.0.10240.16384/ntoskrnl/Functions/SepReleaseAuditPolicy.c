// SepReleaseAuditPolicy 
 
unsigned int __fastcall SepReleaseAuditPolicy(unsigned int a1, char a2)
{
  if ( a1 && (!a2 || a2 == 1) )
    a1 = ExFreePoolWithTag(a1);
  return a1;
}
