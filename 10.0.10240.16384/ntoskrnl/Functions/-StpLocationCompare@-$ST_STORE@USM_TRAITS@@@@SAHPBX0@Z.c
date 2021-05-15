// -StpLocationCompare@-$ST_STORE@USM_TRAITS@@@@SAHPBX0@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StpLocationCompare(unsigned int *a1, unsigned int *a2)
{
  unsigned int v2; // r2
  int result; // r0

  v2 = *a1;
  result = -1;
  if ( v2 >= *a2 )
    result = 1;
  return result;
}
