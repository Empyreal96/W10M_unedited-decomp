// VfInitPickCurrentRandomTarget 
 
int VfInitPickCurrentRandomTarget()
{
  if ( !VfRandomVerifiedDrivers )
    return 0;
  ++ViLoadedDriversCount;
  if ( ((*(char *)(((unsigned int)ViLoadedDriversCount >> 3) + dword_90800C) >> (ViLoadedDriversCount & 7)) & 1) == 0 )
    return 0;
  --VfRandomVerifiedDrivers;
  return 1;
}
