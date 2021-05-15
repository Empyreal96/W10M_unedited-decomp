// VfPowerIsSystemRestrictedIrp 
 
BOOL __fastcall VfPowerIsSystemRestrictedIrp(int a1)
{
  return !*(_BYTE *)(a1 + 1) || *(_BYTE *)(a1 + 1) != 1;
}
