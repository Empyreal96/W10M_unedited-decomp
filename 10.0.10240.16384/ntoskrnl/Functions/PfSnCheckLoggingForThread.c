// PfSnCheckLoggingForThread 
 
int __fastcall PfSnCheckLoggingForThread(int a1, unsigned int *a2, char a3)
{
  int v3; // r2
  unsigned int v5; // r3
  unsigned int *v6; // r2
  unsigned int v7; // r1

  if ( (*(_BYTE *)(a1 + 968) & 0x40) == 0 || (a3 & 2) != 0 )
  {
    v3 = (*(_DWORD *)(a1 + 960) >> 9) & 7;
    if ( (*(_DWORD *)(*(_DWORD *)(a1 + 336) + 192) & 0x100000) != 0 )
      return sub_547900();
    if ( ((*(_DWORD *)(a1 + 960) >> 9) & 7u) >= 2 )
      goto LABEL_5;
    if ( a1 == (__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) && *(_DWORD *)(a1 + 1000) )
      v3 = 2;
    if ( v3 >= 2 )
    {
LABEL_5:
      v5 = a2[77];
      if ( !v5 || v5 == a1 && a2[78] == *(_DWORD *)(a1 + 880) )
        return 1;
    }
    else
    {
      v6 = a2 + 63;
      do
        v7 = __ldrex(v6);
      while ( __strex(v7 + 1, v6) );
    }
  }
  return 0;
}
