// CmpQueryKeyName 
 
int __fastcall CmpQueryKeyName(int a1, int a2, int a3, unsigned int a4, _DWORD *a5)
{
  unsigned int v5; // r8
  int v6; // r5
  int v7; // r10
  __int16 *v8; // r6
  int v9; // r9
  unsigned int v10; // r4
  int v11; // r1
  _DWORD *v12; // r8
  int v13; // r4
  unsigned int v14; // r1
  int v15; // r3
  int v16; // r0
  int v17; // r5
  int v18; // r0
  int v19; // lr
  unsigned int v20; // r8
  unsigned int v21; // r8
  int v22; // r0
  unsigned int v23; // r1
  __int16 v24; // r3
  __int16 v28; // [sp+20h] [bp-48h] BYREF
  char v29[6]; // [sp+22h] [bp-46h]
  _DWORD v30[2]; // [sp+28h] [bp-40h] BYREF
  _DWORD _30[20]; // [sp+30h] [bp-38h] BYREF

  _30[17] = a2;
  _30[18] = a3;
  _30[19] = a4;
  v5 = a4;
  v6 = a3;
  v7 = a1;
  _30[16] = a1;
  v28 = 0;
  *(_DWORD *)v29 = 0;
  *(_WORD *)&v29[4] = 0;
  v8 = 0;
  v9 = 0;
  v30[1] = v30;
  v30[0] = v30;
  v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v11 = *(__int16 *)(v10 + 0x134);
  *(_WORD *)(v10 + 308) = v11 - 1;
  if ( !CmpCallBackCount || (a1 = ExIsResourceAcquiredSharedLite((int)&CmpRegistryLock, v11, a3, CmpCallBackCount)) != 0 )
  {
    v12 = a5;
  }
  else
  {
    _30[0] = v7;
    _30[1] = v6;
    _30[2] = v5;
    v12 = a5;
    _30[3] = a5;
    a1 = CmpCallCallBacks(47, _30, 1, 48, v7, v30);
    v13 = a1;
    if ( a1 < 0 )
    {
      if ( a1 == -1073740541 )
        v13 = 0;
      v14 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v15 = (__int16)(*(_WORD *)(v14 + 0x134) + 1);
      *(_WORD *)(v14 + 308) = v15;
      if ( !v15 && *(_DWORD *)(v14 + 100) != v14 + 100 && !*(_WORD *)(v14 + 310) )
        KiCheckForKernelApcDelivery(a1);
      return v13;
    }
  }
  v16 = CmpLockRegistry(a1, v11);
  v17 = *(_DWORD *)(v7 + 4);
  if ( (v17 & 1) != 0 )
  {
    v17 ^= 1u;
  }
  else if ( (*(_DWORD *)(v7 + 24) & 2) == 0 )
  {
    v16 = CmpLockKcbShared(v17);
    v9 = 1;
  }
  if ( (*(_DWORD *)(v17 + 4) & 0x20000) != 0 )
  {
    if ( (*(_DWORD *)(v7 + 24) & 1) != 0 )
      v13 = -1073740763;
    else
      v13 = -1073741444;
    CmpUnlockRegistry(v16);
    goto LABEL_36;
  }
  if ( CmpVEEnabled && (*(_WORD *)(v17 + 106) & 0x100) != 0 )
  {
    v18 = CmVirtualKCBToRealPath(v17, &v28);
    if ( v18 >= 0 )
      v8 = &v28;
  }
  else
  {
    v18 = CmpConstructName(v17);
    v8 = (__int16 *)v18;
  }
  if ( v9 )
  {
    v18 = CmpUnlockKcb(v17);
    v9 = 0;
  }
  CmpUnlockRegistry(v18);
  if ( v8 )
  {
    if ( a4 > 8 )
    {
      v19 = *((_DWORD *)v8 + 1);
      v20 = (unsigned __int16)*v8 + 2;
      *a5 = (unsigned __int16)*v8 + 10;
      if ( v20 <= a4 - 8 )
      {
        v13 = 0;
      }
      else
      {
        v20 = a4 - 8;
        v13 = -1073741820;
        if ( a4 - 8 < 2 )
          goto LABEL_36;
      }
      v21 = v20 - 2;
      memmove(a3 + 8, v19, v21);
      *(_WORD *)(a3 + 8 + 2 * (v21 >> 1)) = 0;
      *(_WORD *)a3 = v21;
      *(_WORD *)(a3 + 2) = v21;
      *(_DWORD *)(a3 + 4) = a3 + 8;
      goto LABEL_36;
    }
    *v12 = (unsigned __int16)*v8 + 10;
    v13 = -1073741820;
  }
  else
  {
    v13 = -1073741670;
  }
LABEL_36:
  if ( v9 )
    CmpUnlockKcb(v17);
  v22 = CmPostCallbackNotification(48, v7, v13, _30, v30);
  v23 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v24 = *(_WORD *)(v23 + 0x134) + 1;
  *(_WORD *)(v23 + 308) = v24;
  if ( !v24 && *(_DWORD *)(v23 + 100) != v23 + 100 && !*(_WORD *)(v23 + 310) )
    KiCheckForKernelApcDelivery(v22);
  if ( *(_DWORD *)&v29[2] )
  {
    RtlFreeAnsiString(&v28);
  }
  else if ( v8 )
  {
    ExFreePoolWithTag((unsigned int)v8);
  }
  return v13;
}
