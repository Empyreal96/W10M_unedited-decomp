// ExpCheckIRTimerAccess 
 
int __fastcall ExpCheckIRTimerAccess(char a1)
{
  unsigned int v1; // r0
  int v2; // r0
  int v3; // r2
  int v5; // r4
  int v6; // [sp+20h] [bp-20h] BYREF
  int v7; // [sp+24h] [bp-1Ch] BYREF
  int v8[6]; // [sp+28h] [bp-18h] BYREF

  if ( a1 != 1 )
    return -1073741790;
  v1 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v2 = SeCaptureSubjectContextEx((_DWORD *)v1, *(_DWORD **)(v1 + 0x74), v8);
  v3 = v8[0];
  if ( !v8[0] )
    v3 = v8[2];
  if ( *(_DWORD *)(v3 + 168) == 2 )
    return sub_81BC6C(v2);
  SeAccessCheckWithHint((int)ExpIRTimerSecurityDescriptor, 3, v8, 0, 1u, 0, 0, ExTimerObjectType + 52, 1, &v7, &v6);
  v5 = v6;
  SeReleaseSubjectContext((int)v8);
  return v5;
}
