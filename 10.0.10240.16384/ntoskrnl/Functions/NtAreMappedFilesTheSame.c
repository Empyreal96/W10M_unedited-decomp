// NtAreMappedFilesTheSame 
 
int __fastcall NtAreMappedFilesTheSame(unsigned int a1, unsigned int a2, int a3, int a4)
{
  int v6; // r9
  int v7; // r0
  _DWORD *v8; // r5
  _DWORD *v9; // r6
  unsigned __int8 *v11; // r7
  int v12; // r0
  int v13; // r4
  unsigned int v14; // r2
  int v15; // r4
  unsigned int *v16; // r7
  unsigned int v17; // r1
  int v18; // r0
  unsigned __int8 *v19; // r7
  int v20; // r0
  unsigned int v21; // r2
  int *v22; // r3
  int *v23; // r2
  int v24; // r8
  int v25; // r7
  int v26[8]; // [sp+0h] [bp-20h] BYREF

  v26[0] = a3;
  v26[1] = a4;
  v6 = __mrc(15, 0, 13, 0, 3);
  v7 = MiObtainReferencedVad(a1, v26);
  v8 = (_DWORD *)v7;
  if ( !v7 )
    JUMPOUT(0x7D40BC);
  MiUnlockVad(v6 & 0xFFFFFFC0, v7);
  v9 = (_DWORD *)MiObtainReferencedVad(a2, v26);
  if ( !v9 )
    return sub_7D40AC();
  if ( v8 == v9 )
  {
    MiDereferenceVad((int)v8);
    MiUnlockAndDereferenceVad((int)v9);
    v15 = 0;
  }
  else
  {
    if ( MiVadIsCfgBitmap(v8) != 1 && MiVadIsCfgBitmap(v9) != 1 )
    {
      if ( a1 > a2 )
      {
        v19 = (unsigned __int8 *)(v8 + 6);
        v20 = KeAbPreAcquire((unsigned int)(v8 + 6), 0, 0);
        v13 = v20;
        do
          v21 = __ldrex(v19);
        while ( __strex(v21 | 1, v19) );
        __dmb(0xBu);
        if ( (v21 & 1) != 0 )
          ExfAcquirePushLockExclusiveEx(v8 + 6, v20, (unsigned int)(v8 + 6));
        if ( !v13 )
          goto LABEL_13;
      }
      else
      {
        MiUnlockVad(v6 & 0xFFFFFFC0, (int)v9);
        MiLockVad(v6 & 0xFFFFFFC0, (int)v8);
        v11 = (unsigned __int8 *)(v9 + 6);
        v12 = KeAbPreAcquire((unsigned int)(v9 + 6), 0, 0);
        v13 = v12;
        do
          v14 = __ldrex(v11);
        while ( __strex(v14 | 1, v11) );
        __dmb(0xBu);
        if ( (v14 & 1) != 0 )
          ExfAcquirePushLockExclusiveEx(v9 + 6, v12, (unsigned int)(v9 + 6));
        if ( !v13 )
          goto LABEL_13;
      }
      *(_BYTE *)(v13 + 14) |= 1u;
LABEL_13:
      if ( MiVadDeleted((int)v8) || MiVadDeleted((int)v9) )
      {
        v15 = -1073741503;
      }
      else if ( (v8[7] & 0x8000) == 0
             && (v9[7] & 0x8000) == 0
             && (v22 = (int *)v8[11]) != 0
             && (v23 = (int *)v9[11]) != 0
             && (v24 = *v22, v25 = *v23, *v22)
             && v25
             && *(_DWORD *)(v24 + 32)
             && *(_DWORD *)(v25 + 32) )
      {
        v15 = -1073741612;
        v18 = MI_REFERENCE_CONTROL_AREA_FILE(*v23);
        if ( v24 == *(_DWORD *)(*(_DWORD *)(v18 + 20) + 8) )
          v15 = 0;
        MI_DEREFERENCE_CONTROL_AREA_FILE(v25, v18);
      }
      else
      {
        v15 = -1073741800;
      }
      v16 = v9 + 6;
      __dmb(0xBu);
      do
        v17 = __ldrex(v16);
      while ( __strex(v17 - 1, v16) );
      if ( (v17 & 2) != 0 && (v17 & 4) == 0 )
        ExfTryToWakePushLock(v9 + 6);
      KeAbPostRelease((unsigned int)(v9 + 6));
      MiUnlockAndDereferenceVad((int)v8);
      MiLockVad(v6 & 0xFFFFFFC0, (int)v9);
      MiUnlockAndDereferenceVad((int)v9);
      return v15;
    }
    MiUnlockAndDereferenceVad((int)v9);
    MiLockVad(v6 & 0xFFFFFFC0, (int)v8);
    MiUnlockAndDereferenceVad((int)v8);
    v15 = -1073741800;
  }
  return v15;
}
