// -StpKeyCompare@-$ST_STORE@USM_TRAITS@@@@SAHPBX0@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StpKeyCompare(unsigned int *a1, unsigned int *a2)
{
  unsigned int v2; // r1
  int result; // r0

  v2 = *a2;
  if ( *a1 >= v2 )
    result = *a1 != v2;
  else
    result = -1;
  return result;
}
