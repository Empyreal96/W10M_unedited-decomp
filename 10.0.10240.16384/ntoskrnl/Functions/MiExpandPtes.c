// MiExpandPtes 
 
int __fastcall MiExpandPtes(int *a1, unsigned int a2)
{
  int v4; // r4
  unsigned int v5; // r2
  int v6; // r5
  int v7; // r10
  unsigned int v8; // r8
  int v9; // r1
  unsigned int v10; // r0
  int v11; // r7
  unsigned int v12; // r2
  int v13; // r0
  int v14; // r0
  unsigned int *v16; // r2
  unsigned int v17; // r0
  unsigned int *v18; // r2
  unsigned int v19; // r0
  unsigned int v20; // r5
  unsigned int *v21; // r6
  unsigned int v22; // r2
  unsigned int v23; // r4
  int v24; // r2
  unsigned int v25; // r0
  unsigned int v26; // r3
  int v27; // r2
  unsigned int v28; // r0
  int v29; // r5
  unsigned int v30; // r2
  unsigned int *v31; // r0
  unsigned int v32; // r1
  int v33; // r3
  int v34; // r4
  unsigned int v35; // r4
  int v36; // [sp+0h] [bp-50h]
  unsigned int v37; // [sp+4h] [bp-4Ch]
  int v38; // [sp+8h] [bp-48h]
  int v39; // [sp+Ch] [bp-44h]
  int v40; // [sp+10h] [bp-40h]
  unsigned __int8 *v41; // [sp+14h] [bp-3Ch]
  unsigned int v42; // [sp+18h] [bp-38h]
  int v43; // [sp+18h] [bp-38h]
  int v44; // [sp+1Ch] [bp-34h]
  unsigned int *v45; // [sp+1Ch] [bp-34h]
  unsigned int v46; // [sp+20h] [bp-30h]
  char v47[40]; // [sp+28h] [bp-28h] BYREF

  if ( a2 + 1023 <= a2 )
    goto LABEL_71;
  v4 = a1[3];
  v5 = 1;
  v37 = 1;
  if ( (v4 & 4) != 0 )
  {
    v5 = 16;
    v37 = 16;
  }
  v6 = 0;
  v7 = a1[4];
  v36 = 0;
  if ( a2 >= 0x400 && a1 == &dword_634D58 )
  {
    v6 = 1;
    v36 = 1;
  }
  v8 = (a2 + 1023) & 0xFFFFFC00;
  v38 = v8 / v5;
  if ( (v4 & 2) != 0 )
  {
    v40 = 16;
    v9 = a1[4];
    if ( v6 == 1 )
      v9 = 16;
    if ( (v4 & 4) != 0 )
      v9 |= 0x40000000u;
    v10 = MiObtainSystemVa(v8 >> 10, v9);
  }
  else
  {
    v40 = 1;
    v10 = MiObtainSessionVa(v8 >> 10);
  }
  if ( !v10 )
LABEL_71:
    JUMPOUT(0x5103A0);
  v11 = ((v10 >> 10) & 0x3FFFFC) - 0x40000000;
  v39 = (v11 - a1[2]) >> 2;
  if ( !v6 )
  {
    v42 = ((v11 - a1[2]) >> 2) / v37;
    v44 = a1[1];
    v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v46 = v12;
    if ( (a1[3] & 2) != 0 )
    {
      KeAcquireInStackQueuedSpinLock(a1 + 7, v47);
    }
    else
    {
      --*(_WORD *)(v12 + 310);
      v41 = (unsigned __int8 *)a1[7];
      v29 = KeAbPreAcquire(v41, 0, 0);
      do
        v30 = __ldrex(v41);
      while ( __strex(v30 | 1, v41) );
      __dmb(0xBu);
      if ( (v30 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx(v41, v29, v41);
      if ( v29 )
        *(_BYTE *)(v29 + 14) |= 1u;
    }
    v13 = MiSplitBitmapPages(v7, v44 + (v42 >> 3), v38 + (v42 & 7));
    v43 = v13;
    if ( (a1[3] & 2) != 0 )
    {
      if ( v13 == 1 && (v39 + v8) / v37 > *a1 )
        *a1 = (v39 + v8) / v37;
      v14 = KeReleaseInStackQueuedSpinLock(v47);
    }
    else
    {
      v31 = (unsigned int *)a1[7];
      v45 = v31;
      __dmb(0xBu);
      do
        v32 = __ldrex(v31);
      while ( __strex(v32 - 1, v31) );
      if ( (v32 & 2) != 0 && (v32 & 4) == 0 )
      {
        ExfTryToWakePushLock();
        v31 = v45;
      }
      v14 = KeAbPostRelease(v31);
      v33 = (__int16)(*(_WORD *)(v46 + 310) + 1);
      *(_WORD *)(v46 + 310) = v33;
      if ( !v33 && *(_DWORD *)(v46 + 100) != v46 + 100 )
        v14 = KiCheckForKernelApcDelivery(v14);
    }
    if ( !v43 )
      return sub_510390(v14);
  }
  if ( !MiMakeZeroedPageTables(v11, v11 + 4 * v8 - 4, v40) )
    JUMPOUT(0x510394);
  v16 = (unsigned int *)(a1 + 12);
  do
    v17 = __ldrex(v16);
  while ( __strex(v17 + v38, v16) );
  v18 = (unsigned int *)(a1 + 9);
  do
    v19 = __ldrex(v18);
  while ( __strex(v19 + v38, v18) );
  if ( (dword_681258 & 2) != 0 && a1 == &dword_634D58 )
  {
    v34 = dword_634804;
    KeAcquireInStackQueuedSpinLock(a1 + 7, v47);
    if ( !MiSplitBitmapPages(v7, v34 + ((unsigned int)(2 * v39) >> 3), ((2 * v39) & 7) + 2 * v38) )
      dword_681258 &= 0xFFFFFFFD;
    KeReleaseInStackQueuedSpinLock(v47);
  }
  if ( v36 != 1 && a2 != v8 )
  {
    v20 = (v8 - a2) / v37;
    v21 = (unsigned int *)(a1[1] + 4 * (((v39 + a2) / v37) >> 5));
    v22 = ((v39 + a2) / v37) & 0x1F;
    if ( v20 + v22 <= 0x20 )
    {
      if ( v20 == 32 )
      {
        *v21 = 0;
        return v11;
      }
      __dmb(0xBu);
      v27 = ~(((1 << v20) - 1) << v22);
      do
        v28 = __ldrex(v21);
      while ( __strex(v28 & v27, v21) );
    }
    else
    {
      if ( v22 )
      {
        v23 = 32 - v22;
        __dmb(0xBu);
        v24 = ~(((1 << (32 - v22)) - 1) << v22);
        do
          v25 = __ldrex(v21);
        while ( __strex(v25 & v24, v21) );
        __dmb(0xBu);
        v20 -= v23;
        ++v21;
      }
      if ( v20 >= 0x20 )
      {
        v26 = v20 >> 5;
        do
        {
          v20 -= 32;
          --v26;
          *v21++ = 0;
        }
        while ( v26 );
      }
      if ( !v20 )
        return v11;
      __dmb(0xBu);
      do
        v35 = __ldrex(v21);
      while ( __strex(v35 & ~((1 << v20) - 1), v21) );
    }
    __dmb(0xBu);
  }
  return v11;
}
