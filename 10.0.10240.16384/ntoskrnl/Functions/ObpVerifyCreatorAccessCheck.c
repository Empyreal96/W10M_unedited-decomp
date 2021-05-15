// ObpVerifyCreatorAccessCheck 
 
int __fastcall ObpVerifyCreatorAccessCheck(int a1)
{
  unsigned int v2; // r0
  int v3; // r0
  int v4; // r4
  _DWORD *v6; // r0
  int v7; // r4
  int v8; // r3
  char v9[8]; // [sp+0h] [bp-80h] BYREF
  int v10; // [sp+8h] [bp-78h] BYREF
  int v11; // [sp+Ch] [bp-74h] BYREF
  int v12[8]; // [sp+10h] [bp-70h] BYREF
  char v13[80]; // [sp+30h] [bp-50h] BYREF

  v9[0] = 0;
  v9[1] = 0;
  v9[2] = 0;
  v9[3] = 0;
  v9[4] = 0;
  v9[5] = 16;
  v10 = 0;
  v11 = 0;
  memset(v12, 0, sizeof(v12));
  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v3 = SeCaptureSubjectContextEx((_DWORD *)v2, *(_DWORD **)(v2 + 0x74), v12);
  v4 = v12[0];
  if ( !v12[0] )
    v4 = v12[2];
  if ( *(_DWORD *)(v4 + 168) == 2 )
    return sub_7EF730(v3);
  SeQueryInformationToken(v4, 29, &v10);
  if ( v10 )
    JUMPOUT(0x7EF73C);
  SeQueryInformationToken(v4, 25, &v11);
  RtlInitializeSid((int)v13, (int)v9, 1u);
  v6 = (_DWORD *)RtlSubAuthoritySid((int)v13, 0);
  *v6 = v11;
  v12[5] = (int)v13;
  SeLockSubjectContext(v12);
  v7 = RtlEnumerateBoundaryDescriptorEntries(a1, ObpVerifyAccessToBoundaryEntry, v12);
  SeUnlockSubjectContext(v12);
  v8 = v12[6];
  if ( v12[6] >= 0 )
  {
    if ( v7 < 0 )
    {
      v8 = v7;
      v12[6] = v7;
    }
    if ( v8 >= 0 && v12[4] )
      JUMPOUT(0x7EF752);
  }
  SeReleaseSubjectContext((int)v12);
  if ( v12[4] )
    ExFreePoolWithTag(v12[4]);
  return v12[6];
}
