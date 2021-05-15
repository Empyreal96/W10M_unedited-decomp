// CMFUnmapModules 
 
int __fastcall CMFUnmapModules(__int16 a1)
{
  unsigned int v2; // r7
  unsigned int v3; // r2
  int *v4; // r5
  int v5; // r6
  int v6; // r0
  unsigned int v7; // r2
  int v8; // r0
  unsigned int v9; // r2

  if ( (a1 & 0x20) != 0 )
  {
    v2 = CMFSegmentSectionPointer;
    __dmb(0xBu);
    do
      v3 = __ldrex((unsigned int *)&CMFSegmentSectionPointer);
    while ( __strex(0, (unsigned int *)&CMFSegmentSectionPointer) );
    __dmb(0xBu);
    if ( v2 )
    {
      v4 = (int *)v2;
      v5 = 30;
      do
      {
        if ( *v4 )
        {
          ObfDereferenceObject(*v4);
          *v4 = 0;
        }
        ++v4;
        --v5;
      }
      while ( v5 );
      ExFreePoolWithTag(v2);
    }
  }
  if ( (a1 & 0x10) != 0 )
  {
    v6 = CMFDirectorySectionPointer;
    if ( CMFDirectorySectionPointer )
    {
      __dmb(0xBu);
      do
        v7 = __ldrex((unsigned int *)&CMFDirectorySectionPointer);
      while ( v7 == v6 && __strex(0, (unsigned int *)&CMFDirectorySectionPointer) );
      __dmb(0xBu);
      if ( v6 == v7 )
        ObfDereferenceObject(v6);
    }
  }
  if ( (a1 & 0x100) != 0 )
  {
    v8 = CMFHitsSectionPointer;
    if ( CMFHitsSectionPointer )
    {
      __dmb(0xBu);
      do
        v9 = __ldrex((unsigned int *)&CMFHitsSectionPointer);
      while ( v9 == v8 && __strex(0, (unsigned int *)&CMFHitsSectionPointer) );
      __dmb(0xBu);
      if ( v8 == v9 )
        ObfDereferenceObject(v8);
    }
  }
  return 0;
}
