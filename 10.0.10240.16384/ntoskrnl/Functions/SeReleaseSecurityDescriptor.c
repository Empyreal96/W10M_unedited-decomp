// SeReleaseSecurityDescriptor 
 
unsigned int __fastcall SeReleaseSecurityDescriptor(unsigned int a1, char a2, int a3)
{
  if ( !a2 && a3 == 1 || a2 == 1 )
  {
    if ( a1 )
      a1 = ExFreePoolWithTag(a1);
  }
  return a1;
}
