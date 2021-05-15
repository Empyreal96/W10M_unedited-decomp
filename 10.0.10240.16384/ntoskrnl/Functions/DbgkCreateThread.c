// DbgkCreateThread 
 
int __fastcall DbgkCreateThread(int result)
{
  _DWORD *v1; // r8
  int v2; // r5
  unsigned int *v3; // r4
  unsigned int v4; // r9
  char v5; // r3
  int *v6; // r10
  int v7; // r0
  int i; // r9
  int v9; // r1
  int v10; // r4
  int v11; // r0
  int v12; // r0
  int v13; // r10
  unsigned int *v14; // r0
  unsigned int v15; // r2
  unsigned int *v16; // r10
  unsigned int v17; // r2
  int v18; // r0
  int v19; // r1
  __int16 v20; // r3
  int v21; // r0
  char *v22; // r0
  int v23; // r4
  _DWORD *v24; // r0
  unsigned int v25; // [sp-4h] [bp-108h] BYREF
  int *v26; // [sp+0h] [bp-104h]
  int v27; // [sp+4h] [bp-100h]
  int v28; // [sp+8h] [bp-FCh]
  int v29; // [sp+Ch] [bp-F8h]
  unsigned int v30; // [sp+10h] [bp-F4h]
  int *v31; // [sp+14h] [bp-F0h]
  unsigned int v32; // [sp+18h] [bp-ECh]
  int v33; // [sp+1Ch] [bp-E8h] BYREF
  int v34; // [sp+20h] [bp-E4h] BYREF
  int v35; // [sp+24h] [bp-E0h]
  int v36; // [sp+28h] [bp-DCh]
  int v37; // [sp+2Ch] [bp-D8h]
  int v38; // [sp+30h] [bp-D4h]
  int v39; // [sp+3Ch] [bp-C8h] BYREF
  int v40; // [sp+40h] [bp-C4h]
  int v41; // [sp+54h] [bp-B0h]
  int v42; // [sp+5Ch] [bp-A8h]
  int v43; // [sp+60h] [bp-A4h]
  int v44; // [sp+64h] [bp-A0h]
  int v45; // [sp+68h] [bp-9Ch]
  int v46; // [sp+6Ch] [bp-98h]
  int v47; // [sp+70h] [bp-94h]
  int v48; // [sp+74h] [bp-90h]

  v1 = (_DWORD *)result;
  v28 = result;
  v2 = *(_DWORD *)(result + 116);
  v29 = v2;
  __dmb(0xBu);
  v3 = (unsigned int *)(v2 + 192);
  do
    v4 = __ldrex(v3);
  while ( __strex(v4 | 0x400001, v3) );
  v30 = v4;
  v32 = v4;
  __dmb(0xBu);
  if ( (v4 & 0x400000) == 0 )
  {
    v5 = PspNotifyEnableMask;
    __dmb(0xBu);
    if ( (v5 & 1) != 0 || (PerfGlobalGroupMask & 4) != 0 )
    {
      v25 = 0;
      v6 = &v34;
      v26 = &v34;
      v31 = &v34;
      v34 = 3;
      v35 = *(_DWORD *)(v2 + 296);
      v37 = 0;
      v7 = RtlImageNtHeader(v35);
      if ( v7 )
        v37 = *(_DWORD *)(v7 + 80);
      v36 = 0;
      v38 = 0;
      PsReferenceProcessFilePointer(v2, (int *)&v25);
      PsCallImageNotifyRoutines(*(char **)(v2 + 380), *(_DWORD *)(v2 + 176), (int)&v33, v25);
      result = ObfDereferenceObject(v25);
      for ( i = 0; ; ++i )
      {
        v25 = i;
        if ( i >= 2 )
          break;
        result = PsQuerySystemDllInfo(i);
        v10 = result;
        v27 = result;
        if ( result )
        {
          v34 = 0;
          *(_BYTE *)v6 = 3;
          v35 = *(_DWORD *)(result + 12);
          v6[3] = v9;
          v11 = RtlImageNtHeader(*(_DWORD *)(result + 12));
          if ( v11 )
            v6[3] = *(_DWORD *)(v11 + 80);
          v36 = 0;
          v6[4] = 0;
          v12 = ObFastReferenceObject((_DWORD *)(v10 - 8));
          v25 = v12;
          if ( !v12 )
          {
            v27 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
            --*(_WORD *)(v27 + 308);
            v13 = KeAbPreAcquire(v10 - 4, 0, 0);
            v14 = (unsigned int *)(v10 - 4);
            do
              v15 = __ldrex(v14);
            while ( !v15 && __strex(0x11u, v14) );
            __dmb(0xBu);
            if ( v15 )
              ExfAcquirePushLockSharedEx(v14, v13, v10 - 4);
            if ( v13 )
              *(_BYTE *)(v13 + 14) |= 1u;
            v25 = ObFastReferenceObjectLocked((_DWORD *)(v10 - 8));
            __dmb(0xBu);
            v16 = (unsigned int *)(v10 - 4);
            do
              v17 = __ldrex(v16);
            while ( v17 == 17 && __strex(0, v16) );
            if ( v17 != 17 )
              ExfReleasePushLockShared((_DWORD *)(v10 - 4));
            v18 = KeAbPostRelease(v10 - 4);
            v19 = v27;
            v20 = *(_WORD *)(v27 + 308) + 1;
            *(_WORD *)(v27 + 308) = v20;
            if ( !v20 && *(_DWORD *)(v19 + 100) != v19 + 100 && !*(_WORD *)(v19 + 310) )
              KiCheckForKernelApcDelivery(v18);
            v12 = v25;
            v6 = v26;
          }
          v21 = MiSectionControlArea(v12);
          v27 = MI_REFERENCE_CONTROL_AREA_FILE(v21);
          if ( v25 )
            ObFastDereferenceObject((_DWORD *)(v10 - 8), v25);
          v22 = (char *)(v10 + 4);
          v23 = v27;
          PsCallImageNotifyRoutines(v22, *(_DWORD *)(v2 + 176), (int)&v33, v27);
          result = ObfDereferenceObject(v23);
        }
      }
      LOBYTE(v4) = v30;
    }
  }
  if ( *(_DWORD *)(v2 + 340) )
  {
    if ( (v4 & 1) != 0 )
    {
      if ( (v1[240] & 4) == 0 )
      {
        v42 = 0;
        v43 = v1[231];
        v39 = 2621456;
        v40 = 8;
        v41 = 1;
        result = DbgkpSendApiMessage(v2, 1, &v39);
      }
    }
    else
    {
      v47 = 0;
      v42 = 0;
      v43 = DbgkpSectionToFileHandle(*(_DWORD *)(v2 + 292));
      v44 = *(_DWORD *)(v2 + 296);
      v48 = 0;
      v45 = 0;
      v46 = 0;
      v24 = (_DWORD *)RtlImageNtHeader(*(_DWORD *)(v2 + 296));
      if ( v24 )
      {
        v48 = v24[10] + v24[13];
        v45 = v24[3];
        v46 = v24[4];
      }
      v39 = 3932196;
      v40 = 8;
      v41 = 2;
      DbgkpSendApiMessage(v2, 0, &v39);
      if ( v43 )
        ObCloseHandle(v43);
      result = DbgkSendSystemDllMessages(0, 0, &v39);
    }
    if ( (v1[241] & 4) != 0 )
      result = DbgkpPostModuleMessages(v2, v1, 0);
  }
  return result;
}
