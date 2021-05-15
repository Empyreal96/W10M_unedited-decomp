// RtlFindClearBitsAndSet 
 
int __fastcall RtlFindClearBitsAndSet(unsigned int *a1, unsigned int a2, unsigned int a3)
{
  unsigned int v3; // r9
  unsigned int *v4; // r3
  unsigned int v6; // lr
  unsigned int v7; // r5
  unsigned int v8; // r0
  unsigned int v10; // r10
  unsigned int v11; // r8
  unsigned int *v12; // r1
  int v13; // r2
  int v14; // r2
  int v15; // r3
  unsigned int v16; // r4
  int v17; // r4
  unsigned int *v18; // r6
  unsigned int v19; // r0
  unsigned int v20; // r0
  unsigned int v21; // r4
  unsigned int v22; // r3
  int v23; // t1
  unsigned int v24; // r0
  unsigned int v25; // r3
  int v26; // r2
  char v27; // r0
  unsigned int *v28; // r2
  unsigned int v29; // r0
  unsigned int v30; // r2
  unsigned int v31; // r3
  int v32; // r2
  unsigned int v33; // r0
  int v34; // t1
  unsigned int v35; // r5
  unsigned int v36; // [sp+0h] [bp-28h]
  unsigned int v37; // [sp+4h] [bp-24h]

  v3 = *a1;
  v4 = a1;
  v36 = a3;
  if ( a3 >= *a1 )
    v6 = 0;
  else
    v6 = a3;
  v7 = a1[1];
  v8 = v3 - 1;
  v37 = v4[1];
  if ( !a2 )
    return sub_50EAE4(v8);
  while ( v8 - v6 + 1 < a2 )
  {
    v16 = -1;
LABEL_37:
    if ( !v6 )
      goto LABEL_15;
    v24 = a2 + a3;
    if ( a2 + a3 > v3 )
      v24 = v3;
    v7 = v37;
    v8 = v24 - 1;
    v6 = 0;
  }
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
      v26 = 0;
      goto LABEL_51;
    }
    if ( !*++v12 )
    {
      v25 = __clz(v13);
      goto LABEL_49;
    }
LABEL_46:
    while ( (unsigned int)v12 <= v11 )
    {
      if ( !*++v12 )
      {
        v25 = __clz(*(v12 - 1));
LABEL_49:
        if ( 1 == (unsigned __int8)(v25 >> 5) )
          v26 = 32;
        else
          v26 = v25;
LABEL_51:
        v16 = 32 * ((int)((int)v12 - v7) >> 2) - v26;
        if ( v16 > v10 )
          goto LABEL_35;
        v27 = a2 - v26;
        v28 = &v12[(a2 - v26) >> 5];
        while ( ++v12 != v28 )
        {
          if ( *v12 )
            goto LABEL_46;
        }
        v29 = v27 & 0x1F;
        if ( !v29 )
          goto LABEL_14;
        v30 = __clz(__rbit(*v12));
        if ( 1 == (unsigned __int8)(v30 >> 5) )
          v30 = 32;
        if ( v30 >= v29 )
          goto LABEL_14;
      }
    }
    goto LABEL_35;
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
            goto LABEL_35;
          v13 = *v12;
        }
        v31 = __clz(v13);
        if ( 1 == (unsigned __int8)(v31 >> 5) )
          v32 = 32;
        else
          v32 = v31;
        v16 = 32 * (((int)((int)v12 - v7) >> 2) + 1) - v32;
        if ( v16 > v10 )
          goto LABEL_35;
        v33 = a2 - v32;
        if ( a2 == v32 )
          goto LABEL_14;
        v34 = v12[1];
        ++v12;
        v13 = v34;
        if ( v33 >= 0x20 )
          break;
LABEL_70:
        v35 = __clz(__rbit(v13));
        if ( 1 == (unsigned __int8)(v35 >> 5) )
          v35 = 32;
        if ( v35 >= v33 )
          goto LABEL_14;
        v7 = v37;
      }
      if ( !v13 )
      {
        v33 -= 32;
        if ( !v33 )
          goto LABEL_14;
        v13 = *++v12;
        goto LABEL_70;
      }
    }
  }
  if ( a2 > 1 )
  {
    v17 = 0;
    v18 = (unsigned int *)(v7 + 4 * (v8 >> 5));
    while ( v13 != -1 )
    {
LABEL_20:
      v19 = __clz(__rbit(v13));
      if ( 1 == (unsigned __int8)(v19 >> 5) )
        v19 = 32;
      if ( v19 + v17 >= a2 )
      {
        v14 = -v17;
LABEL_27:
        v15 = (int)v12 - v37;
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
          goto LABEL_27;
        }
      }
      if ( v12 == v18 )
        goto LABEL_35;
      v22 = __clz(v13);
      if ( 1 == (unsigned __int8)(v22 >> 5) )
        v17 = 32;
      else
        v17 = v22;
      v23 = v12[1];
      ++v12;
      v13 = v23;
    }
    while ( 1 )
    {
      if ( (unsigned int)++v12 > v11 )
        goto LABEL_35;
      v13 = *v12;
      if ( *v12 != -1 )
      {
        v17 = 0;
        goto LABEL_20;
      }
    }
  }
  while ( v13 == -1 )
  {
    if ( (unsigned int)++v12 > v11 )
      goto LABEL_35;
    v13 = *v12;
  }
  v14 = __clz(__rbit(~v13));
  v15 = (int)v12 - v7;
LABEL_13:
  v16 = v14 + 32 * (v15 >> 2);
  if ( v16 > v10 )
  {
LABEL_35:
    v16 = -1;
    goto LABEL_36;
  }
LABEL_14:
  if ( v16 == -1 )
  {
LABEL_36:
    a3 = v36;
    goto LABEL_37;
  }
LABEL_15:
  if ( v16 != -1 )
    RtlSetBits(a1, v16, a2);
  return v16;
}
