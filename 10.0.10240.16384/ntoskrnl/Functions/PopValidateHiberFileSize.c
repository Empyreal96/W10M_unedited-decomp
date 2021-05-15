// PopValidateHiberFileSize 
 
int __fastcall PopValidateHiberFileSize(unsigned int a1, unsigned int a2, _DWORD *a3)
{
  int v6; // r4
  __int64 v7; // r6
  __int64 v8; // kr08_8
  int v9; // r1
  int v10; // r3
  __int64 v12; // [sp+40h] [bp-48h]
  int v13; // [sp+48h] [bp-40h]
  int v14; // [sp+4Ch] [bp-3Ch]
  __int64 v15; // [sp+50h] [bp-38h]

  if ( !dword_61EEA4 )
  {
    v7 = 0i64;
LABEL_5:
    v6 = ZwOpenFile();
    if ( v6 >= 0 )
    {
      v6 = ZwQueryVolumeInformationFile();
      ZwClose();
      if ( v6 >= 0 )
      {
        v8 = v12 * (unsigned int)(v13 * v14) - 0x10000000;
        v6 = v8 >= (__int64)(__PAIR64__(a2, a1) - v7) ? 0 : -1073741823;
        v9 = (unsigned __int64)(v8 + v7) >> 32;
        v10 = v8 + v7;
        if ( v8 + v7 > 0 )
          goto LABEL_12;
      }
    }
    goto LABEL_11;
  }
  v6 = ZwQueryInformationFile();
  if ( v6 >= 0 )
  {
    v7 = v15;
    goto LABEL_5;
  }
LABEL_11:
  v10 = 0;
  v9 = 0;
LABEL_12:
  if ( a3 )
  {
    *a3 = v10;
    a3[1] = v9;
  }
  return v6;
}
