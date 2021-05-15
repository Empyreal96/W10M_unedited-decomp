// MiExpandPtes 
 
void __fastcall MiExpandPtes(int *a1, unsigned int a2)
{
  int v4; // r4
  unsigned int v5; // r2
  int v6; // r5
  int v7; // r10
  unsigned int v8; // r8
  int v9; // r1
  unsigned int v10; // r0
  unsigned int v11; // r7
  unsigned int v12; // r2
  int v13; // r0
  unsigned int *v14; // r2
  unsigned int v15; // r0
  unsigned int *v16; // r2
  unsigned int v17; // r0
  unsigned int v18; // r5
  unsigned int *v19; // r6
  unsigned int v20; // r2
  unsigned int v21; // r4
  int v22; // r2
  unsigned int v23; // r0
  unsigned int v24; // r3
  int v25; // r2
  unsigned int v26; // r0
  int v27; // r5
  unsigned int v28; // r2
  unsigned int *v29; // r0
  unsigned int v30; // r1
  int v31; // r0
  int v32; // r3
  int v33; // r4
  unsigned int v34; // r4
  int v35; // [sp+0h] [bp-50h]
  unsigned int v36; // [sp+4h] [bp-4Ch]
  int v37; // [sp+8h] [bp-48h]
  int v38; // [sp+Ch] [bp-44h]
  int v39; // [sp+10h] [bp-40h]
  unsigned __int8 *v40; // [sp+14h] [bp-3Ch]
  unsigned int v41; // [sp+18h] [bp-38h]
  int v42; // [sp+18h] [bp-38h]
  int v43; // [sp+1Ch] [bp-34h]
  unsigned int *v44; // [sp+1Ch] [bp-34h]
  unsigned int v45; // [sp+20h] [bp-30h]
  char v46[40]; // [sp+28h] [bp-28h] BYREF

  if ( a2 + 1023 <= a2 )
    goto LABEL_75;
  v4 = a1[3];
  v5 = 1;
  v36 = 1;
  if ( (v4 & 4) != 0 )
  {
    v5 = 16;
    v36 = 16;
  }
  v6 = 0;
  v7 = a1[4];
  v35 = 0;
  if ( a2 >= 0x400 && a1 == &dword_634D58 )
  {
    v6 = 1;
    v35 = 1;
  }
  v8 = (a2 + 1023) & 0xFFFFFC00;
  v37 = v8 / v5;
  if ( (v4 & 2) != 0 )
  {
    v39 = 16;
    v9 = a1[4];
    if ( v6 == 1 )
      v9 = 16;
    if ( (v4 & 4) != 0 )
      v9 |= 0x40000000u;
    v10 = MiObtainSystemVa(v8 >> 10, v9);
  }
  else
  {
    v39 = 1;
    MiObtainSessionVa(v8 >> 10, v8 % v5, v5, 1, v35, v36);
  }
  if ( !v10 )
LABEL_75:
    JUMPOUT(0x5103A0);
  v11 = ((v10 >> 10) & 0x3FFFFC) - 0x40000000;
  v38 = (int)(v11 - a1[2]) >> 2;
  if ( !v6 )
  {
    if ( !v36 )
      __brkdiv0();
    v41 = ((int)(v11 - a1[2]) >> 2) / v36;
    v43 = a1[1];
    v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v45 = v12;
    if ( (a1[3] & 2) != 0 )
    {
      KeAcquireInStackQueuedSpinLock((unsigned int *)a1 + 7, (unsigned int)v46);
    }
    else
    {
      --*(_WORD *)(v12 + 310);
      v40 = (unsigned __int8 *)a1[7];
      v27 = KeAbPreAcquire((unsigned int)v40, 0, 0);
      do
        v28 = __ldrex(v40);
      while ( __strex(v28 | 1, v40) );
      __dmb(0xBu);
      if ( (v28 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx(v40, v27, (unsigned int)v40);
      if ( v27 )
        *(_BYTE *)(v27 + 14) |= 1u;
    }
    v13 = MiSplitBitmapPages(v7, v43 + (v41 >> 3), v37 + (v41 & 7));
    v42 = v13;
    if ( (a1[3] & 2) != 0 )
    {
      if ( v13 == 1 && (v38 + v8) / v36 > *a1 )
        *a1 = (v38 + v8) / v36;
      KeReleaseInStackQueuedSpinLock((int)v46);
    }
    else
    {
      v29 = (unsigned int *)a1[7];
      v44 = v29;
      __dmb(0xBu);
      do
        v30 = __ldrex(v29);
      while ( __strex(v30 - 1, v29) );
      if ( (v30 & 2) != 0 && (v30 & 4) == 0 )
      {
        ExfTryToWakePushLock(v29);
        v29 = v44;
      }
      v31 = KeAbPostRelease((unsigned int)v29);
      v32 = (__int16)(*(_WORD *)(v45 + 310) + 1);
      *(_WORD *)(v45 + 310) = v32;
      if ( !v32 && *(_DWORD *)(v45 + 100) != v45 + 100 )
        KiCheckForKernelApcDelivery(v31);
    }
    if ( !v42 )
    {
      sub_510390();
      return;
    }
  }
  if ( !MiMakeZeroedPageTables(v11, v11 + 4 * v8 - 4, v39) )
    JUMPOUT(0x510394);
  v14 = (unsigned int *)(a1 + 12);
  do
    v15 = __ldrex(v14);
  while ( __strex(v15 + v37, v14) );
  v16 = (unsigned int *)(a1 + 9);
  do
    v17 = __ldrex(v16);
  while ( __strex(v17 + v37, v16) );
  if ( (dword_681258 & 2) != 0 && a1 == &dword_634D58 )
  {
    v33 = dword_634804;
    KeAcquireInStackQueuedSpinLock((unsigned int *)a1 + 7, (unsigned int)v46);
    if ( !MiSplitBitmapPages(v7, v33 + ((unsigned int)(2 * v38) >> 3), ((2 * v38) & 7) + 2 * v37) )
      dword_681258 &= 0xFFFFFFFD;
    KeReleaseInStackQueuedSpinLock((int)v46);
  }
  if ( v35 != 1 && a2 != v8 )
  {
    if ( !v36 )
      __brkdiv0();
    v18 = (v8 - a2) / v36;
    v19 = (unsigned int *)(a1[1] + 4 * (((v38 + a2) / v36) >> 5));
    v20 = ((v38 + a2) / v36) & 0x1F;
    if ( v18 + v20 <= 0x20 )
    {
      if ( v18 == 32 )
      {
        *v19 = 0;
        return;
      }
      __dmb(0xBu);
      v25 = ~(((1 << v18) - 1) << v20);
      do
        v26 = __ldrex(v19);
      while ( __strex(v26 & v25, v19) );
    }
    else
    {
      if ( v20 )
      {
        v21 = 32 - v20;
        __dmb(0xBu);
        v22 = ~(((1 << (32 - v20)) - 1) << v20);
        do
          v23 = __ldrex(v19);
        while ( __strex(v23 & v22, v19) );
        __dmb(0xBu);
        v18 -= v21;
        ++v19;
      }
      if ( v18 >= 0x20 )
      {
        v24 = v18 >> 5;
        do
        {
          v18 -= 32;
          --v24;
          *v19++ = 0;
        }
        while ( v24 );
      }
      if ( !v18 )
        return;
      __dmb(0xBu);
      do
        v34 = __ldrex(v19);
      while ( __strex(v34 & ~((1 << v18) - 1), v19) );
    }
    __dmb(0xBu);
  }
}
