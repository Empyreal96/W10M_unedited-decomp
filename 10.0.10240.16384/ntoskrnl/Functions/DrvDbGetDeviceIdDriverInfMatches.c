// DrvDbGetDeviceIdDriverInfMatches 
 
int __fastcall DrvDbGetDeviceIdDriverInfMatches(int a1, int a2, int a3, unsigned int a4, unsigned int *a5, unsigned __int8 a6)
{
  int v6; // r8
  int v7; // r4
  unsigned int v8; // r10
  int v9; // r5
  int v11; // r6
  unsigned __int16 *v12; // r7
  int v13; // r0
  unsigned int v14; // r6
  int v15; // r8
  unsigned int v16; // r2
  unsigned int v17; // r3
  int v18; // r0
  int v19; // [sp+14h] [bp-3Ch] BYREF
  int v20; // [sp+18h] [bp-38h]
  unsigned int v21; // [sp+1Ch] [bp-34h] BYREF
  int v22; // [sp+20h] [bp-30h]
  int v23; // [sp+24h] [bp-2Ch]
  int v24; // [sp+28h] [bp-28h]
  unsigned int v25; // [sp+2Ch] [bp-24h]
  unsigned int v26; // [sp+30h] [bp-20h]

  v6 = a3;
  v20 = a3;
  v26 = a4;
  v22 = 0;
  v23 = a2;
  v21 = 0;
  v19 = 0;
  v24 = 0;
  *a5 = 0;
  v7 = PnpCtxRegQueryInfoKey(&v21, a2);
  if ( v7 >= 0 )
  {
    v8 = v21;
    v9 = v22 + 1;
    if ( !v21 )
      return sub_7E4118();
    v11 = a6;
    if ( a6 )
      v9 = v22 + 17;
    v12 = (unsigned __int16 *)ExAllocatePoolWithTag(1, 2 * v9, 1111770192);
    if ( v12 )
    {
      v25 = 0;
      if ( v8 )
      {
        while ( 1 )
        {
          if ( v11 )
          {
            v21 = 4;
            v13 = PnpCtxRegEnumValue(&v19, v23);
            v7 = v13;
            if ( v13 < 0 )
            {
              if ( v13 == -2147483622 )
                v7 = 0;
              break;
            }
            if ( !v9 )
              goto LABEL_28;
            if ( v19 == 3 )
            {
              if ( v21 != 4 )
              {
LABEL_28:
                v7 = -1073741595;
                goto LABEL_25;
              }
            }
            else
            {
              v22 = 0;
            }
            v7 = DrvDbBuildDeviceIdDriverInfMatch();
            if ( v7 < 0 )
              goto LABEL_25;
            v14 = wcslen(v12) + 1;
          }
          else
          {
            v18 = PnpCtxRegEnumValue(&v19, v23);
            v7 = v18;
            if ( v18 < 0 )
            {
              if ( v18 == -2147483622 )
                v7 = 0;
              break;
            }
            if ( !v9 )
            {
              v7 = -1073741595;
              break;
            }
            v12[v9] = 0;
            v14 = v9 + 1;
          }
          if ( v6 )
          {
            v15 = v24 + v14;
            if ( v24 + v14 < v26 )
            {
              RtlStringCchCopyExW((_WORD *)(v20 + 2 * v24), v26 - v24, v12, 0, 0, 2304);
              v24 = v15;
            }
            v6 = v20;
          }
          v16 = v25 + 1;
          *a5 += v14;
          v25 = v16;
          if ( v16 >= v8 )
            break;
          v11 = a6;
        }
      }
      if ( v7 >= 0 )
      {
        if ( *a5 )
        {
          v17 = *a5 + 1;
          *a5 = v17;
          if ( v6 && v17 <= v26 )
            *(_WORD *)(v6 + 2 * v17 - 2) = 0;
          else
            v7 = -1073741789;
        }
        else
        {
          v7 = -1073741275;
        }
      }
LABEL_25:
      ExFreePoolWithTag((unsigned int)v12);
    }
    else
    {
      v7 = -1073741801;
    }
  }
  return v7;
}
