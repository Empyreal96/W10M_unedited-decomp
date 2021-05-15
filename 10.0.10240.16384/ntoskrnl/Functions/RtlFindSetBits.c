// RtlFindSetBits 
 
unsigned int __fastcall RtlFindSetBits(unsigned int *a1, unsigned int a2, unsigned int a3)
{
  unsigned int v3; // r9
  unsigned int v6; // lr
  unsigned int v7; // r5
  unsigned int v8; // r0
  unsigned int result; // r0
  unsigned int v10; // r10
  unsigned int v11; // r8
  _DWORD *v12; // r1
  int v13; // r2
  int v14; // r2
  int v15; // r3
  unsigned int v16; // r0
  int v17; // r4
  _DWORD *v18; // r6
  unsigned int v19; // r0
  unsigned int v20; // r0
  unsigned int v21; // r4
  unsigned int v22; // r3
  int v23; // t1
  unsigned int v24; // r3
  int v25; // r2
  char v26; // r4
  _DWORD *v27; // r2
  unsigned int v28; // r4
  unsigned int v29; // r2
  unsigned int v30; // r3
  int v31; // r2
  unsigned int v32; // r4
  int v33; // t1
  unsigned int v34; // r5
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
    return sub_548758(v8);
  while ( 1 )
  {
    if ( v8 - v6 + 1 >= a2 )
    {
      v10 = v8 - a2 + 1;
      v11 = v7 + 4 * (v10 >> 5);
      v12 = (_DWORD *)(v7 + 4 * (v6 >> 5));
      v13 = ((1 << (v6 & 0x1F)) - 1) | ~*v12;
      if ( a2 > 0x3F )
      {
        if ( (v10 & 0x1F) != 0 )
          v11 += 4;
        if ( !v13 )
        {
          v25 = 0;
          goto LABEL_49;
        }
        if ( *++v12 == -1 )
        {
          v24 = __clz(v13);
          goto LABEL_47;
        }
LABEL_44:
        while ( (unsigned int)v12 <= v11 )
        {
          if ( *++v12 == -1 )
          {
            v24 = __clz(~*(v12 - 1));
LABEL_47:
            if ( 1 == (unsigned __int8)(v24 >> 5) )
              v25 = 32;
            else
              v25 = v24;
LABEL_49:
            result = 32 * ((int)((int)v12 - v7) >> 2) - v25;
            if ( result > v10 )
              goto LABEL_16;
            v26 = a2 - v25;
            v27 = &v12[(a2 - v25) >> 5];
            while ( ++v12 != v27 )
            {
              if ( *v12 != -1 )
                goto LABEL_44;
            }
            v28 = v26 & 0x1F;
            if ( !v28 )
              goto LABEL_14;
            v29 = __clz(__rbit(~*v12));
            if ( 1 == (unsigned __int8)(v29 >> 5) )
              v29 = 32;
            if ( v29 >= v28 )
              goto LABEL_14;
          }
        }
        goto LABEL_16;
      }
      if ( a2 < 0x20 )
      {
        if ( a2 > 1 )
        {
          v17 = 0;
          v18 = (_DWORD *)(v7 + 4 * (v8 >> 5));
          while ( v13 != -1 )
          {
LABEL_24:
            v19 = __clz(__rbit(v13));
            if ( 1 == (unsigned __int8)(v19 >> 5) )
              v19 = 32;
            if ( v19 + v17 >= a2 )
            {
              v14 = -v17;
LABEL_31:
              v15 = (int)v12 - v36;
              goto LABEL_13;
            }
            v20 = ~v13;
            v21 = a2;
            while ( 1 )
            {
              v20 &= v20 >> (v21 >> 1);
              if ( !v20 )
                break;
              v21 -= v21 >> 1;
              if ( v21 <= 1 )
              {
                v14 = __clz(__rbit(v20));
                goto LABEL_31;
              }
            }
            if ( v12 == v18 )
              goto LABEL_16;
            v22 = __clz(v13);
            if ( 1 == (unsigned __int8)(v22 >> 5) )
              v17 = 32;
            else
              v17 = v22;
            v23 = v12[1];
            ++v12;
            v13 = ~v23;
          }
          while ( (unsigned int)++v12 <= v11 )
          {
            v13 = ~*v12;
            if ( *v12 )
            {
              v17 = 0;
              goto LABEL_24;
            }
          }
        }
        else
        {
          while ( v13 == -1 )
          {
            if ( (unsigned int)++v12 > v11 )
              goto LABEL_16;
            v13 = ~*v12;
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
            goto LABEL_17;
          }
        }
LABEL_16:
        result = -1;
LABEL_17:
        a3 = v35;
        goto LABEL_18;
      }
      while ( 1 )
      {
        while ( 1 )
        {
          while ( (v13 & 0x80000000) != 0 )
          {
            if ( (unsigned int)++v12 > v11 )
              goto LABEL_16;
            v13 = ~*v12;
          }
          v30 = __clz(v13);
          if ( 1 == (unsigned __int8)(v30 >> 5) )
            v31 = 32;
          else
            v31 = v30;
          result = 32 * (((int)((int)v12 - v7) >> 2) + 1) - v31;
          if ( result > v10 )
            goto LABEL_16;
          v32 = a2 - v31;
          if ( a2 == v31 )
            goto LABEL_14;
          v33 = v12[1];
          ++v12;
          v13 = ~v33;
          if ( v32 >= 0x20 )
            break;
LABEL_67:
          v34 = __clz(__rbit(v13));
          if ( 1 == (unsigned __int8)(v34 >> 5) )
            v34 = 32;
          if ( v34 >= v32 )
            goto LABEL_14;
          v7 = v36;
        }
        if ( !v13 )
        {
          v32 -= 32;
          if ( !v32 )
            goto LABEL_14;
          v13 = ~*++v12;
          goto LABEL_67;
        }
      }
    }
    result = -1;
LABEL_18:
    if ( !v6 )
      return result;
    v16 = a2 + a3;
    if ( a2 + a3 > v3 )
      v16 = v3;
    v7 = v36;
    v8 = v16 - 1;
    v6 = 0;
  }
}
