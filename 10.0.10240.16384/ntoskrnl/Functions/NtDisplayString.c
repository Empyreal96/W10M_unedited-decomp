// NtDisplayString 
 
int __fastcall NtDisplayString(unsigned int a1)
{
  unsigned int v1; // r4
  int v3; // r5
  _WORD *v4; // r9
  unsigned int v5; // r8
  int v6; // r0
  unsigned __int16 *v7; // r5
  _WORD *v8; // r3
  int v9; // r0
  int v10; // r4
  int v12; // [sp+8h] [bp-20h]

  v1 = a1;
  if ( a1 )
  {
    v3 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
    if ( !SeSinglePrivilegeCheck(SeTcbPrivilege, dword_9227BC, v3, (int)&SeTcbPrivilege) )
      return -1073741727;
    if ( v3 )
    {
      if ( v1 >= MmUserProbeAddress )
        v1 = MmUserProbeAddress;
      v12 = *(_DWORD *)v1;
      v4 = *(_WORD **)(v1 + 4);
      v5 = (unsigned __int16)HIWORD(*(_DWORD *)v1);
      if ( !v4 || !HIWORD(v12) )
        return 0;
      if ( (unsigned int)v4 + HIWORD(v12) > MmUserProbeAddress || (_WORD *)((char *)v4 + HIWORD(v12)) < v4 )
        *(_BYTE *)MmUserProbeAddress = 0;
      if ( !*v4 )
        return 0;
      v6 = ExAllocatePoolWithTag(512, v5 + 2, 1735554131);
      v7 = (unsigned __int16 *)v6;
      if ( !v6 )
        return -1073741801;
      memmove(v6, (int)v4, v5);
      v7[v5 >> 1] = 0;
    }
    else
    {
      v8 = *(_WORD **)(v1 + 4);
      if ( !v8 || !*(_WORD *)(v1 + 2) || !*v8 )
        return 0;
      v9 = ExAllocatePoolWithTag(512, *(unsigned __int16 *)(v1 + 2) + 2, 1735554131);
      v7 = (unsigned __int16 *)v9;
      if ( !v9 )
        return -1073741801;
      memmove(v9, *(_DWORD *)(v1 + 4), *(unsigned __int16 *)(v1 + 2));
      v7[*(unsigned __int16 *)(v1 + 2) >> 1] = 0;
    }
    v10 = BgkDisplayStringEx(v7);
    ExFreePoolWithTag((unsigned int)v7);
    if ( !v10 )
      return -1073741823;
    return 0;
  }
  return -1073741811;
}
