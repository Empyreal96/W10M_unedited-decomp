// NtSuspendThread 
 
int __fastcall NtSuspendThread(int a1, unsigned int a2)
{
  _DWORD *v2; // r5
  _DWORD *v3; // r2
  int v4; // r4
  char v6; // [sp+10h] [bp-28h]
  int v7; // [sp+14h] [bp-24h] BYREF
  _DWORD _1C[11]; // [sp+1Ch] [bp-1Ch] BYREF

  v2 = (_DWORD *)a2;
  _1C[10] = a2;
  _1C[9] = a1;
  v6 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( v6 && a2 )
  {
    v3 = (_DWORD *)a2;
    if ( a2 >= MmUserProbeAddress )
      v3 = (_DWORD *)MmUserProbeAddress;
    *v3 = *v3;
  }
  v4 = ObReferenceObjectByHandleWithTag(a1, 2, PsThreadType, v6, 1968403280, &v7, 0);
  if ( v4 >= 0 )
  {
    v4 = PsSuspendThread(v7, _1C);
    ObfDereferenceObjectWithTag(v7);
    if ( v2 )
      *v2 = _1C[0];
  }
  return v4;
}
