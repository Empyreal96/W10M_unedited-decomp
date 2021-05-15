// RtlValidSecurityDescriptor 
 
BOOL __fastcall RtlValidSecurityDescriptor(int a1, int a2)
{
  __int16 v3; // r5
  int v4; // r3
  int v5; // r3
  int v6; // r3
  int v7; // r0
  int v9; // r0
  int v10; // r3
  int v11; // r0
  int v12; // r0

  if ( *(_BYTE *)a1 != 1 )
    return 0;
  v3 = *(_WORD *)(a1 + 2);
  if ( (v3 & 0x8000) != 0 )
  {
    v4 = *(_DWORD *)(a1 + 4);
    if ( !v4 )
      goto LABEL_4;
    v9 = v4 + a1;
  }
  else
  {
    v9 = *(_DWORD *)(a1 + 4);
  }
  if ( v9 && !RtlValidSid(v9, a2) )
    return 0;
LABEL_4:
  if ( (v3 & 0x8000) != 0 )
  {
    v5 = *(_DWORD *)(a1 + 8);
    if ( !v5 )
      goto LABEL_6;
    v12 = v5 + a1;
  }
  else
  {
    v12 = *(_DWORD *)(a1 + 8);
  }
  if ( v12 && !RtlValidSid(v12, a2) )
    return 0;
LABEL_6:
  if ( (v3 & 4) != 0 )
  {
    if ( (v3 & 0x8000) == 0 )
    {
      v7 = *(_DWORD *)(a1 + 16);
      goto LABEL_10;
    }
    v6 = *(_DWORD *)(a1 + 16);
    if ( v6 )
    {
      v7 = v6 + a1;
LABEL_10:
      if ( v7 && !RtlValidAcl() )
        return 0;
      goto LABEL_12;
    }
  }
LABEL_12:
  if ( (*(_WORD *)(a1 + 2) & 0x10) == 0 )
    return 1;
  if ( (*(_WORD *)(a1 + 2) & 0x8000) != 0 )
  {
    v10 = *(_DWORD *)(a1 + 12);
    if ( !v10 )
      return 1;
    v11 = v10 + a1;
  }
  else
  {
    v11 = *(_DWORD *)(a1 + 12);
  }
  return !v11 || RtlValidAcl();
}
