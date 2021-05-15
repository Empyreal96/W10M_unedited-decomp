// _CmGetDeviceContainerIdFromBase 
 
int __fastcall CmGetDeviceContainerIdFromBase(_DWORD *a1, int a2, int a3, _WORD *a4)
{
  int v7; // r4
  int v8; // r0
  int i; // r6
  char v11; // [sp+10h] [bp-80h] BYREF
  char v12[3]; // [sp+11h] [bp-7Fh] BYREF
  int v13[2]; // [sp+14h] [bp-7Ch] BYREF
  _WORD *v14; // [sp+1Ch] [bp-74h]
  char v15[112]; // [sp+20h] [bp-70h] BYREF

  v13[0] = 0;
  v12[0] = 0;
  v11 = 0;
  v14 = a4;
  v7 = RtlStringCchCopyW(a4, 0x27u, a3);
  if ( v7 >= 0 && !PnpIsNullGuidString(a3) )
  {
    v7 = PnpCtxGetCachedContextBaseKey(a1, 9, v13);
    if ( v7 >= 0 )
    {
      v8 = CmIsDeviceInContainer(a1, v13[0], a3, a3, a2, v12, &v11);
      v7 = v8;
      if ( v8 >= 0 && !v11 )
      {
        for ( i = 0; ; ++i )
        {
          v13[1] = 39;
          v8 = PnpCtxRegEnumKey(v8);
          v7 = v8;
          if ( v8 == -2147483622 )
            break;
          if ( v8 != -1073741789 )
          {
            if ( v8 < 0 )
              return v7;
            v8 = CmValidateDeviceContainerName();
            v7 = v8;
            if ( v8 != -1073741773 )
            {
              if ( v8 < 0 )
                return v7;
              v8 = CmIsDeviceInContainer(a1, v13[0], v15, a3, a2, v12, &v11);
              v7 = v8;
              if ( v8 < 0 )
                return v7;
              if ( v12[0] )
              {
                v8 = RtlStringCchCopyW(v14, 0x27u, (int)v15);
                v7 = v8;
              }
              if ( v7 < 0 || v11 )
                return v7;
            }
          }
        }
        v7 = 0;
      }
    }
  }
  return v7;
}
