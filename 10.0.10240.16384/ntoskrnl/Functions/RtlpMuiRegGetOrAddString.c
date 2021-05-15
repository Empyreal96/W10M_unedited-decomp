// RtlpMuiRegGetOrAddString 
 
int __fastcall RtlpMuiRegGetOrAddString(_DWORD *a1, _WORD *a2, int a3, __int16 *a4)
{
  __int16 v5; // r8
  BOOL v6; // r2
  int result; // r0
  _DWORD v8[8]; // [sp+0h] [bp-20h] BYREF

  v8[0] = a3;
  v8[1] = a4;
  v5 = -1;
  if ( a1 && a2 && *a2 )
  {
    v6 = a3 && (*a1 & 2) != 0;
    v5 = ((int (__fastcall *)(_DWORD, _WORD *, BOOL, _DWORD *))RtlpMuiRegGetOrAddStringToPool)(a1[6], a2, v6, v8);
    if ( v5 < 0 )
      return sub_80C064();
    result = 0;
  }
  else
  {
    result = -1073741811;
  }
  if ( a4 )
    *a4 = v5;
  return result;
}
