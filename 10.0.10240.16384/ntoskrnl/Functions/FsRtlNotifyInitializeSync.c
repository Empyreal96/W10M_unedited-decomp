// FsRtlNotifyInitializeSync 
 
int __fastcall FsRtlNotifyInitializeSync(_DWORD *a1)
{
  _DWORD *v2; // r4
  int result; // r0

  *a1 = 0;
  v2 = (_DWORD *)ExAllocatePoolWithTag(528, 40, 1316115270);
  *v2 = 1;
  v2[1] = 0;
  v2[2] = 0;
  result = KeInitializeEvent((int)(v2 + 3), 1, 0);
  v2[8] = 0;
  v2[9] = 0;
  *a1 = v2;
  return result;
}
