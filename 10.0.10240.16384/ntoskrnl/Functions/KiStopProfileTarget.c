// KiStopProfileTarget 
 
int __fastcall KiStopProfileTarget(int *a1)
{
  int v2; // r5
  int v3; // r7
  unsigned int *v4; // r2
  unsigned int v5; // r1
  unsigned int v6; // r1
  int v7; // r2
  int v8; // r3
  int v9; // r6
  _DWORD *v10; // r1
  _DWORD *v11; // r2
  _DWORD *v12; // r1
  int v13; // r3
  unsigned int v14; // r0
  _DWORD *v15; // r6
  unsigned int v16; // r2
  int v17; // r3
  __int64 v18; // kr00_8
  unsigned int *v19; // r1
  unsigned int v20; // r2
  unsigned int v21; // r1

  v2 = *a1;
  v3 = KfRaiseIrql((unsigned __int8)KiProfileIrql);
  __dmb(0xBu);
  v4 = (unsigned int *)(a1 + 1);
  do
  {
    v5 = __ldrex(v4);
    v6 = v5 - 1;
  }
  while ( __strex(v6, v4) );
  __dmb(0xBu);
  if ( !v6 && *(_BYTE *)(v2 + 50) )
  {
    v7 = v2 + 4;
    *(_BYTE *)(v2 + 50) = 0;
    v8 = *(_DWORD *)(v2 + 4);
    if ( v8 != v2 + 4 )
    {
      v9 = *(_DWORD *)(v2 + 4);
      v10 = *(_DWORD **)(v2 + 8);
      if ( *(_DWORD *)(v8 + 4) != v7 || *v10 != v7 )
        __fastfail(3u);
      *v10 = v9;
      *(_DWORD *)(v9 + 4) = v10;
    }
    v11 = (_DWORD *)KiProfileSourceListHead;
    do
    {
      v12 = v11;
      v13 = v11[2];
      v11 = (_DWORD *)*v11;
    }
    while ( v13 != *(__int16 *)(v2 + 48) );
    v14 = *(_DWORD *)(v2 + 44);
    v15 = v12 + 6;
    while ( v14 )
    {
      v16 = __clz(__rbit(v14));
      v14 &= ~(1 << v16);
      if ( !--v15[v16] )
        a1[5] |= 1 << v16;
    }
    __dmb(0xFu);
    v17 = v12[5] & ~a1[5];
    if ( v12 != (_DWORD *)-12 )
    {
      *((_WORD *)v12 + 7) = 1;
      *((_WORD *)v12 + 6) = 1;
      v12[4] = 0;
      v12[5] = v17;
    }
    if ( !v12[5] )
    {
      v18 = *(_QWORD *)v12;
      if ( *(_DWORD **)(*v12 + 4) != v12 || *(_DWORD **)HIDWORD(v18) != v12 )
        __fastfail(3u);
      *(_DWORD *)HIDWORD(v18) = v18;
      *(_DWORD *)(v18 + 4) = HIDWORD(v18);
      a1[6] = (int)v12;
      if ( *(_WORD *)(v2 + 48) == 1 )
        KiProfileAlignmentFixup = 0;
    }
    *((_BYTE *)a1 + 28) = 1;
  }
  __dmb(0xBu);
  v19 = (unsigned int *)(a1 + 2);
  do
    v20 = __ldrex(v19);
  while ( __strex(v20 - 1, v19) );
  __dmb(0xBu);
  while ( (int)*v19 > 0 )
  {
    __dmb(0xAu);
    __yield();
  }
  v21 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  if ( (a1[*(unsigned __int8 *)(v21 + 2460) + 5] & *(_DWORD *)(v21 + 2456)) != 0 )
    HalStopProfileInterrupt(*(__int16 *)(v2 + 48));
  return KfLowerIrql(v3);
}
