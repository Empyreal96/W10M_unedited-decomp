// NtDrawText 
 
int __fastcall NtDrawText(int *a1)
{
  int v2; // r4
  int v3; // r5
  int v4; // r8
  unsigned int v5; // r8
  unsigned int v6; // r6
  int v7; // r0
  int v9; // [sp+8h] [bp-20h] BYREF
  unsigned int v10; // [sp+Ch] [bp-1Ch]

  v2 = 0;
  v3 = 0;
  v4 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( !SeSinglePrivilegeCheck(SeTcbPrivilege, dword_9227BC, v4) )
    return -1073741727;
  if ( !a1 )
    return -1073741811;
  if ( v4 )
  {
    if ( (unsigned int)a1 >= MmUserProbeAddress )
      a1 = (int *)MmUserProbeAddress;
    v9 = *a1;
    v5 = a1[1];
    v10 = v5;
    v6 = HIWORD(v9);
    if ( !v5 || !HIWORD(v9) )
      goto LABEL_18;
    if ( HIWORD(v9) + v5 > MmUserProbeAddress || HIWORD(v9) + v5 < v5 )
      *(_BYTE *)MmUserProbeAddress = 0;
    v7 = ExAllocatePoolWithTag(512, v6);
    v3 = v7;
    if ( !v7 )
    {
      v2 = -1073741801;
      goto LABEL_18;
    }
    memmove(v7, v5, v6);
    v10 = v3;
    a1 = &v9;
  }
  v2 = BgkDrawText(a1[1]);
LABEL_18:
  if ( v3 )
    ExFreePoolWithTag(v3);
  return v2;
}
