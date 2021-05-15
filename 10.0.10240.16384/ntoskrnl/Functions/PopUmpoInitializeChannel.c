// PopUmpoInitializeChannel 
 
int PopUmpoInitializeChannel()
{
  int v0; // r4
  int v1; // r0
  unsigned int v2; // r6
  int v4; // r4
  int v5; // r5
  int v6; // [sp+0h] [bp-90h] BYREF
  int v7; // [sp+8h] [bp-88h] BYREF
  int v8; // [sp+Ch] [bp-84h]
  char *v9; // [sp+10h] [bp-80h]
  int v10; // [sp+14h] [bp-7Ch]
  char *v11; // [sp+18h] [bp-78h]
  int v12; // [sp+1Ch] [bp-74h]
  int v13; // [sp+20h] [bp-70h]
  int v14; // [sp+24h] [bp-6Ch]
  char v15[8]; // [sp+28h] [bp-68h] BYREF
  char v16[24]; // [sp+30h] [bp-60h] BYREF
  int v17[11]; // [sp+48h] [bp-48h] BYREF

  PopAlpcServerPort = 0;
  PopAlpcClientPort = 0;
  PopUmpoAlpcClientConnected = 0;
  PopUmpoPushLock = 0;
  v6 = 0;
  PopBrightnessWorkItemQueued = 0;
  PopBrightnessNotifyMutex = 1;
  dword_61DEE4 = 0;
  unk_61DEE8 = 0;
  byte_61DEEC = 1;
  byte_61DEED = 0;
  byte_61DEEE = 4;
  dword_61DEF0 = 0;
  dword_61DEF8 = (int)&dword_61DEF4;
  dword_61DEF4 = (int)&dword_61DEF4;
  PopBrightnessChangeWorkList = (int)&PopBrightnessChangeWorkList;
  dword_61DF04 = (int)&PopBrightnessChangeWorkList;
  dword_61DF28 = (int)PopNotifyBrightnessChangesWorker;
  dword_61DF2C = 0;
  PopNotifyBrightnessWorkItem = 0;
  v0 = *(unsigned __int8 *)(SeLocalSystemSid + 1) + 7;
  v1 = ExAllocatePoolWithTag(512, 4 * v0, 1869638997);
  v2 = v1;
  if ( !v1 )
    return sub_96C054();
  v4 = RtlCreateAcl(v1, 4 * v0, 2);
  if ( v4 < 0 )
  {
    if ( (PoDebug & 1) != 0 )
      DbgPrint("%s: RtlCreateAcl failed: 0x%x\n", "PopUmpoInitializeChannel", v4);
  }
  else
  {
    v4 = RtlAddAccessAllowedAce(v2, 2, 0x10000000, SeLocalSystemSid);
    if ( v4 < 0 )
    {
      if ( (PoDebug & 1) != 0 )
        DbgPrint("%s: RtlAddAccessAllowedAce failed: 0x%x\n", "PopUmpoInitializeChannel", v4);
    }
    else
    {
      v4 = RtlCreateSecurityDescriptor(v16, 1);
      if ( v4 < 0 )
      {
        if ( (PoDebug & 1) != 0 )
          DbgPrint("%s: RtlCreateSecurityDescriptor failed: 0x%x\n", "PopUmpoInitializeChannel", v4);
      }
      else
      {
        v4 = RtlSetDaclSecurityDescriptor((int)v16, 1, v2, 0);
        if ( v4 < 0 )
        {
          if ( (PoDebug & 1) != 0 )
            DbgPrint("%s: RtlSetDaclSecurityDescriptor failed: 0x%x\n", "PopUmpoInitializeChannel", v4);
        }
        else
        {
          RtlInitUnicodeString((unsigned int)v15, L"\\PowerPort");
          memset(v17, 0, sizeof(v17));
          v17[0] = 0x100000;
          v7 = 24;
          v8 = 0;
          v9 = v15;
          v10 = 512;
          v11 = v16;
          v12 = 0;
          v17[4] = 512;
          v4 = ZwAlpcCreatePort();
          if ( v4 < 0 )
          {
            if ( (PoDebug & 1) != 0 )
              DbgPrint("%s: ZwAlpcCreatePort failed: 0x%x\n", "PopUmpoInitializeChannel", v4);
          }
          else
          {
            v7 = 24;
            v8 = 0;
            v9 = 0;
            v11 = 0;
            v12 = 0;
            v10 = 512;
            v4 = ExCreateCallback(&v6, &v7, 1, 0);
            if ( v4 < 0 )
            {
              if ( (PoDebug & 1) != 0 )
                DbgPrint("%s: ExCreateCallback failed: 0x%x\n", "PopUmpoInitializeChannel", v4);
            }
            else
            {
              v5 = v6;
              if ( ExRegisterCallback(v6, (int)PopUmpoMessageCallback, 0) )
              {
                v13 = v5;
                v14 = 0;
                v4 = ZwAlpcSetInformation();
                ObfDereferenceObjectWithTag(v5);
                if ( v4 < 0 )
                {
                  if ( (PoDebug & 1) != 0 )
                    DbgPrint("%s: ZwAlpcSetInformation failed: 0x%x\n", "PopUmpoInitializeChannel", v4);
                }
                else
                {
                  PopUmpoProcessMessages();
                  v4 = 0;
                }
              }
              else
              {
                if ( (PoDebug & 1) != 0 )
                  DbgPrint("%s: ExRegisterCallback failed\n", "PopUmpoInitializeChannel");
                v4 = -1073741670;
              }
            }
          }
        }
      }
    }
  }
  ExFreePoolWithTag(v2);
  return v4;
}
