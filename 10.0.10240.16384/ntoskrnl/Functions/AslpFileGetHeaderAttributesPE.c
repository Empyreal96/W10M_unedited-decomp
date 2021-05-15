// AslpFileGetHeaderAttributesPE 
 
int __fastcall AslpFileGetHeaderAttributesPE(int a1, int a2)
{
  int v4; // r5
  int v5; // r3
  int v6; // r3
  int v7; // r3
  int v8; // r3
  int v9; // r3
  int v10; // r3
  int v11; // r3
  int v12; // r3
  int v13; // r3
  int v14; // r3
  unsigned __int16 *v15; // r6
  unsigned int v16; // r0
  int v17; // r3
  int v18; // r3
  unsigned __int16 v20; // [sp+10h] [bp-38h] BYREF
  unsigned __int16 v21; // [sp+12h] [bp-36h] BYREF
  unsigned __int16 v22; // [sp+14h] [bp-34h] BYREF
  int v23; // [sp+18h] [bp-30h] BYREF
  int v24; // [sp+1Ch] [bp-2Ch] BYREF
  int v25; // [sp+20h] [bp-28h] BYREF
  int v26; // [sp+24h] [bp-24h] BYREF
  int v27; // [sp+28h] [bp-20h] BYREF
  unsigned __int16 *v28; // [sp+2Ch] [bp-1Ch] BYREF

  v23 = 0;
  v24 = 0;
  v25 = 0;
  v26 = 0;
  v27 = 0;
  v28 = 0;
  v4 = AslFileMappingEnsure(a2);
  if ( v4 < 0 )
  {
    AslLogCallPrintf(1, (int)"AslpFileGetHeaderAttributesPE", 2000, "AslFileMappingEnsure failed [%x]", v4);
    return v4;
  }
  if ( *(_DWORD *)(a2 + 552) != 6 )
  {
    *(_DWORD *)(a1 + 448) |= 2u;
    *(_DWORD *)(a1 + 472) |= 2u;
    *(_DWORD *)(a1 + 544) |= 2u;
    *(_DWORD *)(a1 + 40) |= 2u;
    *(_DWORD *)(a1 + 616) |= 2u;
    *(_DWORD *)(a1 + 568) |= 2u;
    *(_DWORD *)(a1 + 760) |= 2u;
    *(_DWORD *)(a1 + 712) |= 2u;
    *(_DWORD *)(a1 + 736) |= 2u;
    return 0;
  }
  *(_DWORD *)(a1 + 496) |= 2u;
  *(_DWORD *)(a1 + 520) |= 2u;
  if ( AslpFileGetNtHeaderAttributes(&v23, &v24, &v25, &v26, &v20, &v21, &v22, a2) < 0 )
  {
    *(_DWORD *)(a1 + 448) |= 2u;
    *(_DWORD *)(a1 + 472) |= 2u;
    *(_DWORD *)(a1 + 544) |= 2u;
    *(_DWORD *)(a1 + 40) |= 2u;
    *(_DWORD *)(a1 + 712) |= 2u;
    *(_DWORD *)(a1 + 736) |= 2u;
    v12 = *(_DWORD *)(a1 + 760) | 2;
  }
  else
  {
    v5 = v23;
    *(_DWORD *)(a1 + 432) = 2;
    *(_DWORD *)(a1 + 436) = 4;
    *(_DWORD *)(a1 + 440) = v5;
    *(_DWORD *)(a1 + 444) = 0;
    v6 = *(_DWORD *)(a1 + 448);
    *(_DWORD *)(a1 + 456) = 2;
    *(_DWORD *)(a1 + 460) = 4;
    *(_DWORD *)(a1 + 468) = 0;
    *(_DWORD *)(a1 + 448) = v6 | 1;
    v7 = v24;
    *(_DWORD *)(a1 + 528) = 2;
    *(_DWORD *)(a1 + 532) = 4;
    *(_DWORD *)(a1 + 540) = 0;
    *(_DWORD *)(a1 + 464) = v7;
    v8 = *(_DWORD *)(a1 + 472);
    *(_DWORD *)(a1 + 24) = 2;
    *(_DWORD *)(a1 + 28) = 4;
    *(_DWORD *)(a1 + 36) = 0;
    *(_DWORD *)(a1 + 472) = v8 | 1;
    v9 = v25;
    *(_DWORD *)(a1 + 696) = 1;
    *(_DWORD *)(a1 + 700) = 2;
    *(_DWORD *)(a1 + 708) = 0;
    *(_DWORD *)(a1 + 536) = v9;
    v10 = *(_DWORD *)(a1 + 544);
    *(_DWORD *)(a1 + 720) = 1;
    *(_DWORD *)(a1 + 724) = 2;
    *(_DWORD *)(a1 + 732) = 0;
    *(_DWORD *)(a1 + 544) = v10 | 1;
    v11 = v26;
    *(_DWORD *)(a1 + 744) = 1;
    *(_DWORD *)(a1 + 748) = 2;
    *(_DWORD *)(a1 + 756) = 0;
    *(_DWORD *)(a1 + 32) = v11;
    *(_DWORD *)(a1 + 40) |= 1u;
    *(_DWORD *)(a1 + 704) = v20;
    *(_DWORD *)(a1 + 712) |= 1u;
    *(_DWORD *)(a1 + 728) = v21;
    *(_DWORD *)(a1 + 736) |= 1u;
    *(_DWORD *)(a1 + 752) = v22;
    v12 = *(_DWORD *)(a1 + 760) | 1;
  }
  *(_DWORD *)(a1 + 760) = v12;
  if ( AslpFileGetExeWrapper(&v27, a2) < 0 )
  {
    v14 = *(_DWORD *)(a1 + 616) | 2;
  }
  else
  {
    v13 = v27;
    *(_DWORD *)(a1 + 600) = 2;
    *(_DWORD *)(a1 + 604) = 4;
    *(_DWORD *)(a1 + 608) = v13;
    *(_DWORD *)(a1 + 612) = 0;
    v14 = *(_DWORD *)(a1 + 616) | 1;
  }
  *(_DWORD *)(a1 + 616) = v14;
  if ( AslpFileGetExportName(&v28, a2) < 0 )
  {
    v18 = *(_DWORD *)(a1 + 568) | 2;
    goto LABEL_17;
  }
  v15 = v28;
  v4 = AslStringXmlSanitize(v28);
  if ( v4 >= 0 )
  {
    *(_DWORD *)(a1 + 552) = 4;
    v16 = wcslen(v15);
    *(_QWORD *)(a1 + 560) = (int)v15;
    v17 = *(_DWORD *)(a1 + 568);
    *(_DWORD *)(a1 + 556) = v16;
    v18 = v17 | 5;
LABEL_17:
    *(_DWORD *)(a1 + 568) = v18;
    return 0;
  }
  AslLogCallPrintf(1, (int)"AslpFileGetHeaderAttributesPE", 2113, "AslStringXmlSanitize failed [%x]", v4);
  return v4;
}
