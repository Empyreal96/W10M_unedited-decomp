// ExRegisterBootDevice 
 
int __fastcall ExRegisterBootDevice(int *a1, int *a2)
{
  int v4; // r5
  int v5; // r7
  int v6; // r0
  int v7; // r0
  int v8; // r1
  int v9; // r2
  int v10; // r3
  _DWORD *v11; // r6
  int v12; // r3
  int v13; // r6
  unsigned int v14; // r2
  void **v15; // r0
  int v17; // [sp+10h] [bp-40h] BYREF
  int v18; // [sp+14h] [bp-3Ch] BYREF
  int var38[16]; // [sp+18h] [bp-38h] BYREF

  v4 = 0;
  KeWaitForSingleObject((unsigned int)&ExExternalBootSupportInitializationEvent, 0, 0, 0, 0);
  if ( !ExBootDeviceRemovalHandler )
  {
    var38[0] = 24;
    var38[1] = 0;
    var38[2] = 0;
    var38[4] = 0;
    var38[5] = 0;
    var38[3] = 512;
    v4 = PsCreateSystemThread(&v17, 0, var38, 0, 0, ExpWaitForBootDevices, 0);
    if ( v4 >= 0 )
    {
      v4 = ObReferenceObjectByHandle(v17, 0x1FFFFF, 0, 0, &v18, 0);
      ExBootDeviceRemovalHandler = v18;
      ZwClose();
      KeSetPriorityThread(ExBootDeviceRemovalHandler, 31);
    }
  }
  KeSetEvent((int)&ExExternalBootSupportInitializationEvent, 0, 0);
  if ( v4 >= 0 )
  {
    if ( *a1 != 1 || !a1[2] || a1[1] || !a1[4] )
      v4 = -1073741811;
    if ( v4 >= 0 )
    {
      v5 = ExAllocatePoolWithTag(512, 40);
      if ( !v5 )
        v4 = -1073741670;
      if ( v4 >= 0 )
      {
        ObfReferenceObjectWithTag(a1[2]);
        v6 = a1[3];
        if ( v6 )
          ObfReferenceObjectWithTag(v6);
        memset((_BYTE *)v5, 0, 40);
        *(_DWORD *)v5 = 1347306562;
        v7 = *a1;
        v8 = a1[1];
        v9 = a1[2];
        v10 = a1[3];
        v11 = a1 + 4;
        *(_DWORD *)(v5 + 16) = v7;
        *(_DWORD *)(v5 + 20) = v8;
        *(_DWORD *)(v5 + 24) = v9;
        *(_DWORD *)(v5 + 28) = v10;
        v12 = v11[1];
        *(_DWORD *)(v5 + 32) = *v11;
        *(_DWORD *)(v5 + 36) = v12;
        v13 = KfRaiseIrql(2);
        if ( (dword_682604 & 0x210000) != 0 )
        {
          KiAcquireSpinLockInstrumented((int)&ExBootDeviceListSpinLock);
        }
        else
        {
          do
            v14 = __ldrex((unsigned int *)&ExBootDeviceListSpinLock);
          while ( __strex(1u, (unsigned int *)&ExBootDeviceListSpinLock) );
          __dmb(0xBu);
          if ( v14 )
            KxWaitForSpinLockAndAcquire((unsigned int *)&ExBootDeviceListSpinLock);
        }
        v15 = (void **)dword_61A204;
        *(_DWORD *)(v5 + 8) = &ExBootDeviceList;
        *(_DWORD *)(v5 + 12) = v15;
        if ( *v15 != &ExBootDeviceList )
          __fastfail(3u);
        *v15 = (void *)(v5 + 8);
        dword_61A204 = v5 + 8;
        if ( (dword_682604 & 0x10000) != 0 )
        {
          KiReleaseSpinLockInstrumented(&ExBootDeviceListSpinLock, var38[15]);
        }
        else
        {
          __dmb(0xBu);
          ExBootDeviceListSpinLock = 0;
        }
        KfLowerIrql(v13);
        *a2 = v5;
      }
    }
  }
  return v4;
}
