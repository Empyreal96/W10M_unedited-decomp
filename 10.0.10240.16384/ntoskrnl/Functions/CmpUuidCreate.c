// CmpUuidCreate 
 
int __fastcall CmpUuidCreate(int a1)
{
  int result; // r0
  int v2; // r1

  result = ExUuidCreate(a1);
  if ( result == -1073741267 )
    result = sub_7D1378(-1073741267, v2);
  return result;
}
