// IopFindActiveConnectBlockLocked 
 
int *__fastcall IopFindActiveConnectBlockLocked(unsigned int a1)
{
  int *result; // r0
  int *i; // r3
  unsigned int v4; // r2

  result = 0;
  for ( i = (int *)ActiveConnectList; i != &ActiveConnectList; i = (int *)*i )
  {
    v4 = i[2];
    if ( v4 > a1 )
      break;
    if ( v4 == a1 )
      return i;
  }
  return result;
}
