// sub_4FAB58 
 
unsigned int __fastcall sub_4FAB58(int a1, unsigned __int16 *a2, unsigned __int16 **a3, int a4, int a5, int a6)
{
  unsigned int v6; // r7
  unsigned int v8; // r6
  unsigned int v9; // r4
  unsigned __int16 *v10; // r5
  unsigned int v11; // t1
  int v12; // r8
  int v13; // r3
  int v14; // r3
  unsigned int v15; // r9
  unsigned int v16; // r0
  int v17; // r4
  unsigned int v18; // t1
  unsigned __int16 *v19; // r5

  v6 = a4;
  if ( a3 )
    *a3 = a2;
  if ( !a2 || a4 && (a4 < 2 || a4 > 36) )
  {
    PopPoCoalescinCallback();
    return 0;
  }
  v9 = *a2;
  v8 = 0;
  v10 = a2 + 1;
  while ( iswctype(v9, 8) )
  {
    v11 = *v10++;
    v9 = v11;
  }
  if ( v9 == 45 )
  {
    v12 = a5 | 2;
  }
  else
  {
    v12 = a5;
    if ( v9 != 43 )
      goto LABEL_15;
  }
  v9 = *v10++;
LABEL_15:
  if ( v6 )
    goto LABEL_22;
  if ( !wchartodigit(v9) )
  {
    v13 = *v10;
    if ( v13 != 120 && v13 != 88 )
    {
      v6 = 8;
      goto LABEL_27;
    }
    v6 = 16;
LABEL_22:
    if ( v6 == 16 && !wchartodigit(v9) )
    {
      v14 = *v10;
      if ( v14 == 120 || v14 == 88 )
      {
        v9 = v10[1];
        v10 += 2;
      }
    }
    goto LABEL_27;
  }
  v6 = 10;
LABEL_27:
  v15 = 0xFFFFFFFF / v6;
  while ( 1 )
  {
    v16 = wchartodigit(v9);
    if ( v16 != -1 )
      goto LABEL_36;
    if ( (v9 < 0x41 || v9 > 0x5A) && (v9 < 0x61 || v9 > 0x7A) )
      break;
    if ( v9 >= 0x61 )
      v9 -= 32;
    v16 = v9 - 55;
LABEL_36:
    v17 = a6;
    if ( v16 >= v6 )
      goto LABEL_46;
    v12 |= 8u;
    if ( a6 || v8 < v15 || v8 == v15 && v16 <= 0xFFFFFFFF % v6 )
    {
      v8 = v8 * v6 + v16;
    }
    else
    {
      v12 |= 4u;
      if ( !a3 )
        goto LABEL_46;
    }
    v18 = *v10++;
    v9 = v18;
  }
  v17 = a6;
LABEL_46:
  v19 = v10 - 1;
  if ( (v12 & 8) != 0 )
  {
    if ( ((v12 & 4) != 0 || (v12 & 1) == 0 && ((v12 & 2) != 0 && v8 > 0x80000000 || (v12 & 2) == 0 && v8 > 0x7FFFFFFF))
      && !v17 )
    {
      gbl_errno = 34;
      if ( (v12 & 1) != 0 )
      {
        v8 = -1;
      }
      else if ( (v12 & 2) != 0 )
      {
        v8 = 0x80000000;
      }
      else
      {
        v8 = 0x7FFFFFFF;
      }
    }
  }
  else
  {
    if ( a3 )
      v19 = a2;
    v8 = 0;
  }
  if ( a3 )
    *a3 = v19;
  if ( (v12 & 2) != 0 )
    v8 = -v8;
  return v8;
}
