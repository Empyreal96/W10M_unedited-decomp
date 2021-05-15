// EtwpValidateEnableNotification 
 
int __fastcall EtwpValidateEnableNotification(int a1, char a2, int a3, _DWORD *a4, int a5)
{
  unsigned int v6; // r4
  int v9; // r9
  int v10; // r3
  unsigned int v11; // r6
  int v12; // r4
  _DWORD *v13; // r0
  int v14; // r3
  int v15; // r1
  int v16; // r2
  int v17; // r3
  int v18; // r3
  int result; // r0
  int v20; // r3
  unsigned int v21; // r3
  int v22; // r3
  int v23; // r0
  int v24; // r3
  int v25[8]; // [sp+0h] [bp-20h] BYREF

  v25[0] = a3;
  v25[1] = (int)a4;
  v6 = *(_DWORD *)(a1 + 4);
  v9 = a2;
  *a4 = 0;
  if ( v6 < 0x78 || *(_DWORD *)(a1 + 116) && EtwpValidateFilterDescriptors(a1, a5) )
    return -1073741811;
  v10 = *(_DWORD *)(a1 + 72);
  if ( v10 != 1 && v10 )
    return sub_807FE4();
  v11 = *(unsigned __int16 *)(a1 + 78);
  *(_BYTE *)(a3 + 18) = (v11 & 0x8000) != 0;
  if ( (v11 & 0x8000) != 0 )
  {
    v22 = *(_DWORD *)(a1 + 80);
    if ( (v22 & 0x20) != 0 )
      return -1073741811;
    v23 = a1 + 40;
    goto LABEL_20;
  }
  PsGetMonitorContextServerSilo(EtwSiloMonitor, -1, v25);
  v12 = *(_DWORD *)(v25[0] + 360);
  PsDereferenceMonitorContextServerSilo(v25[0]);
  if ( v11 == v12 )
    return -1073741790;
  v13 = (_DWORD *)EtwpAcquireLoggerContextByLoggerId(v11, 0);
  if ( !v13 )
    goto LABEL_32;
  v14 = *(_DWORD *)(a1 + 80);
  *a4 = v13;
  if ( (v14 & 0x20) != 0 )
  {
    v24 = v13[3];
    if ( (v24 & 0x800) != 0 || (v24 & 0x10000) != 0 || (v24 & 0x20000) != 0 || (v24 & 0x1000000) != 0 )
      return -1073741811;
  }
  if ( (v13[152] & 0x40) != 0 )
  {
LABEL_32:
    result = -1073741162;
    goto LABEL_15;
  }
  v15 = v13[51];
  v16 = v13[52];
  v17 = v13[53];
  *(_DWORD *)a3 = v13[50];
  *(_DWORD *)(a3 + 4) = v15;
  *(_DWORD *)(a3 + 8) = v16;
  *(_DWORD *)(a3 + 12) = v17;
  if ( (v13[3] & 0x80) != 0 )
    *(_BYTE *)(a3 + 16) = 1;
  v18 = v13[3];
  if ( (v18 & 0x1000000) != 0 )
    *(_BYTE *)(a3 + 17) = 1;
  if ( v9 )
  {
    result = EtwpCheckGuidAccess(a1 + 40, 128, 0, v18);
    if ( result < 0 )
      goto LABEL_15;
    v23 = a3;
LABEL_20:
    result = EtwpCheckGuidAccess(v23, 128, 0, v22);
    goto LABEL_15;
  }
  result = 0;
LABEL_15:
  v20 = *(_DWORD *)(a1 + 80);
  if ( (v20 & 0x10) != 0 )
    v21 = v20 & 0xFFFFFFEF;
  else
    v21 = v20 | 0x40;
  *(_DWORD *)(a1 + 80) = v21;
  return result;
}
