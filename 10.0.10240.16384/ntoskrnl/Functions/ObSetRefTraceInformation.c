// ObSetRefTraceInformation 
 
int __fastcall ObSetRefTraceInformation(unsigned int a1, unsigned int a2, int a3)
{
  unsigned int v4; // r4
  int v5; // r8
  int v6; // r0
  int result; // r0
  unsigned int _2C; // [sp+2Ch] [bp+Ch]

  _2C = a2;
  v4 = a1;
  v5 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v6 = SeSinglePrivilegeCheck(SeDebugPrivilege, dword_922784, v5, (int)&SeDebugPrivilege);
  if ( !v6 )
    return -1073741790;
  if ( a2 < 0x14 )
    return -1073741811;
  if ( v5 )
  {
    if ( (v4 & 3) != 0 )
      ExRaiseDatatypeMisalignment(v6);
    if ( v4 + a2 > MmUserProbeAddress || v4 + a2 < v4 )
      *(_BYTE *)MmUserProbeAddress = 0;
  }
  if ( *(_BYTE *)v4 )
    result = ObpStartRuntimeStackTrace(v4);
  else
    result = ObpStopRuntimeStackTrace(a3);
  return result;
}
