// PfpRpCHashAddEntries 
 
int __fastcall PfpRpCHashAddEntries(int a1, _DWORD *a2, unsigned __int8 *a3, int *a4, int a5)
{
  int v5; // r4
  int *v6; // r9
  _DWORD *v7; // r7
  int v8; // r10
  unsigned int v11; // r5
  unsigned int v12; // r5
  int v13; // r0
  int v14; // r4
  unsigned int v15; // r2
  unsigned int v16; // r1
  int v17; // r0
  unsigned int v18; // r1
  __int16 v19; // r3
  int v20; // r4
  int v21; // r4
  int v22; // r1
  int *v23; // r0
  int v24; // lr
  int v25; // r2
  int v26; // r3
  int v27; // r1
  unsigned int v28; // r1
  int v29; // r0
  unsigned int v30; // r1
  __int16 v31; // r3
  unsigned int v32; // r0
  unsigned int v34; // [sp+0h] [bp-30h]
  unsigned int v35; // [sp+4h] [bp-2Ch]
  _DWORD *v36; // [sp+8h] [bp-28h] BYREF
  int v37; // [sp+Ch] [bp-24h]

  v5 = a2[1];
  v6 = a4;
  v34 = 1 << v5;
  v7 = 0;
  v8 = a5;
  v11 = (unsigned int)a4 + (a5 << v5);
  v35 = v11;
  v36 = 0;
  v37 = a1;
  if ( a5 )
  {
    v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v12 + 308);
    v13 = KeAbPreAcquire((unsigned int)a3, 0, 0);
    v14 = v13;
    do
      v15 = __ldrex(a3);
    while ( __strex(v15 | 1, a3) );
    __dmb(0xBu);
    if ( (v15 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(a3, v13, (unsigned int)a3);
    v11 = v35;
    if ( v14 )
      *(_BYTE *)(v14 + 14) |= 1u;
  }
  if ( (unsigned int)v6 >= v11 )
    goto LABEL_35;
  do
  {
    if ( (unsigned int)(2 * a2[3]) >= a2[2] )
    {
      __dmb(0xBu);
      do
        v16 = __ldrex((unsigned int *)a3);
      while ( __strex(v16 - 1, (unsigned int *)a3) );
      if ( (v16 & 2) != 0 && (v16 & 4) == 0 )
        ExfTryToWakePushLock((unsigned int *)a3);
      v17 = KeAbPostRelease((unsigned int)a3);
      v18 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v19 = *(_WORD *)(v18 + 0x134) + 1;
      *(_WORD *)(v18 + 308) = v19;
      if ( !v19 && *(_DWORD *)(v18 + 100) != v18 + 100 && !*(_WORD *)(v18 + 310) )
        KiCheckForKernelApcDelivery(v17);
      v20 = PfpRpCHashGrow(v37, a2, a3, &v36);
      if ( v20 < 0 )
      {
        v7 = v36;
        goto LABEL_46;
      }
    }
    v21 = *v6;
    v22 = a2[2];
    if ( !v22 )
    {
      v23 = 0;
LABEL_30:
      memmove((int)v23, (int)v6, v34);
      ++a2[3];
      goto LABEL_31;
    }
    v24 = a2[1];
    v25 = (37
         * (37 * (37 * ((unsigned __int8)*v6 + 11623883) + (unsigned __int8)BYTE1(*v6)) + (unsigned __int8)BYTE2(*v6))
         + HIBYTE(*v6)) & (v22 - 1);
    v23 = (int *)(*a2 + (v25 << v24));
    v26 = *v23;
    v27 = 0;
    if ( *v23 )
    {
      do
      {
        if ( v26 == v21 )
          break;
        if ( !v27 )
        {
          v27 = -1640531535 * v21;
          if ( ((-1640531535 * v21) & 1) == 0 )
            ++v27;
        }
        v25 = (v25 + v27) & (a2[2] - 1);
        v23 = (int *)((v25 << v24) + *a2);
        v26 = *v23;
      }
      while ( *v23 );
      v8 = a5;
      v11 = v35;
    }
    if ( !*v23 )
      goto LABEL_30;
LABEL_31:
    v6 = (int *)((char *)v6 + v34);
  }
  while ( (unsigned int)v6 < v11 );
  v7 = v36;
LABEL_35:
  if ( v8 )
  {
    __dmb(0xBu);
    do
      v28 = __ldrex((unsigned int *)a3);
    while ( __strex(v28 - 1, (unsigned int *)a3) );
    if ( (v28 & 2) != 0 && (v28 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)a3);
    v29 = KeAbPostRelease((unsigned int)a3);
    v30 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v31 = *(_WORD *)(v30 + 0x134) + 1;
    *(_WORD *)(v30 + 308) = v31;
    if ( !v31 && *(_DWORD *)(v30 + 100) != v30 + 100 && !*(_WORD *)(v30 + 310) )
      KiCheckForKernelApcDelivery(v29);
  }
  v20 = 0;
LABEL_46:
  while ( 1 )
  {
    v32 = (unsigned int)v7;
    if ( !v7 )
      break;
    v7 = (_DWORD *)*v7;
    ExFreePoolWithTag(v32);
  }
  return v20;
}
