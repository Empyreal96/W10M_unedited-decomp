// WdipSemSqmEnabled 
 
BOOL WdipSemSqmEnabled()
{
  __int64 v0; // kr00_8

  v0 = WdipSemRegHandle;
  return EtwEventEnabled(WdipSemRegHandle, SHIDWORD(WdipSemRegHandle), (int)WDI_SEM_EVENT_SQM_INCREMENT_DWORD)
      && EtwEventEnabled(v0, SHIDWORD(v0), (int)WDI_SEM_EVENT_SQM_ADD_TO_STREAM);
}
