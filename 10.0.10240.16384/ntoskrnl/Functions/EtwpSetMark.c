// EtwpSetMark 
 
int __fastcall EtwpSetMark(int a1, char *a2, unsigned int a3, int a4, char a5)
{
  int v8; // r4
  char *v9; // r2
  int v10; // r9
  _DWORD _10[21]; // [sp+10h] [bp-40h] BYREF
  int varg_r3; // [sp+64h] [bp+14h]

  varg_r3 = a4;
  LOBYTE(varg_r3) = a4;
  _10[20] = a3;
  _10[19] = a2;
  _10[18] = a1;
  v8 = 0;
  if ( a3 <= 4 )
    return -1073741811;
  if ( a3 > 0xFFDD )
    return -1073741675;
  if ( a5 )
  {
    if ( ((unsigned __int8)a2 & 3) != 0 )
      ExRaiseDatatypeMisalignment(a1);
    v9 = &a2[a3];
    if ( (unsigned int)&a2[a3] > MmUserProbeAddress || v9 < a2 )
      *(_BYTE *)MmUserProbeAddress = 0;
  }
  v10 = 0;
  if ( (*(_DWORD *)a2 & 1) != 0 && a4 )
  {
    if ( SeSinglePrivilegeCheck(SeDebugPrivilege, dword_922784, a5, (int)&SeDebugPrivilege) )
    {
      v10 = 1;
      MmEmptyAllWorkingSets();
    }
    else
    {
      v8 = -1073741727;
    }
  }
  _10[0] = a2 + 4;
  _10[1] = 0;
  _10[2] = a3 - 4;
  _10[3] = 0;
  _10[4] = &EtwpNull;
  _10[5] = 0;
  _10[6] = 2;
  _10[7] = 0;
  EtwpLogSystemEventUnsafe((int)_10, (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0), a1, 2u, 3874, 12544);
  if ( v10 )
    MmIdentifyPhysicalMemory(a1, 629, 1);
  return v8;
}
