// CcDeallocateBcb 
 
int __fastcall CcDeallocateBcb(_WORD *a1)
{
  if ( *a1 == 765 )
    ExDeleteResourceLite(a1 + 28);
  return ExFreePoolWithTag(a1, 0);
}
