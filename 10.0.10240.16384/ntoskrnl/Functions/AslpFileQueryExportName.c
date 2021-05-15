// AslpFileQueryExportName 
 
int __fastcall AslpFileQueryExportName(_BYTE *a1, int a2)
{
  int v4; // r4
  unsigned int v5; // r0
  unsigned int v6; // r2
  _BYTE *v7; // r0
  int v8; // r2
  int v9; // r1
  unsigned int v10; // r1
  unsigned int v12; // [sp+Ch] [bp-24h] BYREF
  int v13[8]; // [sp+10h] [bp-20h] BYREF

  v12 = 0;
  v13[0] = 0;
  *a1 = 0;
  v4 = AslpFileGetImageNtHeader(v13, a2);
  if ( v4 >= 0 )
  {
    v5 = RtlImageDirectoryEntryToData(*(_DWORD *)(a2 + 536), *(unsigned __int8 *)(a2 + 551), 0, (int)&v12);
    if ( v5 && v12 >= 0x28 )
    {
      v6 = *(_DWORD *)(a2 + 536);
      if ( v5 < v6 || v5 + 40 > v6 + *(_DWORD *)(a2 + 528) )
      {
        v4 = -1073741701;
        AslLogCallPrintf(
          2,
          (int)"AslpFileQueryExportName",
          2896,
          "Export directory pointer invalid (points to location outside file), invalid image format");
      }
      else
      {
        v7 = (_BYTE *)AslpImageRvaToVa(v13[0], a2 + 520);
        if ( v7 && (v8 = *(_DWORD *)(a2 + 528), v9 = *(_DWORD *)(a2 + 536), (unsigned int)v7 < v8 + v9) && *v7 )
        {
          v10 = v9 + v8 - (_DWORD)v7;
          if ( v10 > 0x100 )
            v10 = 256;
          v4 = RtlStringCchCopyA((int)a1, v10);
          if ( v4 >= 0 )
            v4 = 0;
          else
            AslLogCallPrintf(1, (int)"AslpFileQueryExportName", 2917, "RtlStringCchCopyA failed [%x]", v4);
        }
        else
        {
          v4 = -1073741701;
          AslLogCallPrintf(2, (int)"AslpFileQueryExportName", 2905, "Export directory invalid or invalid image format");
        }
      }
    }
    else
    {
      v4 = -1073741275;
      if ( v5 )
        AslLogCallPrintf(
          2,
          (int)"AslpFileQueryExportName",
          2882,
          "RtlImageDirectoryEntryToData returned ExportDirectory that was too small");
    }
  }
  else
  {
    AslLogCallPrintf(1, (int)"AslpFileQueryExportName", 2865, "AslpFileGetImageNtHeader failed [%x]", v4);
  }
  return v4;
}
