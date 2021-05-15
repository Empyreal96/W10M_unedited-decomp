// ObpChargeQuotaForObject 
 
int __fastcall ObpChargeQuotaForObject(int a1, int a2, unsigned int a3, int a4)
{
  char v5; // r3
  int *v7; // r6
  int v8; // r4
  int v9; // r9
  int v10; // r3
  int result; // r0
  int v12; // r7
  int v13; // r0
  int v14; // r0
  int v15[8]; // [sp+0h] [bp-20h] BYREF

  v15[0] = a3;
  v15[1] = a4;
  v5 = *(_BYTE *)(a1 + 14);
  v15[0] = 0;
  if ( (v5 & 8) != 0 )
    v7 = (int *)(a1 - ObpInfoMaskToOffset[v5 & 0xF]);
  else
    v7 = 0;
  if ( (*(_BYTE *)(a1 + 15) & 1) == 0 )
    return 0;
  *(_BYTE *)(a1 + 15) &= 0xFEu;
  if ( v7 )
  {
    v9 = v7[1];
    v8 = *v7;
    if ( a3 || (v10 = *(_DWORD *)(a1 + 20)) != 0 && (a3 = v10 & 0xFFFFFFF8, (v10 & 0xFFFFFFF8) != 0) )
    {
      result = SeComputeQuotaInformationSize(a3, v15);
      if ( result < 0 )
        return result;
      v12 = v15[0];
      if ( v15[0] )
      {
        v13 = PsChargeSharedPoolQuota(a2, v15[0], 0);
        v7[3] = v13;
        if ( !v13 )
          JUMPOUT(0x7C04B6);
      }
      v7[2] = v12;
    }
  }
  else
  {
    v9 = *(_DWORD *)(ObTypeIndexTable[BYTE1(a1) ^ (unsigned __int8)ObHeaderCookie ^ *(unsigned __int8 *)(a1 + 12)] + 84);
    v8 = *(_DWORD *)(ObTypeIndexTable[BYTE1(a1) ^ (unsigned __int8)ObHeaderCookie ^ *(unsigned __int8 *)(a1 + 12)] + 80);
  }
  v14 = PsChargeSharedPoolQuota(a2, v8, v9);
  *(_DWORD *)(a1 + 16) = v14;
  if ( v14 )
    return 0;
  return sub_7C04A8();
}
