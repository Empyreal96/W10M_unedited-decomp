// ObSetSecurityObjectByPointer 
 
int ObSetSecurityObjectByPointer(int a1, ...)
{
  int v1; // r2
  int (__fastcall *v2)(int, _DWORD, int *, int, _DWORD); // r4
  int varg_r1; // [sp+2Ch] [bp+Ch] BYREF
  va_list varg_r1a; // [sp+2Ch] [bp+Ch]
  int varg_r2; // [sp+30h] [bp+10h]
  va_list varg_r3; // [sp+34h] [bp+14h] BYREF

  va_start(varg_r3, a1);
  va_start(varg_r1a, a1);
  varg_r1 = va_arg(varg_r3, _DWORD);
  varg_r2 = va_arg(varg_r3, _DWORD);
  v1 = varg_r2;
  v2 = *(int (__fastcall **)(int, _DWORD, int *, int, _DWORD))(ObTypeIndexTable[*(unsigned __int8 *)(a1 - 12) ^ (unsigned __int8)((unsigned __int16)(a1 - 24) >> 8) ^ (unsigned __int8)ObHeaderCookie]
                                                             + 108);
  __mrc(15, 0, 13, 0, 3);
  return v2(a1, 0, (int *)varg_r1a, v1, 0);
}
