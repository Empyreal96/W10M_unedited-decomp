// PiControlGetDeviceInterfaceEnabled 
 
int __fastcall PiControlGetDeviceInterfaceEnabled(int a1, unsigned __int16 *a2, int a3, char a4)
{
  unsigned int v5; // r2
  int v6; // r8
  int v7; // r5
  unsigned int v8; // r2
  unsigned int *v9; // r4
  int v10; // r0
  unsigned int v11; // r2
  int v12; // r1
  unsigned int v13; // r0
  unsigned int v14; // r2
  int v15; // r0
  unsigned int v16; // r1
  __int16 v17; // r3
  int v19; // [sp+8h] [bp-28h] BYREF
  unsigned int *v20; // [sp+Ch] [bp-24h] BYREF
  __int16 v21[2]; // [sp+10h] [bp-20h] BYREF
  unsigned int v22[7]; // [sp+14h] [bp-1Ch] BYREF

  v5 = *a2;
  v6 = a4;
  v21[1] = v5;
  v21[0] = v5;
  v19 = 0;
  if ( !v5 || v5 > 0x3F0 || (v5 & 1) != 0 || *((_DWORD *)a2 + 2) )
    return -1073741811;
  v7 = PiControlMakeUserModeCallersCopy((int *)v22, *((_DWORD *)a2 + 1), v5, 2, a4, 1);
  if ( v7 < 0 )
    return v7;
  v7 = PnpUnicodeStringToWstr(&v19, 0, v21);
  if ( v7 < 0 || (v7 = PiDmGetObject(3, v19, &v20), v7 < 0) )
  {
LABEL_23:
    PnpUnicodeStringToWstrFree(v19, v21);
    if ( v6 )
    {
      if ( v22[0] )
        ExFreePoolWithTag(v22[0]);
    }
    return v7;
  }
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v8 + 308);
  v9 = v20;
  v10 = KeAbPreAcquire((unsigned int)v20, 0, 0);
  do
    v11 = __ldrex(v9);
  while ( !v11 && __strex(0x11u, v9) );
  __dmb(0xBu);
  if ( !v11 )
  {
    if ( v10 )
      *(_BYTE *)(v10 + 14) |= 1u;
    *((_BYTE *)a2 + 12) = v9[7] != 0;
    __pld(v9);
    v12 = *v9;
    if ( (*v9 & 0xFFFFFFF0) > 0x10 )
      v13 = v12 - 16;
    else
      v13 = 0;
    if ( (v12 & 2) != 0 )
      goto LABEL_28;
    __dmb(0xBu);
    do
      v14 = __ldrex(v9);
    while ( v14 == v12 && __strex(v13, v9) );
    if ( v14 != v12 )
LABEL_28:
      ExfReleasePushLock(v9, v12);
    v15 = KeAbPostRelease((unsigned int)v9);
    v16 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v17 = *(_WORD *)(v16 + 0x134) + 1;
    *(_WORD *)(v16 + 308) = v17;
    if ( !v17 && *(_DWORD *)(v16 + 100) != v16 + 100 && !*(_WORD *)(v16 + 310) )
      KiCheckForKernelApcDelivery(v15);
    PiDmObjectRelease(v9);
    goto LABEL_23;
  }
  return sub_7C5B8C(v10, 17);
}
