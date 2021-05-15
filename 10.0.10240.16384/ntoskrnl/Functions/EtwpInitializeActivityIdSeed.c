// EtwpInitializeActivityIdSeed 
 
_DWORD *__fastcall EtwpInitializeActivityIdSeed(int a1, __int16 a2)
{
  _DWORD *result; // r0
  int v4; // [sp+8h] [bp-20h] BYREF
  int v5; // [sp+10h] [bp-18h] BYREF
  __int16 v6; // [sp+14h] [bp-14h]

  *(_WORD *)(a1 + 6) = a2;
  KeQuerySystemTime((_DWORD *)(a1 + 8));
  v4 = 16;
  result = (_DWORD *)HeadlessDispatch(21, 0, 0, &v5, &v4);
  if ( result )
    result = KeQuerySystemTime(&v5);
  *(_DWORD *)a1 = v5;
  *(_WORD *)(a1 + 4) = v6;
  return result;
}
