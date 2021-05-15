// WheapGenerateETWEvents 
 
int WheapGenerateETWEvents()
{
  return EtwWrite(WheapEtwHandle, unk_6197CC, (int)EVENT_WHEA_ERROR, 0);
}
