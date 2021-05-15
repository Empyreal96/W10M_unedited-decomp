// RtlFindSetBitsAndClear 
 
unsigned int __fastcall RtlFindSetBitsAndClear(unsigned int *a1, unsigned int a2, unsigned int a3)
{
  unsigned int v3; // r9
  unsigned int *v4; // r3
  unsigned int v6; // lr
  unsigned int v7; // r5
  unsigned int v8; // r0
  unsigned int v9; // r4
  unsigned int v10; // r10
  unsigned int v11; // r8
  _DWORD *v12; // r1
  int v13; // r2
  int v14; // r2
  unsigned int v15; // r3
  char v16; // r0
  _DWORD *v17; // r2
  unsigned int v18; // r0
  unsigned int v19; // r2
  unsigned int v20; // r0
  unsigned int v21; // r4
  _DWORD *v22; // r6
  unsigned int v23; // r0
  unsigned int v24; // r4
  unsigned int v25; // r0
  int v26; // r2
  unsigned int v27; // r2
  unsigned int v28; // r0
  int v29; // t1
  unsigned int v30; // r5
  int v31; // t1
  int v32; // r3
  unsigned int v34; // [sp+0h] [bp-28h]
  unsigned int v35; // [sp+4h] [bp-24h]

  v3 = *a1;
  v4 = a1;
  v34 = a3;
  if ( a3 < *a1 )
    v6 = a3;
  else
    v6 = 0;
  v7 = a1[1];
  v8 = v3 - 1;
  v35 = v4[1];
  if ( !a2 )
  {
    v9 = v6 & 0xFFFFFFF8;
    goto LABEL_76;
  }
  while ( 1 )
  {
    if ( v8 - v6 + 1 < a2 )
    {
      v9 = -1;
      goto LABEL_30;
    }
    v10 = v8 - a2 + 1;
    v11 = v7 + 4 * (v10 >> 5);
    v12 = (_DWORD *)(v7 + 4 * (v6 >> 5));
    v13 = ((1 << (v6 & 0x1F)) - 1) | ~*v12;
    if ( a2 > 0x3F )
    {
      if ( (v10 & 0x1F) != 0 )
        v11 += 4;
      if ( v13 )
      {
        if ( *++v12 != -1 )
          goto LABEL_15;
        v15 = __clz(v13);
LABEL_18:
        v14 = v15;
        if ( 1 == (unsigned __int8)(v15 >> 5) )
          v14 = 32;
      }
      else
      {
        v14 = 0;
      }
      v9 = 32 * ((int)((int)v12 - v7) >> 2) - v14;
      if ( v9 <= v10 )
      {
        v16 = a2 - v14;
        v17 = &v12[(a2 - v14) >> 5];
        while ( ++v12 != v17 )
        {
          if ( *v12 != -1 )
            goto LABEL_15;
        }
        v18 = v16 & 0x1F;
        if ( !v18 )
          goto LABEL_28;
        v19 = __clz(__rbit(~*v12));
        if ( 1 == (unsigned __int8)(v19 >> 5) )
          v19 = 32;
        if ( v19 >= v18 )
          goto LABEL_28;
LABEL_15:
        while ( (unsigned int)v12 <= v11 )
        {
          if ( *++v12 == -1 )
          {
            v15 = __clz(~*(v12 - 1));
            goto LABEL_18;
          }
        }
      }
      goto LABEL_70;
    }
    if ( a2 >= 0x20 )
    {
      while ( 1 )
      {
        while ( 1 )
        {
          while ( (v13 & 0x80000000) != 0 )
          {
            if ( (unsigned int)++v12 > v11 )
              goto LABEL_70;
            v13 = ~*v12;
          }
          v27 = __clz(v13);
          if ( 1 == (unsigned __int8)(v27 >> 5) )
            v27 = 32;
          v9 = 32 * (((int)((int)v12 - v7) >> 2) + 1) - v27;
          if ( v9 > v10 )
            goto LABEL_70;
          v28 = a2 - v27;
          if ( a2 == v27 )
            goto LABEL_28;
          v29 = v12[1];
          ++v12;
          v13 = ~v29;
          if ( v28 >= 0x20 )
            break;
LABEL_59:
          v30 = __clz(__rbit(v13));
          if ( 1 == (unsigned __int8)(v30 >> 5) )
            v30 = 32;
          if ( v30 >= v28 )
            goto LABEL_28;
          v7 = v35;
        }
        if ( !v13 )
        {
          v28 -= 32;
          if ( !v28 )
            goto LABEL_28;
          v13 = ~*++v12;
          goto LABEL_59;
        }
      }
    }
    if ( a2 <= 1 )
    {
      while ( v13 == -1 )
      {
        if ( (unsigned int)++v12 > v11 )
          goto LABEL_70;
        v13 = ~*v12;
      }
      v26 = __clz(__rbit(~v13));
      v32 = (int)v12 - v7;
LABEL_69:
      v9 = v26 + 32 * (v32 >> 2);
      if ( v9 <= v10 )
      {
LABEL_28:
        if ( v9 != -1 )
          break;
        goto LABEL_29;
      }
    }
    else
    {
      v21 = 0;
      v22 = (_DWORD *)(v7 + 4 * (v8 >> 5));
      while ( v13 != -1 )
      {
LABEL_41:
        v23 = __clz(__rbit(v13));
        if ( 1 == (unsigned __int8)(v23 >> 5) )
          v23 = 32;
        if ( v23 + v21 >= a2 )
        {
          v26 = -v21;
LABEL_68:
          v32 = (int)v12 - v35;
          goto LABEL_69;
        }
        v24 = ~v13;
        v25 = a2;
        while ( 1 )
        {
          v24 &= v24 >> (v25 >> 1);
          if ( !v24 )
            break;
          v25 -= v25 >> 1;
          if ( v25 <= 1 )
          {
            v26 = __clz(__rbit(v24));
            goto LABEL_68;
          }
        }
        if ( v12 == v22 )
          goto LABEL_70;
        v21 = __clz(v13);
        if ( 1 == (unsigned __int8)(v21 >> 5) )
          v21 = 32;
        v31 = v12[1];
        ++v12;
        v13 = ~v31;
      }
      while ( (unsigned int)++v12 <= v11 )
      {
        v13 = ~*v12;
        if ( *v12 )
        {
          v21 = 0;
          goto LABEL_41;
        }
      }
    }
LABEL_70:
    v9 = -1;
LABEL_29:
    a3 = v34;
LABEL_30:
    if ( !v6 )
      break;
    v20 = a2 + a3;
    if ( a2 + a3 > v3 )
      v20 = v3;
    v7 = v35;
    v8 = v20 - 1;
    v6 = 0;
  }
  v4 = a1;
LABEL_76:
  if ( v9 != -1 )
    RtlClearBits(v4, v9, a2);
  return v9;
}
