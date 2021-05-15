// PiSwIrpGetLifetime 
 
int __fastcall PiSwIrpGetLifetime(_DWORD *a1)
{
  int v2; // r2
  _DWORD *v3; // r7
  int v4; // r4
  _DWORD *v5; // r6
  int v6; // r2
  int v7; // r3
  int v8; // r0
  unsigned int v9; // r1
  __int16 v10; // r3

  v2 = a1[24];
  v3 = (_DWORD *)a1[3];
  v4 = 0;
  v5 = *(_DWORD **)(*(_DWORD *)(v2 + 28) + 16);
  if ( *(_DWORD *)(v2 + 8) < 4u )
  {
    v4 = -1073741811;
  }
  else
  {
    v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v7 = *(__int16 *)(v6 + 0x134) - 1;
    *(_WORD *)(v6 + 308) = v7;
    ExAcquireResourceExclusiveLite((int)&PiSwLockObj, 1, v6, v7);
    if ( v5 && v5[11] && !v5[12] )
    {
      *v3 = v5[24];
      a1[7] = 4;
    }
    else
    {
      v4 = -1073741637;
    }
    v8 = ExReleaseResourceLite((int)&PiSwLockObj);
    v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v10 = *(_WORD *)(v9 + 0x134) + 1;
    *(_WORD *)(v9 + 308) = v10;
    if ( !v10 && *(_DWORD *)(v9 + 100) != v9 + 100 )
      return sub_81B06C(v8);
  }
  a1[6] = v4;
  IofCompleteRequest((int)a1, 0);
  return v4;
}
