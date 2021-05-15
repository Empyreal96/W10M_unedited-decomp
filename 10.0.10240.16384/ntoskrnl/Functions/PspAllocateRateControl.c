// PspAllocateRateControl 
 
int __fastcall PspAllocateRateControl(int a1)
{
  int v1; // r5
  int v2; // r2
  int v3; // r0
  _BYTE *v4; // r4
  int v5; // r6

  v1 = PspGetRateControlSize(a1);
  if ( v2 == 2 )
    v3 = 512;
  else
    v3 = 1;
  v4 = (_BYTE *)ExAllocatePoolWithTag(v3, v1, 1649046352);
  if ( !v4 )
    return (int)v4;
  v5 = PsChargeSharedPoolQuota(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), v1, 0);
  if ( v5 )
  {
    memset(v4, 0, v1);
    *(_DWORD *)v4 = v5;
    return (int)v4;
  }
  return sub_7BDA68(v4);
}
