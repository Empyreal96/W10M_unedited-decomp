// MiDeletePhysmemVad 
 
int __fastcall MiDeletePhysmemVad(int a1)
{
  __int64 v1; // r1
  unsigned int v2; // r10
  unsigned int v3; // r4
  int v4; // r0
  int v5; // r7
  unsigned int v6; // r8
  int v7; // r6
  int v8; // r0
  unsigned __int8 *v9; // r3
  unsigned int v10; // r1
  unsigned int *v12; // r2
  unsigned int v13; // r0
  unsigned int v14; // r7
  int v15; // r5
  int v16; // r0
  unsigned int v17; // r2
  int v18; // r0
  unsigned int *v19; // r4
  unsigned int v20; // r5
  unsigned int v21; // r6
  int v22; // r0
  int v23; // [sp+4h] [bp-D4h]
  int v24; // [sp+Ch] [bp-CCh]
  int v25; // [sp+14h] [bp-C4h]
  _WORD *v26; // [sp+18h] [bp-C0h]
  int v27; // [sp+20h] [bp-B8h] BYREF
  char v28; // [sp+24h] [bp-B4h]
  char v29; // [sp+25h] [bp-B3h]
  int v30; // [sp+28h] [bp-B0h]
  int v31; // [sp+2Ch] [bp-ACh]
  int v32; // [sp+30h] [bp-A8h]
  int v33; // [sp+34h] [bp-A4h]

  v31 = 0;
  v32 = 0;
  v28 = 0;
  v29 = 0;
  v30 = 33;
  v1 = *(_QWORD *)(a1 + 12);
  v33 = 0;
  v2 = (_DWORD)v1 << 12;
  v3 = ((4 * v1) & 0x3FFFFC) - 0x40000000;
  v4 = (HIDWORD(v1) & 0xFFFFF) - 0x10000000;
  v5 = HIDWORD(v1) - v1 + 1;
  v27 = 1;
  v25 = v4;
  do
  {
    v6 = (v3 & 0xFFFFF000) + 4092;
    v23 = v6;
    if ( v6 > 4 * v4 )
    {
      v6 = 4 * v4;
      v23 = 4 * v4;
    }
    v7 = (unsigned __int16)(((int)(v6 - v3) >> 2) + 1);
    v26 = (_WORD *)(2 * ((v2 >> 22) - 534769440));
    v8 = MmPfnDatabase + 24 * (*(_DWORD *)(((v2 >> 20) & 0xFFC) - 1070596096) >> 12);
    v9 = (unsigned __int8 *)(v8 + 15);
    do
      v10 = __ldrex(v9);
    while ( __strex(v10 | 0x80, v9) );
    __dmb(0xBu);
    if ( v10 >> 7 )
      return sub_524BA4();
    *(_DWORD *)(v8 + 12) = *(_DWORD *)(v8 + 12) & 0xC0000000 | (*(_DWORD *)(v8 + 12) - v7) & 0x3FFFFFFF;
    __dmb(0xBu);
    v12 = (unsigned int *)(v8 + 12);
    do
      v13 = __ldrex(v12);
    while ( __strex(v13 & 0x7FFFFFFF, v12) );
    MI_DECREMENT_USED_PTES_BY_HANDLE_CLUSTER(2 * ((v2 >> 22) - 534769440), v7);
    v24 = v5 - v7;
    v14 = 0;
    do
    {
      v15 = *(_DWORD *)v3;
      if ( MI_IS_PFN(*(_DWORD *)v3 >> 12) )
      {
        if ( v3 + 0x40000000 > 0x3FFFFF )
        {
          *(_DWORD *)v3 = 0;
        }
        else
        {
          __dmb(0xBu);
          *(_DWORD *)v3 = 0;
          if ( v3 >= 0xC0300000 && v3 <= 0xC0300FFF )
          {
            v16 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            MiArmWriteConvertedHardwarePde(v16, v16 + 4 * (v3 & 0xFFF), 0);
          }
        }
      }
      else
      {
        v17 = v15 & 0xFFFFFFFC | 0x400;
        if ( v3 + 0x40000000 > 0x3FFFFF )
        {
          *(_DWORD *)v3 = v17;
        }
        else
        {
          __dmb(0xBu);
          *(_DWORD *)v3 = v17;
          if ( v3 + 1070596096 <= 0xFFF )
          {
            v18 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            MiArmWriteConvertedHardwarePde(v18, v18 + 4 * (v3 & 0xFFF), v17);
          }
        }
        v14 = v3;
      }
      MiInsertTbFlushEntry(&v27, v2, 1);
      v3 += 4;
      v2 += 4096;
    }
    while ( v3 <= v6 );
    if ( v14 )
    {
      MiFlushTbList(&v27);
      v19 = (unsigned int *)(v3 - 4 * v7);
      if ( (unsigned int)v19 <= v14 )
      {
        v20 = (unsigned int)(v19 + 267649024);
        do
        {
          v21 = *v19;
          if ( *v19 )
          {
            if ( v20 + 3145728 > 0x3FFFFF )
            {
              *v19 = 0;
            }
            else
            {
              __dmb(0xBu);
              *v19 = 0;
              if ( v20 <= 0xFFF )
              {
                v22 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
                MiArmWriteConvertedHardwarePde(v22, v22 + 4 * ((unsigned __int16)v19 & 0xFFF), 0);
              }
            }
            MiDereferenceIoPages(1, v21 >> 12, 1);
          }
          ++v19;
          v20 += 4;
        }
        while ( (unsigned int)v19 <= v14 );
        v6 = v23;
      }
      v3 = v6 + 4;
    }
    if ( !*v26 )
      MiDeletePageTableHierarchy(&v27, v3 - 4);
    v5 = v24;
    v4 = v25;
  }
  while ( v24 );
  return MiFlushTbList(&v27);
}
