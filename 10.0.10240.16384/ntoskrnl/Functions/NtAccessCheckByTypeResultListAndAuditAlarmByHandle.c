// NtAccessCheckByTypeResultListAndAuditAlarmByHandle 
 
int NtAccessCheckByTypeResultListAndAuditAlarmByHandle(int a1, int a2, ...)
{
  int varg_r2; // [sp+50h] [bp+10h] BYREF
  va_list varg_r2a; // [sp+50h] [bp+10h]
  int varg_r3; // [sp+54h] [bp+14h]
  int v6; // [sp+58h] [bp+18h]
  int v7; // [sp+5Ch] [bp+1Ch]
  int v8; // [sp+60h] [bp+20h]
  int v9; // [sp+64h] [bp+24h]
  int v10; // [sp+68h] [bp+28h]
  int v11; // [sp+6Ch] [bp+2Ch]
  int v12; // [sp+70h] [bp+30h]
  int v13; // [sp+74h] [bp+34h]
  int v14; // [sp+78h] [bp+38h]
  int v15; // [sp+7Ch] [bp+3Ch]
  int v16; // [sp+80h] [bp+40h]
  int v17; // [sp+84h] [bp+44h]
  int v18; // [sp+88h] [bp+48h]
  va_list va1; // [sp+8Ch] [bp+4Ch] BYREF

  va_start(va1, a2);
  va_start(varg_r2a, a2);
  varg_r2 = va_arg(va1, _DWORD);
  varg_r3 = va_arg(va1, _DWORD);
  v6 = va_arg(va1, _DWORD);
  v7 = va_arg(va1, _DWORD);
  v8 = va_arg(va1, _DWORD);
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
  return SepAccessCheckAndAuditAlarm(
           a1,
           a2,
           varg_r2a,
           varg_r3,
           v6,
           v7,
           v8,
           v9,
           v10,
           v11,
           v12,
           v13,
           v14,
           v16,
           v17,
           v18,
           1);
}
