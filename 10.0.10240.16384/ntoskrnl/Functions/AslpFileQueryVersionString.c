// AslpFileQueryVersionString 
 
int __fastcall AslpFileQueryVersionString(_DWORD *a1, int a2, unsigned __int16 *a3, unsigned int a4, int a5)
{
  int *v7; // r10
  unsigned int i; // r5
  int v10; // t1
  int v11; // r3
  int v12; // r4
  int v13; // r0
  int v14; // r5
  int v15; // t1
  int v16; // r0
  int v18; // [sp+8h] [bp-130h] BYREF
  int v19; // [sp+Ch] [bp-12Ch] BYREF
  int v20; // [sp+10h] [bp-128h]
  int v21; // [sp+14h] [bp-124h]
  unsigned __int16 v22[144]; // [sp+18h] [bp-120h] BYREF

  v7 = (int *)off_41D960;
  v20 = a2;
  v21 = a5;
  v22[0] = 0;
  v18 = 0;
  v19 = 0;
  *a1 = 0;
  for ( i = 0; i < 4; ++i )
  {
    v10 = *v7++;
    v12 = RtlStringCchCopyW(v22, 0x80u, v10);
    if ( v12 < 0 )
    {
      AslLogCallPrintf(1, (int)"AslpFileQueryVersionString", 1909, "RtlStringCchCopyW failed [%x]", v12);
      return v12;
    }
    v12 = RtlStringCchCatW(v22, 0x80u, v21, v11);
    if ( v12 < 0 )
    {
      AslLogCallPrintf(1, (int)"AslpFileQueryVersionString", 1915, "RtlStringCchCatW failed [%x]", v12);
      return v12;
    }
    v13 = AslpFileVerQueryValue(v20, v22, &v18, &v19);
    v12 = v13;
    if ( v13 >= 0 )
    {
LABEL_17:
      v12 = 0;
      *a1 = v18;
      return v12;
    }
    if ( v13 != -1073741275 )
    {
      AslLogCallPrintf(1, (int)"AslpFileQueryVersionString", 1925, "AslpFileVerQueryValue failed [%x]", v13);
      return v12;
    }
  }
  if ( !a3 )
    return -1073741275;
  v14 = 0;
  if ( !a4 )
    return -1073741275;
  while ( 1 )
  {
    v15 = *a3;
    a3 += 2;
    v12 = RtlStringCchPrintfW(v22, 0x80u, (int)L"\\StringFileInfo\\%04X%04X\\%s", v15);
    if ( v12 < 0 )
      break;
    v16 = AslpFileVerQueryValue(v20, v22, &v18, &v19);
    v12 = v16;
    if ( v16 >= 0 )
      goto LABEL_17;
    if ( v16 != -1073741275 )
    {
      AslLogCallPrintf(1, (int)"AslpFileQueryVersionString", 1954, "AslpFileVerQueryValue failed [%x]", v16);
      return v12;
    }
    if ( ++v14 >= a4 )
      return -1073741275;
  }
  AslLogCallPrintf(1, (int)"AslpFileQueryVersionString", 1943, "RtlStringCchPrintfW failed [%x]", v12);
  return v12;
}
