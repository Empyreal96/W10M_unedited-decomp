// sub_53B7D4 
 
void sub_53B7D4(int a1, int a2, int a3, int a4, ...)
{
  int v4; // r5
  _DWORD *v5; // r6
  int v6; // r7
  int v7; // r8
  int v8; // r9
  int v9; // r10
  int v10; // r0
  unsigned int *v11; // r1
  int *v12; // r0
  unsigned int *v13; // r2
  unsigned int v14; // r0
  _DWORD *v15; // r8
  unsigned int v16; // r0
  int v17; // r1
  unsigned int v18; // r3
  char v19; // r3
  char v20; // r3
  int v21; // r1
  int v22; // r0
  _DWORD *v23; // r1
  int v24; // r0
  _DWORD *v25; // r1
  int v26; // r0
  int v27; // r4
  int v28; // r0
  unsigned int *v29; // r1
  int *v30; // r0
  unsigned int *v31; // r2
  unsigned int v32; // r0
  int v33; // [sp+0h] [bp+0h] BYREF
  va_list va; // [sp+0h] [bp+0h]
  unsigned int *v35; // [sp+4h] [bp+4h]
  int v36; // [sp+8h] [bp+8h]
  int v37; // [sp+Ch] [bp+Ch]
  int v38; // [sp+10h] [bp+10h]
  int v39; // [sp+14h] [bp+14h]
  unsigned int v40; // [sp+18h] [bp+18h] BYREF
  va_list va1; // [sp+18h] [bp+18h]
  int v42; // [sp+1Ch] [bp+1Ch]
  va_list va2; // [sp+20h] [bp+20h] BYREF

  va_start(va2, a4);
  va_start(va1, a4);
  va_start(va, a4);
  v33 = va_arg(va1, _DWORD);
  v35 = va_arg(va1, unsigned int *);
  v36 = va_arg(va1, _DWORD);
  v37 = va_arg(va1, _DWORD);
  v38 = va_arg(va1, _DWORD);
  v39 = va_arg(va1, _DWORD);
  va_copy(va2, va1);
  v40 = va_arg(va2, _DWORD);
  v42 = va_arg(va2, _DWORD);
  if ( (*(_DWORD *)(v6 + 4) & v9) != 0 )
  {
    KiReleaseQueuedSpinLockInstrumented((int *)va, STACK[0x10C]);
    goto LABEL_11;
  }
  v10 = v33;
  if ( !v33 )
  {
    v11 = v35;
    __dmb(0xBu);
    do
      v12 = (int *)__ldrex(v11);
    while ( v12 == (int *)va && __strex(0, v11) );
    if ( v12 == (int *)va )
    {
LABEL_11:
      KfLowerIrql(v7);
      if ( CcUnmapInactiveViews(64, 0, (unsigned int *)va1) == 1 )
      {
        v15 = (_DWORD *)((v38 & (v40 >> 10)) - v8);
        MiChargeWsles((int)v5 + v4, -64, 0);
        if ( (v15[3] & 0xFFFFF000) == 0x2000 )
        {
          v16 = v15[2];
          while ( 1 )
          {
            __dmb(0xFu);
            v17 = KiTbFlushTimeStamp;
            __dmb(0xBu);
            v18 = (v17 - (v16 >> 12)) & 0xFFFFF;
            if ( v18 > 2 || ((v16 >> 12) & 1) == 0 && v18 >= 2 )
              goto LABEL_23;
            if ( (v17 & 1) == 0 )
              break;
            __dmb(0xFu);
            v19 = KiTbFlushTimeStamp;
            __dmb(0xBu);
            if ( (v19 & 1) != 0 )
            {
              do
              {
                __dmb(0xAu);
                __yield();
                v20 = KiTbFlushTimeStamp;
                __dmb(0xBu);
              }
              while ( (v20 & 1) != 0 );
            }
            if ( ((v16 >> 12) & 1) == 0 )
              goto LABEL_23;
          }
          MiInsertTbFlushEntry((int)va2, v40, 64, 0);
          MiFlushTbList((unsigned int)va2, v21);
        }
LABEL_23:
        if ( (unsigned int)v15 + v8 > 0x3FFFFF )
        {
          *v15 = 0;
        }
        else
        {
          __dmb(0xBu);
          *v15 = 0;
          if ( (unsigned int)(v15 + 267649024) <= 0xFFF )
          {
            v22 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            MiArmWriteConvertedHardwarePde(v22, (_DWORD *)(v22 + 4 * ((unsigned __int16)v15 & 0xFFF)), 0);
          }
        }
        v23 = v15 + 1;
        if ( (unsigned int)v15 + v8 + 4 > 0x3FFFFF )
        {
          *v23 = 0;
        }
        else
        {
          __dmb(0xBu);
          *v23 = 0;
          if ( (unsigned int)(v15 + 267649025) <= 0xFFF )
          {
            v24 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            MiArmWriteConvertedHardwarePde(v24, (_DWORD *)(v24 + 4 * ((unsigned __int16)v23 & 0xFFF)), 0);
          }
        }
        v25 = v15 + 2;
        if ( (unsigned int)v15 + v8 + 8 > 0x3FFFFF )
        {
          *v25 = 0;
        }
        else
        {
          __dmb(0xBu);
          *v25 = 0;
          if ( (unsigned int)(v15 + 267649026) <= 0xFFF )
          {
            v26 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            MiArmWriteConvertedHardwarePde(v26, (_DWORD *)(v26 + 4 * ((unsigned __int16)v25 & 0xFFF)), 0);
          }
        }
LABEL_48:
        JUMPOUT(0x49D7CA);
      }
      v27 = KfRaiseIrql(2);
      v39 = v27;
      KeAcquireInStackQueuedSpinLockAtDpcLevel(v5 + 1556, (int *)va);
      if ( v5[1553] >> 12 != (v37 - v5[1555] - v8) >> 2 )
        JUMPOUT(0x49D698);
      if ( (*(_DWORD *)(v6 + 4) & v9) != 0 )
      {
        KiReleaseQueuedSpinLockInstrumented((int *)va, STACK[0x10C]);
      }
      else
      {
        v28 = v33;
        if ( !v33 )
        {
          v29 = v35;
          __dmb(0xBu);
          do
            v30 = (int *)__ldrex(v29);
          while ( v30 == (int *)va && __strex(0, v29) );
          if ( v30 == (int *)va )
            goto LABEL_47;
          v28 = KxWaitForLockChainValid((int *)va);
        }
        v33 = 0;
        __dmb(0xBu);
        v31 = (unsigned int *)(v28 + 4);
        do
          v32 = __ldrex(v31);
        while ( __strex(v32 ^ 1, v31) );
      }
LABEL_47:
      KfLowerIrql(v27);
      MiChargeWsles((int)v5 + v4, -64, 0);
      goto LABEL_48;
    }
    v10 = KxWaitForLockChainValid((int *)va);
  }
  v33 = 0;
  __dmb(0xBu);
  v13 = (unsigned int *)(v10 + 4);
  do
    v14 = __ldrex(v13);
  while ( __strex(v14 ^ 1, v13) );
  goto LABEL_11;
}
