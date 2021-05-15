// BiCreateKeySecurityDescriptor 
 
_BYTE *__fastcall BiCreateKeySecurityDescriptor(int a1)
{
  __int64 v2; // kr00_8
  int v3; // r4
  unsigned int v4; // r4
  unsigned int v5; // r9
  int v6; // r0
  _BYTE *v7; // r5
  int v8; // r4
  unsigned int v9; // r4
  int v10; // r0

  v2 = *(_QWORD *)(SeExports + 224);
  v3 = RtlLengthSid(*(_DWORD *)(SeExports + 224));
  v4 = RtlLengthSid(SHIDWORD(v2)) + v3 + 24;
  v5 = RtlLengthSid(SHIDWORD(v2)) + v4 + 20;
  v6 = ExAllocatePoolWithTag(1, v5, 1262764866);
  v7 = (_BYTE *)v6;
  if ( !v6 )
    goto LABEL_11;
  if ( RtlCreateAcl(v6 + 20, v4, 2) < 0
    || RtlpAddKnownAce(v7 + 20, 2u, 0, a1, (_BYTE *)HIDWORD(v2), 0) < 0
    || RtlpAddKnownAce(v7 + 20, 2u, 0, 983103, (_BYTE *)v2, 0) < 0
    || RtlCreateSecurityDescriptor(v7, 1) < 0
    || RtlSetDaclSecurityDescriptor((int)v7, 1, (int)(v7 + 20), 0) < 0
    || (v8 = RtlLengthSid(SHIDWORD(v2)), RtlLengthSecurityDescriptor((int)v7) + v8 < v5)
    || (v9 = RtlLengthSecurityDescriptor((int)v7),
        v10 = RtlLengthSid(SHIDWORD(v2)),
        memmove((int)&v7[v9], SHIDWORD(v2), v10),
        RtlSetOwnerSecurityDescriptor((int)v7, (int)&v7[v9], 0) < 0) )
  {
    ExFreePoolWithTag((unsigned int)v7);
LABEL_11:
    v7 = 0;
  }
  return v7;
}
