// SeReleaseUnicodeStringStructures 
 
unsigned int __fastcall SeReleaseUnicodeStringStructures(unsigned int a1, char a2)
{
  if ( a2 == 1 )
  {
    if ( a1 )
      a1 = ExFreePoolWithTag(a1);
  }
  return a1;
}
