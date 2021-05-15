// KiSetSystemTimeDpc 
 
int __fastcall KiSetSystemTimeDpc(int a1, int a2, unsigned int *a3, unsigned int *a4)
{
  unsigned int v7; // r4
  unsigned int v8; // r4
  unsigned int v9; // r1
  int v11; // r0
  int v12; // r8
  char *v13; // r9
  _QWORD *v14; // r4
  __int64 v15; // r0
  _DWORD *v16; // r2
  int v17; // r3
  __int64 v18; // kr00_8
  __int64 v19; // kr08_8
  bool v20; // cf
  int v21; // r3
  int v22; // r2
  unsigned int v23; // r2
  unsigned int v24; // r2
  unsigned int v25; // r1
  int v26; // r3
  unsigned int v27; // r2
  unsigned int v28; // r2
  unsigned int v29; // r1
  int v30; // r3
  unsigned int v31; // r2
  int v32; // [sp+0h] [bp-28h]

  v32 = a2;
  __dmb(0xBu);
  do
  {
    v7 = __ldrex(a4);
    v8 = v7 - 1;
  }
  while ( __strex(v8, a4) );
  __dmb(0xBu);
  v9 = ~v8 & 0x80000000;
  if ( (v8 & 0x7FFFFFFF) != 0 )
    return sub_5197E4(v8 & 0x7FFFFFFF, v9);
  v11 = a4[1] | v9;
  __dmb(0xBu);
  *a4 = v11;
  v12 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
  if ( KiSerializeTimerExpiration )
  {
    if ( *(_BYTE *)(v12 + 17) )
      v13 = (char *)KiProcessorBlock + 4096;
    else
      v13 = 0;
  }
  else
  {
    v13 = (char *)(v12 + 4096);
  }
  if ( *(_BYTE *)(v12 + 17) )
  {
    v14 = *(_QWORD **)(a2 + 12);
    LODWORD(v15) = RtlGetSystemTimePrecise();
    *v14 = v15;
    v16 = *(_DWORD **)(a2 + 8);
    *(_DWORD *)(a2 + 16) = *v16;
    v17 = v16[1];
    v18 = *(_QWORD *)(a2 + 12);
    *(_DWORD *)(a2 + 20) = v17;
    LODWORD(v15) = v17;
    v19 = *(_QWORD *)v18;
    v20 = HIDWORD(v18) >= *(_DWORD *)v18;
    *(_DWORD *)(a2 + 16) = HIDWORD(v18) - *(_DWORD *)v18;
    v21 = *(_DWORD *)(a2 + 4);
    v22 = v15 - (HIDWORD(v19) + !v20);
    *(_DWORD *)(a2 + 20) = v22;
    if ( (v21 & 1) != 0 )
    {
      if ( KeAdjustInterruptTime(*(_DWORD *)(a2 + 16), *(_DWORD *)(a2 + 20), (v21 & 2) != 0) )
      {
        *(_BYTE *)a2 = 1;
        *(_QWORD *)(a2 + 16) = -*(_QWORD *)(a2 + 16);
      }
    }
    else
    {
      KiUpdateSystemTime(*(_DWORD *)(a2 + 16), v22, 0);
    }
  }
  __dmb(0xBu);
  do
  {
    v23 = __ldrex(a4);
    v24 = v23 - 1;
  }
  while ( __strex(v24, a4) );
  __dmb(0xBu);
  v25 = ~v24 & 0x80000000;
  if ( (v24 & 0x7FFFFFFF) != 0 )
  {
    while ( (*a4 & 0x80000000) != v25 )
    {
      __dmb(0xAu);
      __yield();
    }
    __dmb(0xBu);
  }
  else
  {
    v26 = a4[1] | v25;
    __dmb(0xBu);
    *a4 = v26;
  }
  if ( *(_QWORD *)(a2 + 16) )
  {
    if ( v13 )
      KiAdjustTimerDueTimes(v12, v13, a2, *(_DWORD *)(a2 + 20) | *(_DWORD *)(a2 + 16), v32);
    __dmb(0xBu);
    do
    {
      v27 = __ldrex(a4);
      v28 = v27 - 1;
    }
    while ( __strex(v28, a4) );
    __dmb(0xBu);
    v29 = ~v28 & 0x80000000;
    if ( (v28 & 0x7FFFFFFF) != 0 )
    {
      while ( (*a4 & 0x80000000) != v29 )
      {
        __dmb(0xAu);
        __yield();
      }
      __dmb(0xBu);
    }
    else
    {
      v30 = a4[1] | v29;
      __dmb(0xBu);
      *a4 = v30;
    }
  }
  __dmb(0xBu);
  do
    v31 = __ldrex(a3);
  while ( __strex(v31 - 1, a3) );
  __dmb(0xBu);
  return KiExitDispatcher(v12, 0, 1, 0, 2u);
}
