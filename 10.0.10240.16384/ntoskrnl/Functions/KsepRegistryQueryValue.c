// KsepRegistryQueryValue 
 
int __fastcall KsepRegistryQueryValue(int a1, unsigned __int16 *a2, _DWORD *a3, int a4, unsigned int a5, unsigned int *a6)
{
  int v6; // r6
  unsigned int v8; // r5
  unsigned int v9; // r5
  _WORD *v10; // r3
  unsigned int v11; // r2
  unsigned int v12; // r2
  _WORD *v13; // r3
  unsigned int v14; // r2
  unsigned int v15; // r2
  _WORD *v16; // r3
  int v17; // r0
  int v18; // r5
  unsigned int v19; // r2
  unsigned int v20; // r2
  _WORD *v21; // r3
  int v22; // r4
  unsigned int v23; // r2
  char v27[40]; // [sp+18h] [bp-28h] BYREF

  v6 = a4;
  if ( !a1 )
  {
    __dmb(0xBu);
    do
    {
      v8 = __ldrex(&KsepHistoryErrorsIndex);
      v9 = v8 + 1;
    }
    while ( __strex(v9, &KsepHistoryErrorsIndex) );
    __dmb(0xBu);
    v10 = &KsepHistoryErrors[4 * (v9 & 0x3F)];
    v10[1] = 4;
    *((_DWORD *)v10 + 1) = -1073740768;
    LOBYTE(v10) = KsepDebugFlag;
    KsepHistoryErrors[4 * (v9 & 0x3F)] = 969;
    if ( ((unsigned __int8)v10 & 4) != 0 )
      RtlAssert((int)"KeyHandle != NULL", (int)"minkernel\\ntos\\kshim\\kseregistry.c", 969, 0);
  }
  if ( !v6 )
  {
    __dmb(0xBu);
    do
    {
      v11 = __ldrex(&KsepHistoryErrorsIndex);
      v12 = v11 + 1;
    }
    while ( __strex(v12, &KsepHistoryErrorsIndex) );
    __dmb(0xBu);
    v13 = &KsepHistoryErrors[4 * (v12 & 0x3F)];
    *((_DWORD *)v13 + 1) = -1073740768;
    v13[1] = 4;
    LOBYTE(v13) = KsepDebugFlag;
    KsepHistoryErrors[4 * (v12 & 0x3F)] = 970;
    if ( ((unsigned __int8)v13 & 4) != 0 )
      RtlAssert((int)"ValueBuffer != NULL", (int)"minkernel\\ntos\\kshim\\kseregistry.c", 970, 0);
  }
  if ( !a6 )
  {
    __dmb(0xBu);
    do
    {
      v14 = __ldrex(&KsepHistoryErrorsIndex);
      v15 = v14 + 1;
    }
    while ( __strex(v15, &KsepHistoryErrorsIndex) );
    __dmb(0xBu);
    v16 = &KsepHistoryErrors[4 * (v15 & 0x3F)];
    *((_DWORD *)v16 + 1) = -1073740768;
    v16[1] = 4;
    LOBYTE(v16) = KsepDebugFlag;
    KsepHistoryErrors[4 * (v15 & 0x3F)] = 971;
    if ( ((unsigned __int8)v16 & 4) != 0 )
      RtlAssert((int)"ActualLength != NULL", (int)"minkernel\\ntos\\kshim\\kseregistry.c", 971, 0);
  }
  RtlInitUnicodeString((unsigned int)v27, a2);
  v17 = ZwQueryValueKey();
  v18 = v17;
  if ( v17 == -1073741789 )
  {
    v22 = KsepPoolAllocatePaged(0);
    if ( v22 )
    {
      v18 = ZwQueryValueKey();
      if ( !v18 )
      {
        v23 = *(_DWORD *)(v22 + 8);
        if ( v23 <= a5 )
        {
          memmove(a4, v22 + 12, v23);
          *a3 = *(_DWORD *)(v22 + 4);
          *a6 = *(_DWORD *)(v22 + 8);
        }
        else
        {
          *a6 = v23;
          v18 = -1073741789;
        }
      }
      KsepPoolFreePaged(v22);
    }
    else
    {
      v18 = -1073741801;
    }
  }
  else if ( v17 >= 0 )
  {
    __dmb(0xBu);
    do
    {
      v19 = __ldrex(&KsepHistoryErrorsIndex);
      v20 = v19 + 1;
    }
    while ( __strex(v20, &KsepHistoryErrorsIndex) );
    __dmb(0xBu);
    v21 = &KsepHistoryErrors[4 * (v20 & 0x3F)];
    *((_DWORD *)v21 + 1) = -1073740768;
    v21[1] = 4;
    LOBYTE(v21) = KsepDebugFlag;
    KsepHistoryErrors[4 * (v20 & 0x3F)] = 989;
    if ( ((unsigned __int8)v21 & 4) != 0 )
      RtlAssert((int)"!NT_SUCCESS(Status)", (int)"minkernel\\ntos\\kshim\\kseregistry.c", 989, 0);
  }
  return v18;
}
