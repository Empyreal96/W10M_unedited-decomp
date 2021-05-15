// PspAllocateMonitorContextArrayServerSilo 
 
int __fastcall PspAllocateMonitorContextArrayServerSilo(int a1)
{
  _BYTE *v2; // r0
  _BYTE *v3; // r4

  v2 = (_BYTE *)ExAllocatePoolWithTag(512, 128, 1097623891);
  v3 = v2;
  if ( !v2 )
    return -1073741670;
  memset(v2, 0, 128);
  *(_DWORD *)(a1 + 32) = v3;
  *(_DWORD *)(a1 + 36) = 32;
  return 0;
}
