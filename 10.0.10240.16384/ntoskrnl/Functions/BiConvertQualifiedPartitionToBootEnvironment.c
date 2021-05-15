// BiConvertQualifiedPartitionToBootEnvironment 
 
int __fastcall BiConvertQualifiedPartitionToBootEnvironment(_DWORD *a1, unsigned int a2, _DWORD *a3)
{
  int v5; // r5
  _BYTE *v6; // r0
  _DWORD *v7; // r4
  int v8; // r3

  if ( a2 < 0x3C )
    return -1073741811;
  v6 = (_BYTE *)ExAllocatePoolWithTag(1, 72, 1262764866);
  v7 = v6;
  if ( !v6 )
    return -1073741670;
  memset(v6, 0, 72);
  *v7 = 6;
  v7[2] = 72;
  v7[1] = 0;
  v7[8] = 0;
  v8 = a1[5];
  if ( v8 )
  {
    if ( v8 != 1 )
    {
      v5 = -1073741811;
      ExFreePoolWithTag((unsigned int)v7);
      return v5;
    }
    v7[9] = 0;
    v7[10] = a1[7];
    v7[11] = a1[8];
    v7[12] = a1[9];
    v7[13] = a1[10];
    v7[4] = a1[11];
    v7[5] = a1[12];
    v7[6] = a1[13];
    v7[7] = a1[14];
  }
  else
  {
    v7[9] = 1;
    v7[10] = a1[7];
    v7[4] = a1[8];
    v7[5] = a1[9];
  }
  v5 = 0;
  *a3 = v7;
  return v5;
}
