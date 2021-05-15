// RtlEmptyAtomTable 
 
int __fastcall RtlEmptyAtomTable(_DWORD *a1, int a2)
{
  int *v5; // r9
  unsigned int i; // r8
  int *v7; // r6
  int v8; // r1
  __int64 **v9; // r7
  __int64 *v10; // r0
  __int64 v11; // r2
  int v12; // r4
  unsigned int *v13; // r4
  unsigned int v14; // r1
  int v15; // r0
  unsigned int v16; // r1
  __int16 v17; // r3

  if ( !RtlpLockAtomTable(a1) )
    return -1073741811;
  v5 = a1 + 6;
  for ( i = 0; i < a1[5]; ++i )
  {
    v7 = v5++;
    while ( 1 )
    {
      v12 = *v7;
      if ( !*v7 )
        break;
      if ( a2 || (*(_WORD *)(v12 + 22) & 1) == 0 )
      {
        v8 = *v7;
        *v7 = *(_DWORD *)v12;
        *(_DWORD *)v12 = 0;
        RtlpFreeHandleForAtom((int)a1, v8);
        v9 = (__int64 **)(v12 + 8);
        while ( *v9 != (__int64 *)v9 )
        {
          v10 = *v9;
          v11 = **v9;
          if ( (__int64 **)HIDWORD(v11) != v9 || *(__int64 **)(v11 + 4) != v10 )
            __fastfail(3u);
          *v9 = (__int64 *)v11;
          *(_DWORD *)(v11 + 4) = v9;
          RtlpFreeAtom((int)v10);
        }
        RtlpFreeAtom(v12);
      }
      else
      {
        v7 = (int *)*v7;
      }
    }
  }
  v13 = a1 + 2;
  __dmb(0xBu);
  do
    v14 = __ldrex(v13);
  while ( __strex(v14 - 1, v13) );
  if ( (v14 & 2) != 0 && (v14 & 4) == 0 )
    ExfTryToWakePushLock(a1 + 2);
  v15 = KeAbPostRelease((unsigned int)(a1 + 2));
  v16 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v17 = *(_WORD *)(v16 + 0x134) + 1;
  *(_WORD *)(v16 + 308) = v17;
  if ( !v17 && *(_DWORD *)(v16 + 100) != v16 + 100 && !*(_WORD *)(v16 + 310) )
    KiCheckForKernelApcDelivery(v15);
  return 0;
}
