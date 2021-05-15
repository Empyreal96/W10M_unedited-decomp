// ObpStartRuntimeStackTrace 
 
int __fastcall ObpStartRuntimeStackTrace(int a1)
{
  int v2; // r6
  int v3; // lr
  unsigned int v4; // r8
  int v5; // r0
  unsigned int v6; // r3
  unsigned int v7; // r1
  unsigned int i; // r0
  unsigned int j; // lr
  unsigned __int16 v11; // r3
  int v12; // r0
  unsigned int v13; // r2
  int v14; // r0
  int v15; // r5
  unsigned int v16; // r2
  int v17; // r8
  int v18; // r3
  int v19; // r9
  unsigned int v20; // r2
  _DWORD *v21; // r1
  unsigned int v22; // r1
  int v23; // r0
  unsigned int v24; // r4
  __int16 v25; // r3
  unsigned int v26; // r0
  unsigned int v27; // r1
  int v28; // r0
  unsigned int v29; // r1
  __int16 v30; // r3
  int v32; // [sp+4h] [bp-ACh]
  int v33; // [sp+8h] [bp-A8h]
  unsigned int v34; // [sp+Ch] [bp-A4h]
  int v35; // [sp+10h] [bp-A0h]
  int v36; // [sp+18h] [bp-98h]
  int v37; // [sp+28h] [bp-88h]
  int v38; // [sp+28h] [bp-88h]
  unsigned int v39; // [sp+28h] [bp-88h]
  int v40; // [sp+34h] [bp-7Ch]
  int v41; // [sp+40h] [bp-70h]
  int v42[24]; // [sp+50h] [bp-60h] BYREF
  _BYTE v43[60]; // [sp+54h] [bp-5Ch] BYREF

  v42[0] = 0;
  memset(v43, 0, sizeof(v43));
  v33 = 0;
  v36 = 0;
  v32 = 0;
  v2 = 0;
  v3 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v40 = v3;
  v37 = *(_DWORD *)(a1 + 12);
  v4 = *(_DWORD *)(a1 + 16);
  v41 = *(_DWORD *)(a1 + 4);
  v34 = *(_DWORD *)(a1 + 8);
  v35 = *(unsigned __int8 *)(a1 + 1);
  v5 = (unsigned __int16)v37;
  if ( (_WORD)v37 )
  {
    if ( (v37 & 1) != 0 )
      return -1073741811;
    v6 = ((unsigned __int16)v37 >> 1)
       - 5 * ((unsigned int)((3435973837u * (unsigned __int64)((unsigned __int16)v37 >> 1)) >> 32) >> 2);
    if ( v6 )
    {
      if ( v6 != 4 )
        return -1073741811;
    }
    v7 = ((unsigned int)(unsigned __int16)v37 + 2) / 0xA;
    v38 = v7;
    if ( v7 > 0x10 )
    {
      v7 = 16;
      v38 = 16;
    }
    if ( v3 )
    {
      if ( (v4 & 1) != 0 )
        ExRaiseDatatypeMisalignment(v5);
      if ( v5 + v4 > MmUserProbeAddress || v5 + v4 < v4 )
        *(_BYTE *)MmUserProbeAddress = 0;
    }
    for ( i = 0; i < v7; ++i )
    {
      for ( j = 0; j < 4; ++j )
        v42[i] = *(unsigned __int16 *)(v4 + 2 * (5 * i - j) + 6) | (v42[i] << 8);
      v7 = v38;
    }
    v2 = 16;
  }
  if ( (_WORD)v41 )
  {
    if ( (v41 & 1) != 0 )
      return -1073741811;
    if ( (unsigned __int16)v41 >= 0x80u )
      v11 = 126;
    else
      v11 = v41;
    v39 = v11;
    LOWORD(v36) = v11;
    v12 = ExAllocatePoolWithTag(512, v11 + 2, 1951556175);
    v32 = v12;
    if ( !v12 )
      return -1073741801;
    HIWORD(v36) = v39 + 2;
    if ( v40 )
    {
      if ( (v34 & 1) != 0 )
        ExRaiseDatatypeMisalignment(v12);
      if ( (unsigned __int16)v41 + v34 > MmUserProbeAddress || (unsigned __int16)v41 + v34 < v34 )
        *(_BYTE *)MmUserProbeAddress = 0;
    }
    memmove(v12, v34, v39);
    *(_WORD *)(v32 + 2 * (v39 >> 1)) = 0;
    v2 |= 0x20u;
  }
  if ( v2 )
  {
    if ( v35 )
      v2 |= 0x40u;
    v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v13 + 310);
    v14 = KeAbPreAcquire((unsigned int)&ObpStackTraceLock, 0, 0);
    v15 = v14;
    do
      v16 = __ldrex((unsigned __int8 *)&ObpStackTraceLock);
    while ( __strex(v16 | 1, (unsigned __int8 *)&ObpStackTraceLock) );
    __dmb(0xBu);
    if ( (v16 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(&ObpStackTraceLock, v14, (unsigned int)&ObpStackTraceLock);
    if ( v15 )
      *(_BYTE *)(v15 + 14) |= 1u;
    v17 = ObpTraceFlags;
    if ( (ObpTraceFlags & 0x73) != 0 )
    {
      v18 = 0;
    }
    else
    {
      v18 = ObpInitStackAndObjectTables();
      v33 = v18;
      v17 = ObpTraceFlags;
    }
    if ( v18 < 0 )
    {
      __dmb(0xBu);
      do
        v27 = __ldrex((unsigned int *)&ObpStackTraceLock);
      while ( __strex(v27 - 1, (unsigned int *)&ObpStackTraceLock) );
      if ( (v27 & 2) != 0 && (v27 & 4) == 0 )
        ExfTryToWakePushLock((unsigned int *)&ObpStackTraceLock);
      v28 = KeAbPostRelease((unsigned int)&ObpStackTraceLock);
      v29 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v30 = *(_WORD *)(v29 + 0x136) + 1;
      *(_WORD *)(v29 + 310) = v30;
      if ( !v30 && *(_DWORD *)(v29 + 100) != v29 + 100 )
        KiCheckForKernelApcDelivery(v28);
      if ( !v32 )
        return v33;
      v26 = v32;
    }
    else
    {
      v19 = dword_61FDE4;
      ObpRuntimeTraceProcessName = v36;
      dword_61FDE4 = v32;
      memmove((int)ObpRuntimeTracePoolTags, (int)v42, 0x40u);
      v20 = v17 & 0xFFFFFF8E | v2 | 2;
      ObpRuntimeTraceFlags = v20;
      ObpTraceFlags = v20;
      if ( (v20 & 0x10) != 0 )
        v21 = ObpRuntimeTracePoolTags;
      else
        v21 = 0;
      ObpTracePoolTags = (int)v21;
      if ( (v20 & 0x20) != 0 )
        ObpTraceProcessName = (int)&ObpRuntimeTraceProcessName;
      else
        ObpTraceProcessName = 0;
      __dmb(0xBu);
      do
        v22 = __ldrex((unsigned int *)&ObpStackTraceLock);
      while ( __strex(v22 - 1, (unsigned int *)&ObpStackTraceLock) );
      if ( (v22 & 2) != 0 && (v22 & 4) == 0 )
        ExfTryToWakePushLock((unsigned int *)&ObpStackTraceLock);
      v23 = KeAbPostRelease((unsigned int)&ObpStackTraceLock);
      v24 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v25 = *(_WORD *)(v24 + 0x136) + 1;
      *(_WORD *)(v24 + 310) = v25;
      if ( !v25 && *(_DWORD *)(v24 + 100) != v24 + 100 )
        KiCheckForKernelApcDelivery(v23);
      if ( !v19 )
        return v33;
      v26 = v19;
    }
    ExFreePoolWithTag(v26);
    return v33;
  }
  return -1073741811;
}
