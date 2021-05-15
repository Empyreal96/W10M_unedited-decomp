// HvWriteLogFile 
 
int __fastcall HvWriteLogFile(_DWORD *a1, int a2, int a3, unsigned int *a4)
{
  int v5; // r2
  unsigned int v6; // r6
  int v9; // r2
  unsigned int v11; // r7
  int v12; // r1
  _QWORD *v13; // r3
  unsigned int v14; // lr
  int v15; // r1
  int (__fastcall *v16)(_DWORD *, int, _DWORD *, int, char *, _DWORD, _DWORD); // r4
  __int64 v17; // kr00_8
  int v18; // r4
  char v19[8]; // [sp+10h] [bp-30h] BYREF
  _DWORD v20[10]; // [sp+18h] [bp-28h] BYREF

  v5 = a1[23];
  v6 = 0;
  if ( (v5 & 1) != 0 || (v5 & 0x8000) != 0 )
    goto LABEL_14;
  v9 = a1[24];
  if ( v9 && a1[v9 + 444] )
  {
    if ( !a2 )
      return sub_7F3DE0();
    v6 = a1[472];
    v11 = a1[473];
    v12 = a1[24];
    switch ( v12 )
    {
      case 4:
        goto LABEL_8;
      case 5:
        v13 = a1 + 490;
        break;
      case 1:
LABEL_8:
        v13 = a1 + 488;
        break;
      default:
        v13 = 0;
        break;
    }
    v14 = a1[27];
    if ( (signed __int64)(v14 + (unsigned __int64)v11) > *v13 )
      CmpDoFileSetSizeEx((int)a1, v12, v14 + v11, (v14 + (unsigned __int64)v11) >> 32, 1);
    v15 = a1[24];
    v16 = (int (__fastcall *)(_DWORD *, int, _DWORD *, int, char *, _DWORD, _DWORD))a1[5];
    v20[0] = a1[27];
    v20[1] = v6;
    v20[2] = v11;
    if ( v16(a1, v15, v20, 1, v19, 0, 0) )
    {
      if ( CmpFileFlushAndPurge(a1, a1[24]) )
      {
        v17 = *((_QWORD *)a1 + 12);
        a1[25] = HIDWORD(v17) + 1;
        a1[27] += v11;
        *((_BYTE *)a1 + HvpLogTypeToLogArrayIndex(v17) + 120) = 1;
        CmpTraceHiveFlushWroteLogFile();
        *a4 = v11;
LABEL_14:
        v18 = 0;
        goto LABEL_15;
      }
      v18 = -1073741823;
    }
    else
    {
      v18 = -1073741491;
    }
LABEL_15:
    if ( !a2 )
    {
      if ( v6 )
        ExFreePoolWithTag(v6);
    }
    return v18;
  }
  return -1073741811;
}
