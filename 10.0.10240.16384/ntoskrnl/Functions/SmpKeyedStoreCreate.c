// SmpKeyedStoreCreate 
 
int SmpKeyedStoreCreate(int a1, int a2, ...)
{
  int v3; // r0
  int v4; // r1
  int v5; // r2
  int v6; // r3
  int v7; // r5
  _DWORD **v9; // r4
  unsigned int *v10; // r0
  unsigned int v11; // r4
  unsigned int v12; // r1
  int v13[8]; // [sp+0h] [bp-20h] BYREF
  int varg_r2; // [sp+30h] [bp+10h] BYREF
  va_list varg_r2a; // [sp+30h] [bp+10h]
  int varg_r3; // [sp+34h] [bp+14h]
  int v17; // [sp+38h] [bp+18h]
  int v18; // [sp+3Ch] [bp+1Ch]
  int v19; // [sp+40h] [bp+20h]
  int v20; // [sp+44h] [bp+24h]
  int v21; // [sp+48h] [bp+28h]
  int v22; // [sp+4Ch] [bp+2Ch]
  int v23; // [sp+50h] [bp+30h]
  int v24; // [sp+54h] [bp+34h]
  int v25; // [sp+58h] [bp+38h]
  va_list va1; // [sp+5Ch] [bp+3Ch] BYREF

  va_start(va1, a2);
  va_start(varg_r2a, a2);
  varg_r2 = va_arg(va1, _DWORD);
  varg_r3 = va_arg(va1, _DWORD);
  v17 = va_arg(va1, _DWORD);
  v18 = va_arg(va1, _DWORD);
  v19 = va_arg(va1, _DWORD);
  v20 = va_arg(va1, _DWORD);
  v21 = va_arg(va1, _DWORD);
  v22 = va_arg(va1, _DWORD);
  v23 = va_arg(va1, _DWORD);
  v24 = va_arg(va1, _DWORD);
  v25 = va_arg(va1, _DWORD);
  v13[1] = varg_r3;
  v13[0] = -1;
  if ( SmpKeyedStoreEntryGet(a1, (int)varg_r2a, 0, 0) )
    return -1073741791;
  v3 = SmpDirtyStoreCreate(a2, 128, 1, v13);
  v7 = v3;
  if ( v3 < 0 )
  {
    if ( v13[0] != -1 )
    {
      v9 = (_DWORD **)(a2 + 96 * (v13[0] & 0x1F));
      SmKmStoreDeleteWhenEmpty(a2, *v9, 1, 3 * (v13[0] & 0x1F));
      v10 = (unsigned int *)(v9 + 1);
      __pld(v9 + 1);
      v11 = (unsigned int)v9[1] & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v12 = __ldrex(v10);
      while ( v12 == v11 && __strex(v11 - 2, v10) );
      if ( v12 != v11 )
        ExfReleaseRundownProtection((unsigned __int8 *)v10);
    }
    return v7;
  }
  return sub_7BF5AC(v3, v4, v5, v6, v17, v18, v19, v20, v21, v22, v23, v24, v25);
}
