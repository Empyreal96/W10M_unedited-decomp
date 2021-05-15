// -SmStInitialize@-$SMKM_STORE@USM_TRAITS@@@@SAXPAU1@@Z 
 
_BYTE *__fastcall SMKM_STORE<SM_TRAITS>::SmStInitialize(int a1)
{
  _BYTE *result; // r0

  memset((_BYTE *)a1, 0, 3960);
  *(_BYTE *)(a1 + 3516) = 2;
  ST_STORE<SM_TRAITS>::StInitialize(a1);
  *(_DWORD *)(a1 + 3544) = 0;
  *(_DWORD *)(a1 + 3548) = a1 + 3544;
  *(_DWORD *)(a1 + 3552) = 0;
  *(_DWORD *)(a1 + 3556) = a1 + 3552;
  *(_DWORD *)(a1 + 3560) = 0;
  *(_DWORD *)(a1 + 3564) = a1 + 3560;
  *(_DWORD *)(a1 + 3536) = 0;
  *(_BYTE *)(a1 + 3616) = 0;
  *(_BYTE *)(a1 + 3617) = 0;
  *(_BYTE *)(a1 + 3618) = 4;
  *(_DWORD *)(a1 + 3620) = 0;
  *(_DWORD *)(a1 + 3624) = a1 + 3624;
  *(_DWORD *)(a1 + 3628) = a1 + 3624;
  *(_BYTE *)(a1 + 3600) = 0;
  *(_BYTE *)(a1 + 3601) = 0;
  *(_BYTE *)(a1 + 3602) = 4;
  *(_DWORD *)(a1 + 3604) = 0;
  *(_DWORD *)(a1 + 3608) = a1 + 3608;
  *(_DWORD *)(a1 + 3612) = a1 + 3608;
  *(_BYTE *)(a1 + 3632) = 1;
  *(_BYTE *)(a1 + 3633) = 0;
  *(_BYTE *)(a1 + 3634) = 4;
  *(_DWORD *)(a1 + 3636) = 0;
  *(_DWORD *)(a1 + 3640) = a1 + 3640;
  *(_DWORD *)(a1 + 3644) = a1 + 3640;
  result = memset((_BYTE *)(a1 + 3880), 0, 64);
  *(_BYTE *)(a1 + 3884) = 1;
  *(_BYTE *)(a1 + 3885) = 0;
  *(_BYTE *)(a1 + 3886) = 4;
  *(_DWORD *)(a1 + 3888) = 0;
  *(_DWORD *)(a1 + 3892) = a1 + 3892;
  *(_DWORD *)(a1 + 3896) = a1 + 3892;
  return result;
}
