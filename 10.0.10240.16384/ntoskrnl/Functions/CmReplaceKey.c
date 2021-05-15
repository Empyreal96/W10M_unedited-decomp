// CmReplaceKey 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall CmReplaceKey(_DWORD *a1, int a2, int a3, int a4)
{
  int v6; // r4
  int v7; // r2
  int v8; // r3
  _DWORD *v9; // r6
  int v10; // r2
  int v11; // r3
  _DWORD *v12; // r7
  int v13; // r0
  int v14; // r8
  unsigned int v15; // r2
  int v16; // r1 OVERLAPPED
  _DWORD *v17; // r2 OVERLAPPED
  int v18; // r1
  unsigned int v19; // r0
  unsigned int v20; // r2
  int v22; // [sp+Ch] [bp-234h]
  int v23[2]; // [sp+10h] [bp-230h] BYREF
  _DWORD *v24; // [sp+18h] [bp-228h] BYREF
  char v25[544]; // [sp+20h] [bp-220h] BYREF

  LOBYTE(v23[0]) = 0;
  v6 = CmpCmdHiveOpen(a3, 0, (int)v23, (int *)&v24, 16777217, 0, 0, v22, v23[0], v23[1], (char)v24);
  if ( v6 >= 0 )
  {
    while ( 1 )
    {
      CmpLockRegistry();
      ExAcquireResourceExclusiveLite(a1[468], 1, v7, v8);
      v9 = v24;
      if ( (a1[23] & 4) != 0 )
      {
        v6 = -1073741611;
        goto LABEL_19;
      }
      if ( (a1[807] & 0x20) != 0 )
      {
        v6 = -1073741811;
        goto LABEL_19;
      }
      if ( (a1[828] & 1) == 0 )
        break;
      ExReleaseResourceLite(a1[468]);
      CmpUnlockRegistry();
      if ( CmpFlushHive((int)a1, 4) < 0 )
      {
        v6 = -1073741670;
        CmpLockRegistry();
        ExAcquireResourceExclusiveLite(a1[468], 1, v10, v11);
        goto LABEL_19;
      }
    }
    if ( a1 == off_60E8A4 )
    {
      v6 = CmpPreserveSystemHiveData(a1, v24);
      if ( v6 < 0 )
        goto LABEL_19;
      if ( !HvSyncHive(v9) )
        goto LABEL_10;
    }
    v6 = CmpCmdRenameHive(a1[444], v25, a4, 512, 0);
    if ( v6 >= 0 )
    {
      a1[23] |= 4u;
      v6 = CmpCmdRenameHive(v9[444], 0, v25, 0, 0);
      if ( v6 < 0 || (v6 = ZwFlushBuffersFile(), v6 < 0) )
      {
        if ( CmpCmdRenameHive(a1[444], 0, v25, 0, 0) < 0 )
LABEL_10:
          v6 = -1073741492;
      }
    }
LABEL_19:
    ExReleaseResourceLite(a1[468]);
    CmpUnlockRegistry();
    CmpDestroySecurityCache(v9);
    v12 = v9 + 808;
    if ( (_DWORD *)v9[808] != v9 + 808 )
    {
      v13 = KeAbPreAcquire((unsigned int)&CmpHiveListHeadLock, 0, 0);
      v14 = v13;
      do
        v15 = __ldrex((unsigned __int8 *)&CmpHiveListHeadLock);
      while ( __strex(v15 | 1, (unsigned __int8 *)&CmpHiveListHeadLock) );
      __dmb(0xBu);
      if ( (v15 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx(&CmpHiveListHeadLock, v13, (unsigned int)&CmpHiveListHeadLock);
      if ( v14 )
        *(_BYTE *)(v14 + 14) |= 1u;
      *(_QWORD *)&v16 = *(_QWORD *)v12;
      if ( *(_DWORD **)(*v12 + 4) != v12 || (_DWORD *)*v17 != v12 )
        __fastfail(3u);
      *v17 = v16;
      *(_DWORD *)(v16 + 4) = v17;
      __pld(&CmpHiveListHeadLock);
      v18 = CmpHiveListHeadLock;
      v19 = CmpHiveListHeadLock - 16;
      if ( (CmpHiveListHeadLock & 0xFFFFFFF0) <= 0x10 )
        v19 = 0;
      if ( (CmpHiveListHeadLock & 2) != 0 )
        goto LABEL_35;
      __dmb(0xBu);
      do
        v20 = __ldrex((unsigned int *)&CmpHiveListHeadLock);
      while ( v20 == v18 && __strex(v19, (unsigned int *)&CmpHiveListHeadLock) );
      if ( v20 != v18 )
LABEL_35:
        ExfReleasePushLock(&CmpHiveListHeadLock, v18);
      KeAbPostRelease((unsigned int)&CmpHiveListHeadLock);
    }
    HvFreeHive((int)v9, 1);
    if ( v6 < 0 )
      CmpCmdHiveClose((int)v9);
    CmpDereferenceHive(v9);
  }
  return v6;
}
