// MiSessionObjectCreate 
 
int MiSessionObjectCreate()
{
  int v0; // r4
  int v1; // r4
  int v2; // r4
  int v3; // r0
  unsigned int v4; // r5
  unsigned int v5; // r0
  _DWORD *v6; // r6
  int v7; // r5
  int v8; // r0
  unsigned int *v9; // r2
  unsigned int v10; // r1
  int v11; // r3
  int v13; // r0
  int v14; // r0
  int v15; // [sp+18h] [bp-160h] BYREF
  int v16; // [sp+20h] [bp-158h] BYREF
  int v17[6]; // [sp+28h] [bp-150h] BYREF
  char v18[8]; // [sp+40h] [bp-138h] BYREF
  char v19[24]; // [sp+48h] [bp-130h] BYREF
  unsigned __int16 v20[140]; // [sp+60h] [bp-118h] BYREF

  v0 = RtlCreateSecurityDescriptor(v19, 1);
  if ( v0 < 0 )
    return v0;
  v1 = RtlLengthSid(SeLocalSystemSid);
  v2 = v1 + RtlLengthSid(SeAliasAdminsSid);
  v3 = ExAllocatePoolWithTag(1, v2 + 32, 1818452292);
  v4 = v3;
  if ( !v3 )
    JUMPOUT(0x80FA0E);
  v0 = RtlCreateAcl(v3, v2 + 32, 2);
  v5 = v4;
  if ( v0 < 0 )
    goto LABEL_16;
  v0 = RtlAddAccessAllowedAce(v4, 2, 983043, SeAliasAdminsSid);
  v5 = v4;
  if ( v0 < 0 )
    goto LABEL_16;
  v0 = RtlAddAccessAllowedAce(v4, 2, 983043, SeLocalSystemSid);
  if ( v0 < 0
    || (v0 = RtlSetDaclSecurityDescriptor((int)v19, 1, v4, 0), v0 < 0)
    || (v6 = *(_DWORD **)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 324),
        v0 = RtlStringCchPrintfW(v20, 0x80u, (int)L"\\KernelObjects\\Session%d", v6[2]),
        v0 < 0) )
  {
    v5 = v4;
LABEL_16:
    ExFreePoolWithTag(v5);
    return v0;
  }
  RtlInitUnicodeString((unsigned int)v18, v20);
  v17[0] = 24;
  v17[1] = 0;
  v17[3] = 512;
  v17[2] = (int)v18;
  v17[4] = (int)v19;
  v17[5] = 0;
  v0 = ObCreateObject(0, (_DWORD *)MmSessionObjectType, (int)v17, 0, 0, 24, 0, 0, &v15);
  ExFreePoolWithTag(v4);
  if ( v0 < 0 )
    return v0;
  v7 = v15;
  v8 = v15;
  *(_DWORD *)(v15 + 16) = v6;
  KeInitializeEvent(v8, 0, 0);
  *(_DWORD *)(v7 + 20) = 0;
  if ( !PsCpuFairShareEnabled || !v6[2] )
  {
LABEL_10:
    v0 = ObInsertObject(v7, 0, 1, 0, 0, (int)&v16);
    if ( v0 >= 0 )
    {
      v9 = v6 + 3;
      v6[1] |= 0x40u;
      do
        v10 = __ldrex(v9);
      while ( __strex(v10 + 1, v9) );
      __dmb(0xBu);
      v11 = v16;
      v6[11] = v7;
      v6[12] = v11;
      v6[2097] = 2;
      v6[2098] = 1;
      KeInitializeEvent((int)(v6 + 2099), 1, 1);
    }
    return v0;
  }
  v13 = KeGetSchedulingGroupSize();
  v14 = ExAllocatePoolWithTag(516, v13, 1886537555);
  *(_DWORD *)(v7 + 20) = v14;
  if ( v14 )
  {
    v15 = 5;
    KeInsertSchedulingGroup(v14, 5, 0, 0);
    goto LABEL_10;
  }
  return sub_80FA08();
}
