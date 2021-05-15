// PiDmObjectGetCachedObjectPropertyData 
 
int __fastcall PiDmObjectGetCachedObjectPropertyData(int a1, int a2, unsigned int *a3, unsigned int a4, int a5, int a6, int a7, int a8)
{
  int v9; // r9
  unsigned int *v10; // r8
  int (**v11)[5]; // r5
  unsigned int v12; // r6
  int v13; // r7
  unsigned int v14; // r4
  unsigned int v15; // r1
  int (*v16)[5]; // t1
  int v18; // r3
  int v19; // r0
  int v20; // r5
  unsigned int v21; // r2
  unsigned int *v22; // r2
  int v23; // r1
  unsigned int v24; // r0
  unsigned int v25; // r2
  int v26; // r0
  unsigned int v27; // r1
  __int16 v28; // r3
  unsigned int varg_r3; // [sp+44h] [bp+14h]

  varg_r3 = a4;
  v9 = -1073741802;
  v10 = a3;
  switch ( a1 )
  {
    case 1:
      v11 = (int (**)[5])&PiDmCachedDeviceKeys;
      v12 = 9;
      break;
    case 3:
      v11 = &PiDmCachedDeviceInterfaceKeys;
      v12 = 1;
      break;
    case 5:
      v11 = &PiDmCachedDeviceContainerKeys;
      v12 = 3;
      break;
    default:
      return v9;
  }
  v13 = *(_DWORD *)(a4 + 16);
  v14 = 0;
  while ( 1 )
  {
    v16 = *v11;
    v11 += 4;
    v15 = (unsigned int)v16;
    if ( v13 == (*v16)[4] && !memcmp(a4, v15, 16) )
      break;
    if ( ++v14 >= v12 )
    {
      v14 = -1;
      break;
    }
  }
  if ( v14 >= v12 )
    return v9;
  if ( v10 )
  {
    v18 = __mrc(15, 0, 13, 0, 3);
    --*(_WORD *)((v18 & 0xFFFFFFC0) + 0x134);
    v19 = KeAbPreAcquire((unsigned int)v10, 0, 0);
    v20 = v19;
    do
      v21 = __ldrex(v10);
    while ( !v21 && __strex(0x11u, v10) );
    __dmb(0xBu);
    if ( v21 )
      ExfAcquirePushLockSharedEx(v10, v19, (unsigned int)v10);
    if ( v20 )
      *(_BYTE *)(v20 + 14) |= 1u;
    v22 = &v10[5 * v14];
    if ( v22[16] )
      v9 = PiDmCacheDataDecode(v22 + 16, a5, a6, a7, a8);
    else
      v9 = -1073741802;
    __pld(v10);
    v23 = *v10;
    if ( (*v10 & 0xFFFFFFF0) > 0x10 )
      v24 = v23 - 16;
    else
      v24 = 0;
    if ( (v23 & 2) != 0 )
      goto LABEL_39;
    __dmb(0xBu);
    do
      v25 = __ldrex(v10);
    while ( v25 == v23 && __strex(v24, v10) );
    if ( v25 != v23 )
LABEL_39:
      ExfReleasePushLock(v10, v23);
    v26 = KeAbPostRelease((unsigned int)v10);
    v27 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v28 = *(_WORD *)(v27 + 0x134) + 1;
    *(_WORD *)(v27 + 308) = v28;
    if ( !v28 && *(_DWORD *)(v27 + 100) != v27 + 100 && !*(_WORD *)(v27 + 310) )
      KiCheckForKernelApcDelivery(v26);
    return v9;
  }
  return sub_7C6990();
}
