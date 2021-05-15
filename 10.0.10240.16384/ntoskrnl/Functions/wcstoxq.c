// wcstoxq 
 
unsigned int __fastcall wcstoxq(int a1, unsigned __int16 *a2, unsigned __int16 **a3, int a4, int a5, int *a6)
{
  int v6; // r7
  unsigned int v8; // r5
  unsigned int v9; // r6
  unsigned int v10; // r0
  unsigned __int16 *v11; // r4
  unsigned int v12; // t1
  int v13; // r9
  int v14; // r3
  int v15; // r3
  int v16; // r0
  unsigned int v17; // r2
  int v18; // r3
  unsigned int v19; // r1
  unsigned int v20; // r0
  unsigned int v21; // t1
  unsigned __int16 *v22; // r4
  int *v23; // r3
  unsigned int v24; // r8
  unsigned int v26; // [sp+8h] [bp-30h]
  unsigned int v28; // [sp+10h] [bp-28h]
  int v29; // [sp+14h] [bp-24h]
  unsigned int v30; // [sp+18h] [bp-20h]

  v6 = a4;
  if ( a3 )
    *a3 = a2;
  if ( !a2 || a4 && (a4 < 2 || a4 > 36) )
  {
    PopPoCoalescinCallback();
    return 0;
  }
  v8 = *a2;
  v9 = 0;
  v24 = 0;
  v10 = v8;
  v11 = a2 + 1;
  while ( iswctype(v10, 8) )
  {
    do
    {
      v12 = *v11++;
      v10 = v12;
    }
    while ( v12 == v8 );
    v8 = v10;
  }
  if ( v8 == 45 )
  {
    v13 = a5 | 2;
  }
  else
  {
    v13 = a5;
    if ( v8 != 43 )
      goto LABEL_16;
  }
  v8 = *v11++;
LABEL_16:
  if ( v6 )
    goto LABEL_23;
  if ( !wchartodigit(v8) )
  {
    v14 = *v11;
    if ( v14 != 120 && v14 != 88 )
    {
      v6 = 8;
      goto LABEL_28;
    }
    v6 = 16;
LABEL_23:
    if ( v6 == 16 && !wchartodigit(v8) )
    {
      v15 = *v11;
      if ( v15 == 120 || v15 == 88 )
      {
        v8 = v11[1];
        v11 += 2;
      }
    }
    goto LABEL_28;
  }
  v6 = 10;
LABEL_28:
  v16 = _rt_udiv64(v6, 0xFFFFFFFFFFFFFFFFui64);
  v29 = v18;
  v30 = v17;
  v28 = v19;
  v26 = v16;
  while ( 1 )
  {
    v20 = wchartodigit(v8);
    if ( v20 != -1 )
      goto LABEL_37;
    if ( (v8 < 0x41 || v8 > 0x5A) && (v8 < 0x61 || v8 > 0x7A) )
      break;
    if ( v8 >= 0x61 )
      v8 -= 32;
    v20 = v8 - 55;
LABEL_37:
    if ( v20 >= v6 )
      break;
    v13 |= 8u;
    if ( v9 < v28 || v9 <= v28 && v24 < v26 || v24 == v26 && v9 == v28 && (v29 || v20 <= v30) )
    {
      v9 = (v6 * __PAIR64__(v9, v24) + v20) >> 32;
      v24 = v6 * v24 + v20;
    }
    else
    {
      v13 |= 4u;
      if ( !a3 )
        break;
    }
    v21 = *v11++;
    v8 = v21;
  }
  v22 = v11 - 1;
  if ( (v13 & 8) != 0 )
  {
    if ( (v13 & 4) != 0
      || (v13 & 1) == 0
      && ((v13 & 2) != 0 && (v9 > 0x80000000 || v9 >= 0x80000000 && v24) || (v13 & 2) == 0 && v9 > 0x7FFFFFFF) )
    {
      v23 = a6;
      if ( !a6 )
        v23 = &gbl_errno;
      *v23 = 34;
      if ( (v13 & 1) != 0 )
      {
        v24 = -1;
      }
      else if ( (v13 & 2) != 0 )
      {
        v24 = 0;
      }
      else
      {
        v24 = -1;
      }
    }
  }
  else
  {
    if ( a3 )
      v22 = a2;
    v24 = 0;
  }
  if ( a3 )
    *a3 = v22;
  if ( (v13 & 2) != 0 )
    v24 = -v24;
  return v24;
}
