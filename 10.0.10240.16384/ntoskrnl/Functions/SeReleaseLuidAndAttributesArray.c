// SeReleaseLuidAndAttributesArray 
 
unsigned int __fastcall SeReleaseLuidAndAttributesArray(unsigned int a1, char a2)
{
  if ( a2 == 1 || !a2 )
  {
    if ( a1 )
      a1 = ExFreePoolWithTag(a1);
  }
  return a1;
}
