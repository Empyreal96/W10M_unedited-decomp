// BiConvertBootEnvironmentDeviceToQualifiedPartition 
 
int __fastcall BiConvertBootEnvironmentDeviceToQualifiedPartition(_DWORD *a1, _DWORD *a2, _DWORD *a3)
{
  int v6; // r5
  _BYTE *v7; // r0
  _DWORD *v8; // r4
  int v9; // r3

  if ( *a1 == 6 )
  {
    v7 = (_BYTE *)ExAllocatePoolWithTag(1, 60, 1262764866);
    v8 = v7;
    if ( !v7 )
      return -1073741670;
    memset(v7, 0, 60);
    *v8 = 6;
    if ( a1[8] )
    {
      v6 = -1073741637;
LABEL_13:
      ExFreePoolWithTag((unsigned int)v8);
      return v6;
    }
    v9 = a1[9];
    if ( v9 == 1 )
    {
      v8[5] = 0;
      v8[7] = a1[10];
      v8[8] = a1[4];
      v8[9] = a1[5];
    }
    else
    {
      if ( v9 )
      {
        v6 = -1073741811;
        goto LABEL_13;
      }
      v8[5] = 1;
      v8[7] = a1[10];
      v8[8] = a1[11];
      v8[9] = a1[12];
      v8[10] = a1[13];
      v8[11] = a1[4];
      v8[12] = a1[5];
      v8[13] = a1[6];
      v8[14] = a1[7];
    }
    v6 = 0;
    *a3 = 60;
    *a2 = v8;
    return v6;
  }
  return -1073741811;
}
