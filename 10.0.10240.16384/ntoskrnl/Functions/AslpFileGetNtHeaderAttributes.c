// AslpFileGetNtHeaderAttributes 
 
int __fastcall AslpFileGetNtHeaderAttributes(_DWORD *a1, _DWORD *a2, _DWORD *a3, _DWORD *a4, _WORD *a5, _WORD *a6, _WORD *a7, int a8)
{
  int v12; // r0
  int v13; // r4
  int v14; // r1
  int v15; // r0
  __int16 v16; // r2
  _DWORD v18[9]; // [sp+Ch] [bp-24h] BYREF

  v18[0] = a2;
  v18[1] = a3;
  v18[2] = a4;
  v12 = AslpFileGetImageNtHeader(v18, a8);
  v13 = v12;
  if ( v12 >= 0 )
  {
    v14 = v18[0];
    *a2 = *(unsigned __int8 *)(v18[0] + 70) + (*(unsigned __int8 *)(v18[0] + 68) << 16);
    *a3 = *(_DWORD *)(v14 + 8);
    v15 = *(unsigned __int16 *)(v14 + 24);
    *a7 = v15;
    *a5 = *(_WORD *)(v14 + 4);
    if ( v15 == 267 || v15 == 523 )
    {
      *a1 = *(_DWORD *)(v14 + 88);
      *a4 = *(_DWORD *)(v14 + 80);
      v16 = *(_WORD *)(v14 + 92);
      v13 = 0;
    }
    else
    {
      v16 = 0;
      *a1 = 0;
      *a4 = 0;
      v13 = -1073741637;
    }
    *a6 = v16;
  }
  else
  {
    AslLogCallPrintf(1, (int)"AslpFileGetNtHeaderAttributes", 2289, "AslpFileGetImageNtHeader failed [%x]", v12);
  }
  return v13;
}
