// PfSnQueryVolumeInfo 
 
int __fastcall PfSnQueryVolumeInfo(int a1, unsigned __int16 *a2, _DWORD *a3, _DWORD *a4, _DWORD *a5)
{
  int v9; // r0
  int v10; // r4
  int v11; // r1
  int v12; // r2
  int v13; // r3
  char v14; // r3
  int result; // r0
  int v16[6]; // [sp+10h] [bp-60h] BYREF
  _DWORD v17[2]; // [sp+28h] [bp-48h] BYREF
  char v18[8]; // [sp+30h] [bp-40h] BYREF
  int v19[14]; // [sp+38h] [bp-38h] BYREF

  v17[0] = 0;
  v17[1] = 0;
  memset(v16, 0, 20);
  v16[4] |= 2u;
  RtlInitUnicodeString((unsigned int)v18, a2);
  v9 = PfpOpenHandleCreate(v16, a1, v18, 0, 1048960, 0, 0, 0);
  v10 = v9;
  if ( v9 < 0
    || (v9 = NtQueryVolumeInformationFile(v16[0], v17, v19, 0x18u, 1u), v10 = v9, (v9 & 0xC0000000) == -1073741824) )
  {
    v14 = v16[4];
  }
  else
  {
    *a4 = v19[0];
    a4[1] = v19[1];
    *a5 = v19[2];
    v11 = v16[1];
    v12 = v16[2];
    v13 = v16[3];
    *a3 = v16[0];
    a3[1] = v11;
    a3[2] = v12;
    a3[3] = v13;
    a3[4] = v16[4];
    v9 = (int)memset(v16, 0, 20);
    v10 = 0;
    v14 = LOBYTE(v16[4]) | 2;
    v16[4] |= 2u;
  }
  if ( (v14 & 4) != 0 )
    result = sub_806CD0(v9);
  else
    result = v10;
  return result;
}
