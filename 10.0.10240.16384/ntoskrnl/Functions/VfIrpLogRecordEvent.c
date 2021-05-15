// VfIrpLogRecordEvent 
 
int __fastcall VfIrpLogRecordEvent(int result, int a2, int a3)
{
  unsigned int v5; // r0
  _DWORD *v6; // r0
  int v7; // r7
  unsigned int v8; // r2
  int v9; // r0
  _DWORD *v10; // r9
  int v11; // r4
  int v12; // r3
  __int64 v13; // r0
  int v14; // r2
  int v15; // r3
  int v16; // r1
  int v17; // r2
  int v18; // r3
  int v19; // r3
  _DWORD *v20; // [sp+0h] [bp-50h] BYREF
  char var48[76]; // [sp+8h] [bp-48h] BYREF
  int vars4; // [sp+54h] [bp+4h]

  if ( (result & 0x400) != 0 )
  {
    if ( ViIrpLogDdiLock != 2 )
    {
      __dmb(0xBu);
      do
        v5 = __ldrex((unsigned int *)&ViIrpLogDdiLock);
      while ( !v5 && __strex(1u, (unsigned int *)&ViIrpLogDdiLock) );
      __dmb(0xBu);
      if ( !v5 )
      {
        v6 = (_DWORD *)ExAllocatePoolWithTag(512, 16, 2001299030);
        if ( v6 )
        {
          v6[2] = ViIrpLogExposeWmiCallback;
          v6[3] = v6;
          *v6 = 0;
          ExQueueWorkItem(v6, 1);
        }
        else
        {
          ViIrpLogDdiLock = 0;
        }
      }
    }
    v7 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented((int)&ViIrpLogDatabaseLock);
    }
    else
    {
      do
        v8 = __ldrex((unsigned int *)&ViIrpLogDatabaseLock);
      while ( __strex(1u, (unsigned int *)&ViIrpLogDatabaseLock) );
      __dmb(0xBu);
      if ( v8 )
        KxWaitForSpinLockAndAcquire((unsigned int *)&ViIrpLogDatabaseLock);
    }
    if ( IovUtilIsDeviceObjectMarked(a2, 0) )
    {
      if ( (dword_682604 & 0x10000) == 0 )
      {
        __dmb(0xBu);
        ViIrpLogDatabaseLock = 0;
        return KfLowerIrql(v7);
      }
LABEL_34:
      KiReleaseSpinLockInstrumented(&ViIrpLogDatabaseLock, vars4);
      return KfLowerIrql(v7);
    }
    v9 = ViIrpLogDatabaseFindPointer(a2, &v20);
    v10 = v20;
    v11 = v9;
    if ( *v20 )
    {
      if ( (dword_682604 & 0x10000) != 0 )
        goto LABEL_34;
LABEL_35:
      __dmb(0xBu);
      ViIrpLogDatabaseLock = 0;
      return KfLowerIrql(v7);
    }
    if ( !v9 )
    {
      v11 = ExAllocatePoolWithTag(512, 832, 1699309142);
      if ( !v11 )
        goto LABEL_33;
      ObfReferenceObject(a2);
      *(_DWORD *)(v11 + 12) = 0;
      *(_DWORD *)v11 = a2;
      v12 = *(_DWORD *)(a2 + 44);
      HIDWORD(v13) = v10 + 1;
      *(_DWORD *)(v11 + 24) = 0;
      *(_DWORD *)(v11 + 16) = v12;
      *(_DWORD *)(v11 + 20) = 20;
      LODWORD(v13) = v10[1];
      v14 = v11 + 4;
      *(_QWORD *)(v11 + 4) = v13;
      if ( *(_DWORD **)(v13 + 4) != v10 + 1 )
        __fastfail(3u);
      *(_DWORD *)(v13 + 4) = v14;
      *(_DWORD *)HIDWORD(v13) = v14;
    }
    v15 = *(_DWORD *)(v11 + 12);
    if ( (v15 & 6) == 0 )
    {
      if ( v15 == 1 )
        v16 = *(_DWORD *)(v11 + 20);
      else
        v16 = *(_DWORD *)(v11 + 24);
      if ( VfMajorBuildIrpLogEntry(a3, v16, v11 + 40 * *(_DWORD *)(v11 + 24) + 32, (int)var48) )
      {
        memmove(v11 + 40 * *(_DWORD *)(v11 + 24) + 32, (int)var48, 0x28u);
        v17 = *(_DWORD *)(v11 + 24) + 1;
        v18 = *(_DWORD *)(v11 + 20);
        *(_DWORD *)(v11 + 24) = v17;
        if ( v17 == v18 )
        {
          v19 = *(_DWORD *)(v11 + 12);
          *(_DWORD *)(v11 + 24) = 0;
          *(_DWORD *)(v11 + 12) = v19 | 1;
        }
      }
    }
LABEL_33:
    if ( (dword_682604 & 0x10000) != 0 )
      goto LABEL_34;
    goto LABEL_35;
  }
  return result;
}
