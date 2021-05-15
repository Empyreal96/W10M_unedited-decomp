// VfPoolInitPhase0 
 
void VfPoolInitPhase0()
{
  int v0; // r3
  int v1; // r2

  if ( (MmVerifierData & 0xFBF) != 0 )
  {
    v0 = VfPoolTracesLength;
    if ( (unsigned int)VfPoolTracesLength >= 0x10000 )
    {
      v1 = 0x100000;
      if ( (unsigned int)VfPoolTracesLength <= 0x100000 )
      {
        while ( (VfPoolTracesLength & v1) == 0 )
        {
          v1 >>= 1;
          if ( v1 < 0x10000 )
            goto LABEL_10;
        }
        v0 = VfPoolTracesLength & v1;
        VfPoolTracesLength &= v1;
      }
      else
      {
        v0 = 0x100000;
        VfPoolTracesLength = 0x100000;
      }
    }
    else
    {
      v0 = 0x10000;
      VfPoolTracesLength = 0x10000;
    }
LABEL_10:
    VfPoolTraces = ExAllocatePoolWithTagPriority(512, v0 << 6, 1414555222, 32);
  }
}
