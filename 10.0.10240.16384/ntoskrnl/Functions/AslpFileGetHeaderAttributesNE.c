// AslpFileGetHeaderAttributesNE 
 
int __fastcall AslpFileGetHeaderAttributesNE(int a1, int a2)
{
  int v4; // r5
  int v5; // r3
  unsigned __int16 *v7; // r6
  unsigned int v8; // r0
  int v9; // r3
  int v10; // r3
  unsigned __int16 *v11; // r6
  unsigned int v12; // r0
  int v13; // r3
  unsigned __int16 *v14; // [sp+8h] [bp-20h] BYREF
  unsigned __int16 *v15; // [sp+Ch] [bp-1Ch] BYREF

  v14 = 0;
  v15 = 0;
  v4 = AslFileMappingEnsure(a2);
  if ( v4 < 0 )
  {
    AslLogCallPrintf(1, (int)"AslpFileGetHeaderAttributesNE", 2158, "AslFileMappingEnsure failed [%x]", v4);
    return v4;
  }
  if ( *(_DWORD *)(a2 + 552) == 5 )
  {
    *(_DWORD *)(a1 + 448) |= 2u;
    *(_DWORD *)(a1 + 472) |= 2u;
    *(_DWORD *)(a1 + 544) |= 2u;
    *(_DWORD *)(a1 + 40) |= 2u;
    *(_DWORD *)(a1 + 616) |= 2u;
    *(_DWORD *)(a1 + 568) |= 2u;
    *(_DWORD *)(a1 + 712) |= 2u;
    *(_DWORD *)(a1 + 736) |= 2u;
    *(_DWORD *)(a1 + 760) |= 2u;
    if ( AslpFileGet16BitDescription(&v14, a2) < 0 )
    {
      v10 = *(_DWORD *)(a1 + 496) | 2;
    }
    else
    {
      v7 = v14;
      v4 = AslStringXmlSanitize(v14);
      if ( v4 < 0 )
      {
        AslLogCallPrintf(1, (int)"AslpFileGetHeaderAttributesNE", 2193, "AslStringXmlSanitize failed [%x]", v4);
        return v4;
      }
      *(_DWORD *)(a1 + 480) = 4;
      v8 = wcslen(v7);
      *(_QWORD *)(a1 + 488) = (int)v7;
      v9 = *(_DWORD *)(a1 + 496);
      *(_DWORD *)(a1 + 484) = v8;
      v10 = v9 | 5;
    }
    *(_DWORD *)(a1 + 496) = v10;
    if ( AslpFileGet16BitModuleName(&v15, a2) >= 0 )
    {
      v11 = v15;
      v4 = AslStringXmlSanitize(v15);
      if ( v4 < 0 )
      {
        AslLogCallPrintf(1, (int)"AslpFileGetHeaderAttributesNE", 2214, "AslStringXmlSanitize failed [%x]", v4);
        return v4;
      }
      *(_DWORD *)(a1 + 504) = 4;
      v12 = wcslen(v11);
      *(_QWORD *)(a1 + 512) = (int)v11;
      v13 = *(_DWORD *)(a1 + 520);
      *(_DWORD *)(a1 + 508) = v12;
      v5 = v13 | 5;
      goto LABEL_7;
    }
  }
  else
  {
    *(_DWORD *)(a1 + 496) |= 2u;
  }
  v5 = *(_DWORD *)(a1 + 520) | 2;
LABEL_7:
  *(_DWORD *)(a1 + 520) = v5;
  return 0;
}
