// KsepRegistryCreateKey 
 
int __fastcall KsepRegistryCreateKey(unsigned __int16 *a1, unsigned __int16 *a2, _DWORD *a3)
{
  unsigned int v6; // r2
  unsigned int v7; // r2
  _WORD *v8; // r3
  unsigned int v9; // r2
  unsigned int v10; // r2
  _WORD *v11; // r3
  unsigned int v12; // r2
  unsigned int v13; // r2
  _WORD *v14; // r3
  int v15; // r4
  unsigned int v16; // r1
  _DWORD v18[2]; // [sp+18h] [bp-48h] BYREF
  _DWORD v19[2]; // [sp+20h] [bp-40h] BYREF
  int v20; // [sp+28h] [bp-38h]
  int v21; // [sp+2Ch] [bp-34h]
  _DWORD *v22; // [sp+30h] [bp-30h]
  int v23; // [sp+34h] [bp-2Ch]
  int v24; // [sp+38h] [bp-28h]
  int v25; // [sp+3Ch] [bp-24h]

  v18[0] = 0;
  v18[1] = 0;
  v19[0] = 0;
  v19[1] = 0;
  if ( !a1 )
  {
    __dmb(0xBu);
    do
    {
      v6 = __ldrex(&KsepHistoryErrorsIndex);
      v7 = v6 + 1;
    }
    while ( __strex(v7, &KsepHistoryErrorsIndex) );
    __dmb(0xBu);
    v8 = &KsepHistoryErrors[4 * (v7 & 0x3F)];
    *((_DWORD *)v8 + 1) = -1073740768;
    v8[1] = 4;
    LOBYTE(v8) = KsepDebugFlag;
    KsepHistoryErrors[4 * (v7 & 0x3F)] = 503;
    if ( ((unsigned __int8)v8 & 4) != 0 )
      RtlAssert((int)"EnginePath != NULL", (int)"minkernel\\ntos\\kshim\\kseregistry.c", 503, 0);
  }
  if ( !a2 )
  {
    __dmb(0xBu);
    do
    {
      v9 = __ldrex(&KsepHistoryErrorsIndex);
      v10 = v9 + 1;
    }
    while ( __strex(v10, &KsepHistoryErrorsIndex) );
    __dmb(0xBu);
    v11 = &KsepHistoryErrors[4 * (v10 & 0x3F)];
    *((_DWORD *)v11 + 1) = -1073740768;
    v11[1] = 4;
    LOBYTE(v11) = KsepDebugFlag;
    KsepHistoryErrors[4 * (v10 & 0x3F)] = 504;
    if ( ((unsigned __int8)v11 & 4) != 0 )
      RtlAssert((int)"SearchKey != NULL", (int)"minkernel\\ntos\\kshim\\kseregistry.c", 504, 0);
  }
  if ( !a3 )
  {
    __dmb(0xBu);
    do
    {
      v12 = __ldrex(&KsepHistoryErrorsIndex);
      v13 = v12 + 1;
    }
    while ( __strex(v13, &KsepHistoryErrorsIndex) );
    __dmb(0xBu);
    v14 = &KsepHistoryErrors[4 * (v13 & 0x3F)];
    *((_DWORD *)v14 + 1) = -1073740768;
    v14[1] = 4;
    LOBYTE(v14) = KsepDebugFlag;
    KsepHistoryErrors[4 * (v13 & 0x3F)] = 505;
    if ( ((unsigned __int8)v14 & 4) != 0 )
      RtlAssert((int)"Handle != NULL", (int)"minkernel\\ntos\\kshim\\kseregistry.c", 505, 0);
  }
  KsepStringDuplicate((int)v18, a1);
  v20 = 24;
  v21 = 0;
  v22 = v18;
  v24 = 0;
  v25 = 0;
  v23 = 576;
  v15 = ZwCreateKey();
  if ( v15 >= 0 )
  {
    v15 = KsepStringDuplicate((int)v19, a2);
    if ( v15 >= 0 )
    {
      v20 = 24;
      v21 = 0;
      v22 = v19;
      v23 = 576;
      v24 = 0;
      v25 = 0;
      v15 = ZwCreateKey();
      if ( v15 >= 0 )
      {
        *a3 = 0;
        __dmb(0xBu);
        do
          v16 = __ldrex(&dword_621724[5]);
        while ( __strex(v16 + 1, &dword_621724[5]) );
        __dmb(0xBu);
      }
    }
  }
  KsepStringFree(v18);
  KsepStringFree(v19);
  return v15;
}
