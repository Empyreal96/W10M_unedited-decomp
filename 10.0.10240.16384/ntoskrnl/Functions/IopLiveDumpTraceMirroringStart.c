// IopLiveDumpTraceMirroringStart 
 
int IopLiveDumpTraceMirroringStart()
{
  int result; // r0
  int v1; // r1
  int *v2; // r2

  result = IopLiveDumpIsTracingEnabled();
  if ( result )
  {
    if ( (*(_DWORD *)(v1 + 48) & 1) != 0 )
      v2 = LIVEDUMP_EVENT_SIZING_WORKFLOW_MIRRORING_START;
    else
      v2 = LIVEDUMP_EVENT_CAPTURE_PAGES_WORKFLOW_MIRRORING_START;
    result = EtwWrite(IopLiveDumpEtwRegHandle, SHIDWORD(IopLiveDumpEtwRegHandle), (int)v2, 0);
  }
  return result;
}
