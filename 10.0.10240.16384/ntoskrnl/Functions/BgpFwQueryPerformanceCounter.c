// BgpFwQueryPerformanceCounter 
 
_DWORD *__fastcall BgpFwQueryPerformanceCounter(_DWORD *a1, int a2, int a3, int a4)
{
  _DWORD *result; // r0
  int v6; // [sp+0h] [bp-10h] BYREF
  int v7; // [sp+4h] [bp-Ch]
  int v8; // [sp+8h] [bp-8h]

  v7 = a3;
  v8 = a4;
  KeQueryPerformanceCounter(&v6, a2);
  result = a1;
  *a1 = v6;
  a1[1] = v7;
  return result;
}
