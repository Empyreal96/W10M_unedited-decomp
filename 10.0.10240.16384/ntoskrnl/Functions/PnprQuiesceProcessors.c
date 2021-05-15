// PnprQuiesceProcessors 
 
_BYTE *PnprQuiesceProcessors()
{
  int v0; // r4
  int v1; // r6
  unsigned int v2; // r2
  int v3; // r3
  int v4; // r3
  int v5; // r2
  int v6; // r2
  _BYTE *result; // r0
  int v8; // r0
  int v9; // r3
  unsigned int *v10; // r2
  unsigned int v11; // r1
  int v12; // r3
  unsigned int *v13; // r2
  unsigned int v14; // r1
  int v15; // r3
  int v16; // r2
  unsigned int v17; // r0
  _DWORD *v18; // r4
  int v19; // r2
  int v20; // r3
  int v21; // r3
  int v22; // r4
  int v23; // r0
  int v24; // r2
  char v25[4]; // [sp+0h] [bp-60h] BYREF
  unsigned int v26; // [sp+4h] [bp-5Ch]
  int v27; // [sp+8h] [bp-58h]
  int v28; // [sp+Ch] [bp-54h]
  int v29; // [sp+10h] [bp-50h]
  char v30[2]; // [sp+18h] [bp-48h] BYREF
  __int16 v31; // [sp+1Ah] [bp-46h]
  int v32; // [sp+38h] [bp-28h]
  int v33; // [sp+3Ch] [bp-24h]
  int v34; // [sp+40h] [bp-20h]
  _BYTE v35[28]; // [sp+44h] [bp-1Ch] BYREF

  v0 = *(_DWORD *)(PnprContext + 124);
  KfRaiseIrql(2);
  KeInitializeDpc((int)v30, (int)PnprQuiesceProcessorDpc, (int)v25);
  v30[1] = 2;
  v32 = *(_DWORD *)&KeActiveProcessors;
  v33 = dword_681D74;
  v34 = dword_681D78[0];
  __dmb(0xBu);
  v1 = v34 & ~(1 << *(_DWORD *)(PnprContext + 128));
  v34 = v1;
  while ( v1 )
  {
    v2 = __clz(__rbit(v1));
    v1 &= ~(1 << v2);
    v26 = v2;
    v31 = v2 + 32;
    __dmb(0xBu);
    v25[0] = 0;
    KeInsertQueueDpc((int)v30);
    while ( 1 )
    {
      v3 = (unsigned __int8)v25[0];
      __dmb(0xBu);
      if ( v3 )
        break;
      __dmb(0xAu);
      __yield();
    }
  }
  if ( (*(_DWORD *)(PnprContext + 48) & 0x20) != 0 && ((int (__cdecl *)())off_617A14)() < 0 )
  {
    v4 = PnprContext;
    v5 = *(_DWORD *)(PnprContext + 608);
    if ( !v5 )
      v5 = 2428;
  }
  else
  {
    ((void (__cdecl *)())off_6179EC)();
    KeSuspendClockTimerSafe();
    v8 = PnprGetMillisecondCounter(0);
    v9 = PnprContext;
    *(_DWORD *)(PnprContext + 616) = v8;
    *(_DWORD *)(v9 + 620) = 0;
    __dmb(0xBu);
    v10 = (unsigned int *)(PnprContext + 132);
    do
      v11 = __ldrex(v10);
    while ( __strex(v11 + 1, v10) );
    __dmb(0xBu);
    while ( 1 )
    {
      v12 = *(_DWORD *)(PnprContext + 132);
      __dmb(0xBu);
      if ( v12 >= v0 )
        break;
      __dmb(0xAu);
      __yield();
    }
    if ( (*(_DWORD *)(PnprContext + 48) & 0x20) != 0 )
    {
      __dmb(0xBu);
      v13 = (unsigned int *)(PnprContext + 140);
      do
        v14 = __ldrex(v13);
      while ( __strex(v14 + 1, v13) );
      __dmb(0xBu);
      while ( 1 )
      {
        v15 = *(_DWORD *)(PnprContext + 140);
        __dmb(0xBu);
        if ( v15 >= v0 )
          break;
        __dmb(0xAu);
        __yield();
      }
      (*(void (__fastcall **)(_DWORD, int))(PnprContext + 604))(*(_DWORD *)(PnprContext + 552), 1);
      *(_DWORD *)(PnprContext + 624) = PnprGetMillisecondCounter(0);
    }
    v27 = *(_DWORD *)&KeActiveProcessors;
    v28 = dword_681D74;
    v29 = dword_681D78[0];
    __dmb(0xBu);
    v16 = PnprContext;
    v17 = 0;
    v32 = v27;
    v18 = *(_DWORD **)(PnprContext + 16);
    v33 = v28;
    v34 = v29;
    if ( v18[1] )
    {
      do
      {
        v19 = dword_681D78[v17];
        __dmb(0xBu);
        v20 = v19 & ~*(_DWORD *)(*v18 + 4 * v17);
        __dmb(0xBu);
        dword_681D78[v17++] = v20;
      }
      while ( v17 < v18[1] );
      v16 = PnprContext;
    }
    __dmb(0xBu);
    *(_DWORD *)(v16 + 152) = 0;
    v21 = PnprContext;
    __dmb(0xBu);
    *(_DWORD *)(v21 + 148) = 1;
    if ( !*(_DWORD *)(*(_DWORD *)(PnprContext + 16) + 12)
      || (*(_DWORD *)(PnprContext + 628) = PnprGetMillisecondCounter(0),
          v22 = ((int (__cdecl *)())off_6179EC)(),
          v23 = PnprGetMillisecondCounter(0),
          v4 = PnprContext,
          *(_DWORD *)(PnprContext + 632) = v23,
          v22 >= 0) )
    {
      __dmb(0xBu);
      result = v35;
      *(_DWORD *)&KeActiveProcessors = v32;
      dword_681D74 = v33;
      dword_681D78[0] = v34;
      while ( 1 )
      {
        v24 = *(_DWORD *)(PnprContext + 152);
        __dmb(0xBu);
        if ( v24 >= *(_DWORD *)(*(_DWORD *)(PnprContext + 16) + 12) )
          break;
        __dmb(0xAu);
        __yield();
      }
      return result;
    }
    v5 = *(_DWORD *)(v4 + 608);
    if ( !v5 )
      v5 = 2513;
  }
  *(_DWORD *)(v4 + 608) = v5;
  v6 = *(_DWORD *)(v4 + 612);
  if ( !v6 )
    v6 = 1;
  *(_DWORD *)(v4 + 612) = v6;
  __dmb(0xBu);
  result = v35;
  *(_DWORD *)&KeActiveProcessors = v32;
  dword_681D74 = v33;
  dword_681D78[0] = v34;
  return result;
}
