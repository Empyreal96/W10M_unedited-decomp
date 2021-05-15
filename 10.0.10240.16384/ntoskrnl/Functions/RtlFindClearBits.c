// RtlFindClearBits 
 
unsigned int __fastcall RtlFindClearBits(unsigned int *a1, unsigned int a2, unsigned int a3)
{
  unsigned int v3; // r9
  unsigned int v6; // lr
  unsigned int v7; // r5
  unsigned int v8; // r0
  unsigned int result; // r0
  unsigned int v10; // r10
  unsigned int v11; // r8
  unsigned int *v12; // r1
  int v13; // r2
  int v14; // r2
  int v15; // r3
  int v16; // r4
  unsigned int *v17; // r6
  unsigned int v18; // r0
  unsigned int v19; // r0
  unsigned int v20; // r4
  unsigned int v21; // r3
  int v22; // t1
  unsigned int v23; // r3
  int v24; // r2
  char v25; // r4
  unsigned int *v26; // r2
  unsigned int v27; // r4
  unsigned int v28; // r2
  unsigned int v29; // r3
  int v30; // r2
  unsigned int v31; // r4
  int v32; // t1
  unsigned int v33; // r5
  unsigned int v34; // r0
  unsigned int v35; // [sp+0h] [bp-28h]
  unsigned int v36; // [sp+4h] [bp-24h]

  v3 = *a1;
  v35 = a3;
  if ( a3 >= *a1 )
    v6 = 0;
  else
    v6 = a3;
  v7 = a1[1];
  v8 = v3 - 1;
  v36 = a1[1];
  if ( !a2 )
    return sub_50EA90(v8);
  while ( 1 )
  {
    if ( v8 - v6 + 1 >= a2 )
    {
      v10 = v8 - a2 + 1;
      v11 = v7 + 4 * (v10 >> 5);
      v12 = (unsigned int *)(v7 + 4 * (v6 >> 5));
      v13 = ((1 << (v6 & 0x1F)) - 1) | *v12;
      if ( a2 > 0x3F )
      {
        if ( (v10 & 0x1F) != 0 )
          v11 += 4;
        if ( !v13 )
        {
          v24 = 0;
          goto LABEL_45;
        }
        if ( !*++v12 )
        {
          v23 = __clz(v13);
          goto LABEL_43;
        }
LABEL_40:
        while ( (unsigned int)v12 <= v11 )
        {
          if ( !*++v12 )
          {
            v23 = __clz(*(v12 - 1));
LABEL_43:
            if ( 1 == (unsigned __int8)(v23 >> 5) )
              v24 = 32;
            else
              v24 = v23;
LABEL_45:
            result = 32 * ((int)((int)v12 - v7) >> 2) - v24;
            if ( result > v10 )
              goto LABEL_33;
            v25 = a2 - v24;
            v26 = &v12[(a2 - v24) >> 5];
            while ( ++v12 != v26 )
            {
              if ( *v12 )
                goto LABEL_40;
            }
            v27 = v25 & 0x1F;
            if ( !v27 )
              goto LABEL_14;
            v28 = __clz(__rbit(*v12));
            if ( 1 == (unsigned __int8)(v28 >> 5) )
              v28 = 32;
            if ( v28 >= v27 )
              goto LABEL_14;
          }
        }
        goto LABEL_33;
      }
      if ( a2 < 0x20 )
      {
        if ( a2 > 1 )
        {
          v16 = 0;
          v17 = (unsigned int *)(v7 + 4 * (v8 >> 5));
          while ( v13 != -1 )
          {
LABEL_18:
            v18 = __clz(__rbit(v13));
            if ( 1 == (unsigned __int8)(v18 >> 5) )
              v18 = 32;
            if ( v18 + v16 >= a2 )
            {
              v14 = -v16;
LABEL_25:
              v15 = (int)v12 - v36;
              goto LABEL_13;
            }
            v19 = ~v13;
            v20 = a2;
            while ( 1 )
            {
              v19 &= v19 >> (v20 >> 1);
              if ( !v19 )
                break;
              v20 -= v20 >> 1;
              if ( v20 <= 1 )
              {
                v14 = __clz(__rbit(v19));
                goto LABEL_25;
              }
            }
            if ( v12 == v17 )
              goto LABEL_33;
            v21 = __clz(v13);
            if ( 1 == (unsigned __int8)(v21 >> 5) )
              v16 = 32;
            else
              v16 = v21;
            v22 = v12[1];
            ++v12;
            v13 = v22;
          }
          while ( (unsigned int)++v12 <= v11 )
          {
            v13 = *v12;
            if ( *v12 != -1 )
            {
              v16 = 0;
              goto LABEL_18;
            }
          }
        }
        else
        {
          while ( v13 == -1 )
          {
            if ( (unsigned int)++v12 > v11 )
              goto LABEL_33;
            v13 = *v12;
          }
          v14 = __clz(__rbit(~v13));
          v15 = (int)v12 - v7;
LABEL_13:
          result = v14 + 32 * (v15 >> 2);
          if ( result <= v10 )
          {
LABEL_14:
            if ( result != -1 )
              return result;
            goto LABEL_34;
          }
        }
LABEL_33:
        result = -1;
LABEL_34:
        a3 = v35;
        goto LABEL_74;
      }
      while ( 1 )
      {
        while ( 1 )
        {
          while ( (v13 & 0x80000000) != 0 )
          {
            if ( (unsigned int)++v12 > v11 )
              goto LABEL_33;
            v13 = *v12;
          }
          v29 = __clz(v13);
          if ( 1 == (unsigned __int8)(v29 >> 5) )
            v30 = 32;
          else
            v30 = v29;
          result = 32 * (((int)((int)v12 - v7) >> 2) + 1) - v30;
          if ( result > v10 )
            goto LABEL_33;
          v31 = a2 - v30;
          if ( a2 == v30 )
            goto LABEL_14;
          v32 = v12[1];
          ++v12;
          v13 = v32;
          if ( v31 >= 0x20 )
            break;
LABEL_63:
          v33 = __clz(__rbit(v13));
          if ( 1 == (unsigned __int8)(v33 >> 5) )
            v33 = 32;
          if ( v33 >= v31 )
            goto LABEL_14;
          v7 = v36;
        }
        if ( !v13 )
        {
          v31 -= 32;
          if ( !v31 )
            goto LABEL_14;
          v13 = *++v12;
          goto LABEL_63;
        }
      }
    }
    result = -1;
LABEL_74:
    if ( !v6 )
      return result;
    v34 = a2 + a3;
    if ( a2 + a3 > v3 )
      v34 = v3;
    v7 = v36;
    v8 = v34 - 1;
    v6 = 0;
  }
}
