// SiGetDriveLayoutInformation 
 
int __fastcall SiGetDriveLayoutInformation(unsigned __int16 *a1, int *a2)
{
  int v2; // r4
  int v3; // r6
  int v4; // r5
  char v7[8]; // [sp+30h] [bp-40h] BYREF
  int v8; // [sp+38h] [bp-38h]
  int v9; // [sp+3Ch] [bp-34h]
  char *v10; // [sp+40h] [bp-30h]
  int v11; // [sp+44h] [bp-2Ch]
  int v12; // [sp+48h] [bp-28h]
  int v13; // [sp+4Ch] [bp-24h]

  RtlInitUnicodeString((unsigned int)v7, a1);
  v8 = 24;
  v9 = 0;
  v11 = 576;
  v10 = v7;
  v12 = 0;
  v13 = 0;
  v2 = ZwOpenFile();
  if ( v2 >= 0 )
  {
    v8 = 24;
    v9 = 0;
    v11 = 512;
    v10 = 0;
    v12 = 0;
    v13 = 0;
    v2 = ZwCreateEvent();
    if ( v2 >= 0 )
    {
      v3 = 18480;
      v4 = ExAllocatePoolWithTag(1, 18480, 1263556947);
      if ( v4 )
      {
        while ( 1 )
        {
          v2 = ZwDeviceIoControlFile();
          if ( v2 == 259 )
            return sub_8158B8();
          ZwResetEvent();
          if ( v2 != -1073741789 )
            break;
          ExFreePoolWithTag(v4);
          v3 += 9216;
          v4 = ExAllocatePoolWithTag(1, v3, 1263556947);
          if ( !v4 )
          {
            v2 = -1073741670;
            goto LABEL_9;
          }
        }
        if ( v2 < 0 )
          goto LABEL_14;
        *a2 = v4;
LABEL_9:
        if ( v2 >= 0 )
          return v2;
LABEL_14:
        if ( v4 )
          ExFreePoolWithTag(v4);
      }
      else
      {
        v2 = -1073741670;
      }
    }
  }
  return v2;
}
