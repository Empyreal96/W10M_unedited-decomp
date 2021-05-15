// RtlGetAce 
 
int __fastcall RtlGetAce(unsigned __int8 *a1, unsigned int a2, int a3)
{
  unsigned int v3; // r3
  unsigned int v5; // r2

  v3 = *a1;
  if ( v3 >= 2 && v3 <= 4 && a2 < *((unsigned __int16 *)a1 + 2) )
  {
    v5 = 0;
    *(_DWORD *)a3 = a1 + 8;
    if ( a2 )
    {
      while ( *(_DWORD *)a3 < (unsigned int)&a1[*((unsigned __int16 *)a1 + 1)] )
      {
        ++v5;
        *(_DWORD *)a3 += *(unsigned __int16 *)(*(_DWORD *)a3 + 2);
        if ( v5 >= a2 )
          goto LABEL_5;
      }
    }
    else
    {
LABEL_5:
      if ( *(_DWORD *)a3 < (unsigned int)&a1[*((unsigned __int16 *)a1 + 1)] )
        return 0;
    }
  }
  return -1073741811;
}
