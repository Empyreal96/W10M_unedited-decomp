// AuthzBasepUnicodeStringFromOperandValue 
 
int __fastcall AuthzBasepUnicodeStringFromOperandValue(_DWORD *a1, int a2, unsigned __int16 *a3, _BYTE *a4)
{
  int v6; // r7
  int v10; // r2
  int v11; // r0
  int v12; // r1
  unsigned int v13; // r2
  unsigned __int16 *v14; // r3
  unsigned int v15; // r6
  int v16; // r4

  *a4 = 0;
  v6 = 0;
  if ( a1[3] != 1 )
    return sub_517B18();
  a3[1] = a1[5];
  *a3 = a1[5];
  *((_DWORD *)a3 + 1) = a1[6];
  if ( !*a3 || !*((_DWORD *)a3 + 1) )
    return -1073741406;
  v10 = a1[3];
  if ( v10 == 1 && (a1[6] & 1) != 0 )
    goto LABEL_7;
  if ( v10 != 2 )
  {
LABEL_11:
    if ( a2 )
    {
      v15 = 0;
      if ( (*a3 & 0xFFFE) != 0 )
      {
        do
        {
          v16 = *((_DWORD *)a3 + 1);
          *(_WORD *)(v16 + 2 * v15) = RtlUpcaseUnicodeChar(*(unsigned __int16 *)(v16 + 2 * v15));
          ++v15;
        }
        while ( v15 < *a3 >> 1 );
      }
    }
    return v6;
  }
  if ( a2 )
  {
LABEL_7:
    v11 = AuthzBasepMemAlloc(a3[1]);
    *((_DWORD *)a3 + 1) = v11;
    if ( v11 )
    {
      if ( a1[3] == 1 )
      {
        v12 = a1[6];
        v13 = a1[5];
      }
      else
      {
        v14 = *(unsigned __int16 **)(a1[4] + 24);
        v13 = *v14;
        v12 = *((_DWORD *)v14 + 1);
      }
      memmove(v11, v12, v13);
      *a4 = 1;
      goto LABEL_11;
    }
    v6 = -1073741801;
  }
  return v6;
}
