// AslpFileHasActiveMarkWrapper 
 
int __fastcall AslpFileHasActiveMarkWrapper(_DWORD *a1, int a2, int a3)
{
  unsigned int v6; // r5
  int v7; // r3
  int v8; // r4
  char *v9; // r4
  int v11; // [sp+1Ch] [bp-43Ch]
  unsigned int v12; // [sp+20h] [bp-438h]
  int v13; // [sp+24h] [bp-434h]
  char v14[16]; // [sp+28h] [bp-430h] BYREF
  _BYTE v15[1056]; // [sp+38h] [bp-420h] BYREF

  strcpy(v14, "TMSAMVOF");
  v11 = 0;
  memset(v15, 0, 1024);
  v6 = *(_DWORD *)(a3 + 528);
  if ( v6 >= 0x400 )
    v6 = 1024;
  *a1 = 0;
  v7 = (*(_QWORD *)(a3 + 528) - (unsigned __int64)(*(_DWORD *)(a2 + 156) + v6)) >> 32;
  v12 = *(_DWORD *)(a3 + 528) - (*(_DWORD *)(a2 + 156) + v6);
  v13 = v7;
  if ( v7 < 0 )
    return -1073741275;
  v8 = ZwSetInformationFile();
  if ( v8 >= 0 )
  {
    v11 = 0;
    v8 = ZwReadFile();
    if ( v8 >= 0 )
    {
      v9 = &v15[v11 - 26];
      if ( RtlCompareMemory((unsigned __int8 *)v9, (int)v14, 8) != 8
        || *((_WORD *)v9 + 4) != 1
        || *(unsigned int *)(v9 + 18) + 1i64 + *(unsigned int *)(v9 + 14) + *(unsigned int *)(v9 + 10) + 621 != *(_DWORD *)(v9 + 22) )
      {
        while ( memcmp((unsigned int)v9, (unsigned int)v14, 8)
             || *((_WORD *)v9 + 4) != 1
             || *(unsigned int *)(v9 + 10) + 1i64 + *(_QWORD *)(v9 + 22) + *(_QWORD *)(v9 + 14) + 621 != *(_QWORD *)(v9 + 30) )
        {
          if ( --v9 < v15 )
            goto LABEL_18;
        }
      }
      *a1 = 1;
LABEL_18:
      v8 = 0;
    }
    else
    {
      AslLogCallPrintf(1, (int)"AslpFileHasActiveMarkWrapper", 2623, "NtReadFile failed [%x]", v8);
    }
  }
  else
  {
    AslLogCallPrintf(1, (int)"AslpFileHasActiveMarkWrapper", 2608, "NtSetInformationFile failed [%x]", v8);
  }
  return v8;
}
