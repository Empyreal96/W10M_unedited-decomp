// AhcCacheQueryHwId 
 
int __fastcall AhcCacheQueryHwId(unsigned int a1, int a2)
{
  unsigned __int16 *v3; // r5
  int v4; // r4
  int v5; // r1
  int v6; // r6
  unsigned int v7; // r9
  unsigned __int16 *v8; // r0
  bool v9; // r2
  bool *v10; // r3
  unsigned __int16 v12; // [sp+0h] [bp-E8h] BYREF
  __int16 v13; // [sp+2h] [bp-E6h]
  unsigned __int16 *v14; // [sp+4h] [bp-E4h]
  int v15; // [sp+8h] [bp-E0h]
  int v16; // [sp+10h] [bp-D8h] BYREF
  unsigned __int16 v17; // [sp+B4h] [bp-34h] BYREF
  unsigned __int16 v18; // [sp+B6h] [bp-32h]
  unsigned int v19; // [sp+B8h] [bp-30h]
  unsigned int vars8; // [sp+F0h] [bp+8h]
  int anonymous4; // [sp+F4h] [bp+Ch]

  anonymous4 = a2;
  vars8 = a1;
  v12 = 0;
  v13 = 0;
  v3 = 0;
  v14 = 0;
  if ( ExGetPreviousMode() == 1 )
  {
    v5 = a1;
    if ( a1 >= MmUserProbeAddress )
      v5 = MmUserProbeAddress;
    memmove((int)&v16, v5, 0xB8u);
    v6 = v18;
    if ( v18 && v17 && (v7 = v19) != 0 && (v17 & 1) == 0 && (v18 & 1) == 0 && v17 <= (unsigned int)v18 && v17 <= 0xFFFCu )
    {
      v15 = v17 + 2;
      v8 = (unsigned __int16 *)ExAllocatePoolWithTag(1, v15, 1868787809);
      v3 = v8;
      v14 = v8;
      if ( v8 )
      {
        v13 = v15;
        v12 = 0;
        memset(v8, 0, (unsigned __int16)v15);
        if ( (v7 & 1) != 0 )
          ExRaiseDatatypeMisalignment();
        if ( v6 + v7 > MmUserProbeAddress || v6 + v7 < v7 )
          *(_BYTE *)MmUserProbeAddress = 0;
        RtlCopyUnicodeString(&v12, &v17);
        v3 = v14;
        v9 = KseLookupHardwareId(v14) == 0;
        v10 = (bool *)(a1 + 160);
        if ( a1 + 160 >= MmUserProbeAddress )
          v10 = (bool *)MmUserProbeAddress;
        *v10 = v9;
        v4 = 0;
      }
      else
      {
        v4 = -1073741670;
      }
    }
    else
    {
      v4 = -1073741811;
    }
  }
  else
  {
    v4 = -1073741822;
  }
  if ( v3 )
    ExFreePoolWithTag((unsigned int)v3);
  return v4;
}
