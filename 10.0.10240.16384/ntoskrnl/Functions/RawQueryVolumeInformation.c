// RawQueryVolumeInformation 
 
int __fastcall RawQueryVolumeInformation(int a1, _DWORD *a2, _DWORD *a3, int a4)
{
  int v5; // r3
  int v6; // r4
  int v8; // r5
  int v9; // r0
  int v10; // r5
  int v11; // r3
  int v13[6]; // [sp+0h] [bp-18h] BYREF

  v13[0] = (int)a3;
  v13[1] = a4;
  v5 = a3[3];
  v6 = a3[2];
  v8 = a2[3];
  v13[0] = v6;
  switch ( v5 )
  {
    case 1:
      v9 = RawQueryFsVolumeInfo(a1, a3[7], v8, v13);
LABEL_3:
      v6 = v13[0];
      v10 = v9;
LABEL_4:
      v11 = a3[2];
      a2[6] = v10;
      a2[7] = v11 - v6;
      IofCompleteRequest((int)a2, 1);
      return v10;
    case 3:
      v9 = RawQueryFsSizeInfo(a1, a3[7], v8, v13);
      goto LABEL_3;
    case 4:
      v9 = RawQueryFsDeviceInfo(a1, a3[7], v8, v13);
      goto LABEL_3;
    case 5:
      v9 = RawQueryFsAttributeInfo(a1, v8, v13);
      goto LABEL_3;
  }
  if ( v5 != 11 )
  {
    v10 = -1073741811;
    goto LABEL_4;
  }
  return sub_7CFD1C();
}
