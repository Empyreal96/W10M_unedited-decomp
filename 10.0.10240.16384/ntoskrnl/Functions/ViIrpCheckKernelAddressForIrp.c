// ViIrpCheckKernelAddressForIrp 
 
int __fastcall ViIrpCheckKernelAddressForIrp(int result, unsigned int a2, int a3)
{
  int v3; // r6
  int v4; // r5

  v3 = result;
  if ( a2 )
  {
    if ( a2 < MmHighestUserAddress )
    {
      v4 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
      if ( v4 != PsInitialSystemProcess
        && v4 != PsIdleProcess
        && (!a3 || (result = VfTargetDriversIsEnabled(*(_DWORD *)(a3 + 104))) != 0) )
      {
        result = VerifierBugCheckIfAppropriate(196, 226, v3);
      }
    }
  }
  return result;
}
