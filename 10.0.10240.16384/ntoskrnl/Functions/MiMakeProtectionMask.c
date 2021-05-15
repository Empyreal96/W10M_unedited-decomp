// MiMakeProtectionMask 
 
int __fastcall MiMakeProtectionMask(unsigned int a1)
{
  int v1; // r2
  int *v2; // r3
  int v3; // r2
  int v4; // r3

  if ( a1 >= 0x800 )
    return -1;
  v1 = a1 & 0xF;
  if ( (a1 & 0xF) != 0 )
  {
    if ( (a1 & 0xF0) == 0 )
    {
      v2 = MmUserProtectionToMask1;
      goto LABEL_5;
    }
    return -1;
  }
  v1 = (unsigned __int8)a1 >> 4;
  if ( !((unsigned __int8)a1 >> 4) )
    return -1;
  v2 = MmUserProtectionToMask2;
LABEL_5:
  v3 = *((char *)v2 + v1);
  v4 = -1;
  if ( v3 == -1 )
    return v4;
  if ( (a1 & 0x700) == 0 )
    return v3;
  if ( (a1 & 0x100) != 0 )
  {
    if ( v3 == 24 || (a1 & 0x600) != 0 )
      return v4;
    v3 |= 0x10u;
  }
  if ( (a1 & 0x200) != 0 )
  {
    if ( v3 == 24 || (a1 & 0x400) != 0 )
      return v4;
    v3 |= 8u;
  }
  if ( (a1 & 0x400) == 0 )
    return v3;
  if ( v3 != 24 && (v3 & 2) == 0 )
    return v3 | 0x18;
  return v4;
}
