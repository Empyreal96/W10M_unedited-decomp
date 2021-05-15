// PspConvertJobNotificationLimitFromV2 
 
_DWORD *__fastcall PspConvertJobNotificationLimitFromV2(_DWORD *result, _DWORD *a2)
{
  *a2 = 0;
  a2[10] = result[12];
  *a2 = *result;
  a2[1] = result[1];
  a2[2] = result[2];
  a2[3] = result[3];
  a2[4] = result[4];
  a2[5] = result[5];
  a2[12] = result[6];
  a2[13] = result[7];
  a2[6] = result[8];
  a2[7] = result[9];
  a2[8] = result[10];
  a2[9] = result[11];
  return result;
}
