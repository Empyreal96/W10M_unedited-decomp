// PsQueryCpuQuotaInformation 
 
int __fastcall PsQueryCpuQuotaInformation(unsigned int *a1, unsigned int a2, int a3, unsigned int a4)
{
  int v4; // r8
  unsigned int *v6; // r6
  int v7; // r4
  unsigned int v8; // r9
  unsigned int v9; // r5
  int i; // r0
  int v11; // r8
  int v12; // r0
  _DWORD *v14; // [sp+8h] [bp-38h]
  unsigned __int16 *v15; // [sp+1Ch] [bp-24h]
  unsigned int varg_r1; // [sp+4Ch] [bp+Ch]
  int varg_r2; // [sp+50h] [bp+10h]
  unsigned int varg_r3; // [sp+54h] [bp+14h]

  varg_r1 = a2;
  varg_r2 = a3;
  v14 = (_DWORD *)a4;
  varg_r3 = a4;
  a3 = (char)a3;
  v4 = a3;
  LOBYTE(varg_r2) = a3;
  v6 = a1;
  if ( !PsCpuFairShareEnabled )
    return -1073741399;
  if ( (_BYTE)a3 && !SeSinglePrivilegeCheck(SeIncreaseQuotaPrivilege, dword_922794, (char)a3) )
    return -1073741727;
  if ( a2 )
  {
    a4 = a2 - 4;
    if ( ((a2 - 4) & 7) != 0 || a2 < 4 )
      return -1073741820;
    v8 = a4 >> 3;
    if ( v4 == 1 )
      ProbeForWrite(v6, a2, 4);
  }
  else
  {
    v8 = 0;
    v6 = 0;
  }
  v9 = 0;
  for ( i = 0; ; i = v11 )
  {
    v11 = MiGetNextSession(i, a2, a3, a4);
    if ( !v11 )
      break;
    v15 = (unsigned __int16 *)MmGetSessionSchedulingGroupByProcess();
    if ( v15 )
    {
      if ( v9 < v8 )
      {
        v12 = MmGetSessionIdEx(v11);
        a3 = (int)&v6[2 * v9];
        __dmb(0xBu);
        *(_DWORD *)(a3 + 4) = v12;
        a4 = *v15;
        __dmb(0xBu);
        *(_DWORD *)(a3 + 8) = a4;
      }
      ++v9;
    }
  }
  if ( v6 )
  {
    __dmb(0xBu);
    *v6 = v9;
  }
  *v14 = 8 * v9 + 4;
  if ( v9 > v8 )
    v7 = -1073741789;
  else
    v7 = 0;
  return v7;
}
