// KeAbPostRelease 
 
unsigned int __fastcall KeAbPostRelease(unsigned int result)
{
  unsigned int v1; // r7
  int v2; // r10
  int v3; // r6
  int v4; // r3
  int v5; // r2
  int v6; // lr
  unsigned int v7; // r1
  int v8; // r2
  int v9; // r5
  __int16 v10; // r3
  int v11; // r2
  __int16 v12; // r3
  unsigned int v13; // r3
  int v14; // r3
  unsigned int *v15; // r2
  unsigned int v16; // r1
  char v17; // r2
  unsigned __int8 *v18; // r4
  int v19; // [sp+Ch] [bp-24h]

  v1 = result;
  if ( KiAbEnabled )
  {
    v2 = result & 0x7FFFFFFC;
    if ( (result & 0x7FFFFFFC) != 0 )
    {
      v19 = 0;
      v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      if ( result >= dword_63389C )
      {
        v4 = *((unsigned __int8 *)&MiState[2423]
             + ((int)(((result >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2));
        if ( v4 == 1 || v4 == 11 )
          return sub_50CC78();
      }
      if ( (unsigned int)KeGetCurrentIrql(result) <= 1 )
      {
        v19 = 1;
        --*(_WORD *)(v3 + 310);
      }
      v5 = *(char *)(v3 + 484);
      __dmb(0xBu);
      v6 = (v5 | *(char *)(v3 + 810)) ^ 0x3F;
      v7 = __clz(v6);
      result = 31 - v7;
      if ( 1 == (unsigned __int8)(v7 >> 5) )
      {
LABEL_24:
        if ( (*(_DWORD *)(v3 + 80) & 0x8000) == 0 )
          KeBugCheckEx(354, v3, v1);
        if ( v19 )
        {
          v14 = (__int16)(*(_WORD *)(v3 + 310) + 1);
          *(_WORD *)(v3 + 310) = v14;
          if ( !v14 && *(_DWORD *)(v3 + 100) != v3 + 100 )
            return KiCheckForKernelApcDelivery(result);
        }
      }
      else
      {
        v8 = -1;
        while ( 1 )
        {
          v6 &= ~(1 << result);
          v9 = v3 + 48 * result + 488;
          if ( (*(_BYTE *)(v3 + 48 * result + 502) & 1) != 0
            && (*(_DWORD *)(v3 + 48 * result + 504) & 1) == 0
            && (*(_DWORD *)(v3 + 48 * result + 504) & 0x7FFFFFFC) == v2
            && *(_DWORD *)(v3 + 48 * result + 508) == -1 )
          {
            *(_BYTE *)(v3 + 48 * result + 502) &= 0xFEu;
            if ( *(_DWORD *)(v3 + 48 * result + 504) )
              break;
          }
          v13 = __clz(v6);
          result = 31 - v13;
          if ( 1 == (unsigned __int8)(v13 >> 5) )
            goto LABEL_24;
        }
        *(_BYTE *)(v3 + 48 * result + 504) |= 2u;
        if ( *(int *)(v3 + 48 * result + 504) < 0 )
          KiAbEntryRemoveFromTree(v3 + 48 * result + 488);
        v10 = *(_WORD *)(v9 + 44);
        if ( v10 )
        {
          if ( (v10 & 1) != 0 )
          {
            __dmb(0xBu);
            v15 = (unsigned int *)(v3 + 804);
            do
              v16 = __ldrex(v15);
            while ( __strex(v16 - 1, v15) );
            __dmb(0xBu);
            PsBoostThreadIoEx(v3, 1, 0);
          }
          if ( (*(_WORD *)(v9 + 44) & 0xFFFE) != 0 )
            KiAbThreadUnboostCpuPriority(v3, v9, v8, *(_WORD *)(v9 + 44) & 0xFFFE);
          if ( (dword_682604 & 0x200) != 0 )
            EtwTraceAutoBoostClearFloor(
              v3,
              *(_DWORD *)(v9 + 16) & 0xFFFFFFFC | 0x80000000,
              *(unsigned __int16 *)(v9 + 44));
          *(_WORD *)(v9 + 44) = 0;
        }
        *(_BYTE *)(v9 + 13) &= 0xFEu;
        result = (unsigned __int64)(715827883i64 * (v9 - v3 - 488)) >> 32;
        *(_DWORD *)(v9 + 16) = 0;
        v11 = (v9 - v3 - 488) / 48;
        if ( v19 )
        {
          *(_BYTE *)(v3 + 484) |= 1 << v11;
          v12 = *(_WORD *)(v3 + 310) + 1;
          *(_WORD *)(v3 + 310) = v12;
          if ( v12 || *(_DWORD *)(v3 + 100) == v3 + 100 )
            return result;
          return KiCheckForKernelApcDelivery(result);
        }
        __dmb(0xBu);
        v17 = 1 << v11;
        v18 = (unsigned __int8 *)(v3 + 810);
        do
          result = __ldrex(v18);
        while ( __strex(result | v17, v18) );
        __dmb(0xBu);
      }
    }
  }
  return result;
}
