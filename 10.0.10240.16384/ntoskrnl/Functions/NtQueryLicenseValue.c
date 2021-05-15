// NtQueryLicenseValue 
 
int __fastcall NtQueryLicenseValue(int a1, unsigned int a2, int a3, int a4, unsigned int a5)
{
  __int64 *v6; // r8
  unsigned int v7; // r5
  int v8; // r0
  int v9; // r4
  __int64 *v10; // r2
  unsigned int v11; // r2
  int v12; // r1
  int v13; // r0
  _DWORD *v14; // r2
  _DWORD *v15; // r2
  __int64 v19; // [sp+20h] [bp-28h] BYREF
  int varg_r0; // [sp+50h] [bp+8h]
  unsigned int varg_r1; // [sp+54h] [bp+Ch]
  int varg_r2; // [sp+58h] [bp+10h]
  int varg_r3; // [sp+5Ch] [bp+14h]

  varg_r0 = a1;
  varg_r3 = a4;
  varg_r2 = a3;
  varg_r1 = a2;
  v6 = (__int64 *)a1;
  v7 = 0;
  v19 = 0i64;
  v8 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v9 = 0;
  if ( v6 && a5 )
  {
    if ( v8 )
    {
      v10 = v6;
      if ( (unsigned int)v6 >= MmUserProbeAddress )
        v10 = (__int64 *)MmUserProbeAddress;
      LODWORD(v19) = *(_DWORD *)v10;
      v11 = *((_DWORD *)v10 + 1);
      HIDWORD(v19) = v11;
      if ( v11 && (v12 = (unsigned __int16)v19, (_WORD)v19) && !((unsigned __int16)v19 % 2) )
      {
        if ( (v11 & 1) != 0 )
          ExRaiseDatatypeMisalignment(v8);
        if ( (unsigned __int16)v19 + v11 > MmUserProbeAddress || (unsigned __int16)v19 + v11 < v11 )
        {
          *(_BYTE *)MmUserProbeAddress = 0;
          v12 = (unsigned __int16)v19;
        }
        v13 = ExAllocatePoolWithTag(1, v12, 542329939);
        v7 = v13;
        if ( v13 )
        {
          memmove(v13, SHIDWORD(v19), (unsigned __int16)v19);
          HIDWORD(v19) = v7;
          v6 = &v19;
          if ( a2 )
          {
            v14 = (_DWORD *)a2;
            if ( a2 >= MmUserProbeAddress )
              v14 = (_DWORD *)MmUserProbeAddress;
            *v14 = *v14;
          }
          if ( a3 && a4 )
            ProbeForWrite(a3, a4, 1);
          v15 = (_DWORD *)a5;
          if ( a5 >= MmUserProbeAddress )
            v15 = (_DWORD *)MmUserProbeAddress;
          *v15 = *v15;
        }
        else
        {
          v9 = -1073741801;
        }
      }
      else
      {
        v9 = -1073741811;
      }
    }
    if ( v9 >= 0 )
      v9 = sub_6E2B78(v6, a2, a3, a4, a5);
  }
  else
  {
    v9 = -1073741811;
  }
  if ( v7 )
    ExFreePoolWithTag(v7);
  return v9;
}
