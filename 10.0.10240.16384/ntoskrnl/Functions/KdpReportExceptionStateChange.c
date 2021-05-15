// KdpReportExceptionStateChange 
 
int __fastcall KdpReportExceptionStateChange(int *a1, int a2, int a3)
{
  char *v6; // r1
  int v7; // r0
  int v8; // r6
  int v9; // r2
  int result; // r0
  __int16 v11; // [sp+0h] [bp-118h] BYREF
  char *v12; // [sp+4h] [bp-114h]
  __int16 v13[4]; // [sp+8h] [bp-110h] BYREF
  char v14[32]; // [sp+10h] [bp-108h] BYREF
  int v15; // [sp+30h] [bp-E8h]
  int v16; // [sp+34h] [bp-E4h]
  int v17; // [sp+38h] [bp-E0h]
  int v18; // [sp+3Ch] [bp-DCh]
  int v19; // [sp+40h] [bp-D8h]
  int v20; // [sp+44h] [bp-D4h]
  int v21; // [sp+48h] [bp-D0h]
  BOOL v22; // [sp+C8h] [bp-50h]
  int v23; // [sp+D0h] [bp-48h]

  do
  {
    KdpSetCommonState(12336, a2, (int)v14);
    v6 = v14;
    v7 = (int)a1;
    v15 = *a1;
    v16 = a1[1];
    v17 = a1[2];
    v18 = 0;
    v19 = a1[3];
    v20 = v19 >> 31;
    v8 = 15;
    v21 = a1[4];
    do
    {
      v9 = *(_DWORD *)(v7 + 20);
      v7 += 4;
      *((_QWORD *)v6 + 8) = v9;
      v6 += 8;
      --v8;
    }
    while ( v8 );
    v22 = a3 == 0;
    v23 = *(_DWORD *)(a2 + 68);
    v11 = 240;
    v12 = v14;
    v13[0] = 0;
    result = KdpSendWaitContinue(v7, (int)&v11, (int)v13, a2);
  }
  while ( result == 2 );
  return (unsigned __int8)result;
}
