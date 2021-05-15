// PopUnregisterPowerSettingCallback 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PopUnregisterPowerSettingCallback(int a1)
{
  int v1; // r3
  int v2; // r1 OVERLAPPED
  _DWORD *v3; // r2 OVERLAPPED
  bool v4; // zf
  int v5; // r3

  v1 = *(char *)(a1 + 17);
  __dmb(0xBu);
  *(_QWORD *)&v2 = *(_QWORD *)a1;
  v4 = v1 == 0;
  v5 = *(_DWORD *)(*(_DWORD *)a1 + 4);
  if ( !v4 )
    return sub_554CA8(a1, v2, v3, v5);
  if ( v5 != a1 || *v3 != a1 )
    __fastfail(3u);
  *v3 = v2;
  *(_DWORD *)(v2 + 4) = v3;
  *(_DWORD *)a1 = a1;
  *(_DWORD *)(a1 + 4) = a1;
  *(_DWORD *)(a1 + 8) = 0;
  return ExFreePoolWithTag(a1, 1952797520);
}
