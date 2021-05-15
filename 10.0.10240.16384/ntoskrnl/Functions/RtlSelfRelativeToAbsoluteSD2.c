// RtlSelfRelativeToAbsoluteSD2 
 
int __fastcall RtlSelfRelativeToAbsoluteSD2(int a1, _DWORD *a2)
{
  __int16 v3; // r4
  int v4; // r0
  int v5; // r3
  int v6; // [sp+18h] [bp-28h] BYREF
  int v7; // [sp+1Ch] [bp-24h] BYREF
  int v8; // [sp+20h] [bp-20h] BYREF
  int v9; // [sp+24h] [bp-1Ch] BYREF
  unsigned int v10; // [sp+28h] [bp-18h] BYREF
  unsigned int v11; // [sp+2Ch] [bp-14h] BYREF
  unsigned int v12; // [sp+30h] [bp-10h] BYREF
  unsigned int v13[3]; // [sp+34h] [bp-Ch] BYREF

  if ( !a1 )
    return -1073741585;
  if ( !a2 )
    return -1073741584;
  if ( *a2 < 0x14u )
    return -1073741811;
  v3 = *(_WORD *)(a1 + 2);
  if ( (v3 & 0x8000) == 0 )
    return -1073741593;
  v4 = RtlpQuerySecurityDescriptor(a1, &v6, v13, &v7, &v12, &v9, &v11, &v8, &v10);
  v5 = v6;
  *(_WORD *)(v4 + 2) = v3 & 0x7FFF;
  *(_DWORD *)(v4 + 4) = v5;
  *(_DWORD *)(v4 + 8) = v7;
  *(_DWORD *)(v4 + 12) = v8;
  *(_DWORD *)(v4 + 16) = v9;
  return 0;
}
