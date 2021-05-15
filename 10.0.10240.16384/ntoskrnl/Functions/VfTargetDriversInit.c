// VfTargetDriversInit 
 
void VfTargetDriversInit()
{
  unsigned int v0; // r1

  if ( !VfSafeMode )
  {
    if ( VfAvlInitializeTree(ViTargetDriversAvl, 0, 28, (int)ViTargetDelayFreeAvlNode) >= 0 )
    {
      dword_61D2B4 = 0;
      __dmb(0xBu);
      do
        v0 = __ldrex((unsigned int *)&ViTargetInitialized);
      while ( __strex(1u, (unsigned int *)&ViTargetInitialized) );
      __dmb(0xBu);
    }
    else
    {
      sub_969990();
    }
  }
}
