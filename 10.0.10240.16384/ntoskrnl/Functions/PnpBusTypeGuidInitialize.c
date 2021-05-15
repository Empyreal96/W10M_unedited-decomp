// PnpBusTypeGuidInitialize 
 
int PnpBusTypeGuidInitialize()
{
  PnpBusTypeGuidCountMax = 16;
  PnpBusTypeGuidArray = ExAllocatePoolWithTag(1, 256, 1970499664);
  if ( !PnpBusTypeGuidArray )
    return sub_970AE0();
  PnpBusTypeGuidCount = 0;
  PnpBusTypeGuidLock = 1;
  dword_630C64 = 0;
  unk_630C68 = 0;
  byte_630C6C = 1;
  byte_630C6D = 0;
  byte_630C6E = 4;
  dword_630C70 = 0;
  dword_630C78 = (int)&dword_630C74;
  dword_630C74 = (int)&dword_630C74;
  return 0;
}
