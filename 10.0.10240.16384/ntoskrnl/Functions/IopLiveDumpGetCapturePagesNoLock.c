// IopLiveDumpGetCapturePagesNoLock 
 
unsigned int __fastcall IopLiveDumpGetCapturePagesNoLock(unsigned int result, _DWORD *a2, int a3, int a4, unsigned int *a5, _DWORD *a6)
{
  unsigned int v7; // r6
  unsigned int *v9; // r8
  unsigned int v10; // r3
  unsigned int v11; // r3
  int v12; // r2

  v7 = a2[5];
  v9 = (unsigned int *)result;
  *a5 = 0;
  if ( v7 != -1 )
  {
    while ( 1 )
    {
      result = RtlFindSetBits(v9, 1u, v7);
      if ( result < v7 || result == -1 )
        break;
      v10 = *a5;
      v7 = result + 1;
      *(_DWORD *)(a3 + 4 * *a5) = result;
      v11 = v10 + 1;
      *a5 = v11;
      if ( v11 >= 0x40 )
      {
        a2[5] = *(_DWORD *)(a3 + 4 * v11 - 4) + 1;
        goto LABEL_7;
      }
    }
  }
  a2[5] = -1;
LABEL_7:
  if ( *a5 )
  {
    v12 = a2[6];
    a2[4] = *a5;
    *a6 = v12;
    a2[6] = v12 + 1;
  }
  return result;
}
