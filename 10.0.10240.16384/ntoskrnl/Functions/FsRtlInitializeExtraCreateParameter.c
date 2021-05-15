// FsRtlInitializeExtraCreateParameter 
 
_DWORD *__fastcall FsRtlInitializeExtraCreateParameter(_DWORD *result, int a2, int a3, int a4, _DWORD *a5, int a6)
{
  int v6; // r5
  int v7; // r6
  int v8; // r7

  *result = 1215324997;
  result[1] = 0;
  result[2] = 0;
  result[3] = 0;
  v6 = a5[1];
  v7 = a5[2];
  v8 = a5[3];
  result[4] = *a5;
  result[5] = v6;
  result[6] = v7;
  result[7] = v8;
  result[9] = a2;
  result[10] = a4;
  result[8] = a3;
  result[11] = a6;
  result[12] = 0;
  return result;
}
