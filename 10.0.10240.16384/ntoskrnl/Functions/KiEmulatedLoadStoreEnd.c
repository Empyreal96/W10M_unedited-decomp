// KiEmulatedLoadStoreEnd 
 
void __fastcall KiEmulatedLoadStoreEnd(int a1, int a2, int a3, int a4, int a5, int a6)
{
  __asm
  {
    CPS.W           #0x1B
    CPS.W           #0x17
  }
  _R4 = a6;
  __asm
  {
    MSR.W           SPSR_fsxc, R4
    SRS.W           SP, #0x17
  }
  JUMPOUT(0x420EF2);
}
