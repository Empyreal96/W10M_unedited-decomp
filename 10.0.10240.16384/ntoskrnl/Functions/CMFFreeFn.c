// CMFFreeFn 
 
unsigned int __fastcall CMFFreeFn(int a1, unsigned int a2)
{
  return ExFreePoolWithTag(a2);
}
