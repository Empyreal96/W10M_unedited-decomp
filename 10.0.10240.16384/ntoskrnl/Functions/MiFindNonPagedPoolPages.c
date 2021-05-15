// MiFindNonPagedPoolPages 
 
int __fastcall MiFindNonPagedPoolPages(int a1, int a2)
{
  int v2; // r8
  int v3; // r7
  int v6; // r2
  int v7; // r1
  _WORD *v8; // r10
  int v9; // r3
  int v10; // r0
  int v11; // r4
  unsigned int *v12; // r6
  int v13; // r1
  unsigned int v14; // r5
  unsigned int v15; // r0
  unsigned int v16; // r1
  int v17; // r6
  int v18; // r4
  int v19; // r5
  unsigned __int8 *v20; // r3
  unsigned int v21; // r1
  unsigned __int8 *v22; // r1
  int v23; // r3
  unsigned int v24; // r2
  int v25; // r3
  unsigned int *v26; // r2
  unsigned int v27; // r0
  _WORD *v28; // [sp+0h] [bp-50h] BYREF
  unsigned __int16 v29; // [sp+4h] [bp-4Ch]
  unsigned __int16 v30; // [sp+6h] [bp-4Ah]
  int v31; // [sp+8h] [bp-48h]
  int v32[3]; // [sp+20h] [bp-30h] BYREF
  int v33; // [sp+2Ch] [bp-24h]

  v32[0] = 0;
  v32[1] = 0;
  v32[2] = 0;
  v33 = 0;
  v2 = 0;
  v31 = 0;
  v3 = a2;
  if ( *(_DWORD *)(dword_6337E8 + 176 * a1 + 124) )
    return sub_514770();
  v33 = a2;
  if ( !MiObtainNonPagedPoolCharges(a2) )
    return 0;
  MI_INITIALIZE_COLOR_BASE(0, a1 + 1, &v28);
  if ( !v3 )
    return v2;
  v6 = v29;
  v7 = v30;
  v8 = v28;
  while ( 1 )
  {
    v9 = (unsigned __int16)(*v8 + 1);
    *v8 = v9;
    v10 = MiGetPage(MiSystemPartition, v7 | v9 & v6, 12);
    if ( v10 == -1 )
      break;
    v11 = MmPfnDatabase + 24 * v10;
    if ( (*(_BYTE *)(v11 + 18) & 0xC0) != 64 )
      MiChangePageAttribute(MmPfnDatabase + 24 * v10, 1, 0);
    v12 = (unsigned int *)(v11 + 12);
    v13 = *(_DWORD *)(v11 + 12);
    do
      v14 = __ldrex(v12);
    while ( v14 == v13 && __strex(v13 & 0xFF0FFFFF, v12) );
    if ( v13 != v14 )
    {
      do
      {
        v15 = v14;
        do
          v16 = __ldrex(v12);
        while ( v16 == v14 && __strex(v14 & 0xFF0FFFFF, v12) );
        v14 = v16;
      }
      while ( v15 != v16 );
    }
    *(_DWORD *)v11 = v2;
    v6 = v29;
    v7 = v30;
    --v33;
    v2 = v11;
    if ( !--v3 )
      return v2;
  }
  ++dword_632AC4;
  if ( v2 )
  {
    v17 = v31;
    v18 = v2;
    do
    {
      if ( v18 == v17 )
        break;
      v19 = KfRaiseIrql(2);
      v20 = (unsigned __int8 *)(v18 + 15);
      do
        v21 = __ldrex(v20);
      while ( __strex(v21 | 0x80, v20) );
      __dmb(0xBu);
      if ( v21 >> 7 )
      {
        v22 = (unsigned __int8 *)(v18 + 15);
        do
        {
          do
          {
            __dmb(0xAu);
            __yield();
            v23 = *(_DWORD *)(v18 + 12);
            __dmb(0xBu);
          }
          while ( v23 < 0 );
          do
            v24 = __ldrex(v22);
          while ( __strex(v24 | 0x80, v22) );
          __dmb(0xBu);
        }
        while ( v24 >> 7 );
      }
      v25 = *(_DWORD *)(v18 + 12);
      *(_WORD *)(v18 + 16) = 1;
      *(_DWORD *)(v18 + 12) = v25 & 0xC0000000 | 1;
      __dmb(0xBu);
      v26 = (unsigned int *)(v18 + 12);
      do
        v27 = __ldrex(v26);
      while ( __strex(v27 & 0x7FFFFFFF, v26) );
      KfLowerIrql(v19);
      v18 = *(_DWORD *)v18;
    }
    while ( v18 );
    MiReturnPhysicalPoolPages(v2);
  }
  v32[0] = v33;
  MiReturnNonPagedPoolCharges(v32);
  return 0;
}
