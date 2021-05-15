// PopUmpoInitializeMonitorChannel 
 
int PopUmpoInitializeMonitorChannel()
{
  int v0; // r6
  int v2; // r4
  int v3; // r5
  int v4; // [sp+0h] [bp-78h] BYREF
  int v5; // [sp+8h] [bp-70h] BYREF
  int v6; // [sp+Ch] [bp-6Ch]
  char *v7; // [sp+10h] [bp-68h]
  int v8; // [sp+14h] [bp-64h]
  int v9; // [sp+18h] [bp-60h]
  int v10; // [sp+1Ch] [bp-5Ch]
  int v11; // [sp+20h] [bp-58h]
  int v12; // [sp+24h] [bp-54h]
  char v13[8]; // [sp+28h] [bp-50h] BYREF
  int v14[11]; // [sp+30h] [bp-48h] BYREF

  PopAlpcMonitorServerPort = 0;
  PopAlpcMonitorClientPort = 0;
  v4 = 0;
  v0 = 0;
  RtlInitUnicodeString((unsigned int)v13, L"\\PowerMonitorPort");
  memset(v14, 0, sizeof(v14));
  v14[0] = 0x100000;
  v14[4] = 256;
  v5 = 24;
  v6 = 0;
  v7 = v13;
  v9 = 0;
  v10 = 0;
  v8 = 512;
  if ( ZwAlpcCreatePort() < 0 )
    return sub_96C11C();
  v5 = 24;
  v6 = 0;
  v7 = 0;
  v9 = 0;
  v10 = 0;
  v8 = 512;
  v2 = ExCreateCallback(&v4, &v5, 1, 1);
  if ( v2 < 0 )
  {
    if ( (PoDebug & 1) != 0 )
      DbgPrint("%s: Failed to create callback, %#08lx\n", "PopUmpoInitializeMonitorChannel", v2);
    v3 = v4;
  }
  else
  {
    v3 = v4;
    v0 = ExRegisterCallback(v4, (int)PopMonitorAlpcCallback, 0);
    if ( v0 )
    {
      v11 = v3;
      v12 = PopAlpcMonitorServerPort;
      v2 = ZwAlpcSetInformation();
      ObfDereferenceObjectWithTag(v3);
      if ( v2 < 0 )
      {
        if ( (PoDebug & 1) != 0 )
          JUMPOUT(0x96C12C);
      }
      else
      {
        PopMonitorProcessLoop();
        v2 = 0;
      }
    }
    else if ( (PoDebug & 1) != 0 )
    {
      JUMPOUT(0x96C12E);
    }
  }
  if ( v2 < 0 )
  {
    if ( PopAlpcMonitorServerPort )
      ZwClose();
    if ( v0 )
      ExUnregisterCallback(v0);
    if ( v3 )
      ObfDereferenceObjectWithTag(v3);
  }
  return v2;
}
