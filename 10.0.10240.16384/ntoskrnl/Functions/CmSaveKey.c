// CmSaveKey 
 
int __fastcall CmSaveKey(_DWORD *a1, int a2, int a3)
{
  _DWORD *v4; // r4
  int v7; // r5
  _DWORD *v8; // r6
  int v9; // r2
  int v10; // r3
  int v11; // r5
  unsigned int *v12; // r8
  unsigned int v13; // r0
  unsigned int v14; // r1
  int v15; // r5
  int v16; // r0
  unsigned int v17; // r4
  unsigned int v18; // r1
  int v19; // r1
  int v20; // r8
  int v21; // r1
  int v23; // [sp+4h] [bp-4Ch]
  char v24[16]; // [sp+10h] [bp-40h] BYREF
  char v25[48]; // [sp+20h] [bp-30h] BYREF

  v4 = (_DWORD *)a1[5];
  if ( v4 == CmpMasterHive )
    return -1073741790;
  v7 = CmpUuidCreate((int)v25);
  if ( v7 >= 0 )
  {
    v7 = CmpUuidCreate((int)v24);
    if ( v7 >= 0 )
    {
      v8 = (_DWORD *)CmpCreateTemporaryHive();
      if ( !v8 )
        return -1073741670;
      CmpLockRegistry();
      CmpLockKcbShared(a1);
      CmpTraceHiveSaveStart((int)a1);
      v10 = a1[1];
      if ( (v10 & 0x20000) != 0 )
      {
        v7 = -1073741444;
      }
      else
      {
        ExAcquireResourceExclusiveLite(v4[468], 1, v9, v10);
        v11 = a1[6];
        if ( (v4[23] & 2) != 0 && v4[11] && v4[444] )
        {
          v12 = v4 + 458;
          __pld(v4 + 458);
          v13 = v4[458] & 0xFFFFFFFE;
          do
            v14 = __ldrex(v12);
          while ( v14 == v13 && __strex(v13 + 2, v12) );
          __dmb(0xBu);
          if ( v14 == v13 )
            v15 = 1;
          else
            v15 = ExfAcquireRundownProtection(v4 + 458);
          ExReleaseResourceLite(v4[468]);
          CmpUnlockKcb(a1);
          CmpUnlockRegistry();
          if ( v15 )
          {
            v16 = CmpSaveKeyByFileCopy(v4, a2);
            __pld(v12);
            v7 = v16;
            v17 = *v12 & 0xFFFFFFFE;
            __dmb(0xBu);
            do
              v18 = __ldrex(v12);
            while ( v18 == v17 && __strex(v17 - 2, v12) );
            if ( v18 != v17 )
              ExfReleaseRundownProtection((unsigned __int8 *)v12);
            if ( v7 >= 0 )
              CmpTraceHiveSaveFileCopied();
          }
          else
          {
            v7 = -1073741444;
          }
          goto LABEL_33;
        }
        v19 = a1[6];
        *(_DWORD *)(v8[8] + 24) = a3;
        v8[37] = a3;
        v20 = CmpCopyKeyPartial((int)v4, v19, (int)v8, 0xFFFFFFFF, 6, v23, 0);
        if ( v20 != -1 )
        {
          CmpTraceHiveSaveTreeCopied();
          *(_DWORD *)(v8[8] + 36) = v20;
          if ( CmpCopySyncTree((int)v4, v11, (int)v8, v20) )
          {
            ExReleaseResourceLite(v4[468]);
            CmpUnlockKcb(a1);
            CmpUnlockRegistry();
            v8[446] = a2;
            v7 = HvWriteExternal(v8);
            if ( v7 >= 0 )
              CmpTraceHiveSaveFileWritten();
            goto LABEL_33;
          }
        }
        v7 = -1073741670;
        ExReleaseResourceLite(v4[468]);
      }
      CmpUnlockKcb(a1);
      CmpUnlockRegistry();
LABEL_33:
      v8[446] = 0;
      CmpDestroyTemporaryHive(v8);
      CmpTraceHiveSaveStop(v7, v21);
      return v7;
    }
  }
  return v7;
}
