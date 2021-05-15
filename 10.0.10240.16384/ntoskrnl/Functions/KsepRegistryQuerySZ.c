// KsepRegistryQuerySZ 
 
int __fastcall KsepRegistryQuerySZ(int a1, unsigned __int16 *a2, int a3, int a4, unsigned int a5, _DWORD *a6)
{
  int v8; // r0
  int v9; // r5
  unsigned int v10; // r2
  unsigned int v11; // r2
  _WORD *v12; // r3
  unsigned int v13; // r2
  unsigned int v14; // r2
  _WORD *v15; // r3
  unsigned int v16; // r2
  unsigned int v17; // r2
  _WORD *v18; // r3
  int v19; // r4
  unsigned int v20; // r2
  char v23[40]; // [sp+18h] [bp-28h] BYREF

  if ( !a1 )
    return sub_7CEFA4(4);
  if ( !a4 )
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
    v12[1] = 4;
    LOBYTE(v12) = KsepDebugFlag;
    KsepHistoryErrors[4 * (v11 & 0x3F)] = 850;
    if ( ((unsigned __int8)v12 & 4) != 0 )
      RtlAssert((int)"ValueBuffer != NULL", (int)"minkernel\\ntos\\kshim\\kseregistry.c", 850, 0);
  }
  if ( !a6 )
  {
    __dmb(0xBu);
    do
    {
      v13 = __ldrex(&KsepHistoryErrorsIndex);
      v14 = v13 + 1;
    }
    while ( __strex(v14, &KsepHistoryErrorsIndex) );
    __dmb(0xBu);
    v15 = &KsepHistoryErrors[4 * (v14 & 0x3F)];
    *((_DWORD *)v15 + 1) = -1073740768;
    v15[1] = 4;
    LOBYTE(v15) = KsepDebugFlag;
    KsepHistoryErrors[4 * (v14 & 0x3F)] = 851;
    if ( ((unsigned __int8)v15 & 4) != 0 )
      RtlAssert((int)"ActualLength != NULL", (int)"minkernel\\ntos\\kshim\\kseregistry.c", 851, 0);
  }
  RtlInitUnicodeString((unsigned int)v23, a2);
  v8 = ZwQueryValueKey();
  v9 = v8;
  if ( v8 == -1073741789 )
  {
    v19 = KsepPoolAllocatePaged(0);
    if ( v19 )
    {
      v9 = ZwQueryValueKey();
      if ( !v9 )
      {
        v20 = *(_DWORD *)(v19 + 8);
        if ( v20 <= a5 )
        {
          if ( *(_DWORD *)(v19 + 4) == a3 )
          {
            memmove(a4, v19 + 12, v20);
            *a6 = *(_DWORD *)(v19 + 8);
          }
          else
          {
            v9 = -1073741788;
          }
        }
        else
        {
          v9 = -1073741789;
        }
      }
      KsepPoolFreePaged(v19);
    }
    else
    {
      v9 = -1073741801;
    }
  }
  else if ( v8 >= 0 )
  {
    __dmb(0xBu);
    do
    {
      v16 = __ldrex(&KsepHistoryErrorsIndex);
      v17 = v16 + 1;
    }
    while ( __strex(v17, &KsepHistoryErrorsIndex) );
    __dmb(0xBu);
    v18 = &KsepHistoryErrors[4 * (v17 & 0x3F)];
    *((_DWORD *)v18 + 1) = -1073740768;
    v18[1] = 4;
    LOBYTE(v18) = KsepDebugFlag;
    KsepHistoryErrors[4 * (v17 & 0x3F)] = 869;
    if ( ((unsigned __int8)v18 & 4) != 0 )
      RtlAssert((int)"!NT_SUCCESS(Status)", (int)"minkernel\\ntos\\kshim\\kseregistry.c", 869, 0);
  }
  return v9;
}
