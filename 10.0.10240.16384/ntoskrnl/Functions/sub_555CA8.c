// sub_555CA8 
 
// positive sp value has been detected, the output may be wrong!
int __fastcall sub_555CA8(int a1, int a2)
{
  if ( !a1 )
    return MmIsDriverVerifying(a2);
  if ( a1 != 1 )
  {
    if ( a1 == 2 && (MmVerifierData & 0x40000000) != 0 )
      JUMPOUT(0x4F9232);
LABEL_9:
    JUMPOUT(0x4F9230);
  }
  if ( MmVerifierData >= 0 )
    goto LABEL_9;
  return ((int (__fastcall *)(int))PpvUtilIsHardwareBeingVerified)(a2);
}
