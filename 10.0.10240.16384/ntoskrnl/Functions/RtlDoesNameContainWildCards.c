// RtlDoesNameContainWildCards 
 
int __fastcall RtlDoesNameContainWildCards(unsigned __int16 *a1)
{
  unsigned int v1; // r1
  unsigned __int16 *v2; // r2
  unsigned int v3; // r3
  unsigned int v4; // t1

  if ( *a1 )
  {
    v1 = *((_DWORD *)a1 + 1);
    v2 = (unsigned __int16 *)(v1 + 2 * (*a1 >> 1) - 2);
    while ( (unsigned int)v2 >= v1 )
    {
      v4 = *v2--;
      v3 = v4;
      if ( v4 == 92 )
        break;
      if ( v3 < 0x40 && (*((_BYTE *)dword_407310 + v3) & 8) != 0 )
        return 1;
    }
  }
  return 0;
}
