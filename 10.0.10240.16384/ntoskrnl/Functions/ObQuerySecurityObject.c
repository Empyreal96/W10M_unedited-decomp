// ObQuerySecurityObject 
 
int ObQuerySecurityObject(int a1, ...)
{
  int result; // r0
  int varg_r1; // [sp+2Ch] [bp+Ch] BYREF
  va_list varg_r1a; // [sp+2Ch] [bp+Ch]
  int varg_r2; // [sp+30h] [bp+10h]
  void *varg_r3; // [sp+34h] [bp+14h] BYREF
  va_list varg_r3a; // [sp+34h] [bp+14h]
  _DWORD *v7; // [sp+38h] [bp+18h]
  va_list va2; // [sp+3Ch] [bp+1Ch] BYREF

  va_start(va2, a1);
  va_start(varg_r3a, a1);
  va_start(varg_r1a, a1);
  varg_r1 = va_arg(varg_r3a, _DWORD);
  varg_r2 = va_arg(varg_r3a, _DWORD);
  va_copy(va2, varg_r3a);
  varg_r3 = va_arg(va2, void *);
  v7 = va_arg(va2, _DWORD *);
  result = (*(int (__fastcall **)(int, int, int *, int, void **))(ObTypeIndexTable[*(unsigned __int8 *)(a1 - 12) ^ (unsigned __int8)((unsigned __int16)(a1 - 24) >> 8) ^ (unsigned __int8)ObHeaderCookie]
                                                                + 108))(
             a1,
             1,
             (int *)varg_r1a,
             varg_r2,
             varg_r3a);
  *v7 = varg_r3;
  return result;
}
