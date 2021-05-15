// CmpSendBootDeviceUsageNotification 
 
int __fastcall CmpSendBootDeviceUsageNotification(int a1)
{
  int v2; // r4
  int v3; // r5
  int v5; // [sp+24h] [bp-3Ch] BYREF
  char v6[8]; // [sp+28h] [bp-38h] BYREF
  int v7; // [sp+38h] [bp-28h]
  int v8; // [sp+3Ch] [bp-24h]
  char *v9; // [sp+40h] [bp-20h]
  int v10; // [sp+44h] [bp-1Ch]
  int v11; // [sp+48h] [bp-18h]
  int v12; // [sp+4Ch] [bp-14h]

  RtlInitUnicodeString((unsigned int)v6, L"\\Device\\BootDevice");
  v7 = 24;
  v8 = 0;
  v10 = 512;
  v9 = v6;
  v11 = 0;
  v12 = 0;
  v2 = ZwCreateFile();
  if ( v2 >= 0 )
  {
    v2 = ObReferenceObjectByHandle(0, 384, *(_DWORD *)CmIoFileObjectType, 0, (int)&v5, 0);
    v3 = v5;
    if ( v2 >= 0 )
    {
      v2 = PiPagePathSetState(v5, a1 == 0);
      if ( v2 >= 0 )
        v2 = 0;
    }
    if ( v3 )
      ObfDereferenceObject(v3);
  }
  return v2;
}
