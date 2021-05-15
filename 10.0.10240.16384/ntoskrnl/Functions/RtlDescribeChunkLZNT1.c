// RtlDescribeChunkLZNT1 
 
int __fastcall RtlDescribeChunkLZNT1(unsigned int *a1, unsigned int a2, int a3, int *a4)
{
  _WORD *v7; // r3
  int result; // r0
  int v9; // r4
  int v10; // r2
  unsigned int v11; // r2
  unsigned int v12; // r3

  *(_DWORD *)a3 = *a1;
  *a4 = 0;
  v7 = (_WORD *)*a1;
  result = -2147483622;
  if ( (unsigned int)v7 <= a2 - 4 )
  {
    v9 = (unsigned __int16)*v7;
    if ( *v7 )
    {
      v10 = (v9 & 0xFFF) + 3;
      *a4 = v10;
      result = 0;
      v11 = v10 + *a1;
      *a1 = v11;
      if ( v11 > a2 || (v9 & 0x7000) != 12288 )
      {
        v12 = v11 - *a4;
LABEL_14:
        result = -1073741246;
        *a1 = v12;
        return result;
      }
      if ( (v9 & 0xFFFF8000) == 0 )
      {
        if ( *a4 == 4098 )
        {
          *(_DWORD *)a3 += 2;
          *a4 -= 2;
          return result;
        }
        v12 = v11 - *a4;
        goto LABEL_14;
      }
      if ( *a4 == 6 && *(_BYTE *)(*(_DWORD *)a3 + 2) == 2 && !*(_BYTE *)(*(_DWORD *)a3 + 3) )
        *a4 = 0;
    }
  }
  return result;
}
