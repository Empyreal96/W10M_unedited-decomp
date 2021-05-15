// AslFileMappingCreate 
 
int __fastcall AslFileMappingCreate(_DWORD *a1, unsigned __int16 *a2, int a3, int a4, int a5)
{
  unsigned int v9; // r0
  _WORD *v10; // r0
  _WORD *v11; // r5
  _BYTE *v13; // r0
  int v14; // r0
  int v15; // r4
  int v16; // r0
  int v17; // r2
  int v18; // r0
  int v19; // r3
  _DWORD v20[4]; // [sp+8h] [bp-48h] BYREF
  __int64 v21[3]; // [sp+18h] [bp-38h] BYREF

  if ( a2 && *a2 && a1 )
  {
    *a1 = 0;
    v9 = RtlInitUnicodeString((unsigned int)v20, a2);
    v10 = (_WORD *)AslAlloc(v9, 560);
    v11 = v10;
    if ( !v10 )
    {
      v15 = -1073741801;
LABEL_20:
      if ( (unsigned __int16 *)v20[1] != a2 )
        RtlFreeAnsiString(v20);
      return v15;
    }
    if ( RtlStringCchCopyW(v10, 0x104u, (int)a2) < 0 )
      return sub_7CC03C();
    if ( a3 == -1 )
      a3 = 0;
    v13 = v11 + 260;
    if ( a3 )
    {
      memset(v13, 0, 32);
      *((_BYTE *)v11 + 548) = 0;
      *((_DWORD *)v11 + 130) = a3;
    }
    else
    {
      v14 = RtlFileMapInitializeByNtPath((int)v13);
      v15 = v14;
      if ( v14 < 0 )
      {
        if ( !AslFileNotFound(v14) )
        {
          if ( v15 == -1073741790 || v15 == -1073741757 || v15 == -1073741805 || v15 == -1073741638 )
          {
            v17 = 160;
            v18 = 3;
          }
          else
          {
            v17 = 158;
            v18 = 1;
          }
          AslLogCallPrintf(v18, "AslFileMappingCreate", v17, "RtlFileMapInitializeByFilePath failed %S [%x]", a2, v15);
        }
        goto LABEL_18;
      }
    }
    v20[2] = 0;
    v20[3] = 0;
    memset(v21, 0, sizeof(v21));
    if ( ZwQueryInformationFile() < 0 )
      JUMPOUT(0x7CC042);
    if ( a4 )
    {
      *((_BYTE *)v11 + 551) = 1;
      *((_DWORD *)v11 + 134) = a4;
      *((_DWORD *)v11 + 135) = a5;
    }
    *((_QWORD *)v11 + 66) = v21[1];
    if ( a4 )
    {
      if ( !v21[1] )
      {
        AslLogCallPrintf(1, "AslFileMappingCreate", 205, "File size is 0 bytes yet ImageViewBase was present", 5);
        v15 = -1073741811;
LABEL_18:
        if ( v11 )
          AslFileMappingDelete(v11);
        goto LABEL_20;
      }
      v16 = AslpFileMappingGetFileKind(v11 + 260, v11 + 276, v21[1], HIDWORD(v21[1]) | LODWORD(v21[1]), 5);
      if ( v16 >= 0 )
      {
LABEL_17:
        *a1 = v11;
        v11 = 0;
        v15 = 0;
        goto LABEL_18;
      }
      AslLogCallPrintf(1, "AslFileMappingCreate", 212, "AslpFileMappingGetFileKind failed %S [%x]", v11, v16);
      v19 = 3;
    }
    else if ( v21[1] )
    {
      v19 = 2;
    }
    else
    {
      v19 = 1;
    }
    *((_DWORD *)v11 + 138) = v19;
    goto LABEL_17;
  }
  return -1073741811;
}
