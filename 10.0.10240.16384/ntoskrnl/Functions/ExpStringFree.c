// ExpStringFree 
 
unsigned int __fastcall ExpStringFree(unsigned int a1)
{
  if ( a1 )
    a1 = ExFreePoolWithTag(a1);
  return a1;
}
