// NtQueryInformationPort 
 
int __fastcall NtQueryInformationPort(int a1, int a2, unsigned int a3, int a4, unsigned int a5)
{
  char v6; // r8
  _DWORD *v7; // r5
  _DWORD *v8; // r2
  int v9; // r4
  int _C[13]; // [sp+Ch] [bp-1Ch] BYREF

  _C[10] = a2;
  _C[11] = a3;
  _C[12] = a4;
  _C[0] = a4;
  _C[9] = a1;
  v6 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( v6 )
  {
    ProbeForWrite(a3, a4, 4);
    v7 = (_DWORD *)a5;
    if ( a5 )
    {
      v8 = (_DWORD *)a5;
      if ( a5 >= MmUserProbeAddress )
        v8 = (_DWORD *)MmUserProbeAddress;
      *v8 = *v8;
    }
  }
  else
  {
    v7 = (_DWORD *)a5;
  }
  if ( !a1 )
    return -1073741821;
  v9 = ObReferenceObjectByHandle(a1, 0x20000, AlpcPortObjectType, v6, (int)_C, 0);
  if ( v9 >= 0 )
  {
    if ( v7 )
      *v7 = 0;
    ObfDereferenceObject(_C[0]);
  }
  return v9;
}
