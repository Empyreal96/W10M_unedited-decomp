// RtlpDidUnicodeToOemWork 
 
int __fastcall RtlpDidUnicodeToOemWork(unsigned __int16 *a1, int a2)
{
  unsigned int v3; // r5
  int v4; // r4
  int v5; // r0
  unsigned int v7; // r2
  unsigned int v8; // r1
  char *v9; // r5
  int v10; // r0
  unsigned int v11; // r4
  int v12; // r6
  int v13; // r3

  if ( NlsMbOemCodePageTag )
  {
    v7 = *a1;
    v8 = 0;
    if ( *a1 )
    {
      v9 = (char *)*((_DWORD *)a1 + 1);
      v10 = 0;
      v11 = 1;
      while ( 1 )
      {
        v12 = *v9;
        if ( NlsOemLeadByteInfoTable[(unsigned __int8)v12] && v11 < v7 )
        {
          ++v8;
          ++v11;
          v13 = (unsigned __int16)((unsigned __int8)*++v9 + ((_WORD)v12 << 8));
          if ( v13 == (unsigned __int16)OemDefaultChar
            && *(unsigned __int16 *)(v10 + *(_DWORD *)(a2 + 4)) != (unsigned __int16)OemTransUniDefaultChar )
          {
            goto LABEL_19;
          }
        }
        else if ( v12 == (unsigned __int8)OemDefaultChar
               && *(unsigned __int16 *)(v10 + *(_DWORD *)(a2 + 4)) != (unsigned __int16)OemTransUniDefaultChar )
        {
LABEL_19:
          JUMPOUT(0x7DCFA2);
        }
        ++v8;
        ++v11;
        ++v9;
        v10 += 2;
        if ( v8 >= v7 )
          return 1;
      }
    }
    return 1;
  }
  v3 = *a1;
  v4 = 0;
  if ( !*a1 )
    return 1;
  v5 = *((_DWORD *)a1 + 1);
  while ( *(char *)(v5 + v4) != (unsigned __int8)OemDefaultChar )
  {
    if ( ++v4 >= v3 )
      return 1;
  }
  return sub_7DCF94();
}
