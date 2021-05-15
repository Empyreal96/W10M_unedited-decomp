// PspQueryRateControlHistory 
 
int __fastcall PspQueryRateControlHistory(int a1, int a2, int a3, int *a4)
{
  int result; // r0
  int v8; // r1
  char v9; // r2
  _DWORD *v10; // r5
  unsigned int v11; // r0
  unsigned int v12; // r6
  int v13; // r3
  unsigned int v14; // r0
  unsigned int v15; // r4
  unsigned int v16; // r8
  unsigned int v17; // r0
  _BYTE *v18; // r0
  int v19; // r2
  _DWORD *v20; // r4
  int v21; // r3
  int v22; // r1
  int v23; // r3
  unsigned int v24; // r3
  unsigned int v25; // r1
  int v26; // r3
  unsigned int v27; // [sp+0h] [bp-50h] BYREF
  unsigned int v28; // [sp+4h] [bp-4Ch] BYREF
  int v29; // [sp+8h] [bp-48h] BYREF
  int v30; // [sp+Ch] [bp-44h]
  unsigned int v31[2]; // [sp+10h] [bp-40h] BYREF
  int v32[4]; // [sp+18h] [bp-38h] BYREF
  unsigned int v33; // [sp+28h] [bp-28h]
  unsigned int v34; // [sp+2Ch] [bp-24h]

  *a4 = 0;
  result = PspGetRateControlHeaderPtr();
  v10 = *(_DWORD **)result;
  if ( *(_DWORD *)result )
  {
    if ( v8 )
    {
      if ( v8 == 1 )
        return sub_7C2800(result, 1, v9);
      KeQuerySchedulingGroupHistory((int)(v10 + 32), &v29, &v28, (int *)&v27);
      v12 = v27;
      v11 = v28;
    }
    else
    {
      v32[1] = 1;
      v32[0] = v10[9];
      result = PspNetRateControlDispatch(v32);
      if ( result < 0 )
        return result;
      v11 = v33;
      v12 = v34;
      v28 = v33;
      v29 = v32[2];
      v27 = v34;
      v30 = v32[3];
    }
    if ( a2 == 2 )
    {
      v13 = 60000;
    }
    else if ( a2 == 3 )
    {
      v13 = 600000;
    }
    else
    {
      v13 = 10000;
    }
    if ( !v11 )
      __brkdiv0();
    v14 = (v13 + v11 - 1) / v11;
    v15 = (v14 + 7) >> 3;
    v16 = v14;
    if ( v15 < 8 )
      v15 = 8;
    v17 = v10[3];
    if ( !v17 )
      goto LABEL_21;
    if ( v10[4] < v15 )
    {
      ExFreePoolWithTag(v17);
      v10[3] = 0;
      v10[4] = 0;
      v12 = v27;
    }
    v18 = (_BYTE *)v10[3];
    if ( v18 )
    {
      if ( v12 >= 8 * v15 )
      {
        memset(v18, 0, v15);
      }
      else
      {
        if ( !v12 )
        {
LABEL_42:
          if ( v12 > 0x40 )
          {
            LOBYTE(v12) = 64;
            v27 = 64;
          }
          v20 = (_DWORD *)v10[3];
          v21 = v20[1];
          *v20 &= ~((1 << v12) - 1);
          v20[1] = v21 & ~((__PAIR64__(1 << (v12 - 32), 1 << v12) - 1) >> 32);
          v22 = ((1 << v27 != 0) + (1 << (v27 - 32)) - 1) & v30;
          v23 = v20[1];
          *v20 |= ((1 << v27) - 1) & v29;
          v20[1] = v23 | v22;
          v24 = v10[3];
          v31[0] = v16;
          v31[1] = v24;
          v25 = 100 * RtlNumberOfSetBits(v31);
          if ( !v16 )
            __brkdiv0();
          result = v25 / v16;
          if ( v25 / v16 >= 0x3C )
          {
            v26 = 3;
          }
          else if ( (unsigned int)result >= 0x28 )
          {
            v26 = 2;
          }
          else
          {
            if ( (unsigned int)result < 0x14 )
              goto LABEL_28;
            v26 = 1;
          }
          *a4 = v26;
LABEL_28:
          if ( a3 )
            result = (int)memset((_BYTE *)v10[3], 0, v10[4]);
          return result;
        }
        RtlCopyBitMap(v10 + 1, v10 + 1, v12);
        RtlClearBits((_BYTE *)v10 + 4, 0, v27);
      }
    }
    else
    {
LABEL_21:
      result = ExAllocatePoolWithTag(1, v15, 1649046352);
      v10[3] = result;
      if ( !result )
        return result;
      memset((_BYTE *)result, 0, v15);
      v19 = v10[3];
      v10[1] = 8 * v15;
      v10[2] = v19;
      v10[4] = v15;
    }
    v12 = v27;
    goto LABEL_42;
  }
  return result;
}
