// _PnpDispatchDeviceContainer 
 
int __fastcall PnpDispatchDeviceContainer(int a1, unsigned __int16 *a2, int a3, int a4, _DWORD *a5)
{
  int v6; // r4
  __int64 v8; // kr00_8
  int v9; // r8
  int (**v10)[5]; // r6
  int v11; // r5
  unsigned int v12; // r1
  int (*v13)[5]; // t1

  switch ( a4 )
  {
    case 1:
      return CmValidateDeviceContainerName(a1, a2);
    case 2:
      return CmOpenDeviceContainerRegKey(a1, (int)a2, 64, *a5, *a5, *((_BYTE *)a5 + 4), a5[2], a5 + 3);
    case 3:
    case 4:
      return -1073741822;
    case 5:
      if ( *a5 )
        return sub_7EEA88();
      return CmGetMatchingDeviceContainerList(a1, 0, 0, a5[2], a5[3], a5[4], a5[5] & 0xFFFF0000);
    case 6:
      return CmGetDeviceContainerMappedPropertyKeys(a1, a2, a5);
    case 7:
      return CmGetDeviceContainerMappedPropertyLocales(a1, a2, a5, a5[1], a5[2], a5[3], a5[4]);
    case 8:
      return CmGetDeviceContainerMappedProperty(a1, a2, *a5, a5[1], a5[2], a5[3], a5[4], a5[5], a5[6]);
    case 9:
      v6 = -1073741802;
      v8 = *(_QWORD *)(a5 + 1);
      if ( (_DWORD)v8 )
        return v6;
      v9 = *(_DWORD *)(HIDWORD(v8) + 16);
      v10 = &off_40B4B8;
      v11 = 0;
      break;
    default:
      return -1073741811;
  }
  while ( 1 )
  {
    v13 = *v10;
    v10 += 2;
    v12 = (unsigned int)v13;
    if ( v9 == (*v13)[4] && !memcmp(HIDWORD(v8), v12, 16) )
      break;
    if ( (unsigned int)++v11 >= 4 )
      return v6;
  }
  return -1073741790;
}
