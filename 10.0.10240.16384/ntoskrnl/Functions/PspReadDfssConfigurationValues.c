// PspReadDfssConfigurationValues 
 
int PspReadDfssConfigurationValues()
{
  int result; // r0
  int v1; // r3
  int v2; // r6
  int *v3; // r5
  int v4; // r0
  _DWORD *v5; // r2
  _DWORD *v6; // r0
  int v7; // [sp+18h] [bp-38h]

  result = PspDfssConfigurationKey;
  if ( PspDfssConfigurationKey )
  {
    v1 = 0;
    v7 = PspDfssConfigurationKey;
  }
  else
  {
    v1 = ZwOpenKey();
    result = v7;
  }
  if ( v1 >= 0 )
  {
    v2 = 4;
    v3 = &PspDfssConfigValues;
    while ( 1 )
    {
      v4 = RtlQueryImageFileKeyOption(result, v3[1], 4, *v3, 4, 0);
      v5 = (_DWORD *)*v3;
      if ( v4 >= 0 )
      {
        if ( !*v5 )
          *v5 = 1;
      }
      else
      {
        *v5 = v3[2];
      }
      v3 += 3;
      if ( !--v2 )
        break;
      result = v7;
    }
    if ( PspDfssConfigurationNotify )
    {
      KeUpdateGroupSchedulingConstants();
      v6 = (_DWORD *)PspDfssConfigurationNotify;
    }
    else
    {
      v6 = (_DWORD *)ExAllocatePoolWithTag(512, 24);
      PspDfssConfigurationNotify = (int)v6;
      if ( !v6 )
        return ZwClose();
      PspDfssConfigurationKey = v7;
    }
    v6[2] = PspDfssConfigurationChangeHandler;
    v6[3] = 0;
    *v6 = 0;
    result = ZwNotifyChangeKey();
    if ( result < 0 )
    {
      ZwClose();
      PspDfssConfigurationKey = 0;
      result = ExFreePoolWithTag(PspDfssConfigurationNotify);
      PspDfssConfigurationNotify = 0;
    }
  }
  return result;
}
