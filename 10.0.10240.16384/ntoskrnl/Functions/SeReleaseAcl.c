// SeReleaseAcl 
 
unsigned int __fastcall SeReleaseAcl(unsigned int a1, char a2)
{
  if ( a2 == 1 || !a2 )
    a1 = ExFreePoolWithTag(a1);
  return a1;
}
