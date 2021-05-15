// ViZwShouldCheck 
 
int ViZwShouldCheck()
{
  int result; // r0
  int v1; // r2

  result = 0;
  if ( (MmVerifierData & 0x100) != 0 )
  {
    v1 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
    if ( PsInitialSystemProcess )
    {
      if ( v1 != PsInitialSystemProcess && v1 != PsIdleProcess )
        result = 1;
    }
  }
  return result;
}
