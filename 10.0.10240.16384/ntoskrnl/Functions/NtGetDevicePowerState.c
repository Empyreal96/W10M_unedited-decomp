// NtGetDevicePowerState 
 
int __fastcall NtGetDevicePowerState(int a1, unsigned int a2, int a3, int a4)
{
  _DWORD *v4; // r5
  _DWORD *v5; // r2
  char v6; // r3
  int v7; // r4
  int v8; // r6
  int v10; // [sp+8h] [bp-20h] BYREF
  _DWORD _C[11]; // [sp+Ch] [bp-1Ch] BYREF

  v10 = a1;
  _C[0] = a2;
  _C[1] = a3;
  _C[2] = a4;
  v4 = (_DWORD *)a2;
  _C[10] = a2;
  _C[9] = a1;
  if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) )
  {
    v5 = (_DWORD *)a2;
    if ( a2 >= MmUserProbeAddress )
      v5 = (_DWORD *)MmUserProbeAddress;
    *v5 = *v5;
  }
  v6 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v7 = ObReferenceObjectByHandle(a1, 0, (int)IoFileObjectType, v6, (int)&v10, 0);
  if ( v7 >= 0 )
  {
    v7 = IoGetRelatedTargetDevice(v10, _C);
    ObfDereferenceObject(v10);
    if ( v7 >= 0 )
    {
      v8 = _C[0];
      *v4 = PopLockGetDoDevicePowerState(*(_DWORD *)(_C[0] + 176));
      ObfDereferenceObject(v8);
    }
  }
  return v7;
}
