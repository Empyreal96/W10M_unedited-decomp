// ViPostPoolAllocation 
 
int __fastcall ViPostPoolAllocation(unsigned int a1, char a2)
{
  unsigned int *v3; // r4
  int v4; // r6
  unsigned int v5; // r2
  int v6; // r7
  unsigned int v7; // r3
  unsigned int v8; // r5
  _DWORD *v9; // r2
  unsigned int *v10; // r7
  unsigned int *v11; // r2
  unsigned int v12; // r0
  unsigned int *v13; // r2
  unsigned int v14; // r1
  unsigned int v15; // r1
  unsigned int v16; // r0
  unsigned int v17; // r1
  unsigned int v18; // r1
  unsigned int *v19; // r2
  unsigned int v20; // r0
  unsigned int *v21; // r2
  unsigned int v22; // r1
  unsigned int v23; // r1
  unsigned int v24; // r4
  unsigned int v25; // r1
  unsigned int v26; // r1

  v3 = *(unsigned int **)((a1 & 0xFFFFF000) + 4);
  v4 = *(_DWORD *)a1;
  VerifierIsTrackingPool = 1;
  v5 = *(_DWORD *)(a1 + 8);
  v6 = v4 & 1;
  if ( v5 <= 0xFF0 )
  {
    v7 = v5 + 15;
  }
  else
  {
    if ( (*(_DWORD *)(a1 + 8) & 0xFFFu) > 0xFE0 || v5 >= 0x10000 )
    {
      v8 = (v5 + 4095) & 0xFFFFF000;
      goto LABEL_8;
    }
    v7 = v5 + 7;
  }
  v8 = v7 & 0xFFFFFFF8;
LABEL_8:
  if ( (v4 & 1) != 0 )
  {
    v4 &= 0xFFFFFFFE;
    *(_DWORD *)a1 = v4;
    v8 = v5;
  }
  else
  {
    if ( v5 > 0xFF0 )
      goto LABEL_17;
    v8 -= 8;
  }
  if ( v6 )
  {
    v8 = v5;
    if ( (v4 & 0xFFF) != 0 )
    {
      v9 = (_DWORD *)(v4 & 0xFFFFF000);
      v10 = (unsigned int *)((v4 & 0xFFFFF000) + 8);
    }
    else
    {
      v9 = (_DWORD *)(v4 + 4088);
      v10 = (unsigned int *)(v4 + 4084);
    }
    *v9 |= 0x4000u;
    goto LABEL_21;
  }
LABEL_17:
  if ( (v4 & 0xFFF) != 0 && (a2 & 8) != 0 )
    v10 = (unsigned int *)(v4 - 8 + 8 * (*(_WORD *)(v4 - 6) & 0x1FF) - 8);
  else
    v10 = (unsigned int *)(v8 + v4 - 4);
LABEL_21:
  *(_DWORD *)a1 = v4;
  *(_DWORD *)(a1 + 8) = v8;
  if ( (a2 & 1) != 0 )
  {
    v11 = v3 + 14;
    do
      v12 = __ldrex(v11);
    while ( __strex(v12 + v8, v11) );
    if ( v12 + v8 > v3[16] )
      v3[16] = v12 + v8;
    v13 = v3 + 10;
    do
    {
      v14 = __ldrex(v13);
      v15 = v14 + 1;
    }
    while ( __strex(v15, v13) );
    if ( v15 > v3[12] )
      v3[12] = v15;
    do
      v16 = __ldrex(&dword_620DD0);
    while ( __strex(v16 + v8, &dword_620DD0) );
    if ( v16 + v8 > dword_620DD8 )
      dword_620DD8 = v16 + v8;
    do
    {
      v17 = __ldrex(&dword_620DC0);
      v18 = v17 + 1;
    }
    while ( __strex(v18, &dword_620DC0) );
    if ( v18 > dword_620DC8 )
      dword_620DC8 = v18;
  }
  else
  {
    v19 = v3 + 15;
    do
      v20 = __ldrex(v19);
    while ( __strex(v20 + v8, v19) );
    if ( v20 + v8 > v3[17] )
      v3[17] = v20 + v8;
    v21 = v3 + 11;
    do
    {
      v22 = __ldrex(v21);
      v23 = v22 + 1;
    }
    while ( __strex(v23, v21) );
    if ( v23 > v3[13] )
      v3[13] = v23;
    do
      v24 = __ldrex(&dword_620DD4);
    while ( __strex(v24 + v8, &dword_620DD4) );
    if ( v24 + v8 > dword_620DDC )
      dword_620DDC = v24 + v8;
    do
    {
      v25 = __ldrex(&dword_620DC4);
      v26 = v25 + 1;
    }
    while ( __strex(v26, &dword_620DC4) );
    if ( v26 > dword_620DCC )
      dword_620DCC = v26;
  }
  *v10 = a1;
  return v4;
}
