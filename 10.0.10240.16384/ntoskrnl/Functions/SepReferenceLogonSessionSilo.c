// SepReferenceLogonSessionSilo 
 
int __fastcall SepReferenceLogonSessionSilo(_DWORD *a1, int a2, _DWORD *a3)
{
  int v5; // r6
  int v6; // r5
  unsigned int v7; // r4
  _DWORD *i; // r4
  unsigned int *v9; // r2
  unsigned int v10; // r0
  unsigned int *v11; // r2
  unsigned int v12; // r1
  signed int v13; // r1
  int v14; // r0
  unsigned int v15; // r1
  __int16 v16; // r3
  int result; // r0
  int v18; // r0
  unsigned int v19; // r1
  __int16 v20; // r3

  v5 = *a1 & 0xF;
  v6 = SepLogonSessions;
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v7 + 308);
  ExAcquireResourceExclusiveLite((int)&SepRmDbLock + 56 * (v5 & 3), 1, (int)a3, v5 & 3);
  for ( i = *(_DWORD **)(v6 + 4 * v5); i; i = (_DWORD *)*i )
  {
    if ( i[22] == a2 && *a1 == i[1] && a1[1] == i[2] )
    {
      __dmb(0xBu);
      v9 = i + 6;
      do
        v10 = __ldrex(v9);
      while ( __strex(v10 | 8, v9) );
      __dmb(0xBu);
      if ( (v10 & 8) != 0 )
      {
        v11 = i + 5;
        do
        {
          v12 = __ldrex(v11);
          v13 = v12 + 1;
        }
        while ( __strex(v13, v11) );
        if ( v13 <= 1 )
          sub_7DC008();
      }
      v14 = ExReleaseResourceLite((int)&SepRmDbLock + 56 * (v5 & 3));
      v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v16 = *(_WORD *)(v15 + 0x134) + 1;
      *(_WORD *)(v15 + 308) = v16;
      if ( !v16 && *(_DWORD *)(v15 + 100) != v15 + 100 && !*(_WORD *)(v15 + 310) )
        KiCheckForKernelApcDelivery(v14);
      result = 0;
      *a3 = i;
      return result;
    }
  }
  v18 = ExReleaseResourceLite((int)&SepRmDbLock + 56 * (v5 & 3));
  v19 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v20 = *(_WORD *)(v19 + 0x134) + 1;
  *(_WORD *)(v19 + 308) = v20;
  if ( !v20 && *(_DWORD *)(v19 + 100) != v19 + 100 && !*(_WORD *)(v19 + 310) )
    KiCheckForKernelApcDelivery(v18);
  return -1073741729;
}
