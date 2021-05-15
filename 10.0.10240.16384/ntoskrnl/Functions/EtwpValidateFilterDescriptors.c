// EtwpValidateFilterDescriptors 
 
int __fastcall EtwpValidateFilterDescriptors(unsigned int *a1, int a2)
{
  unsigned int v2; // r2
  int v3; // r4
  int v6; // r1
  int v7; // r5
  int v8; // r0
  unsigned int *v9; // r9
  __int64 v10; // r6
  unsigned int v12; // r1
  int v13; // r2
  unsigned __int8 *v14; // r5
  int v15; // r1
  unsigned int v16; // r2
  unsigned int v17; // r0
  char *v18; // r1
  unsigned int v19; // r2
  unsigned int v20; // r0
  char *v21; // r1
  int v22; // [sp+0h] [bp-40h]
  unsigned int v23; // [sp+4h] [bp-3Ch]
  int v24; // [sp+8h] [bp-38h]
  __int64 v25; // [sp+10h] [bp-30h] BYREF
  unsigned int v26; // [sp+18h] [bp-28h]
  int v27; // [sp+1Ch] [bp-24h]

  v2 = a1[29];
  v3 = -1073741811;
  if ( v2 <= 8 )
  {
    v6 = 16 * v2 + 120;
    v7 = 0;
    v8 = 0;
    v23 = 0;
    v24 = v6;
    v22 = 0;
    if ( v2 )
    {
      v9 = a1 + 30;
      while ( 1 )
      {
        v10 = *(_QWORD *)v9;
        if ( *(_QWORD *)v9 < (unsigned __int64)(unsigned int)v6 )
          return v3;
        if ( (a1[20] & 0x20) != 0 )
          return sub_81A674(v8);
        v12 = v9[2];
        if ( v12 > 0x400 && v9[3] != -2147483392 || v12 > 0x1000 || v10 + (unsigned __int64)v12 > a1[1] )
          return v3;
        v13 = v9[3];
        v26 = v9[2];
        v27 = v13;
        v22 += v12;
        v14 = (unsigned __int8 *)a1 + v10;
        v25 = (__int64)a1 + v10;
        switch ( v13 )
        {
          case -2147483640:
            v15 = a2;
LABEL_29:
            v8 = EtwpAllocateStringFilterData(&v25, v15);
            goto LABEL_17;
          case -2147483632:
            v15 = a2 + 4;
            goto LABEL_29;
          case -2147483616:
            v15 = a2 + 8;
            goto LABEL_29;
        }
        if ( v13 == -2147479552 )
          break;
        if ( v13 == -2147483136 )
        {
          if ( v12 - 6 <= 0x3FA )
          {
            v19 = *((unsigned __int16 *)v14 + 1);
            if ( v12 == 2 * (v19 + 2) && *((_WORD *)v14 + 1) && v19 <= 0x40 )
            {
              v20 = 0;
              if ( !*((_WORD *)v14 + 1) )
              {
LABEL_38:
                v8 = EtwpCreatePerfectHashFunction(*v14, v14 + 4);
                goto LABEL_17;
              }
              v21 = (char *)a1 + v10;
              while ( *((unsigned __int16 *)v21 + 2) != 0xFFFF )
              {
                ++v20;
                v21 += 2;
                if ( v20 >= v19 )
                  goto LABEL_38;
              }
            }
          }
LABEL_48:
          v8 = -1073741811;
          goto LABEL_17;
        }
        if ( v13 == -2147483392 )
          v8 = EtwpAllocatePayloadFilterData(a1 + 10, &v25, a2 + 20);
LABEL_17:
        if ( v8 < 0 )
          return v8;
        v9 += 4;
        ++v23;
        v6 = v24;
        if ( v23 >= a1[29] )
        {
          v7 = v22;
          goto LABEL_20;
        }
      }
      if ( v12 - 6 <= 0x3FA )
      {
        v16 = *((unsigned __int16 *)v14 + 1);
        if ( v12 == 2 * (v16 + 2) && *((_WORD *)v14 + 1) && v16 <= 0x40 )
        {
          v17 = 0;
          if ( !*((_WORD *)v14 + 1) )
            goto LABEL_38;
          v18 = (char *)a1 + v10;
          while ( *((unsigned __int16 *)v18 + 2) != 0xFFFF )
          {
            ++v17;
            v18 += 2;
            if ( v17 >= v16 )
              goto LABEL_38;
          }
        }
      }
      goto LABEL_48;
    }
LABEL_20:
    if ( v7 + v6 == a1[1] )
      v3 = 0;
  }
  return v3;
}
