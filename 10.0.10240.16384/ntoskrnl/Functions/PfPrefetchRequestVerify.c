// PfPrefetchRequestVerify 
 
int __fastcall PfPrefetchRequestVerify(unsigned int a1, unsigned int a2)
{
  int result; // r0
  int v4; // r3
  int v5; // r5
  int v6; // r1
  unsigned int v7; // r8
  _DWORD *v8; // r6
  unsigned int v9; // r5
  int v10; // r1
  int v11; // r7
  int *v12; // r5
  int v13; // t1
  int v14; // r3
  int v15; // r6
  int v16; // r1
  unsigned int v17; // r5
  unsigned int *v18; // r6
  int v19[2]; // [sp+8h] [bp-60h] BYREF
  char v20[12]; // [sp+10h] [bp-58h] BYREF
  char v21[8]; // [sp+1Ch] [bp-4Ch] BYREF
  unsigned int v22; // [sp+24h] [bp-44h]
  char v23[52]; // [sp+34h] [bp-34h] BYREF

  if ( a2 < 0x68 )
    return sub_80F1C4();
  if ( *(_DWORD *)a1 != 13 )
    return 1500;
  v4 = *(_DWORD *)(a1 + 4);
  if ( a2 != v4 )
    return 2000;
  if ( v4 + a1 < a1 )
    return 2500;
  if ( *(unsigned __int16 *)(a1 + 28) >= 8u )
    return 3000;
  if ( *(unsigned __int16 *)(a1 + 30) >= 8u )
    return 3200;
  if ( (*(_DWORD *)(a1 + 56) & 0xC0) != 0 )
    return 3400;
  if ( *(unsigned __int8 *)(a1 + 57) >= 6u )
    return 3600;
  result = PfPrefetchRequestPrepareForVerify();
  if ( !result )
  {
    v5 = *(_DWORD *)(a1 + 8);
    if ( PfRequestRangeCheck(v20, *(_DWORD *)(a1 + 32), 32 * v5, 8) )
    {
      v7 = 0;
      if ( v5 )
      {
        v8 = (_DWORD *)(v6 + a1);
LABEL_14:
        v19[0] = v8[6];
        v19[1] = v8[5];
        result = PfPrefetchRequestVerifyPath(a1, v20, v19);
        if ( !result )
        {
          v9 = v8[3] >> 1;
          if ( v9 )
          {
            if ( v9 > v22 )
            {
              result = 14000;
            }
            else if ( PfRequestRangeCheck(v21, v8[4], 32 * v9, 8) )
            {
              v11 = 0;
              v12 = (int *)(v10 + a1);
              while ( 1 )
              {
                if ( v12[6] || v12[7] )
                {
                  result = PfPrefetchRequestVerifyPath(a1, v20, v12 + 6);
                  if ( result )
                    break;
                }
                v13 = *v12;
                v12 += 8;
                v14 = (v13 & 1) != 0 ? 512 : 4096;
                result = PfPrefetchRequestVerifyRanges(a1, (int)v20, (unsigned int *)v12 - 4, v14);
                if ( result )
                  break;
                if ( (unsigned int)++v11 >= v8[3] >> 1 )
                {
                  ++v7;
                  v8 += 8;
                  if ( v7 < *(_DWORD *)(a1 + 8) )
                    goto LABEL_14;
                  goto LABEL_26;
                }
              }
            }
            else
            {
              result = 15000;
            }
          }
          else
          {
            result = 13000;
          }
        }
      }
      else
      {
LABEL_26:
        v15 = *(_DWORD *)(a1 + 20);
        if ( PfRequestRangeCheck(v23, *(_DWORD *)(a1 + 44), 24 * v15, 4) )
        {
          v17 = 0;
          if ( v15 )
          {
            v18 = (unsigned int *)(v16 + a1 + 16);
            while ( 1 )
            {
              result = PfPrefetchRequestVerifyRanges(a1, (int)v20, v18, 4096);
              if ( result )
                break;
              ++v17;
              v18 += 6;
              if ( v17 >= *(_DWORD *)(a1 + 20) )
                goto LABEL_28;
            }
          }
          else
          {
LABEL_28:
            result = 0;
          }
        }
        else
        {
          result = 40000;
        }
      }
    }
    else
    {
      result = 12500;
    }
  }
  return result;
}
