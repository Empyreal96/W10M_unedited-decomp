// SmKmEtwLogStoreRundown 
 
unsigned __int8 *__fastcall SmKmEtwLogStoreRundown(unsigned __int8 *result, int a2)
{
  unsigned int v2; // r6
  int v3; // r10
  int v4; // r8
  int v5; // r9
  unsigned int *v6; // r7
  unsigned int v7; // r5
  unsigned int v8; // r4
  int v9; // r4
  unsigned int v10; // r4
  unsigned int v11; // r1
  unsigned int v12; // r4
  unsigned int v13; // r1
  unsigned int v14; // [sp+0h] [bp-28h]
  int *v15; // [sp+4h] [bp-24h]

  v2 = 0;
  v3 = a2;
  v15 = (int *)result;
  v4 = a2;
  do
  {
    v14 = v2 | (32 * (*(_WORD *)(v4 + 12) & 0x7FF));
    v5 = v3 + 96 * (v14 & 0x1F);
    v6 = (unsigned int *)(v5 + 4);
    __pld((void *)(v5 + 4));
    v7 = *(_DWORD *)(v5 + 4) & 0xFFFFFFFE;
    do
      v8 = __ldrex(v6);
    while ( v8 == v7 && __strex(v7 + 2, v6) );
    __dmb(0xBu);
    if ( v8 == v7 || (result = (unsigned __int8 *)ExfAcquireRundownProtection((_DWORD *)(v5 + 4))) != 0 )
    {
      if ( (*(_WORD *)(v5 + 12) & 0x7FF) == v14 >> 5 )
      {
        v9 = *(_DWORD *)v5;
        goto LABEL_15;
      }
      __pld(v6);
      v10 = *v6 & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v11 = __ldrex(v6);
      while ( v11 == v10 && __strex(v10 - 2, v6) );
      if ( v11 != v10 )
        result = ExfReleaseRundownProtection((unsigned __int8 *)(v5 + 4));
    }
    v9 = 0;
LABEL_15:
    if ( v9 )
    {
      SmKmEtwLogStoreStats(v15, v9);
      SmKmEtwLogStoreChange(v15, v9, SmEventStoreRundown);
      result = (unsigned __int8 *)(v3 + 96 * (v2 & 0x1F) + 4);
      __pld(result);
      v12 = *(_DWORD *)result & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v13 = __ldrex((unsigned int *)result);
      while ( v13 == v12 && __strex(v12 - 2, (unsigned int *)result) );
      if ( v13 != v12 )
        result = ExfReleaseRundownProtection(result);
    }
    ++v2;
    v4 += 96;
  }
  while ( v2 < 0x20 );
  return result;
}
