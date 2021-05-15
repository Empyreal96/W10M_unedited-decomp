// AlpcpReceiveLegacyMessage 
 
int __fastcall AlpcpReceiveLegacyMessage(_DWORD *a1, unsigned int a2, int a3, _DWORD *a4)
{
  __int64 *v4; // r6
  _DWORD **v6; // r1
  unsigned int v7; // r2
  int v8; // r0
  _DWORD *v9; // r5
  _DWORD *v10; // r2
  int v11; // r10
  int *v12; // r5
  unsigned int *v13; // r10
  int v14; // r0
  int v15; // r4
  unsigned int v16; // r2
  unsigned int *v17; // r4
  unsigned int v18; // r2
  _DWORD *v19; // r4
  unsigned int *v20; // r4
  unsigned int v21; // r2
  int v22; // r4
  _DWORD *v23; // r6
  int v24; // r1
  int v25; // r2
  int v26; // r3
  int v27; // r3
  unsigned int v28; // r2
  int v29; // r1
  int v30; // r0
  char v31; // r2
  unsigned int *v32; // r8
  unsigned int v33; // r1
  int v34; // r3
  unsigned int *v35; // r2
  unsigned int v36; // r0
  int v37; // r0
  int v39; // [sp+10h] [bp-58h]
  _DWORD *v41; // [sp+18h] [bp-50h]
  _DWORD *v42; // [sp+1Ch] [bp-4Ch] BYREF
  __int64 *v43; // [sp+20h] [bp-48h]
  _DWORD *v44; // [sp+24h] [bp-44h]
  __int64 v45; // [sp+28h] [bp-40h]
  unsigned int v46; // [sp+30h] [bp-38h]
  _DWORD *v47; // [sp+34h] [bp-34h]
  _DWORD *v48; // [sp+38h] [bp-30h]
  __int64 v49[5]; // [sp+40h] [bp-28h] BYREF
  _DWORD *varg_r0; // [sp+70h] [bp+8h]
  unsigned int varg_r1; // [sp+74h] [bp+Ch]
  __int64 *varg_r2; // [sp+78h] [bp+10h]
  _DWORD *varg_r3; // [sp+7Ch] [bp+14h]

  v47 = a4;
  varg_r3 = a4;
  v4 = (__int64 *)a3;
  v43 = (__int64 *)a3;
  varg_r2 = (__int64 *)a3;
  varg_r1 = a2;
  v6 = (_DWORD **)a1;
  varg_r0 = a1;
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v46 = v7;
  v48 = (_DWORD *)v7;
  v8 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v39 = v8;
  v49[0] = 0i64;
  v41 = *v6;
  v9 = *v6;
  v44 = *v6;
  if ( v8 )
  {
    if ( v4 )
    {
      if ( (unsigned int)v4 >= MmUserProbeAddress )
        v4 = (__int64 *)MmUserProbeAddress;
      v45 = *v4;
      v49[0] = v45;
      v4 = v49;
      v43 = v49;
      varg_r2 = v49;
    }
    if ( a2 )
    {
      if ( (a2 & 7) != 0 )
        ExRaiseDatatypeMisalignment(v8);
      if ( a2 >= MmUserProbeAddress )
        *(_BYTE *)MmUserProbeAddress = 0;
      *(_BYTE *)a2 = *(_BYTE *)a2;
      *(_BYTE *)(a2 + 16) = *(_BYTE *)(a2 + 16);
    }
    if ( a4 )
    {
      v10 = a4;
      if ( (unsigned int)a4 >= MmUserProbeAddress )
        v10 = (_DWORD *)MmUserProbeAddress;
      *v10 = *v10;
    }
  }
  else if ( (*(_DWORD *)(v7 + 76) & 0x400) != 0 )
  {
    v8 = 1;
    v39 = 1;
  }
  v11 = 0;
  v48 = 0;
  if ( (v9[61] & 6) != 6 )
    goto LABEL_41;
  v12 = (int *)v9[2];
  v13 = (unsigned int *)(v12 - 1);
  v14 = KeAbPreAcquire((unsigned int)(v12 - 1), 0, 0);
  v15 = v14;
  do
    v16 = __ldrex(v13);
  while ( !v16 && __strex(0x11u, v13) );
  __dmb(0xBu);
  if ( v16 )
    ExfAcquirePushLockSharedEx(v12 - 1, v14, (unsigned int)(v12 - 1));
  if ( v15 )
    *(_BYTE *)(v15 + 14) |= 1u;
  v48 = (_DWORD *)*v12;
  v11 = (int)v48;
  if ( v48 && ObReferenceObjectSafe((int)v48) )
  {
    v17 = (unsigned int *)(v12 - 1);
    __dmb(0xBu);
    do
      v18 = __ldrex(v17);
    while ( v18 == 17 && __strex(0, v17) );
    if ( v18 != 17 )
      ExfReleasePushLockShared(v12 - 1);
    KeAbPostRelease((unsigned int)(v12 - 1));
    v9 = v48;
    v41 = v48;
    v44 = v48;
    v19 = a1;
    *a1 = v48;
    v8 = v39;
    while ( 1 )
    {
      v22 = AlpcpReceiveMessagePort(v19, v8, v4, &v42, 0);
      if ( v22 )
      {
        v42 = 0;
        goto LABEL_79;
      }
      v23 = v42;
      if ( (v42[5] & 0x80) != 0 )
      {
        if ( (_DWORD *)v42[9] == v9 )
        {
          v42[9] = 0;
          v23[8] = 0;
        }
        AlpcpCancelMessage(v9, (int)v23, 0x10000);
        v23 = 0;
        v42 = 0;
      }
      if ( v23 )
        break;
      v4 = v43;
      v8 = v39;
LABEL_41:
      v19 = a1;
    }
    v23[25] = v46;
    if ( a2 )
    {
      v24 = v23[31];
      v25 = v23[32];
      v26 = v23[33];
      *(_DWORD *)a2 = v23[30];
      *(_DWORD *)(a2 + 4) = v24;
      *(_DWORD *)(a2 + 8) = v25;
      *(_DWORD *)(a2 + 12) = v26;
      v27 = v23[35];
      *(_DWORD *)(a2 + 16) = v23[34];
      *(_DWORD *)(a2 + 20) = v27;
      if ( (v41[38] & 0x1000) != 0 )
        *(_WORD *)(a2 + 4) &= 0xC00Fu;
      if ( v23[22] )
      {
        AlpcpGetDataFromUserVaSafe(v23, a2 + 24);
      }
      else
      {
        v28 = *((unsigned __int16 *)v23 + 60);
        v29 = (int)(v23 + 36);
        v30 = a2 + 24;
        if ( v28 > 0x100 )
        {
          memmove(v30, v29, 0x100u);
          v28 = *((unsigned __int16 *)v23 + 60) - 256;
          v29 = v23[27];
          v30 = a2 + 280;
        }
        memmove(v30, v29, v28);
      }
      v22 = 0;
    }
    if ( v47 )
      *v47 = v23[16];
    if ( a2 )
    {
      if ( AlpcpMessageLogEnabled )
        AlpcpEnterStateChangeEventMessageLog(v23);
      v48 = 0;
      v31 = *((_BYTE *)v23 - 16);
      if ( (v31 & 1) != 0 )
      {
        v48 = (_DWORD *)(0x10000 - *((__int16 *)v23 - 7));
        *((_BYTE *)v23 - 16) = v31 & 0xFE;
        *((_WORD *)v23 - 7) = 0;
      }
      v32 = v23 - 1;
      __dmb(0xBu);
      do
        v33 = __ldrex(v32);
      while ( __strex(v33 - 1, v32) );
      if ( (v33 & 2) != 0 && (v33 & 4) == 0 )
        ExfTryToWakePushLock(v23 - 1);
      KeAbPostRelease((unsigned int)(v23 - 1));
      v34 = (int)v48;
      if ( (int)v48 > 0 )
      {
        __dmb(0xBu);
        v35 = v23 - 3;
        do
        {
          v36 = __ldrex(v35);
          v37 = v36 - v34;
        }
        while ( __strex(v37, v35) );
        __dmb(0xBu);
        if ( v37 <= 0 )
        {
          if ( v37 )
            KeBugCheckEx(24, 0, (int)v23, 40, v37);
          AlpcpDestroyBlob(v23);
        }
      }
    }
    else
    {
      v23[25] = 0;
      AlpcpCancelMessage(v41, (int)v23, 0x10000);
    }
LABEL_79:
    if ( v11 )
      ObfDereferenceObject(v11);
  }
  else
  {
    v20 = (unsigned int *)(v12 - 1);
    __dmb(0xBu);
    do
      v21 = __ldrex(v20);
    while ( v21 == 17 && __strex(0, v20) );
    if ( v21 != 17 )
      ExfReleasePushLockShared(v12 - 1);
    KeAbPostRelease((unsigned int)(v12 - 1));
    v22 = -1073741769;
  }
  return v22;
}
