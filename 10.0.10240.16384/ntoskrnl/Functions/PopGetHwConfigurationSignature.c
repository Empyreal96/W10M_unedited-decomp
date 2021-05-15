// PopGetHwConfigurationSignature 
 
int PopGetHwConfigurationSignature()
{
  unsigned int v0; // r4
  int v1; // r7
  int v2; // r6
  _DWORD *v3; // r0
  unsigned int v4; // r5
  int v5; // r8
  _DWORD *v6; // r0
  int v8[13]; // [sp+Ch] [bp-34h] BYREF

  v8[1] = 1094930505;
  v8[2] = 1;
  v8[3] = 1346584902;
  v8[4] = 0;
  v0 = 0;
  v1 = 0;
  v2 = 4;
  if ( ZwQuerySystemInformation() == -1073741789 )
  {
    v3 = (_DWORD *)ExAllocatePoolWithTag(512, 0, 544040269);
    v4 = (unsigned int)v3;
    if ( v3 )
    {
      v3[1] = 1;
      *v3 = 1094930505;
      v3[2] = 1346584902;
      v3[3] = -16;
      if ( ZwQuerySystemInformation() >= 0 && *(unsigned __int8 *)(v4 + 24) >= 5u )
      {
        v5 = *(_DWORD *)(v4 + 52);
        HalGetMemoryCachingRequirements(v5, 0, 64, 0, v8);
        if ( v8[0] != 1 )
        {
          if ( v8[0] == 2 )
            v2 = 1028;
          else
            v2 = 516;
        }
        v6 = (_DWORD *)MmMapIoSpaceEx(v5, 0, 64, v2);
        v0 = (unsigned int)v6;
        if ( *v6 == 1396916550 )
          v1 = v6[2];
      }
      ExFreePoolWithTag(v4);
      if ( v0 )
        MmUnmapIoSpace(v0, 64);
    }
  }
  return v1;
}
