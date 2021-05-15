// KeRemoveQueueDpcEx 
 
int __fastcall KeRemoveQueueDpcEx(int a1, int a2)
{
  int v3; // r5
  unsigned int v5; // r1
  int v6; // r0
  __int16 *v7; // r2
  int v8; // r1
  unsigned int v9; // r0
  unsigned int v10; // r2
  int v11; // r0
  int v12; // r2
  int v13; // lr
  unsigned int *v14; // r0
  int v15; // r3
  unsigned int v16; // r2
  int v17; // r3
  int v18; // [sp+0h] [bp-80h]
  int v19; // [sp+4h] [bp-7Ch]
  int v20; // [sp+8h] [bp-78h]
  int v21; // [sp+10h] [bp-70h]
  char v22[16]; // [sp+40h] [bp-40h] BYREF
  __int16 v23[4]; // [sp+50h] [bp-30h] BYREF
  int v24; // [sp+58h] [bp-28h]

  if ( (__get_CPSR() & 0x80) != 0 )
  {
    v3 = 0;
  }
  else
  {
    __disable_irq();
    v3 = 1;
  }
  if ( *(_DWORD *)(a1 + 28) )
    return sub_51E950(0x10000, 1680, 1704);
  if ( v3 )
    __enable_irq();
  if ( !a2 )
    return 0;
  if ( !*(_DWORD *)(a1 + 8) )
    return 0;
  KiGetDeepIdleProcessors((int)v22, (int)v23);
  v5 = 0;
  if ( v23[0] )
  {
    v6 = *(_DWORD *)(a1 + 8);
    v7 = v23;
    do
    {
      ++v5;
      *((_DWORD *)v7 + 2) &= v6;
      v7 += 2;
    }
    while ( v5 < (unsigned __int16)v23[0] );
  }
  v8 = v24 & ~*(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x998);
  v9 = v8;
LABEL_15:
  v24 = v8;
  v18 = v8;
  while ( v9 )
  {
    v10 = __clz(__rbit(v9));
    v11 = v9 & ~(1 << v10);
    v12 = (int)*(&KiProcessorBlock + v10);
    v19 = v11;
    v20 = v12;
    if ( *(_BYTE *)a1 == 26 && *(_BYTE *)(v12 + 1752) )
      v13 = v12 + 1704;
    else
      v13 = v12 + 1680;
    __dmb(0xFu);
    v14 = (unsigned int *)(v13 + 8);
    v15 = *(_DWORD *)(v13 + 8);
    __dmb(0xBu);
    if ( v15 )
    {
      if ( (__get_CPSR() & 0x80) != 0 )
      {
        v21 = 0;
      }
      else
      {
        v21 = 1;
        __disable_irq();
      }
      if ( (dword_682604 & 0x210000) != 0 )
      {
        KiAcquireSpinLockInstrumented(v14);
        goto LABEL_30;
      }
      do
        v16 = __ldrex(v14);
      while ( __strex(1u, v14) );
      __dmb(0xBu);
      if ( v16 )
      {
        KxWaitForSpinLockAndAcquire(v14);
LABEL_30:
        v8 = v18;
        v14 = (unsigned int *)(v13 + 8);
      }
      if ( (dword_682604 & 0x10000) != 0 )
      {
        KiReleaseSpinLockInstrumented(v14);
        v8 = v18;
      }
      else
      {
        __dmb(0xBu);
        *v14 = 0;
      }
      v9 = v19;
      v12 = v20;
      if ( v21 )
        __enable_irq();
      goto LABEL_37;
    }
    v9 = v19;
LABEL_37:
    v17 = *(_DWORD *)(v13 + 20);
    __dmb(0xBu);
    if ( v17 != a1 )
    {
      v8 &= ~*(_DWORD *)(v12 + 1048);
      goto LABEL_15;
    }
  }
  if ( v8 )
    KeGenericProcessorCallback(v23, (int)PopPoCoalescinCallback, 0, 2, v18);
  return 0;
}
