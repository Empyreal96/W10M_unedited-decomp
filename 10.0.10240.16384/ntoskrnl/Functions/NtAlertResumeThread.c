// NtAlertResumeThread 
 
int __fastcall NtAlertResumeThread(int a1, unsigned int a2, int a3, int a4)
{
  _DWORD *v4; // r5
  _DWORD *v5; // r2
  int v6; // r0
  int v7; // r4
  int v8; // r6
  int v9; // r8
  char v11; // [sp+10h] [bp-28h]
  int _14[13]; // [sp+14h] [bp-24h] BYREF

  _14[0] = a2;
  _14[1] = a3;
  _14[2] = a4;
  v4 = (_DWORD *)a2;
  _14[12] = a2;
  _14[11] = a1;
  v11 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( v11 && a2 )
  {
    v5 = (_DWORD *)a2;
    if ( a2 >= MmUserProbeAddress )
      v5 = (_DWORD *)MmUserProbeAddress;
    *v5 = *v5;
  }
  v6 = ObReferenceObjectByHandleWithTag(a1, 2, PsThreadType, v11, 1968403280, _14, 0);
  if ( v6 < 0 )
    return v6;
  v8 = _14[0];
  if ( v11 && (*(_DWORD *)(_14[0] + 76) & 0x400) != 0 )
  {
    ObfDereferenceObjectWithTag(_14[0]);
    v7 = -1073741790;
  }
  else
  {
    v9 = KeAlertResumeThread(_14[0]);
    ObfDereferenceObjectWithTag(v8);
    if ( v4 )
      *v4 = v9;
    v7 = 0;
  }
  return v7;
}
