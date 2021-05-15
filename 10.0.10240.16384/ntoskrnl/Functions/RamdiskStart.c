// RamdiskStart 
 
int __fastcall RamdiskStart(_DWORD *a1)
{
  _DWORD *v1; // r7
  _DWORD *v3; // r2
  _DWORD *v4; // r1
  int v5; // r4
  int v6; // r1
  char *v7; // r4
  _BYTE *v8; // r0
  _BYTE *v9; // r0
  int v10; // r0
  _BYTE *v11; // r0
  _BYTE *v12; // r0
  int v13; // r1
  int v14; // r3
  int v16; // [sp+20h] [bp-120h]
  __int16 v17[2]; // [sp+28h] [bp-118h] BYREF
  const __int16 *v18; // [sp+2Ch] [bp-114h]
  _DWORD v19[2]; // [sp+30h] [bp-110h] BYREF
  _DWORD v20[8]; // [sp+38h] [bp-108h] BYREF
  unsigned __int16 v21[4]; // [sp+58h] [bp-E8h] BYREF
  char v22[8]; // [sp+60h] [bp-E0h] BYREF
  _QWORD v23[7]; // [sp+68h] [bp-D8h] BYREF
  char v24[24]; // [sp+A0h] [bp-A0h] BYREF
  unsigned __int16 v25[68]; // [sp+B8h] [bp-88h] BYREF

  v1 = 0;
  v3 = (_DWORD *)a1[6];
  v4 = a1 + 6;
  while ( v3 != v4 )
  {
    v1 = v3;
    if ( v3[2] == 25 )
      break;
    v3 = (_DWORD *)*v3;
  }
  if ( v3 == v4 )
  {
    v5 = -1073741811;
    v6 = 1;
    goto LABEL_27;
  }
  memset(v23, 0, sizeof(v23));
  v23[0] = 0xD9B257FC00000038ui64;
  HIDWORD(v23[5]) = v1[3];
  LOWORD(v23[6]) = 0;
  LODWORD(v23[3]) = v23[3] & 0xFFFFFFE0 | 2;
  v23[1] = 0xCF0379AB4DCB684Eui64;
  v23[2] = 0x350B7F6A2i64;
  LODWORD(v23[5]) = 0;
  v7 = (char *)a1[30];
  v23[4] = (unsigned int)(v1[4] << 12);
  if ( v7 )
  {
    strupr(v7);
    v8 = strstr(v7, "RDIMAGEOFFSET");
    if ( v8 && (v9 = strstr(v8, "=")) != 0 )
    {
      v10 = atol((int)(v9 + 1));
      LODWORD(v23[5]) = v10;
    }
    else
    {
      v10 = v23[5];
    }
    v23[4] -= (unsigned int)v10;
    v11 = strstr(v7, "RDIMAGELENGTH");
    if ( v11 )
    {
      v12 = strstr(v11, "=");
      if ( v12 )
      {
        LODWORD(v23[4]) = atoi64((int)(v12 + 1));
        HIDWORD(v23[4]) = v13;
      }
    }
  }
  v17[1] = 32;
  v17[0] = 30;
  v18 = L"\\Device\\Ramdisk";
  v20[2] = 24;
  v20[3] = 0;
  v20[5] = 576;
  v20[4] = v17;
  v20[6] = 0;
  v20[7] = 0;
  v5 = ZwOpenFile();
  if ( v5 < 0 || (v5 = v16, v16 < 0) )
  {
    v6 = 2;
LABEL_27:
    KeBugCheck2(248, v6, v5, 0, 0, 0);
  }
  v5 = ZwDeviceIoControlFile();
  ZwClose();
  if ( v5 < 0 )
  {
    v6 = 3;
    goto LABEL_27;
  }
  v5 = RtlStringFromGUID((int)v23 + 4, (int)v19);
  if ( v5 < 0 )
  {
    v6 = 4;
    goto LABEL_27;
  }
  RtlStringCbPrintfA((int)v24, 0x14u, (int)"\\ArcName\\%s", a1[26]);
  RtlInitAnsiString((unsigned int)v21, (unsigned int)v24);
  v5 = RtlAnsiStringToUnicodeString((unsigned __int16 *)v20, v21, 1, v14);
  if ( v5 < 0 )
  {
    v6 = 5;
    goto LABEL_27;
  }
  RtlStringCbPrintfW(v25, 0x6Cu, (int)L"\\Device\\Ramdisk%wZ", (int)v19);
  RtlInitUnicodeString((unsigned int)v22, v25);
  v5 = IoCreateSymbolicLink();
  RtlFreeAnsiString(v19);
  RtlFreeAnsiString(v20);
  if ( v5 < 0 )
  {
    v6 = 6;
    goto LABEL_27;
  }
  return 0;
}
