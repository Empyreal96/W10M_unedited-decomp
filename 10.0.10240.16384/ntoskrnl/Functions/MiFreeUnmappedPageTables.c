// MiFreeUnmappedPageTables 
 
int __fastcall MiFreeUnmappedPageTables(int result, _DWORD *a2)
{
  int v2; // r4
  int v3; // r7
  int v5; // r5
  unsigned __int8 *v6; // r3
  unsigned int v7; // r1
  int v8; // r2
  int v9; // r0
  unsigned int *v10; // r2
  unsigned int v11; // r0
  unsigned __int8 *v12; // r3
  unsigned int v13; // r1
  int v14; // r2
  unsigned int *v15; // r2
  unsigned int v16; // r0
  unsigned __int8 *v17; // r1
  int v18; // r3
  unsigned int v19; // r2
  int v20; // [sp+8h] [bp-28h]
  int v21; // [sp+Ch] [bp-24h]

  v2 = result;
  v3 = 0;
  if ( result )
  {
    while ( 1 )
    {
      v21 = *(_DWORD *)v2;
      v5 = MmPfnDatabase + 24 * (*(_DWORD *)(v2 + 20) & 0xFFFFF);
      v20 = KfRaiseIrql(2);
      v6 = (unsigned __int8 *)(v2 + 15);
      do
        v7 = __ldrex(v6);
      while ( __strex(v7 | 0x80, v6) );
      __dmb(0xBu);
      if ( v7 >> 7 )
        break;
      v8 = *(_DWORD *)(v2 + 12);
      *(_BYTE *)(v2 + 18) = *(_BYTE *)(v2 + 18) & 0xF8 | 6;
      *(_DWORD *)(v2 + 12) = v8 & 0xC0000000 | ((v8 & 0x3FFFFFFF) - 1) & 0x3FFFFFFF;
      if ( (v8 & 0x3FFFFFFF) == 1 )
        v9 = MiPfnShareCountIsZero(v2, 0);
      else
        v9 = 2;
      if ( v9 == 3 )
        ++a2[1];
      __dmb(0xBu);
      v10 = (unsigned int *)(v2 + 12);
      do
        v11 = __ldrex(v10);
      while ( __strex(v11 & 0x7FFFFFFF, v10) );
      v12 = (unsigned __int8 *)(v5 + 15);
      do
        v13 = __ldrex(v12);
      while ( __strex(v13 | 0x80, v12) );
      __dmb(0xBu);
      if ( v13 >> 7 )
      {
        v17 = (unsigned __int8 *)(v5 + 15);
        do
        {
          do
          {
            __dmb(0xAu);
            __yield();
            v18 = *(_DWORD *)(v5 + 12);
            __dmb(0xBu);
          }
          while ( (v18 & 0x80000000) != 0 );
          do
            v19 = __ldrex(v17);
          while ( __strex(v19 | 0x80, v17) );
          __dmb(0xBu);
        }
        while ( v19 >> 7 );
      }
      if ( (*(_BYTE *)(v5 + 18) & 7) != 6 )
        KeBugCheckEx(78, 153, (v5 - MmPfnDatabase) / 24);
      v14 = *(_DWORD *)(v5 + 12);
      *(_DWORD *)(v5 + 12) = v14 & 0xC0000000 | ((v14 & 0x3FFFFFFF) - 1) & 0x3FFFFFFF;
      if ( (v14 & 0x3FFFFFFF) == 1 )
        MiPfnShareCountIsZero(v5, 0);
      __dmb(0xBu);
      v15 = (unsigned int *)(v5 + 12);
      do
        v16 = __ldrex(v15);
      while ( __strex(v16 & 0x7FFFFFFF, v15) );
      result = KfLowerIrql(v20);
      ++v3;
      v2 = v21;
      if ( !v21 )
        goto LABEL_21;
    }
    result = sub_53D9B0();
  }
  else
  {
LABEL_21:
    a2[3] += v3;
    *a2 += v3;
  }
  return result;
}
