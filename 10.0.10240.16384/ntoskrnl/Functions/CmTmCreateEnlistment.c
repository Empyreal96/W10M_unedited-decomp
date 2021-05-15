// CmTmCreateEnlistment 
 
int CmTmCreateEnlistment()
{
  int result; // r0

  if ( CmpNoMoreTx == 1 )
    result = -1073741431;
  else
    result = TmCreateEnlistment();
  return result;
}
