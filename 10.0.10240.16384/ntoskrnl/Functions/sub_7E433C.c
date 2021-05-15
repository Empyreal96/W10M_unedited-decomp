// sub_7E433C 
 
void sub_7E433C(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, ...)
{
  _DWORD *v9; // r5
  _DWORD *v10; // r6
  unsigned int v11; // r0
  BOOL v12; // r3
  unsigned int v13; // r0
  _DWORD *v15; // [sp+14h] [bp+14h] BYREF
  va_list va; // [sp+14h] [bp+14h]
  int v17; // [sp+18h] [bp+18h]
  int v18; // [sp+1Ch] [bp+1Ch]
  va_list va1; // [sp+20h] [bp+20h] BYREF

  va_start(va1, a9);
  va_start(va, a9);
  v15 = va_arg(va1, _DWORD *);
  v17 = va_arg(va1, _DWORD);
  v18 = va_arg(va1, _DWORD);
  if ( v9 && PiDevCfgQueryResolveValue((int)va1, a9, (int)L"Reboot", (_DWORD **)va) >= 0 )
  {
    v11 = (unsigned int)v15;
    v12 = v15[1] == 4 && v15[3] == 4;
    if ( v12 && *(_DWORD *)((char *)v15 + v15[2]) )
      *v9 |= 2u;
    ExFreePoolWithTag(v11);
  }
  if ( v10 && PiDevCfgQueryResolveValue((int)va1, a9, (int)L"ConfigFlags", (_DWORD **)va) >= 0 )
  {
    v13 = (unsigned int)v15;
    if ( v15[1] == 4 && v15[3] == 4 )
      *v10 |= *(_DWORD *)((char *)v15 + v15[2]);
    ExFreePoolWithTag(v13);
  }
  JUMPOUT(0x77CBD2);
}
