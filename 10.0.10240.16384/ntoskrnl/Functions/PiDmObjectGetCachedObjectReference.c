// PiDmObjectGetCachedObjectReference 
 
int __fastcall PiDmObjectGetCachedObjectReference(unsigned int *a1, unsigned int *a2, unsigned int *a3, unsigned int *a4, unsigned int *a5)
{
  int v6; // r5
  unsigned int v8; // r7
  unsigned int v9; // r6
  unsigned int v11; // r2
  int v12; // r0
  int v13; // r5
  unsigned int v14; // r2
  unsigned int *v15; // r2
  unsigned int v16; // r3
  unsigned int v17; // r2
  unsigned int *v18; // r2
  unsigned int v19; // r1
  int v20; // r1
  unsigned int v21; // r0
  unsigned int v22; // r2
  int v23; // r0
  unsigned int v24; // r1
  __int16 v25; // r3
  unsigned int v26; // [sp+0h] [bp-28h] BYREF
  unsigned int *var24[15]; // [sp+4h] [bp-24h] BYREF

  var24[11] = a1;
  var24[12] = a2;
  var24[14] = a4;
  v26 = (unsigned int)a2;
  var24[0] = a3;
  var24[1] = a4;
  v6 = -1073741802;
  var24[13] = a3;
  PiDmGetCacheKeys((int)a1, var24, (int *)&v26);
  v8 = v26;
  if ( v26 )
  {
    v9 = PiDmGetCachedKeyIndex(var24[0], v26, (unsigned int)a4);
    if ( v9 < v8 )
    {
      if ( !a3 )
        return sub_7EECA4();
      v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v11 + 308);
      v12 = KeAbPreAcquire((unsigned int)a3, 0, 0);
      v13 = v12;
      do
        v14 = __ldrex(a3);
      while ( !v14 && __strex(0x11u, a3) );
      __dmb(0xBu);
      if ( v14 )
        ExfAcquirePushLockSharedEx(a3, v12, (unsigned int)a3);
      if ( v13 )
        *(_BYTE *)(v13 + 14) |= 1u;
      v15 = &a3[5 * v9];
      v16 = v15[16];
      if ( v16 == 5 )
      {
        v17 = v15[18];
        *a5 = v17;
        __dmb(0xBu);
        v18 = (unsigned int *)(v17 + 4);
        do
          v19 = __ldrex(v18);
        while ( __strex(v19 + 1, v18) );
        __dmb(0xBu);
        v6 = 0;
      }
      else if ( v16 == 1 )
      {
        v6 = -1073741275;
      }
      else
      {
        v6 = -1073741802;
      }
      __pld(a3);
      v20 = *a3;
      if ( (*a3 & 0xFFFFFFF0) > 0x10 )
        v21 = v20 - 16;
      else
        v21 = 0;
      if ( (v20 & 2) != 0 )
        goto LABEL_31;
      __dmb(0xBu);
      do
        v22 = __ldrex(a3);
      while ( v22 == v20 && __strex(v21, a3) );
      if ( v22 != v20 )
LABEL_31:
        ExfReleasePushLock(a3, v20);
      v23 = KeAbPostRelease((unsigned int)a3);
      v24 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v25 = *(_WORD *)(v24 + 0x134) + 1;
      *(_WORD *)(v24 + 308) = v25;
      if ( !v25 && *(_DWORD *)(v24 + 100) != v24 + 100 && !*(_WORD *)(v24 + 310) )
        KiCheckForKernelApcDelivery(v23);
    }
  }
  return v6;
}
