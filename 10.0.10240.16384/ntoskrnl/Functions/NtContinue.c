// NtContinue 
 
int __fastcall NtContinue(int a1, unsigned __int8 a2)
{
  int v2; // r12
  unsigned int v3; // r5
  int v4; // r4
  int v5; // r6
  int result; // r0
  int v7; // [sp+0h] [bp-30h] BYREF

  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v4 = a2;
  v5 = v2;
  result = KiContinue((_DWORD *)a1, (int)&v7, v2);
  if ( !result )
  {
    if ( (*(_DWORD *)(v5 + 132) & 0xF) != 0 )
    {
      *(_DWORD *)(v3 + 96) = *(_DWORD *)(v5 + 8);
      *(_BYTE *)(v3 + 346) = *(_BYTE *)(v5 + 19);
    }
    if ( v4 )
      KeTestAlertThread(*(_BYTE *)(v3 + 346));
    KiExceptionRestoreFromService();
  }
  return result;
}
