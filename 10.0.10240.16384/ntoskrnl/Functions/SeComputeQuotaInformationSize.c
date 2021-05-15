// SeComputeQuotaInformationSize 
 
int __fastcall SeComputeQuotaInformationSize(int a1, unsigned int *a2)
{
  __int16 v3; // r3
  int v4; // r2
  int v5; // r1
  int v6; // r3
  int v7; // r2

  *a2 = 0;
  if ( *(_BYTE *)a1 != 1 )
    return -1073741736;
  v3 = *(_WORD *)(a1 + 2);
  if ( (v3 & 0x8000) != 0 )
  {
    v4 = *(_DWORD *)(a1 + 8);
    if ( v4 )
      v5 = v4 + a1;
    else
      v5 = 0;
  }
  else
  {
    v5 = *(_DWORD *)(a1 + 8);
  }
  if ( (v3 & 4) != 0 )
  {
    if ( (*(_WORD *)(a1 + 2) & 0x8000) != 0 )
    {
      v6 = *(_DWORD *)(a1 + 16);
      if ( v6 )
        v7 = v6 + a1;
      else
        v7 = 0;
    }
    else
    {
      v7 = *(_DWORD *)(a1 + 16);
    }
  }
  else
  {
    v7 = 0;
  }
  if ( v5 )
    *a2 = (4 * *(unsigned __int8 *)(v5 + 1) + 11) & 0xFFFFFFFC;
  if ( v7 )
    *a2 += (*(unsigned __int16 *)(v7 + 2) + 3) & 0xFFFFFFFC;
  return 0;
}
