// MxGetPhase0Mapping 
 
int MxGetPhase0Mapping()
{
  if ( MiHalScratchPte )
    return MiHalScratchPte << 10;
  if ( (*(_DWORD *)((((unsigned int)MiLowHalVa >> 20) & 0xFFC) - 1070596096) & 2) == 0 )
    JUMPOUT(0x9653BC);
  return sub_9653AC();
}
