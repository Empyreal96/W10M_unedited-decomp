// NtCreateIoCompletion 
 
int __fastcall NtCreateIoCompletion(_DWORD *a1, int a2, int a3, int a4)
{
  _DWORD *v6; // r5
  int result; // r0
  int v8; // r4
  char v9; // [sp+18h] [bp-30h]
  int v10; // [sp+20h] [bp-28h] BYREF
  int _24[15]; // [sp+24h] [bp-24h] BYREF

  _24[14] = a4;
  _24[13] = a3;
  _24[12] = a2;
  v6 = a1;
  _24[11] = (int)a1;
  v9 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( v9 )
  {
    if ( (unsigned int)a1 >= MmUserProbeAddress )
      a1 = (_DWORD *)MmUserProbeAddress;
    *a1 = *a1;
  }
  result = ObCreateObject(v9, IoCompletionObjectType, a3, v9, 0, 48, 0, 0, _24);
  if ( result >= 0 )
  {
    v8 = _24[0];
    KeInitializeQueue(_24[0], a4);
    *(_DWORD *)(v8 + 40) = 0;
    *(_BYTE *)(v8 + 44) = 0;
    result = ObInsertObject(v8, 0, a2, 0, 0, &v10);
    _24[0] = result;
    if ( result >= 0 )
      *v6 = v10;
  }
  return result;
}
