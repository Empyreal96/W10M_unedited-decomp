// FsRtlAllocateExtraCreateParameter 
 
int __fastcall FsRtlAllocateExtraCreateParameter(_DWORD *a1, unsigned int a2, char a3, int a4, int a5, _DWORD *a6)
{
  unsigned int v6; // r6
  unsigned int v10; // r1
  int v11; // r1
  int v12; // r2
  int v13; // r3
  _DWORD *v14; // r0

  v6 = a2 + 52;
  *a6 = 0;
  if ( a2 >= 0xFFFFFFCC )
    return -1073741675;
  if ( (a3 & 2) != 0 )
    return sub_7F45C4();
  v10 = a2 + 52;
  if ( (a3 & 1) != 0 )
    v14 = (_DWORD *)ExAllocatePoolWithQuotaTag(9u, v10, a5);
  else
    v14 = (_DWORD *)ExAllocatePoolWithTag(1, v10, a5);
  if ( !v14 )
    return -1073741670;
  v14[1] = 0;
  v14[2] = 0;
  v14[3] = 0;
  *v14 = 1215324997;
  v11 = a1[1];
  v12 = a1[2];
  v13 = a1[3];
  v14[4] = *a1;
  v14[5] = v11;
  v14[6] = v12;
  v14[7] = v13;
  v14[11] = 0;
  v14[12] = 0;
  v14[8] = a4;
  v14[9] = 2;
  v14[10] = v6;
  *a6 = v14 + 13;
  return 0;
}
