// BiIssueGetDriveLayoutIoctl 
 
int __fastcall BiIssueGetDriveLayoutIoctl(int a1, _DWORD *a2)
{
  _DWORD *v2; // r5
  unsigned int *v3; // r6
  int v4; // r4
  int v5; // r7
  int v7; // r7
  int v8; // r7
  _BYTE *v9; // r0
  unsigned int v10; // r0
  _DWORD *v11; // r1
  _DWORD *v12; // r2
  int v13; // r3
  int v15; // [sp+28h] [bp-40h]

  v2 = 0;
  v3 = 0;
  v4 = ZwCreateEvent();
  if ( v4 >= 0 )
  {
    v5 = 18480;
    v2 = (_DWORD *)ExAllocatePoolWithTag(1, 18480, 1262764866);
    if ( v2 )
    {
      while ( 1 )
      {
        v4 = ZwDeviceIoControlFile();
        if ( v4 == 259 )
          return sub_81432C();
        ZwResetEvent();
        if ( v4 != -1073741789 )
          break;
        ExFreePoolWithTag((unsigned int)v2);
        v5 += 9216;
        v2 = (_DWORD *)ExAllocatePoolWithTag(1, v5, 1262764866);
        if ( !v2 )
          goto LABEL_14;
      }
      if ( v4 >= 0 )
      {
LABEL_7:
        *a2 = v2;
        goto LABEL_8;
      }
      v7 = 2056;
      v3 = (unsigned int *)ExAllocatePoolWithTag(1, 2056, 1262764866);
      if ( !v3 )
        goto LABEL_12;
      while ( 1 )
      {
        v4 = ZwDeviceIoControlFile();
        if ( v4 == 259 )
        {
          v4 = ZwWaitForSingleObject();
          if ( v4 >= 0 )
            v4 = v15;
        }
        ZwResetEvent();
        if ( v4 != -1073741789 )
          break;
        ExFreePoolWithTag((unsigned int)v3);
        v7 += 2048;
        v3 = (unsigned int *)ExAllocatePoolWithTag(1, v7, 1262764866);
        if ( !v3 )
          goto LABEL_12;
      }
      if ( v4 >= 0 )
      {
        ExFreePoolWithTag((unsigned int)v2);
        v8 = 144 * *v3;
        v9 = (_BYTE *)ExAllocatePoolWithTag(1, v8 + 48, 1262764866);
        v2 = v9;
        if ( v9 )
        {
          memset(v9, 0, v8 + 48);
          *v2 = 0;
          v10 = 0;
          v11 = v3 + 2;
          v2[1] = *v3;
          v12 = v2 + 12;
          for ( v2[2] = v3[1]; v10 < *v3; v12 += 36 )
          {
            *v12 = 0;
            ++v10;
            v12[2] = *v11;
            v12[3] = v11[1];
            v12[4] = v11[2];
            v12[5] = v11[3];
            v12[6] = v11[5];
            *((_BYTE *)v12 + 28) = *((_BYTE *)v11 + 27);
            *((_BYTE *)v12 + 32) = *((_BYTE *)v11 + 24);
            *((_BYTE *)v12 + 33) = *((_BYTE *)v11 + 25);
            *((_BYTE *)v12 + 34) = *((_BYTE *)v11 + 26);
            v13 = v11[4];
            v11 += 8;
            v12[9] = v13;
          }
          goto LABEL_7;
        }
LABEL_14:
        v4 = -1073741670;
      }
LABEL_8:
      if ( v3 )
        ExFreePoolWithTag((unsigned int)v3);
    }
    else
    {
LABEL_12:
      v4 = -1073741670;
    }
  }
  if ( v4 < 0 )
  {
    if ( v2 )
      ExFreePoolWithTag((unsigned int)v2);
  }
  return v4;
}
