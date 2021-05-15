// PnpLogActionQueueEvent 
 
int __fastcall PnpLogActionQueueEvent(int a1, int a2, int a3)
{
  int result; // r0
  int *v4; // r2

  if ( a2 == 8 )
  {
    if ( a3 )
    {
      if ( a3 == 1 )
      {
        if ( (Microsoft_Windows_Kernel_PnPEnableBits & 0x2000000) == 0 )
          return result;
        v4 = KMPnPEvt_ReenumerateDeviceOnly_Start;
      }
      else
      {
        if ( a3 != 2 || (Microsoft_Windows_Kernel_PnPEnableBits & 0x2000000) == 0 )
          return result;
        v4 = KMPnPEvt_ReenumerateDeviceOnly_Stop;
      }
    }
    else
    {
      if ( (Microsoft_Windows_Kernel_PnPEnableBits & 0x2000000) == 0 )
        return result;
      v4 = KMPnPEvt_ReenumerateDeviceOnly_Queue;
    }
    return Template_z(Microsoft_Windows_Kernel_PnPHandle, MEMORY[0x649E54], v4);
  }
  if ( a2 > 8 && (a2 <= 10 || a2 == 14) )
  {
    if ( a3 )
    {
      if ( a3 == 1 )
      {
        if ( (Microsoft_Windows_Kernel_PnPEnableBits & 0x2000000) != 0 )
          JUMPOUT(0x52001C);
      }
      else if ( a3 == 2 && (Microsoft_Windows_Kernel_PnPEnableBits & 0x2000000) != 0 )
      {
        JUMPOUT(0x520028);
      }
    }
    else if ( (Microsoft_Windows_Kernel_PnPEnableBits & 0x2000000) != 0 )
    {
      result = sub_520010();
    }
  }
  return result;
}
