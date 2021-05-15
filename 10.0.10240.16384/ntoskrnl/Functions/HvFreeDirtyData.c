// HvFreeDirtyData 
 
unsigned int __fastcall HvFreeDirtyData(_DWORD *a1)
{
  unsigned int result; // r0

  result = a1[470];
  if ( result )
  {
    ExFreePoolWithTag(result);
    a1[469] = 0;
    a1[470] = 0;
    result = ExFreePoolWithTag(a1[472]);
    a1[472] = 0;
    a1[473] = 0;
  }
  return result;
}
