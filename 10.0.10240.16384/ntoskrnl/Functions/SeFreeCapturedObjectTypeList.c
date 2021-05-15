// SeFreeCapturedObjectTypeList 
 
int __fastcall SeFreeCapturedObjectTypeList(int result)
{
  if ( result )
    result = ExFreePoolWithTag(result);
  return result;
}
