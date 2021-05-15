// RtlpCopyExtendedContext 
 
int __fastcall RtlpCopyExtendedContext(char a1, int a2, int a3, int a4, int a5, int a6)
{
  int v7; // r10
  int result; // r0
  int v11; // r5
  char v12; // r9
  int v13; // r1
  int v14; // r0
  int v15[8]; // [sp+8h] [bp-20h] BYREF

  v15[0] = a4;
  v7 = a1;
  result = RtlpValidateContextFlags(a4, v15);
  if ( result >= 0 )
  {
    if ( !a3 )
      a3 = a2;
    v11 = a6;
    if ( !a6 )
      v11 = a5;
    v12 = v15[0];
    if ( (v15[0] & 1) != 0 )
    {
      v13 = *(_DWORD *)(a3 + 8);
      v14 = *(_DWORD *)(v11 + 8);
      if ( v13 != v14 || *(_DWORD *)(a3 + 12) < *(_DWORD *)(v11 + 12) )
        return -1073741811;
      if ( (a4 & 0x10000) != 0 )
        return sub_547A78();
      if ( (a4 & 0x100000) != 0 )
      {
        RtlpCopyLegacyContextAmd64(v7, v13 + a2, a4, v14 + a5);
      }
      else if ( (a4 & 0x200000) != 0 )
      {
        RtlpCopyLegacyContextArm(v7, v13 + a2, a4, v14 + a5);
      }
      else if ( (a4 & 0x400000) != 0 )
      {
        RtlpCopyLegacyContextArm64(v7, v13 + a2, a4, v14 + a5);
      }
    }
    if ( (v12 & 2) == 0 || (result = RtlpCopyXStateChunk(v7, a2, a3, a5), result >= 0) )
      result = 0;
  }
  return result;
}
