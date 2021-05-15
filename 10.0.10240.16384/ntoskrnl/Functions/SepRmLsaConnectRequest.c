// SepRmLsaConnectRequest 
 
int SepRmLsaConnectRequest()
{
  int v1; // r7
  _DWORD *v2; // r5
  int v3; // r0
  int v4; // r6
  int v5; // r4
  int v6[7]; // [sp+14h] [bp-7Ch] BYREF
  int v7; // [sp+30h] [bp-60h]
  int v8; // [sp+34h] [bp-5Ch]
  int v9; // [sp+38h] [bp-58h]
  int v10; // [sp+3Ch] [bp-54h]
  int v11; // [sp+40h] [bp-50h]
  int v12; // [sp+44h] [bp-4Ch]
  int v13; // [sp+48h] [bp-48h]
  int v14; // [sp+4Ch] [bp-44h]
  char v15[8]; // [sp+50h] [bp-40h] BYREF
  int v16; // [sp+58h] [bp-38h]
  int v17; // [sp+6Ch] [bp-24h]
  char v18; // [sp+70h] [bp-20h]
  char v19; // [sp+71h] [bp-1Fh]

  v9 = 24;
  v10 = 0;
  v11 = 0;
  v12 = 0;
  v13 = 0;
  v14 = 0;
  if ( ZwOpenProcess() < 0 )
    JUMPOUT(0x816C02);
  if ( ObReferenceObjectByHandle(0, 0, PsProcessType, 0, (int)v6, 0) < 0 )
    return sub_816BFC();
  v1 = PsGetProcessServerSilo(v6[0]);
  ObfDereferenceObject(v6[0]);
  PsGetMonitorContextServerSilo(SeRmSiloMonitor, v1, v6);
  v2 = (_DWORD *)v6[0];
  if ( *(_DWORD *)v6[0] )
    return sub_816BFC();
  v3 = v6[0];
  *(_DWORD *)v6[0] = 0;
  SepRmVerifyLsaProtectionLevel(v3);
  v16 = 12;
  v4 = ZwAcceptConnectPort();
  if ( v4 < 0 )
    goto LABEL_16;
  v4 = ZwCompleteConnectPort();
  if ( v4 < 0 )
    goto LABEL_16;
  v17 = 2;
  v18 = 1;
  v19 = 1;
  v2[6] = 4096;
  v2[7] = 0;
  v4 = ZwCreateSection();
  if ( v4 < 0 )
    goto LABEL_16;
  v6[3] = 24;
  v6[4] = v2[5];
  v6[5] = 0;
  v6[6] = v2[6];
  v7 = 0;
  v8 = 0;
  v17 = 2;
  v18 = 1;
  v19 = 1;
  v5 = PsAttachSiloToCurrentThread(v1);
  RtlInitUnicodeString((unsigned int)v15, L"\\SeLsaCommandPort");
  v4 = ZwConnectPort();
  PsDetachSiloFromCurrentThread(v5);
  if ( v4 < 0 )
    goto LABEL_16;
  if ( v6[1] != 256 )
  {
    v4 = -1073741823;
LABEL_16:
    SepRmCleanupRmLsaState(v2);
    goto LABEL_11;
  }
  v2[9] = v7;
  v2[10] = v8 - v7;
  v2[8] = v8;
LABEL_11:
  if ( v2[5] )
  {
    ZwClose();
    v2[5] = 0;
  }
  if ( v1 )
    PspDereferenceSiloObject(v1);
  PsDereferenceMonitorContextServerSilo((int)v2);
  return v4;
}
