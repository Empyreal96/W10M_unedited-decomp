// KseShimDatabaseBootInitialize 
 
int __fastcall KseShimDatabaseBootInitialize(int a1, unsigned int a2)
{
  int v4; // r0
  int v5; // r4
  int v6; // r4
  unsigned int v7; // r2
  unsigned int v8; // r2
  _WORD *v9; // r3
  unsigned int v10; // r2
  unsigned int v11; // r2
  _WORD *v12; // r3
  unsigned int v13; // r2
  unsigned int v14; // r2
  int v15; // r1
  _WORD *v16; // r2
  unsigned int v17; // r2
  unsigned int v18; // r2
  _WORD *v19; // r3

  if ( KsepShimDbDuringBoot )
    return sub_96F604(4, 9);
  if ( KsepShimDbHandle )
  {
    __dmb(0xBu);
    do
    {
      v7 = __ldrex(&KsepHistoryErrorsIndex);
      v8 = v7 + 1;
    }
    while ( __strex(v8, &KsepHistoryErrorsIndex) );
    __dmb(0xBu);
    v9 = &KsepHistoryErrors[4 * (v8 & 0x3F)];
    *((_DWORD *)v9 + 1) = -1073740768;
    v9[1] = 9;
    *v9 = 122;
    if ( (KsepDebugFlag & 4) != 0 )
      RtlAssert((int)"KsepShimDbHandle == NULL", (int)"minkernel\\ntos\\kshim\\ksesdb.c", 122, 0);
  }
  if ( KsepShimDbAddress )
  {
    __dmb(0xBu);
    do
    {
      v10 = __ldrex(&KsepHistoryErrorsIndex);
      v11 = v10 + 1;
    }
    while ( __strex(v11, &KsepHistoryErrorsIndex) );
    __dmb(0xBu);
    v12 = &KsepHistoryErrors[4 * (v11 & 0x3F)];
    *((_DWORD *)v12 + 1) = -1073740768;
    v12[1] = 9;
    *v12 = 123;
    if ( (KsepDebugFlag & 4) != 0 )
      RtlAssert((int)"KsepShimDbAddress == NULL", (int)"minkernel\\ntos\\kshim\\ksesdb.c", 123, 0);
  }
  KsepShimDbLock = 0;
  KsepShimDbDuringBoot = 1;
  KsepShimDbHandle = 0;
  KsepShimDbAddress = 0;
  if ( !a1 || !a2 )
    return -1073741823;
  v4 = KsepPoolAllocatePaged(a2);
  v5 = v4;
  KsepShimDbAddress = v4;
  if ( v4 )
  {
    memmove(v4, a1, a2);
    KsepShimDbHandle = SdbInitDatabaseInMemory(v5, a2);
    if ( KsepShimDbHandle )
    {
      ++KsepShimDbRefCount;
      v6 = 0;
    }
    else
    {
      __dmb(0xBu);
      do
      {
        v17 = __ldrex(&KsepHistoryErrorsIndex);
        v18 = v17 + 1;
      }
      while ( __strex(v18, &KsepHistoryErrorsIndex) );
      __dmb(0xBu);
      v6 = -1073741823;
      v19 = &KsepHistoryErrors[4 * (v18 & 0x3F)];
      v19[1] = 9;
      *((_DWORD *)v19 + 1) = -1073741823;
      *v19 = 175;
      if ( (KsepDebugFlag & 2) != 0 )
        KsepDebugPrint(1, (int)"KSE: SdbInitDatabaseInMemory failed during boot!\n");
      KsepLogError(1, (int)"KSE: SdbInitDatabaseInMemory failed during boot!\n");
      KsepPoolFreePaged(KsepShimDbAddress);
      KsepShimDbAddress = 0;
    }
  }
  else
  {
    __dmb(0xBu);
    do
    {
      v13 = __ldrex(&KsepHistoryErrorsIndex);
      v14 = v13 + 1;
    }
    while ( __strex(v14, &KsepHistoryErrorsIndex) );
    __dmb(0xBu);
    v15 = v14 & 0x3F;
    v16 = &KsepHistoryErrors[4 * v15];
    *((_DWORD *)v16 + 1) = -1073741823;
    v16[1] = 9;
    *v16 = 158;
    if ( (KsepDebugFlag & 2) != 0 )
      KsepDebugPrint(0, (int)"KSE: Failed to allocate memory for shim database during boot!\n");
    KsepLogError(0, (int)"KSE: Failed to allocate memory for shim database during boot!\n");
    v6 = -1073741670;
  }
  return v6;
}
