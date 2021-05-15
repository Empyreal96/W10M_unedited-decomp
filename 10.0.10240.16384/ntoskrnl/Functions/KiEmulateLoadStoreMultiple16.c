// KiEmulateLoadStoreMultiple16 
 
void __fastcall KiEmulateLoadStoreMultiple16(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
  __asm
  {
    SRS.W           SP, #0x1B
    CPS.W           #0x1B
  }
  a11 = a1;
  JUMPOUT(0x421FCC);
}
