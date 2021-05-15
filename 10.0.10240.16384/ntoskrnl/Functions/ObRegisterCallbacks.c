// ObRegisterCallbacks 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall ObRegisterCallbacks(int a1, unsigned int *a2)
{
  int v3; // r5
  int v5; // r8
  _BYTE *v6; // r0
  unsigned int v7; // r4
  int v8; // r3
  int v9; // r0
  unsigned int v10; // r2
  unsigned int v11; // r9
  int v12; // r8
  int v13; // r7
  _DWORD **v14; // r5
  unsigned int v15; // r0
  unsigned int v16; // r0
  _DWORD *v17; // r1
  _DWORD *v18; // r3
  int v19; // r0
  unsigned int v20; // r9
  _DWORD *v21; // r6
  unsigned int v22; // r2
  unsigned __int8 *v23; // r10
  int v24; // r0
  int v25; // r7
  unsigned int v26; // r2
  int v27; // r1 OVERLAPPED
  _DWORD *v28; // r2 OVERLAPPED
  int *v29; // r7
  int v30; // r1
  unsigned int v31; // r0
  unsigned int v32; // r2
  int v33; // r0
  unsigned int v34; // r1
  __int16 v35; // r3
  unsigned int v36; // r1
  unsigned int v37; // r2

  v3 = 0;
  if ( (*(_WORD *)a1 & 0xFF00) != 256 || !*(_WORD *)(a1 + 2) )
    return -1073741811;
  v5 = *(unsigned __int16 *)(a1 + 4) + 36 * *(unsigned __int16 *)(a1 + 2) + 16;
  v6 = (_BYTE *)ExAllocatePoolWithTag(1, v5, 1816552015);
  v7 = (unsigned int)v6;
  if ( !v6 )
    return -1073741670;
  memset(v6, 0, v5);
  *(_WORD *)v7 = 256;
  *(_DWORD *)(v7 + 4) = *(_DWORD *)(a1 + 12);
  v8 = *(unsigned __int16 *)(a1 + 4);
  *(_WORD *)(v7 + 10) = v8;
  *(_WORD *)(v7 + 8) = v8;
  v9 = v7 - v8 + v5;
  v10 = *(unsigned __int16 *)(v7 + 8);
  *(_DWORD *)(v7 + 12) = v9;
  memmove(v9, *(_DWORD *)(a1 + 8), v10);
  v11 = 0;
  if ( *(_WORD *)(a1 + 2) )
  {
    v12 = 0;
    v13 = 0;
    while ( 1 )
    {
      v14 = (_DWORD **)(v13 + *(_DWORD *)(a1 + 16));
      if ( !v14[1] || (*(_BYTE *)(**v14 + 42) & 0x40) == 0 )
        break;
      v15 = (unsigned int)v14[2];
      if ( v15 )
      {
        if ( !MmVerifyCallbackFunction(v15) )
          goto LABEL_19;
      }
      else if ( !v14[3] )
      {
        break;
      }
      v16 = (unsigned int)v14[3];
      if ( v16 && !MmVerifyCallbackFunction(v16) )
      {
LABEL_19:
        v3 = -1073741790;
        goto LABEL_22;
      }
      v17 = (_DWORD *)(v12 + v7 + 16);
      *v17 = v17;
      v17[1] = v17;
      v17[8] = 0;
      v18 = v14[1];
      v17[4] = v7;
      v17[2] = v18;
      v17[5] = **v14;
      v19 = *(_DWORD *)(v12 + v7 + 36);
      v17[6] = v14[2];
      v17[7] = v14[3];
      v3 = ObpInsertCallbackByAltitude(v19);
      if ( v3 < 0 )
        goto LABEL_22;
      ++v11;
      v13 += 16;
      ++*(_WORD *)(v7 + 2);
      v12 += 36;
      if ( v11 >= *(unsigned __int16 *)(a1 + 2) )
        goto LABEL_21;
    }
    v3 = -1073741811;
LABEL_21:
    if ( v3 >= 0 )
      goto LABEL_46;
LABEL_22:
    v20 = 0;
    if ( *(_WORD *)(v7 + 2) )
    {
      v21 = (_DWORD *)(v7 + 16);
      do
      {
        v22 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        --*(_WORD *)(v22 + 310);
        v23 = (unsigned __int8 *)(v21[5] + 128);
        v24 = KeAbPreAcquire((unsigned int)v23, 0, 0);
        v25 = v24;
        do
          v26 = __ldrex(v23);
        while ( __strex(v26 | 1, v23) );
        __dmb(0xBu);
        if ( (v26 & 1) != 0 )
          ExfAcquirePushLockExclusiveEx(v23, v24, (unsigned int)v23);
        if ( v25 )
          *(_BYTE *)(v25 + 14) |= 1u;
        *(_QWORD *)&v27 = *(_QWORD *)v21;
        if ( *(_DWORD **)(*v21 + 4) != v21 || (_DWORD *)*v28 != v21 )
          __fastfail(3u);
        *v28 = v27;
        *(_DWORD *)(v27 + 4) = v28;
        v29 = (int *)(v21[5] + 128);
        __pld(v29);
        v30 = *v29;
        v31 = *v29 - 16;
        if ( (*v29 & 0xFFFFFFF0) <= 0x10 )
          v31 = 0;
        if ( (v30 & 2) != 0 )
          goto LABEL_39;
        __dmb(0xBu);
        do
          v32 = __ldrex((unsigned int *)v29);
        while ( v32 == v30 && __strex(v31, (unsigned int *)v29) );
        if ( v32 != v30 )
LABEL_39:
          ExfReleasePushLock(v29, v30);
        v33 = KeAbPostRelease((unsigned int)v29);
        v34 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v35 = *(_WORD *)(v34 + 0x136) + 1;
        *(_WORD *)(v34 + 310) = v35;
        if ( !v35 && *(_DWORD *)(v34 + 100) != v34 + 100 )
          KiCheckForKernelApcDelivery(v33);
        ++v20;
        v21 += 9;
      }
      while ( v20 < *(unsigned __int16 *)(v7 + 2) );
    }
    ExFreePoolWithTag(v7);
  }
  else
  {
LABEL_46:
    v36 = 0;
    if ( *(_WORD *)(v7 + 2) )
    {
      v37 = v7 + 16;
      do
      {
        ++v36;
        *(_DWORD *)(v37 + 12) |= 1u;
        v37 += 36;
      }
      while ( v36 < *(unsigned __int16 *)(v7 + 2) );
    }
    *a2 = v7;
  }
  return v3;
}
