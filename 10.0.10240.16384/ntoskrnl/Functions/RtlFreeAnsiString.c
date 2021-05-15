// RtlFreeAnsiString 
 
unsigned int __fastcall RtlFreeAnsiString(_DWORD *a1)
{
  unsigned int result; // r0

  result = a1[1];
  if ( result )
  {
    result = ExFreePool(result);
    *a1 = 0;
    a1[1] = 0;
  }
  return result;
}
