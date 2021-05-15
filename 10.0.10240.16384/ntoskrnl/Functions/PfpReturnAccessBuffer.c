// PfpReturnAccessBuffer 
 
unsigned __int8 *__fastcall PfpReturnAccessBuffer(_DWORD *a1)
{
  unsigned int v2; // r5
  unsigned int v3; // r1
  unsigned int v4; // r4
  unsigned int v5; // r4
  unsigned int v6; // r0
  int v7; // r5
  unsigned int v8; // r4
  unsigned __int8 *result; // r0

  __pld(&dword_643B48);
  v2 = dword_643B48 & 0xFFFFFFFE;
  v3 = (dword_643B48 & 0xFFFFFFFE) + 2;
  do
    v4 = __ldrex((unsigned int *)&dword_643B48);
  while ( v4 == v2 && __strex(v3, (unsigned int *)&dword_643B48) );
  __dmb(0xBu);
  if ( v4 != v2 && !ExfAcquireRundownProtection(&dword_643B48) )
    return (unsigned __int8 *)MmFreeAccessPfnBuffer((int)a1, 0);
  v5 = (unsigned __int16)word_643B64;
  if ( (unsigned __int16)word_643B64 < (unsigned int)dword_643B5C )
  {
    RtlpInterlockedPushEntrySList((unsigned __int64 *)&unk_643B60, a1);
    if ( !dword_643B50 && v5 >= 8 )
      KeSetEvent((int)algn_643B4C, 0, 0);
    v7 = 1;
  }
  else
  {
    __dmb(0xBu);
    do
      v6 = __ldrex(&dword_643B08);
    while ( __strex(v6 + 100, &dword_643B08) );
    __dmb(0xBu);
    v7 = 0;
  }
  __pld(&dword_643B48);
  v8 = dword_643B48 & 0xFFFFFFFE;
  __dmb(0xBu);
  do
    result = (unsigned __int8 *)__ldrex((unsigned int *)&dword_643B48);
  while ( result == (unsigned __int8 *)v8 && __strex(v8 - 2, (unsigned int *)&dword_643B48) );
  if ( result != (unsigned __int8 *)v8 )
    result = ExfReleaseRundownProtection((unsigned __int8 *)&dword_643B48);
  if ( !v7 )
    return (unsigned __int8 *)MmFreeAccessPfnBuffer((int)a1, 0);
  return result;
}
