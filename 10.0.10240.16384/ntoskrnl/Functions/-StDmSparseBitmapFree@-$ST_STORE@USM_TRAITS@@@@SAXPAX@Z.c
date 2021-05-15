// -StDmSparseBitmapFree@-$ST_STORE@USM_TRAITS@@@@SAXPAX@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StDmSparseBitmapFree(int a1)
{
  return ExFreePoolWithTag(a1, 0);
}
