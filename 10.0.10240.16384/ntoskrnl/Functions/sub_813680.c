// sub_813680 
 
void sub_813680()
{
  int v0; // r4
  int v1; // r9

  if ( BiSetRegistryValue(v0, L"FirmwareVariable", L"Description", 3) >= 0 )
  {
    *(_DWORD *)(v1 + 32) |= 2u;
    JUMPOUT(0x7A51DC);
  }
  JUMPOUT(0x7A52C2);
}
