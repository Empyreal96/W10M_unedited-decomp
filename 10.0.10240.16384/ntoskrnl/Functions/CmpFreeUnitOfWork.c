// CmpFreeUnitOfWork 
 
unsigned int __fastcall CmpFreeUnitOfWork(unsigned int a1)
{
  return ExFreePoolWithTag(a1);
}
