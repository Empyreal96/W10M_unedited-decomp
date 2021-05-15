// NtCreateEvent 
 
int __fastcall NtCreateEvent(unsigned int a1, int a2, int a3, int a4, unsigned __int8 a5)
{
  char v5; // r8
  _DWORD *v7; // r5
  _DWORD *v8; // r4
  int result; // r0
  char v10; // [sp+18h] [bp-28h]
  int v11; // [sp+1Ch] [bp-24h]
  _DWORD _24[13]; // [sp+24h] [bp-1Ch] BYREF

  v11 = a2;
  _24[0] = a4;
  v5 = a4;
  _24[12] = a4;
  _24[11] = a3;
  _24[10] = a2;
  v7 = (_DWORD *)a1;
  _24[9] = a1;
  v10 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( v10 )
  {
    v8 = (_DWORD *)a1;
    if ( a1 >= MmUserProbeAddress )
      v8 = (_DWORD *)MmUserProbeAddress;
    *v8 = *v8;
  }
  if ( a4 && a4 != 1 )
    return -1073741811;
  result = ObCreateObjectEx(v10, ExEventObjectType, a3, v10);
  if ( result >= 0 )
  {
    KeInitializeEvent(v11, v5, a5);
    result = ObInsertObjectEx(v11, 0, a2, 0, 0, 0, _24);
    if ( result >= 0 )
      *v7 = _24[0];
  }
  return result;
}
