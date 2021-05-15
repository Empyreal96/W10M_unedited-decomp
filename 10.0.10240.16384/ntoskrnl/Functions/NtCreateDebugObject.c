// NtCreateDebugObject 
 
int __fastcall NtCreateDebugObject(_DWORD *a1, int a2, int a3, int a4)
{
  char v4; // r8
  _DWORD *v6; // r6
  char v7; // lr
  _DWORD *v8; // r4
  int result; // r0
  _DWORD *v10; // r4
  _DWORD *v11; // [sp+20h] [bp-28h] BYREF
  _DWORD _24[15]; // [sp+24h] [bp-24h] BYREF

  v4 = a4;
  _24[14] = a4;
  _24[13] = a3;
  _24[12] = a2;
  v6 = a1;
  _24[11] = a1;
  v7 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( v7 )
  {
    v8 = a1;
    if ( (unsigned int)a1 >= MmUserProbeAddress )
      v8 = (_DWORD *)MmUserProbeAddress;
    *v8 = *v8;
  }
  *a1 = 0;
  if ( (a4 & 0xFFFFFFFE) != 0 )
    return -1073741811;
  result = ObCreateObject(v7, (_DWORD *)DbgkDebugObjectType, a3, v7, 0, 60, 0, 0, &v11);
  if ( result >= 0 )
  {
    v10 = v11;
    v11[4] = 1;
    v10[5] = 0;
    v10[6] = 0;
    KeInitializeEvent((int)(v10 + 7), 1, 0);
    v10[13] = v10 + 12;
    v10[12] = v10 + 12;
    KeInitializeEvent((int)v10, 0, 0);
    if ( (v4 & 1) != 0 )
      v10[14] = 2;
    else
      v10[14] = 0;
    result = ObInsertObject((int)v10, 0, a2, 0, 0, (int)_24);
    if ( result >= 0 )
      *v6 = _24[0];
  }
  return result;
}
