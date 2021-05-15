// HvpFindFreeCellInBin 
 
int __fastcall HvpFindFreeCellInBin(int a1, unsigned int a2, int a3, int a4, _DWORD *a5, _DWORD *a6, int a7)
{
  __int64 v7; // kr00_8
  unsigned int *v8; // r5
  int v10; // r7
  unsigned int v11; // r2
  int result; // r0

  v7 = *(_QWORD *)(a4 + 4);
  v8 = (unsigned int *)(a4 + 32);
  if ( a4 + 32 >= (unsigned int)(HIDWORD(v7) + a4) )
    return -1073741275;
  v10 = (a3 << 31) - a4;
  while ( 1 )
  {
    v11 = *v8;
    if ( (*v8 & 0x80000000) == 0 )
      break;
    v11 = -v11;
LABEL_5:
    v8 = (unsigned int *)((char *)v8 + v11);
    if ( (unsigned int)v8 >= HIDWORD(v7) + a4 )
      return -1073741275;
  }
  if ( a2 > v11 )
    goto LABEL_5;
  if ( !HvpMarkCellDirty(a1, (int)v8 + v10 + v7, 1, 0) )
    return -1073741443;
  *a6 = HvpGetHCell(a1, (char *)v8 + v10 + v7, a7);
  result = 0;
  *a5 = (char *)v8 + v10 + v7;
  return result;
}
