// SepRmCapPoolExpand 
 
int __fastcall SepRmCapPoolExpand(int a1, int a2)
{
  ExFreePoolWithTag(a1);
  return ExAllocatePoolWithTag(1, a2);
}
