// IoInitializeLiveDump 
 
int IoInitializeLiveDump()
{
  EtwRegister(LiveDumpProvGuid, IopLiveDumpTracingControlCallback, 0);
  return TraceLoggingRegisterEx(&dword_617540, 0, 0);
}
