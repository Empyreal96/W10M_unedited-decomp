// RtlpUpdateDynamicTimeZones 
 
int __fastcall RtlpUpdateDynamicTimeZones(__int16 a1)
{
  int v2; // r4
  int v3; // r7
  unsigned __int16 *v5; // [sp+8h] [bp-200h]
  unsigned __int16 *v6; // [sp+Ch] [bp-1FCh] BYREF
  __int16 v7[2]; // [sp+10h] [bp-1F8h] BYREF
  char *v8; // [sp+14h] [bp-1F4h]
  int v9; // [sp+18h] [bp-1F0h]
  int v10; // [sp+1Ch] [bp-1ECh]
  int v11; // [sp+20h] [bp-1E8h]
  unsigned __int16 *v12; // [sp+24h] [bp-1E4h]
  __int16 *v13; // [sp+28h] [bp-1E0h]
  int v14; // [sp+2Ch] [bp-1DCh]
  int v15; // [sp+30h] [bp-1D8h]
  int v16; // [sp+34h] [bp-1D4h]
  int v17[14]; // [sp+40h] [bp-1C8h] BYREF
  int v18[12]; // [sp+78h] [bp-190h] BYREF
  char v19[48]; // [sp+A8h] [bp-160h] BYREF
  int v20; // [sp+E4h] [bp-124h]
  char v21; // [sp+E8h] [bp-120h] BYREF

  memset(v17, 0, sizeof(v17));
  v17[1] = 292;
  v17[2] = (int)L"TZI";
  v17[3] = (int)v18;
  v17[4] = 50331648;
  v2 = RtlpGetRegistryHandle(3, (int)L"Time Zones", 0, (int *)&v6) >= 0;
  v9 = v2;
  if ( !v2 )
    return v2;
  v3 = 0;
  if ( ZwEnumerateKey() < 0 )
  {
LABEL_8:
    ZwClose();
    return v2;
  }
  while ( 1 )
  {
    v11 = 24;
    v13 = v7;
    v14 = 576;
    v7[1] = v20;
    v7[0] = v20;
    v15 = 0;
    v16 = 0;
    v12 = v6;
    v8 = &v21;
    if ( ZwOpenKey() >= 0 )
      break;
LABEL_6:
    ++v3;
    if ( ZwEnumerateKey() < 0 )
    {
      v2 = v9;
      goto LABEL_8;
    }
  }
  RtlInitUnicodeString((unsigned int)v7, L"Dynamic DST");
  v11 = 24;
  v12 = v5;
  v13 = v7;
  v14 = 576;
  v15 = 0;
  v16 = 0;
  if ( ZwOpenKey() < 0 )
  {
LABEL_5:
    ZwClose();
    goto LABEL_6;
  }
  memset(v18, 0, 44);
  v18[0] = -44;
  if ( RtlpQueryRegistryValues(0x40000000, v5, v17, 0, 272, 1u) < 0
    || RtlpFindRegTziForCurrentYear(v19, v10, a1) < 0
    || !memcmp((unsigned int)v19, (unsigned int)v18, 44) )
  {
    ZwClose();
    goto LABEL_5;
  }
  return sub_80BAEC();
}
