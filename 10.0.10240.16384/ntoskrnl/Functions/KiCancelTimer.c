// KiCancelTimer 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall KiCancelTimer(int a1, int a2)
{
  int v3; // r5
  unsigned int v5; // r2
  unsigned int v7; // r9
  char *v8; // r1
  unsigned int *v9; // r10
  unsigned int v10; // r2
  char *v11; // r3
  _DWORD *v12; // r1 OVERLAPPED
  _DWORD *v13; // r2 OVERLAPPED
  int v14; // r3
  unsigned int v15; // r0
  int v16; // r1
  unsigned __int8 *v17; // r3
  unsigned int v18; // r2
  unsigned int v19; // r1
  unsigned int *v20; // r1
  unsigned int v21; // r0
  int v22; // r3
  unsigned int v23; // r0
  unsigned int v24; // r2
  unsigned int v25; // r1
  int v26; // [sp+8h] [bp-38h] BYREF
  char *v27; // [sp+Ch] [bp-34h]
  int v28[12]; // [sp+10h] [bp-30h] BYREF

  v3 = 0;
  while ( 1 )
  {
    do
      v5 = __ldrex((unsigned __int8 *)a1);
    while ( __strex(v5 | 0x80, (unsigned __int8 *)a1) );
    __dmb(0xBu);
    if ( v5 >> 7 )
    {
      do
      {
        do
        {
          __dmb(0xAu);
          __yield();
        }
        while ( (*(_DWORD *)a1 & 0x80) != 0 );
        do
          v24 = __ldrex((unsigned __int8 *)a1);
        while ( __strex(v24 | 0x80, (unsigned __int8 *)a1) );
        __dmb(0xBu);
      }
      while ( v24 >> 7 );
    }
    if ( (*(_BYTE *)(a1 + 3) & 0xC0) == 0 )
      break;
    v7 = *(unsigned __int8 *)(a1 + 2);
    v8 = (char *)*(&KiProcessorBlock + *(_DWORD *)(a1 + 36)) + 4096;
    v9 = (unsigned int *)&v8[24 * v7 + 256];
    v27 = v8;
    while ( 1 )
    {
      do
        v10 = __ldrex(v9);
      while ( __strex(1u, v9) );
      __dmb(0xBu);
      if ( !v10 )
        break;
      do
      {
        __dmb(0xAu);
        __yield();
      }
      while ( *v9 );
    }
    if ( (*(_BYTE *)(a1 + 3) & 0x80) == 0 )
    {
      v11 = &v8[24 * v7];
      *(_QWORD *)&v12 = *(_QWORD *)(a1 + 24);
      if ( v12[1] != a1 + 24 || *v13 != a1 + 24 )
        __fastfail(3u);
      *v13 = v12;
      v12[1] = v13;
      if ( v13 == v12 )
      {
        *((_DWORD *)v11 + 69) = -1;
        v16 = KiPendingTimerBitmaps[2 * (unsigned __int8)*(v27 - 3044) + 1];
        if ( !KiSerializeTimerExpiration )
          return sub_50C8FC();
        __dmb(0xBu);
        v17 = (unsigned __int8 *)(v16 + 4 * (v7 >> 5) + ((int)(v7 & 0x1F) >> 3));
        do
          v18 = __ldrex(v17);
        while ( __strex(v18 & ~(unsigned __int8)(1 << (v7 & 7)), v17) );
        __dmb(0xBu);
      }
      __dmb(0xBu);
      *v9 = 0;
      v14 = 0x40000000;
      if ( a2 )
        v14 = 1073741952;
      __dmb(0xBu);
      do
        v15 = __ldrex((unsigned int *)a1);
      while ( __strex(v15 & ~v14, (unsigned int *)a1) );
      goto LABEL_19;
    }
    __dmb(0xBu);
    *v9 = 0;
    __dmb(0xBu);
    v20 = (unsigned int *)&v8[4 * (*(_BYTE *)(a1 + 3) & 0x3F)];
    do
      v21 = __ldrex(v20);
    while ( __strex(0, v20) );
    __dmb(0xBu);
    if ( v21 )
    {
      v22 = -16777216;
      if ( a2 )
        v22 = -16777088;
      __dmb(0xBu);
      do
        v23 = __ldrex((unsigned int *)a1);
      while ( __strex(v23 & ~v22, (unsigned int *)a1) );
LABEL_19:
      __dmb(0xBu);
      v3 = 1;
      goto LABEL_6;
    }
    __dmb(0xBu);
    do
      v25 = __ldrex((unsigned int *)a1);
    while ( __strex(v25 & 0xFFFFFF7F, (unsigned int *)a1) );
    while ( (*(_BYTE *)(a1 + 3) & 0x80) != 0 )
    {
      __dmb(0xAu);
      __yield();
    }
  }
  if ( a2 )
  {
    __dmb(0xBu);
    do
      v19 = __ldrex((unsigned int *)a1);
    while ( __strex(v19 & 0xFFFFFF7F, (unsigned int *)a1) );
  }
LABEL_6:
  if ( (dword_682608 & 0x20000) != 0 )
  {
    if ( v3 )
    {
      v28[0] = (int)&v26;
      v28[1] = 0;
      v28[2] = 4;
      v28[3] = 0;
      v26 = a1;
      EtwTraceKernelEvent(v28, 1, 1073872896, 3925, 1538);
    }
  }
  return v3;
}
