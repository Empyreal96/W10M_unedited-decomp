// sub_7D0D78 
 
void sub_7D0D78()
{
  if ( WdipSemEnableSemProvider() >= 0
    && WdipSemLoadConfigInfo() >= 0
    && WdipSemLoadGroupPolicy() >= 0
    && WdipSemLoadScenarioTable() >= 0 )
  {
    WdipSemStartTimeoutCheck();
  }
  JUMPOUT(0x78AFA4);
}
