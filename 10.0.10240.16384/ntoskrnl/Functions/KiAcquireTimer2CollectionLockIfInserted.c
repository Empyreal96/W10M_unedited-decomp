// KiAcquireTimer2CollectionLockIfInserted 
 
int __fastcall KiAcquireTimer2CollectionLockIfInserted(int a1)
{
  int v2; // r5
  unsigned int v4; // r2

  v2 = 0;
  if ( (*(_BYTE *)(a1 + 1) & 1) != 0 )
  {
    if ( (dword_682604 & 0x210000) != 0 )
      return sub_52C53C();
    do
      v4 = __ldrex((unsigned int *)&KiTimer2CollectionLock);
    while ( __strex(1u, (unsigned int *)&KiTimer2CollectionLock) );
    __dmb(0xBu);
    if ( v4 )
      KxWaitForSpinLockAndAcquire(&KiTimer2CollectionLock);
    if ( (*(_BYTE *)(a1 + 1) & 1) != 0 )
    {
      v2 = 1;
    }
    else if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(&KiTimer2CollectionLock);
    }
    else
    {
      __dmb(0xBu);
      KiTimer2CollectionLock = 0;
    }
  }
  return v2;
}
