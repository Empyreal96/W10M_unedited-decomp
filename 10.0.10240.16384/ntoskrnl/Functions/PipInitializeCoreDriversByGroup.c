// PipInitializeCoreDriversByGroup 
 
int __fastcall PipInitializeCoreDriversByGroup(int result, _DWORD *a2)
{
  _DWORD *v2; // r4
  _DWORD *v3; // r5
  int v4; // r8
  _DWORD *v5; // r7
  int v6; // r3
  int v7; // r6
  int v8; // r0
  int v9; // r1
  int v10; // r8
  int v11; // r0
  int v12; // r2
  int v13; // [sp+0h] [bp-50h]
  _DWORD *v14; // [sp+18h] [bp-38h]
  int v15; // [sp+1Ch] [bp-34h] BYREF
  int v16; // [sp+20h] [bp-30h]
  char v17[4]; // [sp+28h] [bp-28h] BYREF
  unsigned int v18; // [sp+2Ch] [bp-24h]

  if ( result )
  {
    if ( result == 1 )
    {
      v2 = a2 + 14;
    }
    else
    {
      if ( result != 2 )
        return result;
      v2 = a2 + 16;
    }
  }
  else
  {
    v2 = a2 + 12;
  }
  if ( v2 )
  {
    v3 = (_DWORD *)*v2;
    PnpCoreDriverGroupLoadPhase = result;
    if ( v3 != v2 )
    {
      v4 = (int)(a2 + 4);
      result = 0;
      v14 = a2 + 4;
      do
      {
        v5 = v3;
        v6 = v3[7];
        v3 = (_DWORD *)*v3;
        if ( v6 >= 0 )
        {
          v18 = 0;
          v15 = 0;
          v7 = IopOpenRegistryKeyEx(&v15);
          if ( v7 >= 0 )
          {
            v7 = IopGetDriverNameFromKeyNode(v15);
            if ( v7 >= 0 )
            {
              v13 = v4;
              v8 = PnpInitializeBootStartDriver(v17, v5 + 4, *(_DWORD *)(v5[6] + 28));
              v7 = v8;
              if ( v8 >= 0 )
              {
                v10 = v16;
                if ( v16 )
                {
                  v11 = PnpLockDeviceActionQueue(v8, v9);
                  PipApplyFunctionToServiceInstances(
                    v11,
                    *(_DWORD *)(v10 + 24) + 12,
                    v12,
                    *(_DWORD *)(v10 + 24),
                    v13,
                    v10);
                  PnpUnlockDeviceActionQueue();
                  PnpWaitForEmptyDeviceActionQueue();
                  PnpRequestDeviceAction(0, 7, 0, 0, 0, 0);
                  if ( PnpWaitForEmptyDeviceEventQueue() < 0 )
                    HeadlessKernelAddLogEntry();
                }
                v4 = (int)v14;
              }
            }
          }
          if ( v15 )
            ZwClose();
          if ( v18 )
            ExFreePoolWithTag(v18);
          if ( v7 < 0 )
            return sub_968A94();
          result = 0;
        }
      }
      while ( v3 != v2 );
    }
  }
  return result;
}
