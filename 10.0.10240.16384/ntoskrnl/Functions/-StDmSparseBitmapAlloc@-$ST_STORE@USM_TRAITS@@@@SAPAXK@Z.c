// -StDmSparseBitmapAlloc@-$ST_STORE@USM_TRAITS@@@@SAPAXK@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StDmSparseBitmapAlloc(int a1)
{
  return ExAllocatePoolWithTag(512, a1);
}
