// WheapInitializeEventing 
 
int WheapInitializeEventing()
{
  int result; // r0

  WheapWaitingETWEvents = (int)&WheapWaitingETWEvents;
  dword_6197D4 = (int)&WheapWaitingETWEvents;
  WheapWaitingETWEventLock = 1;
  byte_6197E1 = 0;
  byte_6197E2 = 4;
  dword_6197E4 = 1;
  dword_6197EC = (int)&dword_6197E8;
  dword_6197E8 = (int)&dword_6197E8;
  result = EtwRegister((int)WHEA_ETW_PROVIDER, (int)WheapEtwEnableCallback, 0);
  if ( result )
    result = sub_970AF0();
  return result;
}
