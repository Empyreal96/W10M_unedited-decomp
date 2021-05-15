// sub_8AB448 
 
int __fastcall sub_8AB448(int a1, int a2)
{
  int v4; // r4
  int v5; // r7
  int v6; // r6
  int v8; // [sp+10h] [bp-2B0h] BYREF
  char v9[4]; // [sp+18h] [bp-2A8h] BYREF
  unsigned int v10; // [sp+1Ch] [bp-2A4h]
  char v11[8]; // [sp+20h] [bp-2A0h] BYREF
  _DWORD v12[4]; // [sp+28h] [bp-298h] BYREF
  int v13[8]; // [sp+38h] [bp-288h] BYREF
  char v14[28]; // [sp+58h] [bp-268h] BYREF
  __int16 v15; // [sp+74h] [bp-24Ch]
  char v16; // [sp+76h] [bp-24Ah]
  int v17; // [sp+78h] [bp-248h]
  unsigned __int16 v18[272]; // [sp+A0h] [bp-220h] BYREF

  v8 = 0;
  sub_8AAD98(v14);
  v4 = RtlStringCchPrintfW(v18, 0x104u, (int)L"\\??\\PhysicalDrive%u", a2);
  if ( v4 >= 0 )
  {
    RtlInitUnicodeString((unsigned int)v11, v18);
    v12[0] = 0;
    v12[1] = 0;
    v12[2] = 0;
    v4 = sub_8AB264((int)v11, 2954240, (int)v12, 12, (int)v9, 8, 0, 0);
    if ( v4 >= 0 )
    {
      v5 = ExAllocatePoolWithTag(1, v10, 542329939);
      if ( !v5 )
      {
        v4 = -1073741670;
        goto LABEL_14;
      }
      v4 = sub_8AB264((int)v11, 2954240, (int)v12, 12, v5, v10, 0, &v8);
      v6 = v8;
      if ( v4 < 0 )
        goto LABEL_11;
      if ( !v8 )
      {
LABEL_13:
        ExFreePoolWithTag(v5);
        goto LABEL_14;
      }
      if ( !*(_BYTE *)(a1 + 12) )
      {
        memset(v13, 0, sizeof(v13));
        v13[3] = 1415961924;
        v13[4] = 1232052684;
        v13[5] = -1888808811;
        v13[6] = -2090935510;
        LOBYTE(v13[1]) = 2;
        v4 = sub_8AAAAC(v8, (int)v14);
        if ( v4 < 0 )
          goto LABEL_11;
        HIWORD(v13[1]) = v15;
        BYTE1(v13[1]) = v16;
        v13[2] = v17;
      }
      v4 = sub_8AA490((__int64 *)a1, (int)v13, v5, v10);
LABEL_11:
      if ( v6 )
        ObfDereferenceObject(v6);
      goto LABEL_13;
    }
  }
LABEL_14:
  sub_8AA9E4(v14);
  return v4;
}
