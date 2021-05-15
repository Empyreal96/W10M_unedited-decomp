// PfPrefetchRequestVerifyRanges 
 
int __fastcall PfPrefetchRequestVerifyRanges(int a1, int a2, unsigned int *a3, int a4)
{
  unsigned int v5; // r2
  unsigned int v10; // r1
  __int64 v11; // kr00_8
  unsigned int v12; // r5
  unsigned int v13; // r6
  unsigned int v14; // r9
  unsigned int v15; // lr
  unsigned int *v16; // r2
  int v17; // r7
  __int64 v18; // r0
  unsigned int v19; // r3
  unsigned __int64 v20; // kr10_8

  v5 = *a3;
  if ( !v5 )
    return sub_80F1B4();
  v10 = a3[1];
  if ( !v10 )
    return 21000;
  if ( v5 > *(_DWORD *)(a2 + 32) )
    return 22000;
  if ( !PfRequestRangeCheck(a2 + 24, v10, 16 * v5, 8) )
    return 23000;
  v11 = *(_QWORD *)a3;
  v12 = 0;
  v13 = 0;
  v14 = 0;
  v15 = 0;
  if ( !*a3 )
    return 0;
  v16 = (unsigned int *)(HIDWORD(v11) + a1);
  v17 = a4 - 1;
  while ( 1 )
  {
    HIDWORD(v18) = v16[1];
    v19 = *v16;
    if ( *(_QWORD *)v16 < __PAIR64__(v15, v12) )
      break;
    if ( (v17 & v19) != 0 )
      return 24500;
    LODWORD(v18) = v16[2];
    v20 = v18 + v19;
    v15 = HIDWORD(v20);
    v12 = v20;
    if ( v20 < __PAIR64__(HIDWORD(v18), v19) )
      return 24750;
    if ( !(_DWORD)v18 )
      return 25000;
    if ( ((unsigned int)v18 >> 12) + 2 + v14 < v14 )
      return 26000;
    ++v13;
    v16 += 4;
    v14 += ((unsigned int)v18 >> 12) + 2;
    if ( v13 >= (unsigned int)v11 )
      return 0;
  }
  return 24000;
}
