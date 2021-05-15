// ExpWaitForBootDevices 
 
void ExpWaitForBootDevices()
{
  _DWORD *v0; // r5
  int v1; // r6
  unsigned int v2; // r2
  unsigned int *v3; // r6
  int v4; // r3
  unsigned int v5; // r2
  unsigned int v6; // r2
  unsigned int v7; // r2
  unsigned int v8; // r2
  int v9; // r1
  int v10; // r2
  int v11; // r3
  int v12; // [sp+8h] [bp-20h]
  int vars4; // [sp+2Ch] [bp+4h]

  while ( 1 )
  {
    KeWaitForSingleObject((unsigned int)&ExBootDevicesRemovedEvent, 0, 0, 0, 0);
    v12 = 60;
    while ( 1 )
    {
      v0 = &ExBootDeviceList;
      while ( 1 )
      {
        v1 = KfRaiseIrql(2);
        if ( (dword_682604 & 0x210000) != 0 )
        {
          KiAcquireSpinLockInstrumented((int)&ExBootDeviceListSpinLock);
        }
        else
        {
          do
            v2 = __ldrex((unsigned int *)&ExBootDeviceListSpinLock);
          while ( __strex(1u, (unsigned int *)&ExBootDeviceListSpinLock) );
          __dmb(0xBu);
          if ( v2 )
            KxWaitForSpinLockAndAcquire((unsigned int *)&ExBootDeviceListSpinLock);
        }
        v0 = (_DWORD *)v0[1];
        if ( v0 == (_DWORD *)&ExBootDeviceList )
          break;
        if ( (dword_682604 & 0x10000) != 0 )
        {
          KiReleaseSpinLockInstrumented(&ExBootDeviceListSpinLock, vars4);
        }
        else
        {
          __dmb(0xBu);
          ExBootDeviceListSpinLock = 0;
        }
        KfLowerIrql(v1);
        v3 = v0 - 1;
        v4 = *(v0 - 1);
        __dmb(0xBu);
        if ( v4 )
        {
          if ( ((int (__fastcall *)(_DWORD, _DWORD))v0[6])(v0[5], v0[7]) )
          {
            __dmb(0xBu);
            do
            {
              v5 = __ldrex(v3);
              v6 = v5 - 1;
            }
            while ( __strex(v6, v3) );
            __dmb(0xBu);
            if ( !v6 )
            {
              __dmb(0xBu);
              do
              {
                v7 = __ldrex((unsigned int *)&ExNumMissingBootDevices);
                v8 = v7 - 1;
              }
              while ( __strex(v8, (unsigned int *)&ExNumMissingBootDevices) );
              __dmb(0xBu);
              if ( !v8 )
                goto LABEL_25;
            }
          }
        }
      }
      if ( (dword_682604 & 0x10000) != 0 )
      {
        KiReleaseSpinLockInstrumented(&ExBootDeviceListSpinLock, vars4);
      }
      else
      {
        __dmb(0xBu);
        ExBootDeviceListSpinLock = 0;
      }
      KfLowerIrql(v1);
LABEL_25:
      if ( !ExNumMissingBootDevices )
        break;
      KeFreezeExecution(0, 0);
      KeStallExecutionProcessor(1000000);
      KeThawExecution(1, v9, v10, v11);
      if ( !--v12 )
        KeBugCheckEx(123, 0, 0, 3, 0);
    }
  }
}
