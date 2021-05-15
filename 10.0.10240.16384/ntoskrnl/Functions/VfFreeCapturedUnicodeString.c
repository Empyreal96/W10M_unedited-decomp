// VfFreeCapturedUnicodeString 
 
unsigned int __fastcall VfFreeCapturedUnicodeString(unsigned int result)
{
  if ( *(_WORD *)result )
    result = ExFreePoolWithTag(*(_DWORD *)(result + 4));
  return result;
}
