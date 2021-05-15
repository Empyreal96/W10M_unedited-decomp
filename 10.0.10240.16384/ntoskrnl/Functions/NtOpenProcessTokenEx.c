// NtOpenProcessTokenEx 
 
int __fastcall NtOpenProcessTokenEx(int a1, int a2, int a3, unsigned int a4)
{
  _DWORD *v4; // r5
  int v6; // r9
  _DWORD *v7; // r2
  int v8; // r0
  int v10; // r6
  char v12; // [sp+10h] [bp-30h]
  int v13; // [sp+18h] [bp-28h] BYREF
  _DWORD _1C[15]; // [sp+1Ch] [bp-24h] BYREF

  _1C[13] = a3;
  v4 = (_DWORD *)a4;
  _1C[14] = a4;
  _1C[12] = a2;
  _1C[11] = a1;
  v12 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( v12 )
    v6 = a3 & 0xDF2;
  else
    v6 = a3 & 0x10FF2;
  v13 = v6;
  if ( v12 )
  {
    v7 = (_DWORD *)a4;
    if ( a4 >= MmUserProbeAddress )
      v7 = (_DWORD *)MmUserProbeAddress;
    *v7 = *v7;
  }
  v8 = PsOpenTokenOfProcess(a1, &v13);
  if ( v8 < 0 )
    return v8;
  v10 = ObOpenObjectByPointer(v13, v6, 0, a2, SeTokenObjectType, v12, _1C);
  _1C[1] = v10;
  ObfDereferenceObject(v13);
  if ( v10 >= 0 )
    *v4 = _1C[0];
  return v10;
}
