// RtlValidAcl 
 
int __fastcall RtlValidAcl(unsigned __int8 *a1)
{
  unsigned int v1; // r3
  unsigned int v2; // r6
  unsigned __int8 *v3; // r4
  unsigned int v4; // r1
  unsigned int v5; // r2
  unsigned int v6; // r3
  unsigned int v7; // r3

  v1 = *a1;
  if ( v1 <= 4
    && v1 >= 2
    && (unsigned __int8 *)((unsigned int)(a1 + 3) & 0xFFFFFFFE) == a1 + 2
    && *((unsigned __int16 *)a1 + 1) >= 8u )
  {
    v2 = 0;
    v3 = a1 + 8;
    if ( !*((_WORD *)a1 + 2) )
      return 1;
    while ( 1 )
    {
      v4 = (unsigned int)&a1[*((unsigned __int16 *)a1 + 1)];
      if ( (unsigned int)(v3 + 4) >= v4 )
        break;
      if ( (unsigned __int8 *)((unsigned int)(v3 + 3) & 0xFFFFFFFE) != v3 + 2 )
        break;
      v5 = *((unsigned __int16 *)v3 + 1);
      if ( (unsigned int)&v3[v5] > v4 )
        break;
      v6 = *v3;
      if ( v6 > 3 && (v6 > 0xA || v6 < 9) && (v6 > 0xE || v6 < 0xD) && v6 != 17 && v6 != 20 && v6 != 19 )
        return sub_7FC0DC();
      if ( ((v5 + 3) & 0xFFFFFFFC) != v5 )
        return 0;
      if ( v5 < 0x10 )
        return 0;
      if ( v3[8] != 1 )
        return 0;
      v7 = v3[9];
      if ( v7 > 0xF || v5 < 4 * (v7 + 4) )
        return 0;
      ++v2;
      v3 += *((unsigned __int16 *)v3 + 1);
      if ( v2 >= *((unsigned __int16 *)a1 + 2) )
        return 1;
    }
  }
  return 0;
}
