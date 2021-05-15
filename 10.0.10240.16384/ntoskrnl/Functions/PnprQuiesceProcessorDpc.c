// PnprQuiesceProcessorDpc 
 
int __fastcall PnprQuiesceProcessorDpc(int a1, _BYTE *a2, int a3, unsigned int a4)
{
  int v6; // r7
  unsigned int *v7; // r0
  unsigned int v8; // r4
  int v9; // r3
  _DWORD *v10; // r2
  unsigned int *v11; // r2
  unsigned int v12; // r1
  int v13; // r3
  int v14; // r6
  char v15; // r3
  unsigned int v16; // r1
  int v17; // r4
  _DWORD *v18; // r3
  int i; // r3
  int v20; // r4
  unsigned int *v21; // r2
  unsigned int v22; // r1
  int j; // r3
  int v24; // r3
  int v25; // r2
  int v26; // r2
  unsigned int *v27; // r2
  unsigned int v28; // r1
  int k; // r3
  int result; // r0
  unsigned int *v31; // r2
  unsigned int v32; // r1
  int v33; // r3
  int l; // r3
  unsigned int *v35; // r2
  unsigned int v36; // r1
  int v37; // r3
  int v38; // [sp+4h] [bp-2Ch] BYREF
  int v39; // [sp+8h] [bp-28h] BYREF
  int v40; // [sp+Ch] [bp-24h]

  __dmb(0xBu);
  *a2 = 1;
  v6 = 1;
  v39 = 0;
  __dmb(0xBu);
  v7 = (unsigned int *)(PnprContext + 132);
  do
    v8 = __ldrex(v7);
  while ( __strex(v8 + 1, v7) );
  __dmb(0xBu);
  while ( 1 )
  {
    v9 = *(_DWORD *)(PnprContext + 132);
    __dmb(0xBu);
    if ( v9 >= a3 )
      break;
    __dmb(0xAu);
    __yield();
  }
  v10 = (_DWORD *)PnprContext;
  if ( (*(_DWORD *)(PnprContext + 48) & 0x20) != 0 )
  {
    if ( (__get_CPSR() & 0x80) != 0 )
    {
      v6 = 0;
    }
    else
    {
      __disable_irq();
      v6 = 1;
    }
    __dmb(0xBu);
    v11 = (unsigned int *)(PnprContext + 140);
    do
      v12 = __ldrex(v11);
    while ( __strex(v12 + 1, v11) );
    __dmb(0xBu);
    while ( 1 )
    {
      v13 = *(_DWORD *)(PnprContext + 140);
      __dmb(0xBu);
      if ( v13 >= a3 )
        break;
      __dmb(0xAu);
      __yield();
    }
    v10 = (_DWORD *)PnprContext;
  }
  if ( a4 )
  {
    if ( a4 < 0x20 && (v16 = KiProcessorIndexToNumberMappingTable[a4]) != 0 )
    {
      v14 = (unsigned __int16)(v16 >> 6);
      v15 = v16 & 0x3F;
    }
    else
    {
      v15 = 0;
      v14 = 0;
    }
  }
  else
  {
    v14 = 0;
    v15 = 0;
  }
  v17 = 1 << v15;
  v18 = (_DWORD *)v10[4];
  v40 = v17;
  if ( (*(_DWORD *)(*v18 + 4 * v14) & v17) != 0 )
  {
    for ( i = v10[37]; ; i = *(_DWORD *)(PnprContext + 148) )
    {
      __dmb(0xBu);
      if ( i >= 1 )
        break;
      __dmb(0xAu);
      __yield();
    }
    KeSuspendClockTimerSafe();
    HalGetProcessorIdByNtNumber(a4, &v38);
    v20 = PnprContext;
    if ( (*(_DWORD *)(PnprContext + 564) & 2) != 0 )
    {
      (*(void (__fastcall **)(_DWORD, int, int))(PnprContext + 584))(*(_DWORD *)(PnprContext + 552), v38, 1);
      v20 = PnprContext;
    }
    if ( (*(_DWORD *)(v20 + 48) & 0x20) != 0 )
      ((void (__fastcall *)(int, _DWORD *))off_617A1C)(*(_DWORD *)(v20 + 548), &v39);
    ((void (__cdecl *)())off_6179E8)();
    if ( (*(_DWORD *)(PnprContext + 564) & 2) != 0 )
      (*(void (__fastcall **)(_DWORD, int, _DWORD))(PnprContext + 584))(*(_DWORD *)(PnprContext + 552), v38, 0);
    KeResumeClockTimerSafe();
    if ( (*(_DWORD *)(PnprContext + 48) & 0x20) != 0 && v6 )
      __enable_irq();
    __dmb(0xBu);
    v21 = (unsigned int *)(PnprContext + 152);
    do
      v22 = __ldrex(v21);
    while ( __strex(v22 + 1, v21) );
    __dmb(0xBu);
    v10 = (_DWORD *)PnprContext;
    v17 = v40;
  }
  if ( *(_DWORD *)(v10[5] + 4) && (v10[12] & 8) == 0 )
  {
    for ( j = v10[37]; ; j = *(_DWORD *)(PnprContext + 148) )
    {
      __dmb(0xBu);
      if ( j >= 2 )
        break;
      __dmb(0xAu);
      __yield();
    }
    if ( PnprMirrorMarkedPages() < 0 )
    {
      v24 = PnprContext;
      v25 = *(_DWORD *)(PnprContext + 608);
      if ( !v25 )
        v25 = 2239;
      *(_DWORD *)(PnprContext + 608) = v25;
      v26 = *(_DWORD *)(v24 + 612);
      if ( !v26 )
        v26 = 1;
      *(_DWORD *)(v24 + 612) = v26;
    }
    __dmb(0xBu);
    v27 = (unsigned int *)(PnprContext + 152);
    do
      v28 = __ldrex(v27);
    while ( __strex(v28 + 1, v27) );
    __dmb(0xBu);
    v10 = (_DWORD *)PnprContext;
  }
  for ( k = v10[37]; ; k = *(_DWORD *)(PnprContext + 148) )
  {
    __dmb(0xBu);
    if ( k >= 4 )
      break;
    __dmb(0xAu);
    __yield();
  }
  result = PnprGetStackLimits(
             (int **)(PnprContext + 4 * (a4 + 40)),
             (unsigned int *)(PnprContext + 4 * (a4 + 72)),
             PnprContext,
             a4 + 40);
  __dmb(0xBu);
  v31 = (unsigned int *)(PnprContext + 152);
  do
    v32 = __ldrex(v31);
  while ( __strex(v32 + 1, v31) );
  __dmb(0xBu);
  while ( 1 )
  {
    v33 = *(_DWORD *)(PnprContext + 148);
    __dmb(0xBu);
    if ( v33 >= 5 )
      break;
    __dmb(0xAu);
    __yield();
  }
  if ( (*(_DWORD *)(PnprContext + 48) & 0x20) != 0 )
  {
    for ( l = *(_DWORD *)(PnprContext + 148); ; l = *(_DWORD *)(PnprContext + 148) )
    {
      __dmb(0xBu);
      if ( l >= 6 )
        break;
      __dmb(0xAu);
      __yield();
    }
    if ( (*(_DWORD *)(**(_DWORD **)(PnprContext + 16) + 4 * v14) & v17) != 0 )
    {
      result = ((int (__cdecl *)())off_617A20)();
    }
    else if ( v6 )
    {
      __enable_irq();
    }
  }
  __dmb(0xBu);
  v35 = (unsigned int *)(PnprContext + 136);
  do
    v36 = __ldrex(v35);
  while ( __strex(v36 + 1, v35) );
  __dmb(0xBu);
  while ( 1 )
  {
    v37 = *(_DWORD *)(PnprContext + 136);
    __dmb(0xBu);
    if ( v37 >= a3 )
      break;
    __dmb(0xAu);
    __yield();
  }
  return result;
}
