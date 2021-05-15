// EtwpGetStackExtendedHeaderItem 
 
unsigned int __fastcall EtwpGetStackExtendedHeaderItem(unsigned int result, int a2, int a3, int a4, char a5, unsigned __int64 *a6)
{
  unsigned __int64 v7; // r6
  unsigned int v9; // r9
  BOOL v10; // r0
  int v11; // r2
  bool v12; // cf
  int v13; // r2
  __int16 v14; // r5
  int v15; // r4
  unsigned __int64 v16; // r6
  unsigned __int64 v17; // r6
  __int16 v18; // [sp+0h] [bp-28h]
  int v20; // [sp+8h] [bp-20h]

  v18 = 0;
  v7 = 0i64;
  v9 = result;
  v20 = *(_DWORD *)a4 + 16;
  if ( a5 )
    return sub_525C8C();
  if ( (*(_DWORD *)(result + 76) & 0x400) == 0 && (*(_DWORD *)(result + 960) & 1) == 0 )
  {
    v10 = KeAreInterruptsEnabled();
    if ( v10 )
    {
      result = KeGetCurrentIrql(v10);
      v11 = 1;
    }
    else
    {
      result = 15;
    }
    v12 = result >= 2;
    if ( result == 2 )
    {
      if ( !*(_BYTE *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x590) )
        goto LABEL_20;
      v12 = 1;
    }
    if ( !v12 )
    {
      if ( *(_BYTE *)(v9 + 974) || *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x16A) == 1 )
      {
        __dmb(0xBu);
        do
        {
          v17 = __ldrexd(&EtwpStackMatchId);
          v7 = v17 + 1;
        }
        while ( __strexd(v7, &EtwpStackMatchId) );
        goto LABEL_27;
      }
      v13 = v11 & a2;
      if ( !v13 || !*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x134) )
      {
        if ( !v13 )
        {
          result = RtlWalkFrameChain(v20, a3, 1);
          v18 = result;
          if ( a6 )
            v7 = *a6;
        }
        goto LABEL_15;
      }
LABEL_20:
      __dmb(0xBu);
      do
      {
        v16 = __ldrexd(&EtwpStackMatchId);
        v7 = v16 + 1;
      }
      while ( __strexd(v7, &EtwpStackMatchId) );
LABEL_27:
      __dmb(0xBu);
      goto LABEL_15;
    }
  }
LABEL_15:
  if ( v18 || v7 )
  {
    v14 = 4 * (v18 + 2);
    v15 = (v14 + 15) & 0xFFF8;
    *(_QWORD *)(*(_DWORD *)a4 + 8) = v7;
    result = (unsigned int)memset(
                             (_BYTE *)((unsigned __int16)(v14 + 8) + *(_DWORD *)a4),
                             0,
                             v15 - (unsigned __int16)(v14 + 8));
    **(_WORD **)a4 = v15;
    *(_WORD *)(*(_DWORD *)a4 + 2) = 5;
    *(_WORD *)(*(_DWORD *)a4 + 6) = v14;
    *(_WORD *)(*(_DWORD *)a4 + 4) &= 0xFFFEu;
    *(_WORD *)(*(_DWORD *)a4 + 4) &= 1u;
  }
  else
  {
    if ( a3 == 256 )
      result = RtlpInterlockedPushEntrySList(&EtwpStackLookAsideList, (_DWORD *)(*(_DWORD *)a4 - 4));
    *(_DWORD *)a4 = 0;
  }
  return result;
}
