// EtwpRealtimeConnect 
 
int __fastcall EtwpRealtimeConnect(_DWORD *a1, int a2)
{
  _BYTE *v3; // r4
  _BYTE *v4; // r6
  unsigned int v5; // r8
  _BYTE *v6; // r9
  _DWORD *v7; // r2
  _DWORD *v8; // r2
  _DWORD *v9; // r2
  int v10; // r0
  _DWORD *v11; // r8
  int v12; // r5
  _BYTE *v13; // r9
  unsigned __int8 *v14; // r4
  int v15; // r0
  int v16; // r6
  unsigned int v17; // r2
  int v18; // r1
  unsigned int v19; // r0
  unsigned int v20; // r2
  _BYTE *v22; // [sp+18h] [bp-A0h] BYREF
  unsigned int v23; // [sp+1Ch] [bp-9Ch]
  unsigned int v24; // [sp+20h] [bp-98h]
  int v25; // [sp+24h] [bp-94h] BYREF
  unsigned int v26; // [sp+28h] [bp-90h]
  unsigned int v27; // [sp+2Ch] [bp-8Ch]
  unsigned int v28; // [sp+30h] [bp-88h]
  unsigned int v29; // [sp+34h] [bp-84h]
  unsigned int v30; // [sp+38h] [bp-80h]
  _BYTE *v31; // [sp+3Ch] [bp-7Ch]
  _DWORD *v32; // [sp+40h] [bp-78h]
  unsigned int v33; // [sp+44h] [bp-74h]
  int *v34; // [sp+48h] [bp-70h]
  int v35; // [sp+4Ch] [bp-6Ch]
  unsigned int v36; // [sp+50h] [bp-68h]
  unsigned int v37; // [sp+54h] [bp-64h]
  _DWORD *v38; // [sp+58h] [bp-60h]
  unsigned int v39; // [sp+5Ch] [bp-5Ch]
  _DWORD *v40; // [sp+60h] [bp-58h]
  unsigned int v41; // [sp+64h] [bp-54h]
  unsigned int v42; // [sp+68h] [bp-50h]
  unsigned int v43; // [sp+6Ch] [bp-4Ch]
  _DWORD *v44; // [sp+70h] [bp-48h]
  int v45; // [sp+74h] [bp-44h]
  unsigned int v46; // [sp+78h] [bp-40h]
  unsigned int v47; // [sp+7Ch] [bp-3Ch]
  _DWORD v48[6]; // [sp+80h] [bp-38h] BYREF
  _DWORD _98[12]; // [sp+98h] [bp-20h] BYREF

  _98[11] = a2;
  _98[10] = a1;
  v3 = 0;
  v45 = 0;
  v4 = 0;
  v35 = 0;
  v26 = *a1;
  v46 = v26;
  v25 = 0;
  v34 = a1 + 8;
  v38 = a1 + 8;
  v44 = a1 + 6;
  v32 = a1 + 18;
  v40 = a1 + 18;
  v30 = a1[4];
  v47 = v30;
  v23 = a1[2];
  v42 = v23;
  v24 = a1[1];
  v36 = v24;
  v29 = v24 >> 12;
  v37 = v24 >> 12;
  v28 = a1[12];
  v39 = v28;
  v27 = a1[10];
  v41 = v27;
  v5 = a1[14];
  v33 = v5;
  v43 = v5;
  v6 = (_BYTE *)a1[16];
  v31 = v6;
  v22 = v6;
  ProbeForWrite(v30, (((v24 >> 12) + 31) >> 3) & 0x1FFFFFFC, 4);
  ProbeForWrite(v23, v24, 8);
  v7 = (_DWORD *)v28;
  if ( v28 >= MmUserProbeAddress )
    v7 = (_DWORD *)MmUserProbeAddress;
  *v7 = *v7;
  v8 = (_DWORD *)v5;
  if ( v5 >= MmUserProbeAddress )
    v8 = (_DWORD *)MmUserProbeAddress;
  *v8 = *v8;
  v9 = v6;
  if ( (unsigned int)v6 >= MmUserProbeAddress )
    v9 = (_DWORD *)MmUserProbeAddress;
  *v9 = *v9;
  ProbeForWrite(v27, 4, 4);
  v10 = EtwpAcquireLoggerContextByLoggerId(v26, 1);
  v11 = (_DWORD *)v10;
  if ( !v10 )
    return -1073741811;
  v12 = EtwpCheckLoggerControlAccess(1024, v10);
  if ( v12 < 0 )
    goto LABEL_32;
  v12 = EtwpOpenConsumer(&v25);
  if ( v12 < 0 )
    goto LABEL_32;
  v12 = ObReferenceObjectByHandle(a1[6], 2, ExEventObjectType, 1, (int)&v22, 0);
  v4 = v22;
  if ( v12 < 0 )
    goto LABEL_32;
  v12 = ObReferenceObjectByHandle(*v34, 2, ExEventObjectType, 1, (int)&v22, 0);
  v3 = v22;
  if ( v12 < 0
    || (v48[0] = 24,
        v48[1] = 0,
        v48[3] = 64,
        v48[2] = 0,
        v48[4] = 0,
        v48[5] = 0,
        v12 = ObCreateObject(0, (_DWORD *)EtwpRealTimeConnectionObjectType, (int)v48, 1, 0, 84, 0, 0, &v22),
        v12 < 0) )
  {
LABEL_32:
    EtwpReleaseLoggerContext(v11, 1);
    if ( v25 )
      ZwClose();
    if ( v4 )
      ObfDereferenceObject((int)v4);
    if ( v3 )
      ObfDereferenceObject((int)v3);
  }
  else
  {
    v13 = v22;
    memset(v22, 0, 84);
    *((_WORD *)v13 + 24) = v26;
    *((_DWORD *)v13 + 2) = v25;
    *((_DWORD *)v13 + 3) = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
    *((_DWORD *)v13 + 6) = v4;
    *((_DWORD *)v13 + 7) = v3;
    *((_DWORD *)v13 + 8) = v28;
    *((_DWORD *)v13 + 9) = v27;
    *((_DWORD *)v13 + 15) = v23;
    *((_DWORD *)v13 + 16) = v24;
    *((_DWORD *)v13 + 19) = v33;
    *((_DWORD *)v13 + 20) = v31;
    *((_DWORD *)v13 + 13) = v29;
    *((_DWORD *)v13 + 14) = v30;
    *((_DWORD *)v13 + 5) = a1;
    v12 = ObInsertObject((int)v13, 0, 1024, 1, (int)_98, (int)v32);
    if ( v12 >= 0 )
    {
      v14 = (unsigned __int8 *)(v11 + 126);
      v15 = KeAbPreAcquire((unsigned int)(v11 + 126), 0, 0);
      v16 = v15;
      do
        v17 = __ldrex(v14);
      while ( __strex(v17 | 1, v14) );
      __dmb(0xBu);
      if ( (v17 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx(v11 + 126, v15, (unsigned int)(v11 + 126));
      if ( v16 )
        *(_BYTE *)(v16 + 14) |= 1u;
      v11[67] = v13;
      __pld(v14);
      v18 = *(_DWORD *)v14;
      if ( (*(_DWORD *)v14 & 0xFFFFFFF0) <= 0x10 )
        v19 = 0;
      else
        v19 = v18 - 16;
      if ( (v18 & 2) != 0 )
        goto LABEL_29;
      __dmb(0xBu);
      do
        v20 = __ldrex((unsigned int *)v14);
      while ( v20 == v18 && __strex(v19, (unsigned int *)v14) );
      if ( v20 != v18 )
LABEL_29:
        ExfReleasePushLock(v11 + 126, v18);
      KeAbPostRelease((unsigned int)(v11 + 126));
      EtwpSynchronizeWithLogger(v11, 32);
    }
    EtwpReleaseLoggerContext(v11, 1);
  }
  return v12;
}
