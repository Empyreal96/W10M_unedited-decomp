// AslLogCallPrintf 
 
int AslLogCallPrintf(int a1, int a2, int a3, const char *a4, ...)
{
  int result; // r0

  if ( g_AslLogPfnVPrintf )
    result = sub_81A890();
  return result;
}
