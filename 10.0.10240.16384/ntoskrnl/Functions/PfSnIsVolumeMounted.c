// PfSnIsVolumeMounted 
 
int __fastcall PfSnIsVolumeMounted(unsigned __int16 *a1, _DWORD *a2, _DWORD *a3)
{
  int v5; // r4
  char v6; // r2
  int v8; // [sp+20h] [bp-50h] BYREF
  char v9[8]; // [sp+28h] [bp-48h] BYREF
  char v10[8]; // [sp+30h] [bp-40h] BYREF
  char v11[4]; // [sp+38h] [bp-38h] BYREF
  int v12; // [sp+3Ch] [bp-34h]
  int v13[12]; // [sp+40h] [bp-30h] BYREF

  RtlInitUnicodeString((unsigned int)v9, a1);
  v13[0] = 24;
  v13[1] = 0;
  v13[3] = 576;
  v13[2] = (int)v9;
  v13[4] = 0;
  v13[5] = 0;
  v5 = NtCreateFile(&v8, 1048704, v13, v10, 0, 0, 7, 1, 32, 0, 0);
  if ( v5 >= 0 )
  {
    v5 = NtQueryVolumeInformationFile(v8, v10, v11, 8, 4);
    if ( (v5 & 0xC0000000) != -1073741824 )
    {
      v6 = v12;
      *a2 = (v12 & 0x20) != 0;
      *a3 = (v6 & 1) != 0;
      v5 = 0;
    }
    NtClose();
  }
  return v5;
}
