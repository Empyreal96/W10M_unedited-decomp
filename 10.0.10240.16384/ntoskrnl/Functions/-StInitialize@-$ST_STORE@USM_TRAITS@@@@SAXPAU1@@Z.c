// -StInitialize@-$ST_STORE@USM_TRAITS@@@@SAXPAU1@@Z 
 
_BYTE *__fastcall ST_STORE<SM_TRAITS>::StInitialize(int a1)
{
  _BYTE *v2; // r0
  __int64 v3; // r0
  _BYTE *result; // r0
  _DWORD *v5; // r3
  int v6; // r3

  memset((_BYTE *)a1, 0, 3512);
  *(_BYTE *)a1 = 2;
  ST_STORE<SM_TRAITS>::StDmInitialize(a1 + 56, a1 + 824);
  ST_STORE<SM_TRAITS>::StDmInitialize(a1 + 824, 0);
  memset((_BYTE *)(a1 + 1600), 0, 48);
  SmCrEncInitialize(a1 + 1672);
  *(_DWORD *)(a1 + 1776) = *(_DWORD *)(a1 + 1776) & 0xFFFFFFF8 | 6;
  *(_DWORD *)(a1 + 1780) = 3;
  v2 = memset((_BYTE *)(a1 + 1832), 0, 1296);
  *(_DWORD *)(a1 + 1832) = a1 + 1848;
  v3 = KeQueryInterruptTime(v2);
  *(_QWORD *)(a1 + 1840) = v3 + 600000000;
  *(_DWORD *)(a1 + 3144) = 500;
  *(_DWORD *)(a1 + 3160) = 1000;
  *(_DWORD *)(a1 + 3176) = 3000;
  *(_DWORD *)(a1 + 3192) = 5000;
  *(_DWORD *)(a1 + 3208) = 10000;
  *(_DWORD *)(a1 + 3224) = 20000;
  *(_DWORD *)(a1 + 3240) = 50000;
  *(_DWORD *)(a1 + 3148) = 0;
  *(_DWORD *)(a1 + 3164) = 0;
  *(_DWORD *)(a1 + 3180) = 0;
  *(_DWORD *)(a1 + 3196) = 0;
  *(_DWORD *)(a1 + 3212) = 0;
  *(_DWORD *)(a1 + 3228) = 0;
  *(_DWORD *)(a1 + 3244) = 0;
  *(_DWORD *)(a1 + 3260) = 0;
  *(_DWORD *)(a1 + 3256) = 100000;
  StLcInitialize(a1 + 3128, HIDWORD(v3), a1 + 3144);
  result = memset((_BYTE *)(a1 + 3280), 0, 200);
  v5 = (_DWORD *)(a1 + 3280);
  if ( a1 + 3280 < (unsigned int)(a1 + 3424) )
  {
    do
    {
      *v5 = -1;
      v5[1] = -1;
      v5[2] = -1;
      v5[3] = -1;
      v5 += 6;
    }
    while ( (unsigned int)v5 < a1 + 3424 );
  }
  v6 = *(_DWORD *)(a1 + 3448);
  *(_DWORD *)(a1 + 3424) = -1;
  *(_DWORD *)(a1 + 3428) = -1;
  *(_DWORD *)(a1 + 3448) = v6 & 0xFFFFFFF8 | 6;
  *(_DWORD *)(a1 + 3452) = 6;
  *(_DWORD *)(a1 + 1664) = 0;
  *(_DWORD *)(a1 + 1668) = 0;
  *(_DWORD *)(a1 + 3480) = *(_DWORD *)(a1 + 3480) & 0xFFFFFFF8 | 6;
  *(_DWORD *)(a1 + 3484) = 7;
  return result;
}
