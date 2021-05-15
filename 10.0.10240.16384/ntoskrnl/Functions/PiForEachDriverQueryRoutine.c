// PiForEachDriverQueryRoutine 
 
int __fastcall PiForEachDriverQueryRoutine(int a1, unsigned __int16 *a2, unsigned int a3, _DWORD *a4)
{
  int result; // r0
  unsigned int v8; // r5
  unsigned int v9; // r6
  _DWORD v10[6]; // [sp+0h] [bp-18h] BYREF

  v10[0] = a3;
  v10[1] = a4;
  result = 0;
  v8 = a3;
  if ( (a1 == 1 || a1 == 7) && a3 > 2 )
  {
    if ( a1 == 1 )
    {
      RtlInitUnicodeString((unsigned int)v10, a2);
      result = ((int (__fastcall *)(_DWORD, _DWORD *, _DWORD))a4[1])(*a4, v10, a4[2]);
    }
    else
    {
      while ( *a2 )
      {
        v9 = wcslen(a2) + 1;
        if ( v8 < 2 * v9 )
          return 0;
        v8 -= 2 * v9;
        RtlInitUnicodeString((unsigned int)v10, a2);
        result = ((int (__fastcall *)(_DWORD, _DWORD *, _DWORD))a4[1])(*a4, v10, a4[2]);
        if ( result < 0 || v8 < 2 )
          return result;
        a2 += v9;
      }
    }
  }
  return result;
}
