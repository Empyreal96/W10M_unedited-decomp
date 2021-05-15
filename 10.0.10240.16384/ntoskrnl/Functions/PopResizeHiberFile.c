// PopResizeHiberFile 
 
int __fastcall PopResizeHiberFile(__int64 a1, _QWORD *a2)
{
  int v3; // r5
  int v4; // r6
  int result; // r0
  int v6; // r1
  int v7; // [sp+8h] [bp-40h] BYREF
  int v8[2]; // [sp+10h] [bp-38h] BYREF
  unsigned __int64 v9; // [sp+18h] [bp-30h] BYREF
  int v10; // [sp+20h] [bp-28h]
  int v11; // [sp+28h] [bp-20h]
  int v12; // [sp+2Ch] [bp-1Ch]
  unsigned __int64 v13; // [sp+30h] [bp-18h]

  v3 = HIDWORD(a1);
  v4 = a1;
  if ( !dword_61EEA4 )
  {
LABEL_2:
    result = -1073741823;
    goto LABEL_19;
  }
  if ( qword_61EEA8 == a1 )
  {
LABEL_18:
    result = 0;
    goto LABEL_19;
  }
  if ( PopValidateHiberFileSize(a1, HIDWORD(a1), v8) < 0 )
  {
    v4 = v8[0];
    v3 = v8[1];
  }
  v9 = __PAIR64__(v3, v4);
  if ( v3 <= 0 && (v3 < 0 || !v4) )
    goto LABEL_2;
  v11 = v4;
  v12 = v3;
  result = ZwSetInformationFile();
  if ( result == 259 )
  {
    KeWaitForSingleObject(dword_61EEA4 + 92, 0, 0, 0, 0);
    result = v10;
  }
  if ( result >= 0 )
  {
    v13 = v9;
    result = ZwSetInformationFile();
    if ( result == 259 )
    {
      KeWaitForSingleObject(dword_61EEA4 + 92, 0, 0, 0, 0);
      result = v10;
    }
    if ( result >= 0 )
    {
      result = PopSanityCheckHiberFile(PopHiberInfo, dword_61EEA4, &v9, v8, &v7);
      if ( result >= 0 )
      {
        result = PopSetHiberFileMcb(v8[0], v7);
        if ( result >= 0 )
        {
          qword_61EEA8 = v9;
          FsRtlIssueFileNotificationFsctl((_DWORD *)dword_61EEA4, v6, FILE_TYPE_NOTIFICATION_GUID_HIBERNATION_FILE);
          goto LABEL_18;
        }
      }
    }
  }
LABEL_19:
  *a2 = qword_61EEA8;
  return result;
}
