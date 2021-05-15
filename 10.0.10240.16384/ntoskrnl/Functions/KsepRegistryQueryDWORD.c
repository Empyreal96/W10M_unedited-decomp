// KsepRegistryQueryDWORD 
 
int __fastcall KsepRegistryQueryDWORD(int a1, unsigned __int16 *a2, _DWORD *a3)
{
  unsigned __int16 *v3; // r4
  unsigned int v5; // r4
  unsigned int v6; // r4
  int v7; // r4
  _WORD *v8; // r3
  unsigned int v9; // r2
  unsigned int v10; // r2
  _WORD *v11; // r3
  int result; // r0
  char v14[8]; // [sp+10h] [bp-40h] BYREF
  int v15; // [sp+1Ch] [bp-34h]
  int v16; // [sp+20h] [bp-30h]
  int v17; // [sp+24h] [bp-2Ch]

  v3 = a2;
  if ( !a1 )
  {
    __dmb(0xBu);
    do
    {
      v5 = __ldrex(&KsepHistoryErrorsIndex);
      v6 = v5 + 1;
    }
    while ( __strex(v6, &KsepHistoryErrorsIndex) );
    __dmb(0xBu);
    v7 = v6 & 0x3F;
    v8 = &KsepHistoryErrors[4 * v7];
    *((_DWORD *)v8 + 1) = -1073740768;
    v8[1] = 4;
    LOBYTE(v8) = KsepDebugFlag;
    KsepHistoryErrors[4 * v7] = 646;
    if ( ((unsigned __int8)v8 & 4) != 0 )
      RtlAssert((int)"KeyHandle != NULL", (int)"minkernel\\ntos\\kshim\\kseregistry.c", 646, 0);
    v3 = a2;
  }
  if ( !a3 )
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
    KsepHistoryErrors[4 * (v10 & 0x3F)] = 647;
    if ( ((unsigned __int8)v11 & 4) != 0 )
      RtlAssert((int)"Value != NULL", (int)"minkernel\\ntos\\kshim\\kseregistry.c", 647, 0);
  }
  *a3 = 0;
  RtlInitUnicodeString((unsigned int)v14, v3);
  result = ZwQueryValueKey();
  if ( !result )
  {
    if ( v16 == 4 && v15 == 4 )
      *a3 = v17;
    else
      result = -1073741788;
  }
  return result;
}
