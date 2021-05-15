// KiPreprocessInternalInvalidOpcode 
 
int __fastcall KiPreprocessInternalInvalidOpcode(int *a1, int a2, int a3, _DWORD *a4)
{
  _DWORD *v4; // r6
  int v5; // r8
  int *v6; // r5
  int v7; // r9
  int v8; // r10
  unsigned int v9; // r2
  int v10; // r1
  unsigned __int16 *v11; // r3
  unsigned __int16 *v12; // r3
  int v13; // r1
  int v14; // r3
  int v15; // r3
  int v16; // r3
  int v18; // [sp+Ch] [bp-24h]

  v4 = a4;
  v5 = a3;
  v18 = a2;
  v6 = a1;
  v7 = 0;
  v8 = KeGetCurrentIrql(a1);
  if ( !v8 )
    KfRaiseIrql(1);
  v9 = 0;
  v10 = v4[16];
  if ( (v10 & 1) == 0 )
    goto LABEL_16;
  if ( *v6 == 268435458 )
  {
    v9 = v6[5];
LABEL_16:
    v13 = v18;
    goto LABEL_17;
  }
  if ( (v4[17] & 0x1F) == 19 )
  {
    v9 = *(unsigned __int16 *)(v10 - 1);
    if ( v9 >= 0xE800 )
      v9 = *(unsigned __int16 *)(v10 + 1) | (v9 << 16);
    goto LABEL_16;
  }
  v11 = (unsigned __int16 *)(v10 - 1);
  if ( v10 - 1 >= (unsigned int)MmUserProbeAddress )
    v11 = (unsigned __int16 *)MmUserProbeAddress;
  v9 = *v11;
  if ( v9 >= 0xE800 )
  {
    v12 = (unsigned __int16 *)(v4[16] + 1);
    if ( (unsigned int)v12 >= MmUserProbeAddress )
      v12 = (unsigned __int16 *)MmUserProbeAddress;
    v9 = *v12 | (v9 << 16);
  }
  v13 = v18;
LABEL_17:
  if ( v9 == 57081 )
  {
    v14 = -1073741676;
    goto LABEL_29;
  }
  if ( v9 == 57083 )
  {
    *v6 = -1073740791;
    v6[4] = 1;
    v6[5] = v4[1];
    v7 = KiDispatchFastFail(v6, v13, v5);
    goto LABEL_31;
  }
  if ( v9 != 57084 )
  {
    if ( v9 == 57085 )
    {
      *(_DWORD *)(v5 + 128) += 4;
      *v6 = -2147483645;
      v6[4] = 1;
      v6[5] = v4[13];
      v15 = *(_DWORD *)(v5 + 128);
    }
    else
    {
      if ( v9 != 57086 )
      {
        v14 = -1073741795;
LABEL_29:
        *v6 = v14;
        v6[4] = 0;
        v16 = v4[16];
        goto LABEL_30;
      }
      *(_DWORD *)(v5 + 128) += 2;
      *v6 = -2147483645;
      v6[4] = 1;
      v6[5] = 0;
      v15 = *(_DWORD *)(v5 + 128) - 2;
    }
    v6[3] = v15;
    goto LABEL_31;
  }
  *v6 = -1073740768;
  v6[4] = 0;
  v16 = *(_DWORD *)(v5 + 128);
LABEL_30:
  v6[3] = v16;
LABEL_31:
  if ( *v6 == -2147483645 )
    v4[16] = *(_DWORD *)(v5 + 128) - 2;
  if ( !v8 )
    KfLowerIrql(0);
  return v7;
}
