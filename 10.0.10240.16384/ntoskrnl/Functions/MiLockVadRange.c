// MiLockVadRange 
 
int __fastcall MiLockVadRange(int a1, int a2, unsigned int a3)
{
  unsigned int v3; // r4
  int v4; // r6
  int v5; // r7
  int v6; // r5
  int v7; // r9
  _DWORD *v8; // r8
  _DWORD *v9; // r4
  int *v10; // r10
  unsigned int v11; // r6
  _DWORD *v12; // r2
  int v13; // r3
  _DWORD *i; // r3
  unsigned __int8 *v16; // r9
  int v17; // r0
  int v18; // r7
  unsigned int v19; // r2
  _DWORD *v20; // r3
  unsigned int v21; // r5
  _DWORD *v22; // r2
  _DWORD *j; // r3
  int v24; // r3
  unsigned int *v25; // r6
  unsigned int v26; // r1
  int *v27; // r7
  int v28; // r1
  int v29; // t1
  unsigned __int8 *v30; // r6
  int v31; // r0
  int v32; // r4
  unsigned int v33; // r2
  int v34; // [sp+4h] [bp-34h]
  int v35; // [sp+8h] [bp-30h]
  int v36; // [sp+Ch] [bp-2Ch] BYREF
  unsigned int v37; // [sp+10h] [bp-28h]
  int v38; // [sp+14h] [bp-24h]
  int v39; // [sp+18h] [bp-20h]

  v36 = 0;
  v37 = a3;
  v3 = a2;
  v4 = a1;
  v38 = a1;
  v39 = a2;
  v5 = __mrc(15, 0, 13, 0, 3);
  v6 = 0;
  v7 = 0;
  v34 = 0;
  v35 = v5;
  LOCK_ADDRESS_SPACE_SHARED(v5 & 0xFFFFFFC0, a1);
LABEL_2:
  if ( (*(_DWORD *)(v4 + 192) & 0x20) != 0 )
    return 0;
  if ( v3 == -1 )
  {
    v20 = *(_DWORD **)(v4 + 636);
    v8 = 0;
    while ( v20 )
    {
      v8 = v20;
      v20 = (_DWORD *)*v20;
    }
  }
  else
  {
    v8 = MiLocateAddress(v3);
  }
  v9 = v8;
  v10 = &v36;
  while ( v9 )
  {
    v11 = v9[1];
    v12 = v9;
    if ( v11 )
    {
      for ( i = *(_DWORD **)v11; i; i = (_DWORD *)*i )
        v11 = (unsigned int)i;
    }
    else
    {
      v13 = v9[2];
      while ( 1 )
      {
        v11 = v13 & 0xFFFFFFFC;
        if ( (v13 & 0xFFFFFFFC) == 0 || *(_DWORD **)v11 == v12 )
          break;
        v13 = *(_DWORD *)(v11 + 8);
        v12 = (_DWORD *)v11;
      }
    }
    if ( v37 != -1 )
    {
      if ( v37 > v9[4] << 12 )
        return sub_7D41C8();
      v11 = 0;
    }
    if ( MiVadIsCfgBitmap(v9) == 1 )
    {
      ++v7;
      *v10 = (int)v9;
      v34 = v7;
      ++v10;
    }
    else
    {
      if ( v6 )
      {
        v16 = (unsigned __int8 *)(v9 + 6);
        v17 = KeAbPreAcquire((unsigned int)(v9 + 6), 0, 0);
        v18 = v17;
        do
          v19 = __ldrex(v16);
        while ( __strex(v19 | 1, v16) );
        __dmb(0xBu);
        if ( (v19 & 1) != 0 )
          ExfAcquirePushLockExclusiveEx(v9 + 6, v17, (unsigned int)(v9 + 6));
        v7 = v34;
        if ( v18 )
          *(_BYTE *)(v18 + 14) |= 1u;
        v5 = v35;
      }
      else
      {
        MiLockVad(v5 & 0xFFFFFFC0, (int)v9);
      }
      if ( MiVadDeleted((int)v9) )
      {
        MiReferenceVad((int)v9);
        if ( v8 != v9 )
        {
          do
          {
            v21 = v8[1];
            v22 = v8;
            if ( v21 )
            {
              for ( j = *(_DWORD **)v21; j; j = (_DWORD *)*j )
                v21 = (unsigned int)j;
            }
            else
            {
              v24 = v8[2];
              while ( 1 )
              {
                v21 = v24 & 0xFFFFFFFC;
                if ( (v24 & 0xFFFFFFFC) == 0 || *(_DWORD **)v21 == v22 )
                  break;
                v24 = *(_DWORD *)(v21 + 8);
                v22 = (_DWORD *)v21;
              }
            }
            if ( !MiVadIsCfgBitmap(v8) )
            {
              v25 = v8 + 6;
              __dmb(0xBu);
              do
                v26 = __ldrex(v25);
              while ( __strex(v26 - 1, v25) );
              if ( (v26 & 2) != 0 && (v26 & 4) == 0 )
                ExfTryToWakePushLock(v8 + 6);
              KeAbPostRelease((unsigned int)(v8 + 6));
            }
            v8 = (_DWORD *)v21;
          }
          while ( (_DWORD *)v21 != v9 );
        }
        v4 = v38;
        UNLOCK_ADDRESS_SPACE_SHARED_UNORDERED(v5 & 0xFFFFFFC0, v38);
        if ( MiVadDeleted((int)v9) )
          MiWaitForVadDeletion((int)v9);
        MiUnlockAndDereferenceVad((int)v9);
        v6 = 0;
        v7 = 0;
        v34 = 0;
        LOCK_ADDRESS_SPACE_SHARED(v5 & 0xFFFFFFC0, v4);
        v3 = v39;
        goto LABEL_2;
      }
      ++v6;
    }
    v9 = (_DWORD *)v11;
  }
  if ( v7 )
  {
    v27 = &v36;
    do
    {
      v29 = *v27++;
      v28 = v29;
      if ( v6 )
      {
        v30 = (unsigned __int8 *)(v28 + 24);
        v31 = KeAbPreAcquire(v28 + 24, 0, 0);
        v32 = v31;
        do
          v33 = __ldrex(v30);
        while ( __strex(v33 | 1, v30) );
        __dmb(0xBu);
        if ( (v33 & 1) != 0 )
          ExfAcquirePushLockExclusiveEx(v30, v31, (unsigned int)v30);
        if ( v32 )
          *(_BYTE *)(v32 + 14) |= 1u;
      }
      else
      {
        MiLockVad(v35 & 0xFFFFFFC0, v28);
      }
      ++v6;
      --v7;
    }
    while ( v7 );
  }
  return v6;
}
