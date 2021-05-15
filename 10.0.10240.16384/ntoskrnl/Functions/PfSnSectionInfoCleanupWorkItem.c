// PfSnSectionInfoCleanupWorkItem 
 
unsigned __int8 *__fastcall PfSnSectionInfoCleanupWorkItem(int a1)
{
  unsigned int *v1; // r5
  unsigned int v2; // r6
  __int64 v3; // kr00_8
  unsigned int v4; // r2
  unsigned int *v5; // r9
  unsigned int v6; // r2
  unsigned int v7; // r2
  unsigned int v8; // r4
  unsigned int v9; // r0
  int v10; // r2
  unsigned int v11; // r2
  unsigned int v12; // r1
  int v13; // r3
  unsigned __int8 *result; // r0
  unsigned int v15; // r4
  unsigned int v16; // r1

  v1 = *(unsigned int **)(a1 + 16);
  v2 = v1[1];
  v3 = *(_QWORD *)(v2 + 108);
  PsSetCurrentThreadPrefetching(1);
  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v4 + 308);
  __dmb(0xBu);
  v5 = v1 + 4;
  do
  {
    v6 = __ldrex(v5);
    v7 = v6 + 1;
  }
  while ( __strex(v7, v5) );
  while ( 1 )
  {
    __dmb(0xBu);
    v8 = v7 - 1;
    if ( v7 - 1 >= v1[5] )
      break;
    v9 = *(_DWORD *)(v3 + 4 * v8);
    if ( v9 )
      ExFreePoolWithTag(v9);
    v10 = *(_DWORD *)(HIDWORD(v3) + 4 * v8);
    if ( v10 >= 0 )
      PfSnCleanupPrefetchSectionInfo(*(_DWORD *)(v2 + 104) + 32 * v10, v2, 1);
    __dmb(0xBu);
    do
    {
      v11 = __ldrex(v5);
      v7 = v11 + 1;
    }
    while ( __strex(v7, v5) );
  }
  v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v13 = (__int16)(*(_WORD *)(v12 + 0x134) + 1);
  *(_WORD *)(v12 + 308) = v13;
  if ( !v13 )
    return (unsigned __int8 *)sub_8014DC();
  result = (unsigned __int8 *)PsSetCurrentThreadPrefetching(0);
  __pld(v1);
  v15 = *v1 & 0xFFFFFFFE;
  __dmb(0xBu);
  do
    v16 = __ldrex(v1);
  while ( v16 == v15 && __strex(v15 - 2, v1) );
  if ( v16 != v15 )
    result = ExfReleaseRundownProtection((unsigned __int8 *)v1);
  return result;
}
