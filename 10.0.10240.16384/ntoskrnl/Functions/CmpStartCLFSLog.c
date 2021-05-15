// CmpStartCLFSLog 
 
int __fastcall CmpStartCLFSLog(unsigned __int16 *a1, unsigned __int16 *a2, int a3, int a4, int a5, int a6, int *a7, _DWORD *a8, _DWORD *a9)
{
  __int16 v10; // r2
  int v13; // r4
  int v14; // r0
  int v15; // r6
  int v16; // r5
  int v17; // r1
  int v19[2]; // [sp+20h] [bp-70h] BYREF
  unsigned __int16 v20[2]; // [sp+28h] [bp-68h] BYREF
  int v21; // [sp+2Ch] [bp-64h]
  int v22; // [sp+30h] [bp-60h] BYREF
  int *v23; // [sp+34h] [bp-5Ch]
  int v24; // [sp+38h] [bp-58h]
  int v25; // [sp+3Ch] [bp-54h] BYREF
  int v26; // [sp+40h] [bp-50h]
  char v27[16]; // [sp+48h] [bp-48h] BYREF
  char v28[56]; // [sp+58h] [bp-38h] BYREF

  *a8 = 0;
  *a9 = 0;
  v10 = *a1 + *a2;
  v24 = a6;
  v23 = a7;
  v20[0] = 0;
  v20[1] = v10 + 26;
  v21 = ExAllocatePoolWithTag(1, (unsigned __int16)(v10 + 26), 538987843);
  if ( !v21 )
    return -1073741670;
  *a8 = 0;
  *a9 = 0;
  RtlAppendUnicodeStringToString(v20, (unsigned __int16 *)&CmpLogPrefix);
  RtlAppendUnicodeStringToString(v20, a1);
  RtlAppendUnicodeStringToString(v20, a2);
  RtlAppendUnicodeStringToString(v20, (unsigned __int16 *)&CmpLogExt);
  v19[0] = 0;
  v22 = 0;
  v26 = PsDisableImpersonation((_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0), (int)v27);
  KiStackAttachProcess(PsInitialSystemProcess, 0, (int)v28);
  v14 = ClfsCreateLogFile(v19, v20, -1073676288, 0, a4, 1, 8, 0, 512, 0, 0);
  v13 = v14;
  if ( v14 < 0 )
  {
    if ( v14 == -1073741772 )
    {
      v13 = ClfsCreateLogFile(v19, v20, -1073676288, 0, a4, 2, 8, 0, 512, 0, 0);
      if ( v13 >= 0 )
      {
        v16 = 0;
        while ( 1 )
        {
          v13 = CmpAddRemoveContainerToCLFSLog(
                  v19[0],
                  a1,
                  a2,
                  (unsigned __int16 *)&CmpLogExt,
                  (unsigned __int16 *)&CmpContainerSuffix,
                  v16,
                  v24,
                  1);
          if ( v13 < 0 )
            break;
          if ( (unsigned int)++v16 >= 3 )
            goto LABEL_14;
        }
      }
    }
  }
  else
  {
    v25 = 120;
    v15 = ExAllocatePoolWithTag(1, 120, 538987843);
    if ( v15 )
    {
      v13 = ClfsGetLogFileInformation(v19[0], v15, &v25);
      if ( v13 < 0 )
      {
        ExFreePoolWithTag(v15);
      }
      else
      {
        v16 = *(_DWORD *)(v15 + 40);
        ExFreePoolWithTag(v15);
LABEL_14:
        v13 = ClfsCreateMarshallingArea(v19[0], 1, 0, 0, 4096, 2, 20, &v22);
        if ( v13 >= 0 )
        {
          *v23 = v16;
          *a8 = v19[0];
          *a9 = v22;
        }
      }
    }
    else
    {
      v13 = -1073741670;
    }
  }
  KiUnstackDetachProcess((unsigned int)v28, 0);
  if ( v26 )
    PsRestoreImpersonation((_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0), (int)v27);
  ExFreePoolWithTag(v21);
  if ( v13 < 0 && v19[0] )
    ClfsCloseLogFileObject(v19[0], v17);
  return v13;
}
