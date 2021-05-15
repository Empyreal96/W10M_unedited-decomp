// WdipSemCleanStart 
 
int WdipSemCleanStart()
{
  int v0; // r4
  int v2; // r0

  v0 = WdipSemGetLoggerIds();
  if ( v0 >= 0 )
    return sub_7D0D78();
  v2 = WdipSemCleanupGroupPolicy();
  if ( v0 >= 0 )
    WdipSemEnabled = 1;
  else
    WdipSemShutdown(v2);
  return v0;
}
