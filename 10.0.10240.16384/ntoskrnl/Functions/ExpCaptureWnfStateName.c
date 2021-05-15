// ExpCaptureWnfStateName 
 
int __fastcall ExpCaptureWnfStateName(int *a1, unsigned int *a2, char a3)
{
  int v3; // r2
  int v4; // r0
  unsigned int v5; // r2
  int v6; // r4
  unsigned int v7; // r0
  unsigned int v8; // r2
  __int64 v10; // kr00_8

  if ( a3 )
  {
    if ( (unsigned int)a1 >= MmUserProbeAddress )
      a1 = (int *)MmUserProbeAddress;
    v3 = *a1;
    v4 = a1[1];
  }
  else
  {
    v10 = *(_QWORD *)a1;
    v4 = a1[1];
    v3 = v10;
  }
  v5 = v3 ^ 0xA3BC0074;
  *a2 = v5;
  a2[1] = v4 ^ 0x41C64E6D;
  v6 = v4 ^ 0x41C64E6D;
  v7 = v5;
  if ( (v5 & 0xF) != 1 )
    return -1073741811;
  v8 = (v5 >> 6) & 0xF;
  if ( v8 > 3 )
    return -1073741811;
  if ( (((v6 << 22) | (v7 >> 10)) & 1) != 0 && v8 )
    return sub_7C4978();
  return 0;
}
