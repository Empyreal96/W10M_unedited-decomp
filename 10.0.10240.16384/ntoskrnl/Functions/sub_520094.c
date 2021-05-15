// sub_520094 
 
void sub_520094(int a1, int a2, unsigned int a3, int a4, int a5, int a6, ...)
{
  bool v6; // zf
  int v7; // [sp+8h] [bp+8h] BYREF
  va_list va; // [sp+8h] [bp+8h]
  int v9; // [sp+Ch] [bp+Ch]
  int v10; // [sp+10h] [bp+10h]
  int v11; // [sp+14h] [bp+14h]
  int v12; // [sp+18h] [bp+18h]
  int v13; // [sp+1Ch] [bp+1Ch]
  int v14; // [sp+20h] [bp+20h]
  int v15; // [sp+24h] [bp+24h]
  int v16; // [sp+28h] [bp+28h]
  int v17; // [sp+2Ch] [bp+2Ch]
  int v18; // [sp+30h] [bp+30h]
  int v19; // [sp+34h] [bp+34h]
  int v20; // [sp+38h] [bp+38h]
  int v21; // [sp+3Ch] [bp+3Ch]
  va_list va1; // [sp+40h] [bp+40h] BYREF

  va_start(va1, a6);
  va_start(va, a6);
  v7 = va_arg(va1, _DWORD);
  v9 = va_arg(va1, _DWORD);
  v10 = va_arg(va1, _DWORD);
  v11 = va_arg(va1, _DWORD);
  v12 = va_arg(va1, _DWORD);
  v13 = va_arg(va1, _DWORD);
  v14 = va_arg(va1, _DWORD);
  v15 = va_arg(va1, _DWORD);
  v16 = va_arg(va1, _DWORD);
  v17 = va_arg(va1, _DWORD);
  v18 = va_arg(va1, _DWORD);
  v19 = va_arg(va1, _DWORD);
  v20 = va_arg(va1, _DWORD);
  v21 = va_arg(va1, _DWORD);
  if ( a3 < (unsigned __int16)KeNumberNodes )
  {
    KeQueryNodeActiveAffinity((unsigned __int16)a3, (int *)va, 0);
    v6 = (v7 & dword_681D78[0]) == 0;
    v9 = 0;
    v7 &= dword_681D78[0];
    v10 = 0;
    if ( !v6 )
    {
      KeSetSystemGroupAffinityThread((int)va, va1);
      JUMPOUT(0x4DBB88);
    }
  }
  JUMPOUT(0x4DBB86);
}
