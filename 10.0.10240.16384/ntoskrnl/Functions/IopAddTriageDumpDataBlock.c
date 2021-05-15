// IopAddTriageDumpDataBlock 
 
int __fastcall IopAddTriageDumpDataBlock(unsigned int a1, int *a2, __int64 *a3, int a4, unsigned int a5)
{
  int v9; // r2
  int v10; // r0
  int v11; // t1
  __int64 v13; // kr00_8
  _DWORD *v14; // r2

  if ( !a5 || a5 >= 0x20000 || !IopIsAddressRangeValid(a4, a5) )
    return 0;
  v9 = 0;
  if ( !a1 )
  {
LABEL_8:
    if ( a3 )
    {
      v13 = *a3;
      if ( (unsigned int)v13 < HIDWORD(v13) )
      {
        v14 = (_DWORD *)(*((_DWORD *)a3 + 2) + 8 * v13);
        *(_DWORD *)a3 = v13 + 1;
        *v14 = a4;
        v14[1] = a5 + a4;
        return 1;
      }
    }
    return 0;
  }
  while ( 1 )
  {
    v10 = a2[2];
    v11 = *a2;
    a2 += 3;
    if ( v11 )
      return sub_555630(v10);
    if ( ++v9 >= a1 )
      goto LABEL_8;
  }
}
