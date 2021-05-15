// AslFileAllocAndGetAttributes 
 
int __fastcall AslFileAllocAndGetAttributes(_DWORD *a1, int a2, __int64 a3)
{
  int i; // r1
  int v6; // r3
  int v7; // r3
  int v8; // r3
  int v9; // r4
  unsigned int v11; // r1
  int v12; // r9
  int v13; // r0
  int v14; // r2
  unsigned int v15; // [sp+8h] [bp-28h]
  unsigned int v16; // [sp+Ch] [bp-24h]
  int v17[8]; // [sp+10h] [bp-20h] BYREF

  v15 = HIDWORD(a3);
  v16 = a3;
  if ( a3 )
  {
    if ( *(_DWORD *)(a2 + 552) != 1 )
    {
      v9 = AslFileMappingEnsure(a2);
      if ( v9 < 0 )
      {
        AslLogCallPrintf(1, (int)"AslFileAllocAndGetAttributes", 411, "AslFileMappingEnsure failed [%x]", v9);
        return v9;
      }
      v11 = v15;
      v12 = 0;
      while ( 1 )
      {
        if ( ((__PAIR64__(v11, v16) >> v12) & 1) != 0 && (a1[6 * v12 + 4] & 3) == 0 )
        {
          switch ( v12 )
          {
            case 0:
              v9 = AslpFileGetSizeAttribute(a1, *(_DWORD *)(a2 + 520));
              if ( v9 >= 0 )
                goto LABEL_37;
              AslLogCallPrintf(1, (int)"AslFileAllocAndGetAttributes", 449, "AslpFileGetSizeAttribute failed [%x]", v9);
              return v9;
            case 1:
            case 18:
            case 19:
            case 22:
            case 23:
            case 25:
            case 29:
            case 30:
            case 31:
              v9 = AslpFileGetHeaderAttributesPE(a1, a2);
              if ( v9 >= 0 )
                goto LABEL_37;
              AslLogCallPrintf(
                1,
                (int)"AslFileAllocAndGetAttributes",
                518,
                "AslpFileGetHeaderAttributesPE failed [%x]",
                v9);
              return v9;
            case 2:
            case 26:
              v9 = AslpFileGetChecksumAttributes(a1, a2);
              if ( v9 >= 0 )
                goto LABEL_37;
              AslLogCallPrintf(
                1,
                (int)"AslFileAllocAndGetAttributes",
                547,
                "AslpFileGetChecksumAttributes failed [%x]",
                v9);
              return v9;
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
            case 11:
            case 12:
            case 13:
            case 14:
            case 15:
            case 16:
            case 24:
              v13 = AslpFileGetVersionAttributes(a1, a2);
              if ( v13 < 0 && !AslFileResourceNotFound(v13) )
                AslLogCallPrintf(
                  1,
                  (int)"AslFileAllocAndGetAttributes",
                  473,
                  "AslpFileGetVersionAttributes failed [%x]",
                  v14);
              goto LABEL_37;
            case 17:
              v9 = AslpFileGetModuleType(v17, a2);
              if ( v9 < 0 )
              {
                AslLogCallPrintf(1, (int)"AslFileAllocAndGetAttributes", 486, "AslpFileGetModuleType failed [%x]", v9);
                return v9;
              }
              a1[102] = 2;
              a1[103] = 4;
              a1[104] = v17[0];
              a1[105] = 0;
              a1[106] |= 1u;
LABEL_37:
              v11 = v15;
              break;
            case 20:
            case 21:
              v9 = AslpFileGetHeaderAttributesNE(a1, a2);
              if ( v9 >= 0 )
                goto LABEL_37;
              AslLogCallPrintf(
                1,
                (int)"AslFileAllocAndGetAttributes",
                537,
                "AslpFileGetHeaderAttributesNE failed [%x]",
                v9);
              return v9;
            case 27:
              v9 = AslpFileGetClrVersionAttribute(a1, a2);
              if ( v9 >= 0 )
                goto LABEL_37;
              AslLogCallPrintf(
                1,
                (int)"AslFileAllocAndGetAttributes",
                527,
                "AslpFileGetClrVersionAttribute failed [%x]",
                v9);
              return v9;
            case 28:
              v9 = AslpFileGetFileKindDetailAttribute(a1, a2);
              if ( v9 >= 0 )
                goto LABEL_37;
              AslLogCallPrintf(
                1,
                (int)"AslFileAllocAndGetAttributes",
                501,
                "AslpFileGetFileKindDetailAttribute failed [%x]",
                v9);
              return v9;
            default:
              return -1073741595;
          }
        }
        if ( ++v12 >= 32 )
          return 0;
      }
    }
    for ( i = 0; i < 32; ++i )
    {
      if ( i )
      {
        if ( i == 17 )
        {
          a1[102] = 2;
          a1[103] = 4;
          v7 = a1[106];
          a1[104] = 0;
          a1[105] = 0;
          a1[106] = v7 | 1;
        }
        else if ( i == 28 )
        {
          a1[168] = 2;
          a1[169] = 4;
          v6 = a1[172];
          a1[170] = 1;
          a1[171] = 0;
          a1[172] = v6 | 1;
        }
        else
        {
          a1[6 * i + 4] |= 2u;
        }
      }
      else
      {
        *a1 = 2;
        a1[1] = 4;
        v8 = a1[4];
        a1[2] = 0;
        a1[3] = 0;
        a1[4] = v8 | 1;
      }
    }
  }
  return 0;
}
