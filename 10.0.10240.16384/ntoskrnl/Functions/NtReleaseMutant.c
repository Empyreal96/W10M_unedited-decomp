// NtReleaseMutant 
 
int __fastcall NtReleaseMutant(unsigned int a1, unsigned int a2)
{
  _DWORD *v2; // r5
  unsigned int v3; // r2
  int v4; // r9
  _DWORD *v5; // r2
  int v6; // r8
  int v7; // r6
  int v8; // r10
  unsigned int _10[14]; // [sp+10h] [bp-28h] BYREF

  v2 = (_DWORD *)a2;
  _10[13] = a2;
  _10[12] = a1;
  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v4 = *(char *)(v3 + 0x15A);
  if ( a2 && *(_BYTE *)(v3 + 0x15A) )
  {
    v5 = (_DWORD *)a2;
    if ( a2 >= MmUserProbeAddress )
      v5 = (_DWORD *)MmUserProbeAddress;
    *v5 = *v5;
  }
  v6 = ObReferenceObjectByHandle(a1, 0, ExMutantObjectType, v4, _10);
  _10[1] = v6;
  if ( v6 >= 0 )
  {
    v7 = _10[0];
    v8 = KeReleaseMutant(_10[0], 1, 0, 0);
    _10[2] = v8;
    ObfDereferenceObject(v7);
    if ( v2 )
      *v2 = v8;
  }
  return v6;
}
