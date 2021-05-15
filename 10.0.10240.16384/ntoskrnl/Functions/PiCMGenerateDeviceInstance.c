// PiCMGenerateDeviceInstance 
 
int __fastcall PiCMGenerateDeviceInstance(unsigned __int16 *a1, int a2, unsigned __int16 *a3)
{
  int v3; // r5
  int v6; // r4
  unsigned int v7; // r3
  unsigned __int16 *v8; // r6
  unsigned int v9; // t1
  int v10; // r3
  unsigned __int16 *v11; // r6
  int v12; // r7
  int v13; // r0
  int v14; // r2
  int v15; // r0
  char v17[4]; // [sp+10h] [bp-48h] BYREF
  int v18; // [sp+14h] [bp-44h] BYREF
  int v19; // [sp+18h] [bp-40h]
  int v20; // [sp+1Ch] [bp-3Ch] BYREF
  int v21; // [sp+20h] [bp-38h] BYREF
  int v22; // [sp+24h] [bp-34h] BYREF
  int v23; // [sp+28h] [bp-30h] BYREF
  int v24; // [sp+2Ch] [bp-2Ch] BYREF
  unsigned __int16 v25[20]; // [sp+30h] [bp-28h] BYREF

  v3 = 0;
  *a3 = 0;
  v18 = 0;
  v19 = a2;
  v6 = RtlStringCchLengthW(a1, 0xC8u, &v21);
  if ( v6 >= 0 )
  {
    v7 = *a1;
    v8 = a1;
    while ( v7 )
    {
      if ( v7 <= 0x20 || v7 > 0x7F || v7 == 44 || v7 == 92 )
      {
        v6 = -1073741773;
        break;
      }
      v9 = v8[1];
      ++v8;
      v7 = v9;
    }
    if ( v6 >= 0 )
    {
      v6 = RtlStringCchCopyExW(a3, 200, L"Root", 0, 0, 2048);
      if ( v6 >= 0 )
      {
        v6 = RtlInitUnicodeStringEx((int)v25, a3);
        if ( v6 >= 0 )
        {
          v6 = RtlUpcaseUnicodeString(v25, v25, 0, v10);
          if ( v6 >= 0 )
          {
            v6 = RtlStringCchCatExW(a3, 0xC8u, L"\\");
            if ( v6 >= 0 )
            {
              v6 = RtlStringCchCatExW(a3, 0xC8u, a1);
              if ( v6 >= 0 )
              {
                v11 = (unsigned __int16 *)ExAllocatePoolWithTag(1, 400, 879783504);
                if ( !v11 )
                  return -1073741670;
                v12 = 0;
                while ( 1 )
                {
                  if ( v3 )
                  {
                    ZwClose();
                    v3 = 0;
                    v18 = 0;
                  }
                  v6 = RtlStringCchPrintfExW((int)v11, 200, 0, 0, 2048, L"%s\\%04u");
                  if ( v6 < 0 )
                    break;
                  if ( CmGetDeviceStatus(PiPnpRtlCtx, v11, 0, &v24, &v23, &v22) < 0 )
                  {
                    v17[0] = 0;
                    v13 = CmCreateDevice(PiPnpRtlCtx, (int)v11, 131078, &v18, v17, 0);
                    v6 = v13;
                    v3 = v18;
                    if ( v13 < 0 )
                      break;
                    if ( v17[0] )
                    {
                      v6 = CmValidateDeviceName(v13, v11, v14, (unsigned __int8)v17[0]);
                      if ( v6 < 0 || (v15 = RtlStringCchCopyExW(a3, 200, v11), v6 = v15, v15 < 0) )
                      {
                        CmDeleteDevice(PiPnpRtlCtx, v11, 0);
                      }
                      else if ( v19 )
                      {
                        v20 = 1;
                        v6 = PnpCtxRegSetValue(v15, v3, (int)L"Phantom", 4, (int)&v20, 4);
                      }
                      break;
                    }
                  }
                  if ( (unsigned int)++v12 > 0x270F )
                  {
                    v6 = -2147483622;
                    break;
                  }
                }
                if ( v3 )
                  ZwClose();
                ExFreePoolWithTag((unsigned int)v11);
              }
            }
          }
        }
      }
    }
  }
  if ( v6 == -2147483643 )
    v6 = -1073741789;
  return v6;
}
