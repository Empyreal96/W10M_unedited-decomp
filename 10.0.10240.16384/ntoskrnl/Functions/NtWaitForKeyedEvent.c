// NtWaitForKeyedEvent 
 
int __fastcall NtWaitForKeyedEvent(int a1, unsigned int a2, _DWORD *a3, int *a4)
{
  int *v4; // r6
  unsigned int v5; // r5
  int v6; // r10
  unsigned int v8; // r4
  int v9; // r1
  int v10; // r2
  unsigned int v11; // r5
  _DWORD **v12; // r9
  int v13; // r8
  unsigned int v14; // r2
  _DWORD *i; // r2
  int v16; // r3
  _DWORD *v17; // r8
  _DWORD *v18; // r0
  _DWORD *v19; // r1
  unsigned int v20; // r2
  unsigned int *v21; // r1
  unsigned int v22; // r1
  int v23; // r0
  __int16 v24; // r3
  int v25; // r8
  int v26; // r0
  int v27; // r6
  unsigned int v28; // r2
  unsigned int v29; // r2
  int v30; // r0
  _DWORD *v31; // r1
  unsigned int v32; // r1
  int v33; // r0
  __int16 v34; // r3
  int v35; // r0
  __int16 v36; // r3
  int v38; // [sp+10h] [bp-48h]
  char v40; // [sp+18h] [bp-40h]
  int v42; // [sp+20h] [bp-38h]
  int v43; // [sp+28h] [bp-30h] BYREF
  _DWORD _30[14]; // [sp+30h] [bp-28h] BYREF
  _DWORD *varg_r2; // [sp+68h] [bp+10h]
  int *varg_r3; // [sp+6Ch] [bp+14h]

  varg_r2 = a3;
  v4 = a4;
  varg_r3 = a4;
  LOBYTE(varg_r2) = (_BYTE)a3;
  v5 = a2;
  _30[13] = a2;
  _30[12] = a1;
  v6 = 0;
  v38 = 0;
  if ( (a2 & 1) != 0 )
    return -1073741585;
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v43 = v8;
  v9 = *(char *)(v8 + 0x15A);
  v40 = *(_BYTE *)(v8 + 0x15A);
  if ( a4 )
  {
    if ( *(_BYTE *)(v8 + 0x15A) && ((unsigned int)(a4 + 2) > MmUserProbeAddress || a4 + 2 < a4) )
      *(_BYTE *)MmUserProbeAddress = 0;
    _30[0] = *a4;
    _30[1] = a4[1];
    v4 = _30;
    varg_r3 = _30;
  }
  if ( !a1 )
  {
    v10 = ExpCritSecOutOfMemoryEvent;
    v42 = ExpCritSecOutOfMemoryEvent;
LABEL_12:
    *(_DWORD *)(v8 + 964) |= 8u;
    v43 = *(_DWORD *)(v8 + 116);
    v11 = v10 + 12 * ((v5 >> 5) & 0x3F);
    v12 = (_DWORD **)(v11 + 4);
    --*(_WORD *)(v8 + 308);
    v13 = KeAbPreAcquire(v11, 0, 0);
    do
      v14 = __ldrex((unsigned __int8 *)v11);
    while ( __strex(v14 | 1, (unsigned __int8 *)v11) );
    __dmb(0xBu);
    if ( (v14 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx((_DWORD *)v11, v13, v11);
    if ( v13 )
      *(_BYTE *)(v13 + 14) |= 1u;
    for ( i = *v12; ; i = (_DWORD *)*i )
    {
      v17 = i - 210;
      if ( i == v12 )
        break;
      v16 = i[5];
      if ( (v16 & 1) == 0 )
        break;
      if ( v16 == (a2 | 1) && *(i - 126) == v43 )
      {
        v18 = (_DWORD *)*i;
        v19 = (_DWORD *)i[1];
        if ( *(_DWORD **)(*i + 4) != i || (_DWORD *)*v19 != i )
          __fastfail(3u);
        *v19 = v18;
        v18[1] = v19;
        i[1] = i;
        *i = i;
        goto LABEL_32;
      }
    }
    v38 = *(_DWORD *)(v8 + 860);
    *(_DWORD *)(v8 + 860) = a2;
    v20 = v8 + 840;
    v21 = *(unsigned int **)(v11 + 8);
    *(_DWORD *)(v8 + 840) = v12;
    *(_DWORD *)(v8 + 844) = v21;
    if ( (_DWORD **)*v21 != v12 )
      __fastfail(3u);
    *v21 = v20;
    *(_DWORD *)(v11 + 8) = v20;
    v17 = 0;
LABEL_32:
    __dmb(0xBu);
    do
      v22 = __ldrex((unsigned int *)v11);
    while ( __strex(v22 - 1, (unsigned int *)v11) );
    if ( (v22 & 2) != 0 && (v22 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)v11);
    v23 = KeAbPostRelease(v11);
    if ( v17 )
    {
      v35 = KeReleaseSemaphore((int)(v17 + 221), 1, 1);
      v36 = *(_WORD *)(v8 + 308) + 1;
      *(_WORD *)(v8 + 308) = v36;
      if ( !v36 && *(_DWORD *)(v8 + 100) != v8 + 100 && !*(_WORD *)(v8 + 310) )
        KiCheckForKernelApcDelivery(v35);
    }
    else
    {
      v24 = *(_WORD *)(v8 + 308) + 1;
      *(_WORD *)(v8 + 308) = v24;
      if ( !v24 && *(_DWORD *)(v8 + 100) != v8 + 100 && !*(_WORD *)(v8 + 310) )
        KiCheckForKernelApcDelivery(v23);
      v6 = KeWaitForSingleObject(v8 + 884, 21, v40, a3, v4);
      if ( v6 )
      {
        v25 = 1;
        --*(_WORD *)(v8 + 308);
        v26 = KeAbPreAcquire(v11, 0, 0);
        v27 = v26;
        do
          v28 = __ldrex((unsigned __int8 *)v11);
        while ( __strex(v28 | 1, (unsigned __int8 *)v11) );
        __dmb(0xBu);
        if ( (v28 & 1) != 0 )
          ExfAcquirePushLockExclusiveEx((_DWORD *)v11, v26, v11);
        if ( v27 )
          *(_BYTE *)(v27 + 14) |= 1u;
        v29 = v8 + 840;
        if ( *(_DWORD *)(v8 + 840) != v8 + 840 )
        {
          v30 = *(_DWORD *)v29;
          v31 = *(_DWORD **)(v8 + 844);
          if ( *(_DWORD *)(*(_DWORD *)v29 + 4) != v29 || *v31 != v29 )
            __fastfail(3u);
          *v31 = v30;
          *(_DWORD *)(v30 + 4) = v31;
          *(_DWORD *)(v8 + 844) = v8 + 840;
          *(_DWORD *)v29 = v29;
          v25 = 0;
        }
        __dmb(0xBu);
        do
          v32 = __ldrex((unsigned int *)v11);
        while ( __strex(v32 - 1, (unsigned int *)v11) );
        if ( (v32 & 2) != 0 && (v32 & 4) == 0 )
          ExfTryToWakePushLock((unsigned int *)v11);
        v33 = KeAbPostRelease(v11);
        v34 = *(_WORD *)(v8 + 308) + 1;
        *(_WORD *)(v8 + 308) = v34;
        if ( !v34 && *(_DWORD *)(v8 + 100) != v8 + 100 && !*(_WORD *)(v8 + 310) )
          KiCheckForKernelApcDelivery(v33);
        if ( v25 )
          v6 = KeWaitForSingleObject(v8 + 884, 21, 0, 0, 0);
      }
      *(_DWORD *)(v8 + 860) = v38;
    }
    *(_DWORD *)(v8 + 964) &= 0xFFFFFFF7;
    if ( a1 )
      ObfDereferenceObject(v42);
    return v6;
  }
  v6 = ObReferenceObjectByHandle(a1, 1, ExpKeyedEventObjectType, v9, &v43);
  v10 = v43;
  v42 = v43;
  if ( v6 >= 0 )
    goto LABEL_12;
  return v6;
}
