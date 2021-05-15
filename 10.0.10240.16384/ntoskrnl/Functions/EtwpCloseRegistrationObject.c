// EtwpCloseRegistrationObject 
 
void __fastcall EtwpCloseRegistrationObject(int a1, int a2, int a3, int a4)
{
  if ( a4 == 1 )
  {
    if ( (*(_BYTE *)(a2 + 50) & 2) != 0
      && EtwEventEnabled(EtwpEventTracingProvRegHandle, dword_61ADA4, (int)ETW_EVENT_PROVIDER_UNREGISTERS) )
    {
      sub_7D6BA0();
    }
    else
    {
      *(_BYTE *)(a2 + 50) |= 0x40u;
    }
  }
}
