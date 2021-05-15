// PiDqIrpQueryCreate 
 
int __fastcall PiDqIrpQueryCreate(int a1)
{
  int v1; // r8
  _DWORD *v2; // r5
  int v3; // r6
  unsigned int v4; // r2
  unsigned __int8 *v5; // r6
  int v6; // r0
  int v7; // r4
  unsigned int v8; // r2
  int v9; // r3
  int v10; // r3
  _DWORD *v11; // r8
  int v12; // r1
  int v13; // r2
  int v14; // r3
  unsigned int *v15; // r4
  int v16; // r1
  unsigned int v17; // r0
  unsigned int v18; // r2
  int v19; // r0
  unsigned int v20; // r1
  __int16 v21; // r3
  unsigned int v22; // r2
  unsigned int v23; // r2
  unsigned __int8 *v24; // r4
  int v25; // r0
  int v26; // r8
  unsigned int v27; // r2
  int v28; // r1
  unsigned int v29; // r0
  unsigned int v30; // r2
  int v31; // r0
  __int16 v32; // r3
  _DWORD *v34; // [sp+0h] [bp-80h]
  int v35; // [sp+Ch] [bp-74h]
  int v37; // [sp+14h] [bp-6Ch]
  int v38; // [sp+18h] [bp-68h]
  int v39; // [sp+1Ch] [bp-64h] BYREF
  int v40; // [sp+20h] [bp-60h]
  int v41; // [sp+24h] [bp-5Ch]
  int v42; // [sp+28h] [bp-58h] BYREF
  int v43; // [sp+2Ch] [bp-54h]
  int v44; // [sp+30h] [bp-50h]
  _DWORD *v45; // [sp+34h] [bp-4Ch]
  int v46; // [sp+38h] [bp-48h]
  int v47; // [sp+3Ch] [bp-44h]
  _BYTE v48[16]; // [sp+40h] [bp-40h] BYREF
  _DWORD v49[12]; // [sp+50h] [bp-30h] BYREF

  v44 = a1;
  v1 = *(_DWORD *)(a1 + 96);
  v41 = v1;
  v46 = v1;
  v2 = *(_DWORD **)(*(_DWORD *)(v1 + 28) + 16);
  v45 = v2;
  v43 = 0;
  v38 = 0;
  v47 = 0;
  v40 = 0;
  v35 = 0;
  v39 = 0;
  v37 = 0;
  v42 = 0;
  if ( v2 )
  {
    if ( *(_DWORD *)(a1 + 12) )
    {
      v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v4 + 308);
      v5 = (unsigned __int8 *)(v2 + 8);
      v6 = KeAbPreAcquire((unsigned int)(v2 + 8), 0, 0);
      v7 = v6;
      do
        v8 = __ldrex(v5);
      while ( __strex(v8 | 1, v5) );
      __dmb(0xBu);
      if ( (v8 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx(v2 + 8, v6, (unsigned int)(v2 + 8));
      if ( v7 )
        *(_BYTE *)(v7 + 14) |= 1u;
      v9 = v2[29];
      if ( (v9 & 8) != 0 )
      {
        v3 = -1073741536;
      }
      else if ( (v9 & 0x10) != 0 || (v10 = v9 | 0x10, v2[29] = v10, v43 = 1, (v10 & 4) != 0) )
      {
        v3 = -1073741637;
      }
      else if ( *(_DWORD *)(v1 + 8) >= 0x10u )
      {
        v3 = MesDecodeBufferHandleCreate_0();
        if ( v3 >= 0 )
        {
          v34 = v2 + 3;
          NdrMesTypeDecode2_0();
          v3 = PiDqQueryValidateQueryData(v2[3]);
          if ( v3 >= 0 )
          {
            v11 = (_DWORD *)v2[3];
            if ( !PnpIsNullGuid(v11) )
            {
              v12 = v11[1];
              v13 = v11[2];
              v14 = v11[3];
              v49[0] = *v11;
              v49[1] = v12;
              v49[2] = v13;
              v49[3] = v14;
              v38 = IoSetActivityIdThread((int)v49);
              v40 = 1;
            }
            PiDqTraceQueryCreate(v2);
            v2[29] |= 4u;
          }
        }
      }
      else
      {
        v3 = -1073741789;
      }
      v15 = v2 + 8;
      __pld(v2 + 8);
      v16 = v2[8];
      if ( (v16 & 0xFFFFFFF0) <= 0x10 )
        v17 = 0;
      else
        v17 = v16 - 16;
      if ( (v16 & 2) != 0 )
        goto LABEL_33;
      __dmb(0xBu);
      do
        v18 = __ldrex(v15);
      while ( v18 == v16 && __strex(v17, v15) );
      if ( v18 != v16 )
LABEL_33:
        ExfReleasePushLock(v2 + 8, v16);
      v19 = KeAbPostRelease((unsigned int)(v2 + 8));
      v20 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v21 = *(_WORD *)(v20 + 0x134) + 1;
      *(_WORD *)(v20 + 308) = v21;
      if ( !v21 && *(_DWORD *)(v20 + 100) != v20 + 100 && !*(_WORD *)(v20 + 310) )
        KiCheckForKernelApcDelivery(v19);
      if ( v3 >= 0 )
      {
        v22 = *(_DWORD *)(v41 + 8);
        if ( v22 <= 0x10 )
        {
          v35 = 16;
        }
        else
        {
          v3 = PiDqQuerySerializeActionQueue(v2, *(_DWORD *)(a1 + 12), v22, &v39, &v42);
          v35 = v39;
          v37 = v42;
        }
      }
    }
    else
    {
      v3 = -1073741811;
    }
  }
  else
  {
    v3 = -1073741637;
  }
  if ( v43 )
  {
    v23 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v23 + 308);
    v24 = (unsigned __int8 *)(v2 + 8);
    v25 = KeAbPreAcquire((unsigned int)(v2 + 8), 0, 0);
    v26 = v25;
    do
      v27 = __ldrex(v24);
    while ( __strex(v27 | 1, v24) );
    __dmb(0xBu);
    if ( (v27 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(v2 + 8, v25, (unsigned int)(v2 + 8));
    if ( v26 )
      *(_BYTE *)(v26 + 14) |= 1u;
    if ( v3 < 0 )
    {
      v2[29] |= 1u;
      PiDqQueryFreeActiveData(v2);
    }
    else
    {
      PiDqQueryGetNextIoctlInfo(v2, *(_DWORD *)(v41 + 8), v37, v48, v34);
    }
    v2[29] &= 0xFFFFFFEF;
    __pld(v24);
    v28 = *(_DWORD *)v24;
    if ( (*(_DWORD *)v24 & 0xFFFFFFF0) <= 0x10 )
      v29 = 0;
    else
      v29 = v28 - 16;
    if ( (v28 & 2) != 0 )
      goto LABEL_60;
    __dmb(0xBu);
    do
      v30 = __ldrex((unsigned int *)v24);
    while ( v30 == v28 && __strex(v29, (unsigned int *)v24) );
    if ( v30 != v28 )
LABEL_60:
      ExfReleasePushLock(v2 + 8, v28);
    KeAbPostRelease((unsigned int)(v2 + 8));
    v31 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v32 = *(_WORD *)(v31 + 0x134) + 1;
    *(_WORD *)(v31 + 308) = v32;
    if ( !v32 && *(_DWORD *)(v31 + 100) != v31 + 100 && !*(_WORD *)(v31 + 310) )
      KiCheckForKernelApcDelivery(v31);
  }
  PiDqIrpComplete(a1, v3, v35, v48);
  if ( v40 )
    IoClearActivityIdThread(v38);
  return v3;
}
