// PopShutdownHandler 
 
void __noreturn PopShutdownHandler()
{
  int v0; // r5
  int v1; // r0

  __disable_irq();
  if ( !*(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594) && InbvIsBootDriverInstalled() )
  {
    if ( !InbvCheckDisplayOwnership() )
      InbvAcquireDisplayOwnership();
    InbvResetDisplay();
    InbvSolidColorFill();
    InbvEnableDisplayString(1);
    InbvSetScrollRegion();
    v0 = InbvGetResourceAddress();
    v1 = InbvGetResourceAddress();
    if ( v0 )
    {
      if ( v1 )
      {
        InbvBitBlt();
        InbvBitBlt();
      }
    }
  }
  ((void (__cdecl *)())off_617994)();
}
