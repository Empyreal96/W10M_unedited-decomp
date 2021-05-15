// PpmCheckReportComplete 
 
int PpmCheckReportComplete()
{
  if ( PpmCheckCompleteHandler )
    PpmCheckCompleteHandler(PpmPerfGlobalContext, PpmCheckCompleteHandler, PpmCheckTime, dword_61E04C);
  return 1;
}
