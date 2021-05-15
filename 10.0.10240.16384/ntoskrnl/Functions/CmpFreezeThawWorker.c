// CmpFreezeThawWorker 
 
int CmpFreezeThawWorker()
{
  int result; // r0

  CmpFreezeThawPending = 0;
  if ( CmpFreezeThawState == 1 )
    result = CmThawRegistry();
  return result;
}
