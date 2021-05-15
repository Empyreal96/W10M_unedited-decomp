// WmipDisableCollectOrEvent 
 
int __fastcall WmipDisableCollectOrEvent(int a1, int a2)
{
  int v3; // r4
  int v4; // r4

  if ( a2 == 2244924 )
  {
    v4 = 0;
    goto LABEL_6;
  }
  if ( a2 == 2244928 )
  {
    v4 = 1;
LABEL_6:
    KeWaitForSingleObject((unsigned int)&WmipSMMutex, 0, 0, 0, 0);
    v3 = WmipSendDisableRequest(a1, v4);
    KeReleaseMutex((int)&WmipSMMutex);
    return v3;
  }
  return -1073741649;
}
