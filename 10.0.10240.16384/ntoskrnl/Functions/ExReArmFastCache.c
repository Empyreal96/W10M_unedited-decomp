// ExReArmFastCache 
 
int ExReArmFastCache()
{
  unsigned int v0; // r2
  int v1; // r0
  int v2; // r5
  unsigned int v3; // r1
  int v4; // r3
  int v5; // r5
  int v6; // r6
  __int64 v7; // r8
  int v8; // r5
  int v9; // r0
  __int64 *v10; // r1
  int v11; // r7
  int v12; // t1
  unsigned int i; // r1
  int v14; // r3
  int *v15; // r3
  int v16; // r2
  int v17; // r3
  int *v18; // r7
  int v19; // lr
  int v20; // t1
  unsigned int v21; // r0
  int v22; // r0
  unsigned int v23; // r1
  __int16 v24; // r3
  int v26[2]; // [sp+10h] [bp-48h] BYREF
  __int64 v27; // [sp+18h] [bp-40h] BYREF
  __int64 v28; // [sp+20h] [bp-38h] BYREF
  int v29; // [sp+28h] [bp-30h]
  int v30; // [sp+2Ch] [bp-2Ch]
  int v31; // [sp+30h] [bp-28h]
  int v32; // [sp+34h] [bp-24h]

  v0 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v0 + 308);
  v1 = KeAbPreAcquire((unsigned int)&ExpFastCacheUpdateLock, 0, 0);
  v2 = v1;
  do
    v3 = __ldrex((unsigned __int8 *)&ExpFastCacheUpdateLock);
  while ( __strex(v3 | 1, (unsigned __int8 *)&ExpFastCacheUpdateLock) );
  __dmb(0xBu);
  if ( (v3 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&ExpFastCacheUpdateLock, v1, (unsigned int)&ExpFastCacheUpdateLock);
  if ( v2 )
    *(_BYTE *)(v2 + 14) |= 1u;
  v4 = ExpFastCacheReArmed;
  __dmb(0xBu);
  if ( v4 )
  {
    v5 = -1073700219;
  }
  else
  {
    v6 = 0;
    while ( 1 )
    {
      v5 = sub_8A10B0(v6, 0);
      if ( v5 < 0 )
        break;
      if ( (unsigned int)++v6 >= 5 )
      {
        __dmb(0xBu);
        ExpFastCacheReArmed = 1;
        if ( dword_922C18 || (v5 = sub_7B5F04((int)&dword_8C8214, &dword_922C18), v5 >= 0) )
        {
          v7 = qword_922C10;
          v8 = 0;
          v9 = 0;
          v10 = &v27;
          v27 = qword_922C10;
          v11 = 8;
          do
          {
            v12 = *(unsigned __int8 *)v10;
            v10 = (__int64 *)((char *)v10 + 1);
            v9 = __ROR4__(-23737705 * __ROR4__(-23737705 * __ROR4__(-23737705 * (v12 - 23737705 + v9), 21), 21), 21);
            v8 += v12 - 23737705 + v9;
            --v11;
          }
          while ( v11 );
          for ( i = 0; i < 5; ++i )
          {
            v14 = ExpFastCacheReArmed;
            __dmb(0xBu);
            if ( v14 || (v15 = &dword_920288[10 * i], (v16 = v15[1]) == 0) || v15[5] )
            {
              v17 = 0;
              v26[0] = 0;
            }
            else
            {
              v26[0] = *(_DWORD *)(v16 + 16);
              v17 = *(_DWORD *)(v16 + 20);
            }
            v26[1] = v17;
            v18 = v26;
            v19 = 8;
            do
            {
              v20 = *(unsigned __int8 *)v18;
              v18 = (int *)((char *)v18 + 1);
              v9 = __ROR4__(-23737705 * __ROR4__(-23737705 * __ROR4__(-23737705 * (v20 - 23737705 + v9), 21), 21), 21);
              v8 += v20 - 23737705 + v9;
              --v19;
            }
            while ( v19 );
          }
          v31 = 0;
          v32 = 0;
          v29 = v8;
          v30 = v9;
          v28 = v7;
          v5 = CmSetValueKey((_DWORD *)dword_922C18, (unsigned __int16 *)&dword_8C81C4, 3, (int)&v28, 0x18u, 0, 0);
        }
        break;
      }
    }
  }
  __dmb(0xBu);
  do
    v21 = __ldrex(&ExpFastCacheUpdateLock);
  while ( __strex(v21 - 1, &ExpFastCacheUpdateLock) );
  if ( (v21 & 2) != 0 && (v21 & 4) == 0 )
    ExfTryToWakePushLock(&ExpFastCacheUpdateLock);
  v22 = KeAbPostRelease((unsigned int)&ExpFastCacheUpdateLock);
  v23 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v24 = *(_WORD *)(v23 + 0x134) + 1;
  *(_WORD *)(v23 + 308) = v24;
  if ( !v24 && *(_DWORD *)(v23 + 100) != v23 + 100 && !*(_WORD *)(v23 + 310) )
    KiCheckForKernelApcDelivery(v22);
  return v5;
}
