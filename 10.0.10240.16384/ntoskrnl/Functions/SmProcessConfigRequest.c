// SmProcessConfigRequest 
 
int __fastcall SmProcessConfigRequest(unsigned int a1, int a2, int a3, int a4)
{
  unsigned int v5; // r6
  unsigned int v6; // r5
  unsigned int v7; // r3
  int *v8; // r3
  int v9; // r1
  int varg_r2; // [sp+30h] [bp+10h]

  varg_r2 = a3;
  LOBYTE(varg_r2) = a3;
  if ( a2 == 8 )
  {
    if ( (_BYTE)a3 )
    {
      if ( (a1 & 3) != 0 )
        ExRaiseDatatypeMisalignment(a1);
      if ( a1 >= MmUserProbeAddress )
        *(_BYTE *)MmUserProbeAddress = 0;
      *(_BYTE *)a1 = *(_BYTE *)a1;
      *(_BYTE *)(a1 + 4) = *(_BYTE *)(a1 + 4);
    }
    v5 = *(_DWORD *)a1;
    v6 = *(_DWORD *)(a1 + 4);
    if ( (unsigned __int8)*(_DWORD *)a1 != 2 )
      return -1073741735;
    if ( (v5 & 0xFFFF00) != 0 )
      return -1073741811;
    v7 = HIBYTE(v5);
    if ( HIBYTE(v5) >= 3u )
      return -1073741811;
    if ( v7 )
    {
      if ( v7 == 1 )
      {
        if ( v6 <= 1 )
        {
          v8 = &PspOutSwapSharedPages;
          goto LABEL_22;
        }
        return -1073741811;
      }
      if ( v7 == 2 )
      {
        if ( v6 - 4 <= 0x1C && v6 && ((v6 - 1) & v6) == 0 )
        {
          v8 = &dword_6348C0;
LABEL_22:
          *v8 = v6;
          return 0;
        }
        return -1073741811;
      }
    }
    else
    {
      if ( (v6 & 0xFFFFFFC0) != 0 || ((v6 >> 2) & 3) == 3 || ((v6 >> 4) & 3) == 3 )
        return -1073741811;
      if ( (((v6 >> 2) & 3) == 2 || ((v6 >> 4) & 3) == 2)
        && !SeSinglePrivilegeCheck(SeLockMemoryPrivilege, dword_922B7C, (char)a3, (int)&SeLockMemoryPrivilege) )
      {
        return -1073741790;
      }
      v9 = dword_636CC0;
      dword_636CC0 = (v6 >> 2) & 0xF | (16 * (v6 & 3)) | dword_636CC0 & 0xFFFFFFC0;
      if ( (dword_636CC0 & 3) != 0 )
        SmpSystemStoreCreate(SmGlobals, v9);
    }
    return 0;
  }
  return -1073741306;
}
