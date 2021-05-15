// AslpFileGetVersionBlock 
 
int __fastcall AslpFileGetVersionBlock(_DWORD *a1, _DWORD *a2, int a3, int a4)
{
  int v7; // r2
  int v8; // r4
  int v9; // r0
  int v10; // r2
  int v11; // r0
  int v12; // r4
  int v13; // r0
  const __int16 *v14; // r3
  unsigned int v15; // r4
  _WORD *v16; // r8
  _BYTE *v17; // r0
  _BYTE *v18; // r6
  int v19; // r2
  unsigned int v21; // [sp+14h] [bp-64h] BYREF
  _WORD *v22; // [sp+18h] [bp-60h] BYREF
  _BYTE *v23; // [sp+1Ch] [bp-5Ch]
  _DWORD v24[4]; // [sp+28h] [bp-50h] BYREF
  _DWORD _38[22]; // [sp+38h] [bp-40h] BYREF

  _38[18] = a1;
  _38[19] = a2;
  _38[21] = a4;
  _38[20] = a3;
  v22 = 0;
  v21 = 0;
  v23 = 0;
  memset(_38, 0, 32);
  v7 = *(_DWORD *)(a3 + 556);
  if ( v7 )
  {
    *a2 = v7 + 40;
    *a1 = v7;
    v8 = 0;
  }
  else
  {
    v9 = AslFileMappingEnsure(a3);
    v8 = v9;
    if ( v9 >= 0 )
    {
      if ( *(_DWORD *)(a3 + 552) == 6 )
      {
        v24[0] = 16;
        v24[1] = 1;
        v24[2] = 0;
        if ( *(_BYTE *)(a3 + 551) )
          v10 = 0;
        else
          v10 = 512;
        v11 = LdrResSearchResource(*(_DWORD *)(a3 + 536), (int)v24, 3u, v10 | 0x2000, &v22, (int *)&v21, 0, 0);
        v8 = v11;
        if ( v11 < 0 )
        {
          if ( AslFileResourceNotFound(v11) )
            goto LABEL_30;
          if ( v8 != -1073741701 || *(_BYTE *)(a3 + 551) )
          {
            AslLogCallPrintf(
              1,
              (int)"AslpFileGetVersionBlock",
              1278,
              "LdrResFindResource failed %ls [%x]",
              (const void *)a3,
              v8);
            goto LABEL_30;
          }
          v12 = *(_DWORD *)(a3 + 520);
          memset(_38, 0, 32);
          LOBYTE(_38[7]) = 0;
          _38[0] = v12;
          v8 = RtlFileMapMapView((int)_38, 1);
          if ( v8 < 0 )
          {
            AslLogCallPrintf(1, (int)"AslpFileGetVersionBlock", 1249, "RtlFileMapMapView failed [%x]", v8);
            goto LABEL_30;
          }
          AslLogCallPrintf(
            3,
            (int)"AslpFileGetVersionBlock",
            1258,
            "Re-mapped file as image to get version block: %ls",
            (const void *)a3);
          v13 = LdrResSearchResource(_38[4], (int)v24, 3u, 0, &v22, (int *)&v21, 0, 0);
          v8 = v13;
          if ( v13 < 0 )
            v14 = L"Did not find";
          else
            v14 = L"Found";
          AslLogCallPrintf(
            2,
            (int)"AslpFileGetVersionBlock",
            1271,
            "%ls version block after re-mapping as image [%x]",
            v14,
            v13);
          if ( v8 < 0 )
          {
            AslLogCallPrintf(1, (int)"AslpFileGetVersionBlock", 1274, "LdrResFindResource failed [%x]", v8);
            goto LABEL_30;
          }
        }
        v15 = v21;
        if ( v21 < 0x5C || (v16 = v22, wcsicmp((int)(v22 + 3), L"VS_VERSION_INFO")) )
        {
          v8 = -1073741595;
          AslLogCallPrintf(1, (int)"AslpFileGetVersionBlock", 1291, "Version block invalid");
        }
        else
        {
          v17 = AslAlloc(0, v15);
          v18 = v17;
          v23 = v17;
          if ( v17 )
          {
            memmove((int)v17, (int)v16, v15);
            if ( v15 < (unsigned __int16)*v16 )
              *v16 = v15;
            *(_DWORD *)(a3 + 556) = v18;
            v23 = 0;
            v19 = *(_DWORD *)(a3 + 556);
            *a2 = v19 + 40;
            *a1 = v19;
            v8 = 0;
          }
          else
          {
            v8 = -1073741801;
            AslLogCallPrintf(1, (int)"AslpFileGetVersionBlock", 1302, "Out of memory");
          }
        }
      }
      else
      {
        v8 = -1073741687;
      }
    }
    else
    {
      AslLogCallPrintf(1, (int)"AslpFileGetVersionBlock", 1178, "AslFileMappingEnsure failed [%x]", v9);
    }
  }
LABEL_30:
  RtlFileMapFree(_38);
  return v8;
}
