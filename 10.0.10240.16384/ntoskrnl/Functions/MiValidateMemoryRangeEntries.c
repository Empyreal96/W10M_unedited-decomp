// MiValidateMemoryRangeEntries 
 
int __fastcall MiValidateMemoryRangeEntries(unsigned int *a1, int a2, _DWORD *a3)
{
  unsigned int *v3; // r7
  unsigned int v4; // r4
  unsigned int v5; // r1
  unsigned int v6; // r5
  int v7; // r1
  int result; // r0

  v3 = &a1[2 * a2];
  v4 = 0;
  if ( a1 >= v3 )
  {
LABEL_8:
    if ( a3 )
      *a3 = v4;
    result = 1;
  }
  else
  {
    while ( 1 )
    {
      v5 = *a1;
      if ( *a1 > MmHighestUserAddress )
        break;
      v6 = a1[1];
      if ( !v6 )
        break;
      if ( v6 + v5 < v5 )
        break;
      if ( v6 + v5 - 1 > MmHighestUserAddress )
        break;
      v7 = *a1 & 0xFFF;
      if ( v4 + ((v7 + v6 + 4095) >> 12) < v4 )
        break;
      a1 += 2;
      v4 += (v7 + v6 + 4095) >> 12;
      if ( a1 >= v3 )
        goto LABEL_8;
    }
    result = 0;
  }
  return result;
}
