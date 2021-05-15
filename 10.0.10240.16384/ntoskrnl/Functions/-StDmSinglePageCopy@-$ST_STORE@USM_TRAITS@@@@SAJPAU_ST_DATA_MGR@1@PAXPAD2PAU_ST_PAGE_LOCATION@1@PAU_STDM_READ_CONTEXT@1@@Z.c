// -StDmSinglePageCopy@-$ST_STORE@USM_TRAITS@@@@SAJPAU_ST_DATA_MGR@1@PAXPAD2PAU_ST_PAGE_LOCATION@1@PAU_STDM_READ_CONTEXT@1@@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StDmSinglePageCopy(int a1, int a2, signed int a3, int a4, int a5, int a6)
{
  int v7; // lr
  int v8; // r0
  int v9; // r1
  int v10; // r8
  _DWORD *v11; // r10
  int v12; // r7
  int v13; // r4
  char v14; // r9
  char v15; // r3
  _DWORD *v16; // r1
  int v17; // r4
  int v18; // r1
  unsigned int v19; // r2
  unsigned int *v20; // r5
  int v21; // r0
  int v22; // r4
  unsigned int v23; // r2
  unsigned int *v24; // r4
  unsigned int v25; // r2
  int v26; // r0
  unsigned int v27; // r1
  __int16 v28; // r3
  unsigned int v29; // r2
  int v30; // r1
  unsigned int v31; // r2
  unsigned int *v32; // r10
  int v33; // r0
  int v34; // r5
  unsigned int v35; // r2
  int v37; // [sp+0h] [bp-60h]
  int v38; // [sp+4h] [bp-5Ch]
  int v39; // [sp+1Ch] [bp-44h]
  int v41; // [sp+28h] [bp-38h] BYREF
  char v42[4]; // [sp+2Ch] [bp-34h] BYREF
  int v43[12]; // [sp+30h] [bp-30h] BYREF

  v7 = *(_DWORD *)(a1 + 112);
  v8 = a5;
  v9 = *(_DWORD *)(a1 + 288);
  v10 = v7 + a3;
  v11 = (_DWORD *)a3;
  v12 = a4;
  v13 = (*(unsigned __int16 *)(a5 + 4) + *(_DWORD *)(v9 + 4) - 1) & ~(*(_DWORD *)(v9 + 4) - 1);
  v39 = a4;
  v14 = 0;
  if ( (a4 & 1) != 0 )
  {
    v12 = a4 & 0xFFFFFFFE;
    v39 = *(_DWORD *)(a6 + 20);
  }
  v15 = v10 & 3;
  if ( (v10 & 3) != 0 )
  {
    v10 &= 0xFFFFFFFC;
    v11 = (_DWORD *)(a3 & 0xFFFFFFFC);
    if ( (v15 & 2) != 0 )
    {
      memmove(v12, (int)v11, v7 + v13);
      goto LABEL_40;
    }
    if ( *(_DWORD *)(v9 + 12) )
    {
      memmove(*(_DWORD *)(a1 + 664), v10, v13);
      v10 = *(_DWORD *)(a1 + 664);
      v8 = a5;
    }
  }
  v16 = *(_DWORD **)(a1 + 288);
  if ( v16[3] )
  {
    v43[0] = *(unsigned __int16 *)(v8 + 4);
    v43[1] = *(_DWORD *)(v8 + 8);
    v43[2] = *(_DWORD *)(v8 + 12);
    v16[10] = v43;
    v16[11] = 12;
    v16[14] = v11;
    v16[15] = 16;
    if ( BCryptDecrypt(v16[4], v10, v13, (int)(v16 + 8), v37, v38, v10, v13, (int)v42) < 0 )
    {
      v17 = -1073741173;
LABEL_14:
      ST_STORE<SM_TRAITS>::StDmPageError(a1, v10, v12, a5, v17);
      goto LABEL_41;
    }
  }
  else if ( *(_BYTE *)(a1 + 72) && *v11 != RtlComputeCrc32(0, v10, *(unsigned __int16 *)(v8 + 4)) )
  {
    v17 = -1073741761;
    goto LABEL_14;
  }
  if ( (*(_DWORD *)(a1 + 72) & 0x40000) != 0 )
  {
    v18 = *(_DWORD *)(a1 + 92);
    if ( a6 == -24 )
    {
      v19 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v19 + 310);
      v20 = (unsigned int *)(v18 + 3520);
      v21 = KeAbPreAcquire(v18 + 3520, 0, 0);
      v22 = v21;
      do
        v23 = __ldrex(v20);
      while ( !v23 && __strex(0x11u, v20) );
      __dmb(0xBu);
      if ( v23 )
        ExfAcquirePushLockSharedEx(v20, v21, (unsigned int)v20);
      if ( v22 )
        *(_BYTE *)(v22 + 14) |= 1u;
    }
    else
    {
      v24 = (unsigned int *)(v18 + 3520);
      __dmb(0xBu);
      do
        v25 = __ldrex(v24);
      while ( v25 == 17 && __strex(0, v24) );
      if ( v25 != 17 )
        ExfReleasePushLockShared(v24);
      v26 = KeAbPostRelease((unsigned int)v24);
      v27 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v28 = *(_WORD *)(v27 + 0x136) + 1;
      *(_WORD *)(v27 + 310) = v28;
      if ( !v28 && *(_DWORD *)(v27 + 100) != v27 + 100 )
        KiCheckForKernelApcDelivery(v26);
    }
    v14 = 2;
  }
  v29 = *(unsigned __int16 *)(a5 + 4);
  if ( v29 >= 0x1000 )
  {
    memmove(v12, v10, v29);
  }
  else
  {
    if ( RtlDecompressBufferEx(*(_WORD *)(a1 + 272), v39, 4096, v10, v29, (int)&v41, a2) < 0 || v41 != 4096 )
    {
      v17 = -1073741116;
      v14 |= 1u;
      goto LABEL_41;
    }
    if ( v39 != v12 )
      memmove(v12, v39, 0x1000u);
  }
LABEL_40:
  v17 = 0;
LABEL_41:
  if ( (v14 & 2) != 0 )
  {
    v30 = *(_DWORD *)(a1 + 92);
    v31 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v31 + 310);
    v32 = (unsigned int *)(v30 + 3520);
    v33 = KeAbPreAcquire(v30 + 3520, 0, 0);
    v34 = v33;
    do
      v35 = __ldrex(v32);
    while ( !v35 && __strex(0x11u, v32) );
    __dmb(0xBu);
    if ( v35 )
      ExfAcquirePushLockSharedEx(v32, v33, (unsigned int)v32);
    if ( v34 )
      *(_BYTE *)(v34 + 14) |= 1u;
    *(_DWORD *)(a6 + 24) = 2;
  }
  if ( (v14 & 1) != 0 )
    ST_STORE<SM_TRAITS>::StDmPageError(a1, v10, v12, a5, v17);
  return v17;
}
