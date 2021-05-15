// MiDeletePageTablesForPhysicalRange 
 
unsigned int __fastcall MiDeletePageTablesForPhysicalRange(int a1)
{
  unsigned int v1; // r7
  int v2; // r1
  unsigned int v3; // r5
  int v4; // r8
  unsigned int *i; // r10
  unsigned int v6; // r6
  int v7; // r3
  unsigned int v8; // t1
  int v9; // r0
  unsigned __int8 *v10; // r3
  unsigned int v11; // r1
  unsigned __int8 *v12; // r1
  int v13; // r3
  unsigned int v14; // r2
  unsigned int *v15; // r2
  unsigned int v16; // r0
  int v18; // [sp+0h] [bp-B8h] BYREF
  char v19; // [sp+4h] [bp-B4h]
  char v20; // [sp+5h] [bp-B3h]
  int v21; // [sp+8h] [bp-B0h]
  int v22; // [sp+Ch] [bp-ACh]
  int v23; // [sp+10h] [bp-A8h]
  int v24; // [sp+14h] [bp-A4h]

  v22 = 0;
  v23 = 0;
  v19 = 0;
  v20 = 0;
  v21 = 33;
  v24 = 0;
  v1 = *(_DWORD *)(a1 + 12) << 12;
  v18 = 1;
  v2 = 4194300;
  v3 = ((v1 >> 10) & 0x3FFFFC) - 0x40000000;
  v4 = (*(_DWORD *)(a1 + 16) & 0xFFFFF) - 0xFFFFFFF;
  for ( i = (unsigned int *)(((v3 >> 10) & 0x3FFFFC) - 0x40000000); v3 < 4 * v4; v1 += v6 << 12 )
  {
    v6 = 1024 - ((v3 >> 2) & 0x3FF);
    v7 = 4 * v4 - v3;
    if ( v6 > v7 >> 2 )
      v6 = v7 >> 2;
    v8 = *i++;
    v9 = MmPfnDatabase + 24 * (v8 >> 12);
    v10 = (unsigned __int8 *)(v9 + 15);
    do
      v11 = __ldrex(v10);
    while ( __strex(v11 | 0x80, v10) );
    __dmb(0xBu);
    if ( v11 >> 7 )
    {
      v12 = (unsigned __int8 *)(v9 + 15);
      do
      {
        do
        {
          __dmb(0xAu);
          __yield();
          v13 = *(_DWORD *)(v9 + 12);
          __dmb(0xBu);
        }
        while ( v13 < 0 );
        do
          v14 = __ldrex(v12);
        while ( __strex(v14 | 0x80, v12) );
        __dmb(0xBu);
      }
      while ( v14 >> 7 );
    }
    *(_DWORD *)(v9 + 12) = *(_DWORD *)(v9 + 12) & 0xC0000000 | (*(_DWORD *)(v9 + 12) - 1) & 0x3FFFFFFF;
    __dmb(0xBu);
    v15 = (unsigned int *)(v9 + 12);
    do
      v16 = __ldrex(v15);
    while ( __strex(v16 & 0x7FFFFFFF, v15) );
    v2 = 1;
    MI_DECREMENT_USED_PTES_BY_HANDLE_CLUSTER((_WORD *)(2 * ((v1 >> 22) - 534769440)), 1);
    if ( !*(_WORD *)(2 * ((v1 >> 22) - 534769440)) )
      MiDeletePageTableHierarchy(&v18, v3);
    v3 += 4 * v6;
  }
  return MiFlushTbList((unsigned int)&v18, v2);
}
