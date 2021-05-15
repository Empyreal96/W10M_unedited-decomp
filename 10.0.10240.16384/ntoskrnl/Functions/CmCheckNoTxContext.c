// CmCheckNoTxContext 
 
int CmCheckNoTxContext()
{
  int v0; // r0
  int result; // r0

  v0 = TmCurrentTransaction();
  if ( v0 == -1073741637 )
    result = 0;
  else
    result = sub_7C2F14(v0);
  return result;
}
