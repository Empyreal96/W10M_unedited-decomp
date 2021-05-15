// ExpWnfWriteStateData 
 
int __fastcall ExpWnfWriteStateData(_DWORD *a1, int a2, unsigned int a3, int a4, int a5)
{
  _DWORD *v7; // r5
  int v8; // r8
  unsigned __int8 *v9; // r6
  int v10; // r0
  int v11; // r4
  unsigned int v12; // r2
  unsigned int v13; // r1
  _DWORD *v15; // r4
  unsigned int v16; // r1
  int v17; // r3
  int v18; // r0
  int v19; // r4
  int v20; // r0
  int v21; // r4
  unsigned int v22; // r2
  unsigned int i; // r6
  unsigned int *v24; // r2
  unsigned int v25; // r1
  unsigned int *v26; // r4
  unsigned int v27; // r1
  unsigned int v30; // [sp+Ch] [bp-7Ch]
  unsigned int v31; // [sp+10h] [bp-78h]
  int v32; // [sp+14h] [bp-74h]
  _BYTE v34[96]; // [sp+28h] [bp-60h] BYREF

  v7 = a1;
  v32 = 0;
  if ( a1[15] )
    ExpWnfComposeValueName(a1[6], a1[7]);
  v8 = 0;
  v30 = 0;
  v31 = 0;
  v9 = (unsigned __int8 *)(v7 + 12);
  v10 = KeAbPreAcquire((unsigned int)(v7 + 12), 0, 0);
  v11 = v10;
  do
    v12 = __ldrex(v9);
  while ( __strex(v12 | 1, v9) );
  __dmb(0xBu);
  if ( (v12 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(v7 + 12, v10, (unsigned int)(v7 + 12));
  if ( v11 )
    *(_BYTE *)(v11 + 14) |= 1u;
  if ( a5 && v7[14] != a4 )
  {
    __dmb(0xBu);
    do
      v13 = __ldrex((unsigned int *)v9);
    while ( __strex(v13 - 1, (unsigned int *)v9) );
    if ( (v13 & 2) != 0 && (v13 & 4) == 0 )
      ExfTryToWakePushLock(v7 + 12);
    KeAbPostRelease((unsigned int)(v7 + 12));
    return -1073741823;
  }
  v15 = (_DWORD *)v7[13];
  if ( v15 == (_DWORD *)1 )
    v15 = 0;
  if ( v15 )
  {
    if ( v15[1] >= a3 )
      goto LABEL_50;
  }
  else if ( !v7[15] && !a3 )
  {
    goto LABEL_50;
  }
  __dmb(0xBu);
  do
    v16 = __ldrex((unsigned int *)v9);
  while ( __strex(v16 - 1, (unsigned int *)v9) );
  if ( (v16 & 2) != 0 && (v16 & 4) == 0 )
    ExfTryToWakePushLock(v7 + 12);
  KeAbPostRelease((unsigned int)(v7 + 12));
  if ( ((v7[6] >> 4) & 3) != 3 || PsInitialSystemProcess == v7[21] )
  {
    v8 = ExAllocatePoolWithTag(1, a3 + 16, 543583831);
    v30 = v8;
  }
  else
  {
    v17 = __mrc(15, 0, 13, 0, 3);
    v18 = v7[21];
    if ( v18 == *(_DWORD *)((v17 & 0xFFFFFFC0) + 0x74) )
    {
      v19 = 0;
    }
    else
    {
      v19 = 1;
      KiStackAttachProcess(v18, 0, (int)v34);
    }
    v8 = ExAllocatePoolWithQuotaTag(9u, a3 + 16, 543583831);
    v30 = v8;
    if ( v19 )
      KiUnstackDetachProcess((unsigned int)v34, 0);
  }
  if ( !v8 )
    return -1073741670;
  *(_DWORD *)v8 = 0;
  *(_DWORD *)(v8 + 4) = 0;
  *(_DWORD *)(v8 + 8) = 0;
  *(_DWORD *)(v8 + 12) = 0;
  *(_WORD *)v8 = 2308;
  *(_WORD *)(v8 + 2) = 16;
  *(_DWORD *)(v8 + 4) = a3;
  v20 = KeAbPreAcquire((unsigned int)(v7 + 12), 0, 0);
  v21 = v20;
  do
    v22 = __ldrex(v9);
  while ( __strex(v22 | 1, v9) );
  __dmb(0xBu);
  if ( (v22 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(v7 + 12, v20, (unsigned int)(v7 + 12));
  if ( v21 )
    *(_BYTE *)(v21 + 14) |= 1u;
  v15 = (_DWORD *)v7[13];
  if ( v15 == (_DWORD *)1 )
    v15 = 0;
  if ( !v15 || v15[1] < a3 )
    v15 = (_DWORD *)v8;
LABEL_50:
  for ( i = v7[14] + 1; !i; i = 1 )
    ;
  if ( !v15 )
  {
    v7[13] = 1;
LABEL_60:
    __dmb(0xBu);
    v24 = v7 + 14;
    do
      v25 = __ldrex(v24);
    while ( __strex(i, v24) );
    __dmb(0xBu);
    goto LABEL_63;
  }
  memmove((int)(v15 + 4), a2, a3);
  v15[2] = a3;
  v15[3] = i;
  if ( !v7[15] || (v32 = ZwSetValueKey(), v32 >= 0) )
  {
    if ( v15 == (_DWORD *)v8 )
    {
      v31 = v7[13];
      v7[13] = v15;
      v30 = 0;
    }
    goto LABEL_60;
  }
  v31 = v7[13];
  v7[13] = 0;
LABEL_63:
  v26 = a1 + 12;
  __dmb(0xBu);
  do
    v27 = __ldrex(v26);
  while ( __strex(v27 - 1, v26) );
  if ( (v27 & 2) != 0 && (v27 & 4) == 0 )
    ExfTryToWakePushLock(v26);
  KeAbPostRelease((unsigned int)v26);
  if ( v31 && v31 != 1 )
    ExFreePoolWithTag(v31);
  if ( v30 )
    ExFreePoolWithTag(v30);
  return v32;
}
