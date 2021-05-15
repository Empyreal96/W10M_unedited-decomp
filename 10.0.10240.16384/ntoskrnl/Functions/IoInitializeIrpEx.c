// IoInitializeIrpEx 
 
_BYTE *__fastcall IoInitializeIrpEx(int a1, int a2, __int16 a3, char a4)
{
  _BYTE *result; // r0

  result = IoInitializeIrp(a1, a3, a4);
  if ( a2 )
  {
    if ( (*(_DWORD *)(a2 + 28) & 0x8000000) != 0 )
      *(_DWORD *)(a1 + 104) = *(_DWORD *)(a1 + 96);
  }
  return result;
}
