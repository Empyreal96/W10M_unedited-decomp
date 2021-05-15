// CcFreeVacbArray 
 
unsigned int __fastcall CcFreeVacbArray(unsigned int a1)
{
  if ( *(_DWORD *)(a1 + 4) )
    KeBugCheckEx(52, 565, -1073740768, 0, 0);
  return ExFreePoolWithTag(a1);
}
