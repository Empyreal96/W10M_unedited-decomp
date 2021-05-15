// Normalization__LoadClassMapExceptions 
 
int __fastcall Normalization__LoadClassMapExceptions(int result)
{
  unsigned __int8 *v1; // r1
  unsigned int v2; // r2
  char v3; // r3
  unsigned int v4; // r4
  unsigned int v5; // t1

  v1 = *(unsigned __int8 **)(result + 28);
  *(_BYTE *)(result + 62) = -1;
  *(_BYTE *)(result + 63) = -1;
  *(_BYTE *)(result + 64) = -1;
  *(_BYTE *)(result + 65) = -1;
  *(_BYTE *)(result + 66) = -1;
  v2 = *v1;
  v3 = 0;
  do
  {
    v4 = v2;
    switch ( v2 )
    {
      case 0xD8u:
        *(_BYTE *)(result + 62) = v3;
        break;
      case 0xDCu:
        *(_BYTE *)(result + 63) = v3;
        break;
      case 0xDDu:
        *(_BYTE *)(result + 64) = v3;
        break;
      case 0xE6u:
        *(_BYTE *)(result + 65) = v3;
        break;
      case 0xE7u:
        *(_BYTE *)(result + 66) = v3;
        break;
    }
    v5 = *++v1;
    v2 = v5;
    ++v3;
  }
  while ( v5 >= v4 );
  return result;
}
