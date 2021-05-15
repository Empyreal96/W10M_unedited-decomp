// PspConvertJobLimitViolationToV2 
 
int *__fastcall PspConvertJobLimitViolationToV2(int *result, int *a2)
{
  int v2; // r4
  int v3; // r5

  v2 = *result;
  *a2 = *result;
  v3 = result[1];
  a2[1] = v3;
  a2[2] = result[2];
  a2[3] = result[3];
  a2[4] = result[4];
  a2[5] = result[5];
  a2[6] = result[6];
  a2[7] = result[7];
  a2[8] = result[8];
  a2[9] = result[9];
  a2[10] = result[10];
  a2[11] = result[11];
  a2[12] = result[12];
  a2[13] = result[13];
  a2[14] = result[14];
  a2[15] = result[15];
  a2[16] = result[20];
  a2[17] = result[21];
  a2[18] = result[16];
  a2[19] = result[17];
  a2[20] = result[18];
  a2[21] = result[19];
  *a2 = v2 & 0x78204;
  a2[1] = v3 & 0x78204;
  return result;
}
