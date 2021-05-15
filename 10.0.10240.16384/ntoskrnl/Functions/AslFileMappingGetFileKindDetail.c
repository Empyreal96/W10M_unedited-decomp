// AslFileMappingGetFileKindDetail 
 
int __fastcall AslFileMappingGetFileKindDetail(int *a1, int a2)
{
  int v2; // r3
  int v3; // r4
  int v6; // r5
  const char *v7; // r3
  int v8; // r2
  int v9; // r3
  __int16 v11; // [sp+8h] [bp-20h] BYREF
  unsigned __int16 v12; // [sp+Ah] [bp-1Eh] BYREF
  int v13; // [sp+Ch] [bp-1Ch] BYREF
  int v14[6]; // [sp+10h] [bp-18h] BYREF

  v12 = 0;
  v11 = 0;
  v13 = 0;
  v14[0] = 0;
  v2 = *(_DWORD *)(a2 + 552);
  v3 = 0;
  if ( v2 == 1 )
    v3 = 1;
  if ( v2 == 1 )
    goto LABEL_40;
  v6 = AslFileMappingEnsure(a2);
  if ( v6 >= 0 )
  {
    v9 = *(_DWORD *)(a2 + 552);
    switch ( v9 )
    {
      case 3:
        v3 = 2;
        break;
      case 4:
        v3 = 3;
        break;
      case 5:
        v3 = 4;
        break;
      case 6:
        v6 = AslFileMappingGetImageTypeEx(&v12, &v11, &v13, v14, a2);
        if ( v6 < 0 )
        {
          v7 = "AslFileMappingGetImageTypeEx failed [%x]";
          v8 = 1174;
          goto LABEL_6;
        }
        if ( v13 )
        {
          if ( v11 == 523 )
          {
            v3 = 15;
          }
          else if ( (v14[0] & 0x20002) == 131074 )
          {
            v3 = 14;
          }
          else if ( (v14[0] & 0x20003) == 1 )
          {
            v3 = 13;
          }
          else
          {
            v3 = 12;
          }
        }
        else if ( v11 == 523 )
        {
          switch ( v12 )
          {
            case 0x200u:
              v3 = 11;
              break;
            case 0x8664u:
              v3 = 9;
              break;
            case 0xAA64u:
              v3 = 10;
              break;
            default:
              v3 = 8;
              break;
          }
        }
        else if ( v12 == 332 )
        {
          v3 = 6;
        }
        else if ( v12 == 448 || v12 == 452 )
        {
          v3 = 7;
        }
        else
        {
          v3 = 5;
        }
        break;
      default:
        v6 = -1073741823;
        v3 = 0;
        AslLogCallPrintf(
          1,
          (int)"AslFileMappingGetFileKindDetail",
          1164,
          "Unhandled ASL_FILE_KIND: %d",
          *(_DWORD *)(a2 + 552));
        goto LABEL_41;
    }
LABEL_40:
    v6 = 0;
    goto LABEL_41;
  }
  v7 = "AslFileMappingEnsure failed [%x]";
  v8 = 1129;
LABEL_6:
  AslLogCallPrintf(1, (int)"AslFileMappingGetFileKindDetail", v8, v7, v6);
LABEL_41:
  if ( a1 )
    *a1 = v3;
  return v6;
}
