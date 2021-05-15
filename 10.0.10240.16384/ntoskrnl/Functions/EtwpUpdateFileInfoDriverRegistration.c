// EtwpUpdateFileInfoDriverRegistration 
 
int EtwpUpdateFileInfoDriverRegistration()
{
  int v0; // r4
  char v2[8]; // [sp+28h] [bp-30h] BYREF
  int v3; // [sp+38h] [bp-20h]
  int v4; // [sp+3Ch] [bp-1Ch]
  char *v5; // [sp+40h] [bp-18h]
  int v6; // [sp+44h] [bp-14h]
  int v7; // [sp+48h] [bp-10h]
  int v8; // [sp+4Ch] [bp-Ch]

  RtlInitUnicodeString((unsigned int)v2, L"\\Device\\FileInfo");
  v3 = 24;
  v4 = 0;
  v6 = 576;
  v5 = v2;
  v7 = 0;
  v8 = 0;
  v0 = ZwOpenFile();
  if ( v0 >= 0 )
    v0 = ZwDeviceIoControlFile();
  return v0;
}
