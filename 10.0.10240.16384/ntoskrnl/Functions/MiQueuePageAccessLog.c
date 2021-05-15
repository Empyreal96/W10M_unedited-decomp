// MiQueuePageAccessLog 
 
unsigned __int8 *__fastcall MiQueuePageAccessLog(_DWORD *a1, int a2, int a3, int a4)
{
  unsigned int v5; // r5
  unsigned int v6; // r1
  unsigned int v7; // r4
  unsigned int v8; // r4
  unsigned int v9; // r0
  int v10; // r5
  unsigned int v11; // r4
  unsigned __int8 *result; // r0
  int v13; // [sp+0h] [bp-18h] BYREF
  int v14; // [sp+4h] [bp-14h]

  v13 = a3;
  v14 = a4;
  KeQueryTickCount(&v13);
  a1[6] = v13;
  a1[7] = v14;
  a1[2] = dword_643B68;
  __pld(&dword_643B48);
  v5 = dword_643B48 & 0xFFFFFFFE;
  v6 = (dword_643B48 & 0xFFFFFFFE) + 2;
  do
    v7 = __ldrex((unsigned int *)&dword_643B48);
  while ( v7 == v5 && __strex(v6, (unsigned int *)&dword_643B48) );
  __dmb(0xBu);
  if ( v7 != v5 && !ExfAcquireRundownProtection(&dword_643B48) )
    return (unsigned __int8 *)MmFreeAccessPfnBuffer(a1, 1);
  v8 = (unsigned __int16)word_643B64;
  if ( (unsigned __int16)word_643B64 < (unsigned int)dword_643B5C )
  {
    RtlpInterlockedPushEntrySList((unsigned __int64 *)&unk_643B60, a1);
    if ( !dword_643B50 && v8 >= 8 )
      KeSetEvent((int)algn_643B4C, 0, 0);
    v10 = 1;
  }
  else
  {
    __dmb(0xBu);
    do
      v9 = __ldrex(&dword_643B08);
    while ( __strex(v9 + 100, &dword_643B08) );
    __dmb(0xBu);
    v10 = 0;
  }
  __pld(&dword_643B48);
  v11 = dword_643B48 & 0xFFFFFFFE;
  __dmb(0xBu);
  do
    result = (unsigned __int8 *)__ldrex((unsigned int *)&dword_643B48);
  while ( result == (unsigned __int8 *)v11 && __strex(v11 - 2, (unsigned int *)&dword_643B48) );
  if ( result != (unsigned __int8 *)v11 )
    result = ExfReleaseRundownProtection((unsigned __int8 *)&dword_643B48);
  if ( !v10 )
    return (unsigned __int8 *)MmFreeAccessPfnBuffer(a1, 1);
  return result;
}
