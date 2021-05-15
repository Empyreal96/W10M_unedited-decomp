// RtlGetEnabledExtendedFeatures 
 
__int64 __fastcall RtlGetEnabledExtendedFeatures(__int64 a1)
{
  return a1 & MEMORY[0xFFFF93D8];
}
