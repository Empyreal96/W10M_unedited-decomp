// RtlValidRelativeSecurityDescriptor 
 
int __fastcall RtlValidRelativeSecurityDescriptor(int a1, unsigned int a2, char a3, int a4)
{
  __int16 v7; // r7
  int v8; // r5
  int v9; // r5
  int v10; // r5
  unsigned int v12; // r3
  unsigned int v13; // r3
  int v14; // r5
  int v15[6]; // [sp+0h] [bp-18h] BYREF

  v15[0] = a4;
  if ( a2 < 0x14 )
    return 0;
  if ( *(_BYTE *)a1 != 1 )
    return 0;
  v7 = *(_WORD *)(a1 + 2);
  if ( (v7 & 0x8000) == 0 )
    return 0;
  v8 = *(_DWORD *)(a1 + 4);
  if ( v8 )
  {
    if ( !RtlpValidateSDOffsetAndSize(*(_DWORD *)(a1 + 4), a2, 12, v15) )
      return 0;
    if ( *(_BYTE *)(v8 + a1) != 1 )
      return 0;
    v12 = *(unsigned __int8 *)(v8 + a1 + 1);
    if ( v12 > 0xF || v15[0] < 4 * (v12 + 2) )
      return 0;
  }
  else if ( (a3 & 1) != 0 )
  {
    return 0;
  }
  v9 = *(_DWORD *)(a1 + 8);
  if ( v9 )
  {
    if ( !RtlpValidateSDOffsetAndSize(*(_DWORD *)(a1 + 8), a2, 12, v15) )
      return 0;
    if ( *(_BYTE *)(v9 + a1) != 1 )
      return 0;
    v13 = *(unsigned __int8 *)(v9 + a1 + 1);
    if ( v13 > 0xF || v15[0] < 4 * (v13 + 2) )
      return 0;
  }
  else if ( (a3 & 2) != 0 )
  {
    return 0;
  }
  if ( (v7 & 4) == 0
    || (v10 = *(_DWORD *)(a1 + 16)) == 0
    || RtlpValidateSDOffsetAndSize(*(_DWORD *)(a1 + 16), a2, 8, v15)
    && v15[0] >= (unsigned int)*(unsigned __int16 *)(v10 + a1 + 2)
    && RtlValidAcl() )
  {
    if ( (*(_WORD *)(a1 + 2) & 0x10) == 0 )
      return 1;
    v14 = *(_DWORD *)(a1 + 12);
    if ( !v14
      || RtlpValidateSDOffsetAndSize(*(_DWORD *)(a1 + 12), a2, 8, v15)
      && v15[0] >= (unsigned int)*(unsigned __int16 *)(v14 + a1 + 2)
      && RtlValidAcl() )
    {
      return 1;
    }
  }
  return 0;
}
