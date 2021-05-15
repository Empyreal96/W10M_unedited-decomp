// SiIssueSynchronousIoctl 
 
int __fastcall SiIssueSynchronousIoctl(unsigned __int16 *a1)
{
  int v1; // r4
  int v3; // [sp+20h] [bp-38h]
  char v4[8]; // [sp+28h] [bp-30h] BYREF
  int v5; // [sp+30h] [bp-28h]
  int v6; // [sp+34h] [bp-24h]
  char *v7; // [sp+38h] [bp-20h]
  int v8; // [sp+3Ch] [bp-1Ch]
  int v9; // [sp+40h] [bp-18h]
  int v10; // [sp+44h] [bp-14h]

  RtlInitUnicodeString((unsigned int)v4, a1);
  v5 = 24;
  v6 = 0;
  v8 = 576;
  v7 = v4;
  v9 = 0;
  v10 = 0;
  v1 = ZwOpenFile();
  if ( v1 >= 0 )
  {
    v5 = 24;
    v6 = 0;
    v8 = 512;
    v7 = 0;
    v9 = 0;
    v10 = 0;
    v1 = ZwCreateEvent();
    if ( v1 >= 0 )
    {
      v1 = ZwDeviceIoControlFile();
      if ( v1 == 259 )
      {
        v1 = ZwWaitForSingleObject();
        if ( v1 >= 0 )
          v1 = v3;
      }
    }
  }
  return v1;
}
