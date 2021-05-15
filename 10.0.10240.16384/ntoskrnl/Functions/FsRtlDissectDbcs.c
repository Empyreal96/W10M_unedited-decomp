// FsRtlDissectDbcs 
 
unsigned int __fastcall FsRtlDissectDbcs(unsigned int result, _BYTE *a2, int a3, int a4)
{
  unsigned int v4; // r5
  unsigned int v6; // r4
  int v7; // r3
  __int16 v9; // r3
  unsigned int varg_r0; // [sp+18h] [bp+8h]
  int varg_r3; // [sp+24h] [bp+14h]

  varg_r0 = result;
  varg_r3 = a4;
  v4 = (unsigned __int16)result;
  *(_WORD *)a3 = 0;
  *(_WORD *)(a3 + 2) = 0;
  *(_DWORD *)(a3 + 4) = 0;
  v6 = 0;
  *(_WORD *)a4 = 0;
  *(_WORD *)(a4 + 2) = 0;
  *(_DWORD *)(a4 + 4) = 0;
  if ( (_WORD)result )
  {
    if ( *a2 == 92 )
      v6 = 1;
    for ( result = v6; v6 < v4; ++v6 )
    {
      v7 = (char)a2[v6];
      if ( v7 == 92 )
        break;
      v7 = (unsigned __int8)v7;
      if ( (unsigned __int8)v7 >= 0x80u && NlsMbOemCodePageTag && NlsOemLeadByteInfoTable[v7] )
        ++v6;
    }
    *(_WORD *)a3 = v6 - result;
    *(_WORD *)(a3 + 2) = v6 - result;
    *(_DWORD *)(a3 + 4) = &a2[result];
    if ( v6 < v4 )
    {
      v9 = v4 - v6 - 1;
      *(_WORD *)a4 = v9;
      *(_WORD *)(a4 + 2) = v9;
      *(_DWORD *)(a4 + 4) = &a2[v6 + 1];
    }
  }
  return result;
}
