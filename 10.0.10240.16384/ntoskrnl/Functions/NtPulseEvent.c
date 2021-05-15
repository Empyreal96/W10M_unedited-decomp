// NtPulseEvent 
 
int __fastcall NtPulseEvent(int a1, unsigned int a2)
{
  _DWORD *v2; // r5
  int v3; // r3
  char v4; // r6
  _DWORD *v5; // r2
  int v6; // r4
  int v7; // r8
  int _C[13]; // [sp+Ch] [bp-24h] BYREF

  v2 = (_DWORD *)a2;
  _C[12] = a2;
  _C[11] = a1;
  v3 = __mrc(15, 0, 13, 0, 3);
  v4 = *(_BYTE *)((v3 & 0xFFFFFFC0) + 0x15A);
  if ( a2 && *(_BYTE *)((v3 & 0xFFFFFFC0) + 0x15A) )
  {
    v5 = (_DWORD *)a2;
    if ( a2 >= MmUserProbeAddress )
      v5 = (_DWORD *)MmUserProbeAddress;
    *v5 = *v5;
  }
  v6 = ObReferenceObjectByHandle(a1, 2, ExEventObjectType, v4, (int)_C, 0);
  _C[2] = v6;
  if ( v6 >= 0 )
  {
    v7 = KePulseEvent(_C[0], 1, 0);
    ObfDereferenceObject(_C[0]);
    if ( v2 )
      *v2 = v7;
  }
  return v6;
}
