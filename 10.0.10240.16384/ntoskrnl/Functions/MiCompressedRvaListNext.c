// MiCompressedRvaListNext 
 
int __fastcall MiCompressedRvaListNext(unsigned __int8 *a1, int *a2)
{
  int v2; // r2
  int result; // r0
  unsigned __int8 *v5; // r7
  int v6; // r6
  unsigned int v7; // t1

  v2 = a2[1];
  result = *a2;
  v5 = &a1[v2 + 4];
  v6 = *(_DWORD *)a1 - v2;
  if ( *(_DWORD *)a1 == v2 )
    return 0;
  while ( 1 )
  {
    v7 = *v5++;
    --v6;
    result += MiCfgCompressionTableScales[v7 >> 6] * (v7 & 0x3F);
    if ( v7 >> 6 == 3 )
      break;
    if ( !v6 )
      KeBugCheckEx(26, 1130784544, (int)a1, (int)a2, result);
  }
  *a2 = result;
  a2[1] = v5 - a1 - 4;
  return result;
}
