// sub_524E0C 
 
void __fastcall sub_524E0C(int a1)
{
  if ( (*(_DWORD *)(a1 - 40) & 0xC0000000) == -1073741824 )
  {
    pIoFreeIrp(a1 - 64);
    JUMPOUT(0x45E44A);
  }
  JUMPOUT(0x45E422);
}
