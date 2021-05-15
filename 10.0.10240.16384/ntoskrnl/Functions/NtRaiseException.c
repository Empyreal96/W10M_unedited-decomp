// NtRaiseException 
 
int __fastcall NtRaiseException(int a1, int a2, unsigned __int8 a3)
{
  int v3; // r12
  unsigned int v4; // r4
  int v5; // r5
  int result; // r0
  int v7[12]; // [sp+0h] [bp-30h] BYREF

  *(_DWORD *)(v3 + 8) = *(_DWORD *)(v3 + 128);
  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v5 = v3;
  v7[0] = a3;
  result = ((int (__fastcall *)(int, int, int *, int))KiRaiseException)(a1, a2, v7, v3);
  if ( !result )
  {
    if ( (*(_DWORD *)(v5 + 132) & 0xF) != 0 )
    {
      *(_DWORD *)(v4 + 96) = *(_DWORD *)(v5 + 8);
      *(_BYTE *)(v4 + 346) = *(_BYTE *)(v5 + 19);
    }
    KiExceptionRestoreFromService();
  }
  return result;
}
