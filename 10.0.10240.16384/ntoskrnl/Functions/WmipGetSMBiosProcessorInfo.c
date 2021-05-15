// WmipGetSMBiosProcessorInfo 
 
int WmipGetSMBiosProcessorInfo()
{
  int v0; // r6
  int v1; // r5
  int result; // r0
  _BYTE *v3; // r4
  unsigned int v4; // r9
  int v5; // r10
  unsigned int v6; // r7
  int v7; // r8
  int v8; // r7
  int v9; // r0
  int v10; // [sp+8h] [bp-A0h]
  int v11; // [sp+10h] [bp-98h] BYREF
  unsigned int v12; // [sp+14h] [bp-94h] BYREF
  int v13; // [sp+18h] [bp-90h] BYREF
  int v14; // [sp+20h] [bp-88h] BYREF
  int v15; // [sp+28h] [bp-80h]
  int v16; // [sp+2Ch] [bp-7Ch]
  char *v17; // [sp+30h] [bp-78h]
  int v18; // [sp+34h] [bp-74h]
  int v19; // [sp+38h] [bp-70h]
  int v20; // [sp+3Ch] [bp-6Ch]
  char v21[8]; // [sp+48h] [bp-60h] BYREF
  _BYTE *v22; // [sp+50h] [bp-58h] BYREF
  char v23[8]; // [sp+58h] [bp-50h] BYREF
  unsigned int v24; // [sp+6Ch] [bp-3Ch]
  unsigned __int16 v25[28]; // [sp+70h] [bp-38h] BYREF

  v0 = 0;
  v1 = 0;
  RtlInitUnicodeString((unsigned int)&v14, (unsigned __int16 *)&dword_8CE900);
  RtlInitUnicodeString((unsigned int)&v13, (unsigned __int16 *)&dword_8CE900);
  result = WmipFindSMBiosStructure(4, &v22, &v12, &v11);
  if ( result >= 0 )
  {
    v3 = v22;
    v5 = v11;
    v4 = v12;
    if ( v22[5] == 3 )
    {
      v6 = (unsigned __int8)v22[16];
      v7 = v12 + v11;
      if ( v22[7] && WmipGetSMBiosString((int)v22, (unsigned __int8)v22[7], (_BYTE *)(v7 - 1), (int)&v14) >= 0 )
        v0 = 1;
      if ( v6 && WmipGetSMBiosString((int)v3, v6, (_BYTE *)(v7 - 1), (int)&v13) >= 0 )
        v1 = 1;
      if ( !v0 )
        return sub_817980();
      RtlInitUnicodeString((unsigned int)v23, L"\\Registry\\Machine\\HARDWARE\\DESCRIPTION\\System\\CentralProcessor");
      v15 = 24;
      v16 = 0;
      v17 = v23;
      v19 = 0;
      v20 = 0;
      v18 = 576;
      if ( ZwOpenKey() >= 0 )
      {
        v8 = 0;
        v9 = ZwEnumerateKey();
        if ( v9 != -2147483622 )
        {
          do
          {
            ++v8;
            if ( v9 >= 0 )
            {
              v25[v24 >> 1] = 0;
              RtlInitUnicodeString((unsigned int)v23, v25);
              v15 = 24;
              v16 = v10;
              v17 = v23;
              v18 = 576;
              v19 = 0;
              v20 = 0;
              if ( ZwOpenKey() >= 0 )
              {
                RtlInitUnicodeString((unsigned int)v21, L"VendorIdentifier");
                ZwSetValueKey();
                if ( v1 )
                {
                  RtlInitUnicodeString((unsigned int)v21, L"ProcessorNameString");
                  ZwSetValueKey();
                }
                ZwClose();
              }
            }
            v9 = ZwEnumerateKey();
          }
          while ( v9 != -2147483622 );
          v5 = v11;
          v4 = v12;
        }
        ZwClose();
      }
      if ( v1 )
        RtlFreeAnsiString(&v13);
      result = RtlFreeAnsiString(&v14);
    }
    if ( v4 )
      result = MmUnmapIoSpace(v4, v5);
  }
  return result;
}
