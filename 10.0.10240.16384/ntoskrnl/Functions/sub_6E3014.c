// sub_6E3014 
 
int sub_6E3014()
{
  unsigned int v0; // r2
  int v1; // r5
  unsigned int v2; // r1
  int v3; // r3
  unsigned int v4; // r1
  int v5; // r0
  unsigned int v6; // r1
  __int16 v7; // r3
  int v8; // r5
  unsigned int v9; // r2
  int v10; // r0
  int v11; // r8
  unsigned int v12; // r1
  int *v13; // r8
  unsigned int v14; // r1
  unsigned int v15; // r0
  int v16; // r0
  unsigned int v17; // r1
  __int16 v18; // r3
  char v20; // [sp+8h] [bp-60h]
  char v21; // [sp+9h] [bp-5Fh]
  int v22; // [sp+Ch] [bp-5Ch]
  _DWORD v23[20]; // [sp+18h] [bp-50h] BYREF

  v22 = 0;
  v21 = 0;
  v20 = 0;
  v0 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v0 + 308);
  v1 = KeAbPreAcquire((unsigned int)&dword_922C40, 0, 0);
  do
    v2 = __ldrex((unsigned int *)&dword_922C40);
  while ( !v2 && __strex(0x11u, (unsigned int *)&dword_922C40) );
  __dmb(0xBu);
  if ( v2 )
    ExfAcquirePushLockSharedEx(&dword_922C40, v1, (unsigned int)&dword_922C40);
  if ( v1 )
    *(_BYTE *)(v1 + 14) |= 1u;
  if ( byte_920AF2 )
  {
    v3 = -1073741762;
LABEL_14:
    v22 = v3;
    goto LABEL_15;
  }
  if ( byte_920AF3 )
  {
    if ( !dword_922C3C )
    {
      v3 = -1073741772;
      goto LABEL_14;
    }
  }
  else
  {
    v21 = 1;
  }
LABEL_15:
  __dmb(0xBu);
  do
    v4 = __ldrex((unsigned int *)&dword_922C40);
  while ( v4 == 17 && __strex(0, (unsigned int *)&dword_922C40) );
  if ( v4 != 17 )
    ExfReleasePushLockShared(&dword_922C40);
  v5 = KeAbPostRelease((unsigned int)&dword_922C40);
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v7 = *(_WORD *)(v6 + 0x134) + 1;
  *(_WORD *)(v6 + 308) = v7;
  if ( !v7 && *(_DWORD *)(v6 + 100) != v6 + 100 && !*(_WORD *)(v6 + 310) )
    KiCheckForKernelApcDelivery(v5);
  v8 = v22;
  if ( v22 >= 0 && v21 == 1 )
  {
    v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v9 + 308);
    v10 = KeAbPreAcquire((unsigned int)&dword_922C40, 0, 0);
    v11 = v10;
    do
      v12 = __ldrex((unsigned __int8 *)&dword_922C40);
    while ( __strex(v12 | 1, (unsigned __int8 *)&dword_922C40) );
    __dmb(0xBu);
    if ( (v12 & 1) != 0 )
      v10 = ExfAcquirePushLockExclusiveEx(&dword_922C40, v10, (unsigned int)&dword_922C40);
    if ( v11 )
      *(_BYTE *)(v11 + 14) |= 1u;
    if ( byte_920AF3 == 1 )
      goto LABEL_48;
    v13 = off_920350;
    if ( off_920350 )
    {
      v8 = sub_7BBFAC(v10);
      v22 = v8;
      if ( v8 < 0 )
        goto LABEL_48;
    }
    else
    {
      v13 = (int *)dword_922C44;
      if ( !dword_922C44 )
        goto LABEL_47;
    }
    if ( (v13[3] & 1) != 0 )
    {
      dword_920284 = 2;
      v23[2] = 2;
      sub_6E34A4(v23, 2, 0);
    }
    v14 = dword_922C3C;
    if ( !dword_922C3C )
    {
      v8 = sub_7A0ED8(v13, 1, &byte_922C48, 2339, &dword_922C3C);
      v22 = v8;
      v14 = dword_922C3C;
    }
    if ( v8 >= 0 )
    {
      if ( v14 )
      {
        qsort((unsigned int)&byte_922C48, v14, 8u, (int (__fastcall *)(unsigned int, _BYTE *))sub_6C7BFC);
        byte_920AF3 = 1;
      }
      else
      {
        byte_920AF3 = 1;
        v22 = -1073741772;
      }
      goto LABEL_48;
    }
    if ( v8 != -1073741789 )
    {
LABEL_48:
      __dmb(0xBu);
      do
        v15 = __ldrex((unsigned int *)&dword_922C40);
      while ( __strex(v15 - 1, (unsigned int *)&dword_922C40) );
      if ( (v15 & 2) != 0 && (v15 & 4) == 0 )
        ExfTryToWakePushLock((unsigned int *)&dword_922C40);
      v16 = KeAbPostRelease((unsigned int)&dword_922C40);
      v17 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v18 = *(_WORD *)(v17 + 0x134) + 1;
      *(_WORD *)(v17 + 308) = v18;
      if ( !v18 && *(_DWORD *)(v17 + 100) != v17 + 100 && !*(_WORD *)(v17 + 310) )
        KiCheckForKernelApcDelivery(v16);
      v8 = v22;
      goto LABEL_58;
    }
LABEL_47:
    v22 = -1073741762;
    byte_920AF2 = 1;
    v20 = 1;
    goto LABEL_48;
  }
LABEL_58:
  if ( v20 )
    sub_7663CC(KernelLicensingCacheCorrupt);
  return v8;
}
