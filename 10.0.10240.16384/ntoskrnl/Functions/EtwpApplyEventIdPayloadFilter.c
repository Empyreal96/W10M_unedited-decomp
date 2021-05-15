// EtwpApplyEventIdPayloadFilter 
 
int __fastcall EtwpApplyEventIdPayloadFilter(int a1, int a2, int a3, int a4, unsigned __int16 a5, int a6, int a7, unsigned __int8 a8, unsigned __int8 a9)
{
  int v9; // r4
  unsigned int *v10; // r5
  int v14; // r6
  int v15; // r9
  __int64 v16; // r0
  unsigned int v17; // r2
  __int64 v18; // r0
  int v19; // r3
  unsigned int v20; // r2
  unsigned int v21; // r2
  bool v23; // [sp+10h] [bp-20h]

  v9 = 1;
  v10 = 0;
  v23 = 1;
  if ( a9 >= 2u )
  {
    if ( *(_DWORD *)(*(_DWORD *)(a1 + 344) + 36 * a2 + 24) )
    {
      v18 = EtwpPerfectHashFunctionSearch(a5);
      v19 = (unsigned __int8)*(_BYTE *)HIDWORD(v18);
      v9 = v19 == v18;
      v23 = v19 == (_DWORD)v18;
      if ( v19 != (_DWORD)v18 )
        return v9;
    }
    v10 = *(unsigned int **)(*(_DWORD *)(a1 + 344) + 36 * a2 + 28);
  }
  else
  {
    v14 = 9 * a2;
    v15 = KfRaiseIrql(2);
    if ( !*(_DWORD *)(*(_DWORD *)(a1 + 344) + 4 * v14 + 24) )
      goto LABEL_6;
    v16 = EtwpPerfectHashFunctionSearch(a5);
    if ( (unsigned __int8)*(_BYTE *)HIDWORD(v16) != (_DWORD)v16 )
      v9 = 0;
    v23 = v9;
    if ( v9 )
    {
LABEL_6:
      v10 = *(unsigned int **)(*(_DWORD *)(a1 + 344) + 4 * v14 + 28);
      if ( v10 )
      {
        __dmb(0xBu);
        do
          v17 = __ldrex(v10);
        while ( __strex(v17 + 1, v10) );
        __dmb(0xBu);
      }
    }
    KfLowerIrql(v15);
  }
  if ( v10 )
  {
    if ( EtwpApplyPayloadFilterInternal(a4, a6, a7, a8) >= 0 )
      v9 = v23;
    else
      v9 = 1;
    if ( a9 < 2u )
    {
      __dmb(0xBu);
      do
      {
        v20 = __ldrex(v10);
        v21 = v20 - 1;
      }
      while ( __strex(v21, v10) );
      __dmb(0xBu);
      if ( !v21 )
        ExFreePoolWithTag(v10);
    }
  }
  return v9;
}
