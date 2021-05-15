// FsRtlTeardownPerStreamContexts 
 
int __fastcall FsRtlTeardownPerStreamContexts(int result, int a2)
{
  int v2; // r4
  int v3; // r3
  _DWORD **v4; // r6
  unsigned __int8 *v5; // r8
  unsigned int v6; // r2
  int v7; // r0
  int v8; // r5
  unsigned int v9; // r2
  unsigned int v10; // r8
  int v11; // r5
  int v12; // r1
  unsigned int v13; // r2
  _DWORD *v14; // r3
  _DWORD *v15; // r8
  _DWORD *v16; // r2
  unsigned int *v17; // r5
  int v18; // r1
  unsigned int v19; // r0
  unsigned int v20; // r2
  int v21; // r0
  unsigned int v22; // r1
  __int16 v23; // r3
  unsigned int *v24; // r5
  unsigned int v25; // r1
  unsigned __int8 *v26; // r8
  unsigned int v27; // r2
  int v28; // r0
  int v29; // r5
  unsigned int v30; // r2
  unsigned int v31; // r8
  int v32; // r5
  int v33; // r1
  unsigned int v34; // r2
  unsigned int *v35; // r4
  int v36; // r1
  unsigned int v37; // r0
  unsigned int v38; // r2
  unsigned int v39; // r1
  __int16 v40; // r3
  unsigned int *v41; // r4
  unsigned int v42; // r5
  unsigned int v43; // r1
  int v44; // [sp+4h] [bp-24h]
  unsigned int v45; // [sp+4h] [bp-24h]
  int v46; // [sp+4h] [bp-24h]
  int vars8; // [sp+30h] [bp+8h]

  v2 = result;
  vars8 = result;
  if ( (*(_BYTE *)(result + 7) & 0xF0u) >= 0x30 )
  {
    v3 = *(_DWORD *)(result + 64);
    if ( v3 )
    {
      result = (*(int (__fastcall **)(_DWORD))(v3 + 16))(*(_DWORD *)(result + 64));
      *(_DWORD *)(v2 + 64) = 0;
    }
  }
  v4 = (_DWORD **)(v2 + 44);
  if ( *(_DWORD *)(v2 + 44) != v2 + 44 )
  {
    if ( (*(_BYTE *)(v2 + 7) & 0xF0u) < 0x10 )
    {
      v10 = *(_DWORD *)(v2 + 40);
      v11 = KeAbPreAcquire(v10, 0, 0);
      v12 = KfRaiseIrql(1);
      v44 = v12;
      do
        v13 = __ldrex((unsigned __int8 *)v10);
      while ( __strex(v13 & 0xFE, (unsigned __int8 *)v10) );
      __dmb(0xBu);
      if ( (v13 & 1) == 0 )
      {
        ExpAcquireFastMutexContended(v10, v11);
        v12 = v44;
      }
      if ( v11 )
        *(_BYTE *)(v11 + 14) |= 1u;
      *(_DWORD *)(v10 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      *(_DWORD *)(v10 + 28) = v12;
    }
    else
    {
      v5 = (unsigned __int8 *)(v2 + 52);
      v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v6 + 308);
      v7 = KeAbPreAcquire(v2 + 52, 0, 0);
      v8 = v7;
      do
        v9 = __ldrex(v5);
      while ( __strex(v9 | 1, v5) );
      __dmb(0xBu);
      if ( (v9 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx((_DWORD *)(v2 + 52), v7, v2 + 52);
      if ( v8 )
        *(_BYTE *)(v8 + 14) |= 1u;
    }
    while ( 1 )
    {
      v14 = *v4;
      if ( *v4 == v4 )
        break;
      v15 = *v4;
      v16 = (_DWORD *)*v14;
      if ( (_DWORD **)v14[1] != v4 || (_DWORD *)v16[1] != v15 )
        __fastfail(3u);
      *v4 = v16;
      v16[1] = v4;
      if ( (*(_BYTE *)(v2 + 7) & 0xF0u) < 0x10 )
      {
        v24 = *(unsigned int **)(v2 + 40);
        v24[1] = 0;
        v45 = v24[7];
        __dmb(0xBu);
        do
          v25 = __ldrex(v24);
        while ( !v25 && __strex(1u, v24) );
        if ( v25 )
          ExpReleaseFastMutexContended(v24, v25);
        KfLowerIrql((unsigned __int8)v45);
        KeAbPostRelease((unsigned int)v24);
      }
      else
      {
        v17 = (unsigned int *)(v2 + 52);
        __pld((void *)(v2 + 52));
        v18 = *(_DWORD *)(v2 + 52);
        if ( (v18 & 0xFFFFFFF0) <= 0x10 )
          v19 = 0;
        else
          v19 = v18 - 16;
        if ( (v18 & 2) != 0 )
          goto LABEL_31;
        __dmb(0xBu);
        do
          v20 = __ldrex(v17);
        while ( v20 == v18 && __strex(v19, v17) );
        if ( v20 != v18 )
LABEL_31:
          ExfReleasePushLock((_DWORD *)(v2 + 52), v18);
        v21 = KeAbPostRelease(v2 + 52);
        v22 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v23 = *(_WORD *)(v22 + 0x134) + 1;
        *(_WORD *)(v22 + 308) = v23;
        if ( !v23 && *(_DWORD *)(v22 + 100) != v22 + 100 && !*(_WORD *)(v22 + 310) )
          KiCheckForKernelApcDelivery(v21);
      }
      ((void (__fastcall *)(_DWORD *))v15[4])(v15);
      if ( (*(_BYTE *)(v2 + 7) & 0xF0u) < 0x10 )
      {
        v31 = *(_DWORD *)(v2 + 40);
        v32 = KeAbPreAcquire(v31, 0, 0);
        v33 = KfRaiseIrql(1);
        v46 = v33;
        do
          v34 = __ldrex((unsigned __int8 *)v31);
        while ( __strex(v34 & 0xFE, (unsigned __int8 *)v31) );
        __dmb(0xBu);
        if ( (v34 & 1) == 0 )
        {
          ExpAcquireFastMutexContended(v31, v32);
          v33 = v46;
        }
        if ( v32 )
          *(_BYTE *)(v32 + 14) |= 1u;
        *(_DWORD *)(v31 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        *(_DWORD *)(v31 + 28) = v33;
      }
      else
      {
        v26 = (unsigned __int8 *)(v2 + 52);
        v27 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        --*(_WORD *)(v27 + 308);
        v28 = KeAbPreAcquire(v2 + 52, 0, 0);
        v29 = v28;
        do
          v30 = __ldrex(v26);
        while ( __strex(v30 | 1, v26) );
        __dmb(0xBu);
        if ( (v30 & 1) != 0 )
          ExfAcquirePushLockExclusiveEx((_DWORD *)(v2 + 52), v28, v2 + 52);
        if ( v29 )
          *(_BYTE *)(v29 + 14) |= 1u;
      }
    }
    if ( (*(_BYTE *)(vars8 + 7) & 0xF0u) < 0x10 )
    {
      v41 = *(unsigned int **)(vars8 + 40);
      v41[1] = 0;
      v42 = v41[7];
      __dmb(0xBu);
      do
        v43 = __ldrex(v41);
      while ( !v43 && __strex(1u, v41) );
      if ( v43 )
        ExpReleaseFastMutexContended(v41, v43);
      KfLowerIrql((unsigned __int8)v42);
      result = KeAbPostRelease((unsigned int)v41);
    }
    else
    {
      v35 = (unsigned int *)(vars8 + 52);
      __pld((void *)(vars8 + 52));
      v36 = *(_DWORD *)(vars8 + 52);
      if ( (v36 & 0xFFFFFFF0) <= 0x10 )
        v37 = 0;
      else
        v37 = v36 - 16;
      if ( (v36 & 2) != 0 )
        goto LABEL_67;
      __dmb(0xBu);
      do
        v38 = __ldrex(v35);
      while ( v38 == v36 && __strex(v37, v35) );
      if ( v38 != v36 )
LABEL_67:
        ExfReleasePushLock(v35, v36);
      result = KeAbPostRelease((unsigned int)v35);
      v39 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v40 = *(_WORD *)(v39 + 0x134) + 1;
      *(_WORD *)(v39 + 308) = v40;
      if ( !v40 && *(_DWORD *)(v39 + 100) != v39 + 100 && !*(_WORD *)(v39 + 310) )
        result = KiCheckForKernelApcDelivery(result);
    }
  }
  return result;
}
