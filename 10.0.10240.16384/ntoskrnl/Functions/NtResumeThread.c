// NtResumeThread 
 
int __fastcall NtResumeThread(int a1, unsigned int a2)
{
  _DWORD *v2; // r5
  _DWORD *v3; // r2
  int v4; // r0
  char v7; // [sp+10h] [bp-28h]
  int v8; // [sp+14h] [bp-24h] BYREF
  _DWORD _1C[11]; // [sp+1Ch] [bp-1Ch] BYREF

  v2 = (_DWORD *)a2;
  _1C[10] = a2;
  _1C[9] = a1;
  v7 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( v7 && a2 )
  {
    v3 = (_DWORD *)a2;
    if ( a2 >= MmUserProbeAddress )
      v3 = (_DWORD *)MmUserProbeAddress;
    *v3 = *v3;
  }
  v4 = ObReferenceObjectByHandleWithTag(a1, 4096, PsThreadType, v7, 1968403280, &v8, 0);
  if ( v4 < 0 )
    return v4;
  PsResumeThread(v8, _1C);
  ObfDereferenceObjectWithTag(v8);
  if ( v2 )
    *v2 = _1C[0];
  return 0;
}
