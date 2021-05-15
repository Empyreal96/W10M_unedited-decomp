// NtCreateSemaphore 
 
int __fastcall NtCreateSemaphore(_DWORD *a1, int a2, int a3, int a4, int a5)
{
  _DWORD *v7; // r5
  int result; // r0
  char v9; // [sp+18h] [bp-30h]
  int v10; // [sp+1Ch] [bp-2Ch] BYREF
  _DWORD _24[15]; // [sp+24h] [bp-24h] BYREF

  _24[14] = a4;
  _24[13] = a3;
  _24[12] = a2;
  v7 = a1;
  _24[11] = a1;
  v9 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( v9 )
  {
    if ( (unsigned int)a1 >= MmUserProbeAddress )
      a1 = (_DWORD *)MmUserProbeAddress;
    *a1 = *a1;
  }
  if ( a5 <= 0 || a4 < 0 || a4 > a5 )
    return -1073741811;
  result = ObCreateObject(v9, ExSemaphoreObjectType, a3, v9, 0, 20, 0, 0, &v10);
  if ( result >= 0 )
  {
    KeInitializeSemaphore(v10, a4, a5);
    result = ObInsertObjectEx(v10, 0, a2, 0, 0, 0, _24);
    v10 = result;
    if ( result >= 0 )
      *v7 = _24[0];
  }
  return result;
}
