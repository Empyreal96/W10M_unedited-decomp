// PpmInfoApplySettingUpdate 
 
void __fastcall PpmInfoApplySettingUpdate(int a1)
{
  char v2; // r2
  int v3; // r0
  int v4[2]; // [sp+0h] [bp-18h] BYREF
  __int64 v5; // [sp+8h] [bp-10h] BYREF

  v2 = *(_BYTE *)(a1 + 24);
  LOWORD(v4[0]) = 0;
  HIDWORD(v5) = 1 << (v2 - 32);
  LODWORD(v5) = 1 << v2;
  v3 = PpmGetPolicyAction(&v5, v4);
  if ( (*(_BYTE *)(a1 + 25) & 1) != 0 )
    PpmReapplyPerfPolicy(v4);
  else
    PpmReapplyIdlePolicy(v3);
}
