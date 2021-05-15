// RtlpQueryRegistryDirect 
 
int __fastcall RtlpQueryRegistryDirect(int a1, int a2, unsigned int a3, int a4)
{
  int v4; // r4
  int v6; // r0
  unsigned int v8; // r5
  int v9; // r0
  unsigned int v10; // r1

  v4 = a4;
  if ( a1 != 1 && a1 != 2 && a1 != 7 )
  {
    if ( a3 <= 4 )
    {
      if ( a4 == a2 || !a3 )
        return 0;
      goto LABEL_7;
    }
    v10 = *(_DWORD *)a4;
    if ( *(int *)a4 >= 0 )
    {
      if ( v10 >= a3 + 8 )
      {
        *(_DWORD *)a4 = a3;
        *(_DWORD *)(a4 + 4) = a1;
        v6 = a4 + 8;
        goto LABEL_8;
      }
    }
    else if ( -v10 >= a3 )
    {
LABEL_7:
      v6 = a4;
LABEL_8:
      memmove(v6, a2, a3);
      return 0;
    }
    return -1073741789;
  }
  if ( a3 > 0xFFFE )
    v8 = 65534;
  else
    v8 = (unsigned __int16)a3;
  if ( *(_DWORD *)(a4 + 4) )
  {
    if ( v8 > *(unsigned __int16 *)(a4 + 2) )
      return -1073741789;
LABEL_15:
    memmove(*(_DWORD *)(v4 + 4), a2, v8);
    *(_WORD *)v4 = v8 - 2;
    return 0;
  }
  v9 = ExpAllocateStringRoutine(v8);
  *(_DWORD *)(v4 + 4) = v9;
  if ( v9 )
  {
    *(_WORD *)(v4 + 2) = v8;
    goto LABEL_15;
  }
  return -1073741801;
}
