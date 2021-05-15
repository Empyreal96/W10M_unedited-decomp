// PopSqmBatteryUpdate 
 
_BYTE *__fastcall PopSqmBatteryUpdate(_BYTE *result, int a2, int a3, int a4)
{
  int v6; // r2
  _DWORD *v7; // r0
  int v8; // r1
  int v9; // r2
  int v10[2]; // [sp-4h] [bp-30h] BYREF
  int v11; // [sp+4h] [bp-28h] BYREF
  int v12; // [sp+Ch] [bp-20h] BYREF
  int v13[6]; // [sp+14h] [bp-18h] BYREF

  if ( PopPlatformAoAc )
  {
    PopSqmCreateDwordStreamEntry(v10, (int)result);
    PopSqmCreateDwordStreamEntry(&v11, a2);
    PopSqmCreateDwordStreamEntry(&v12, v6);
    v7 = PopSqmCreateDwordStreamEntry(v13, a4);
    result = PopSqmAddToStream((int)v7, v8, v9, v10);
  }
  return result;
}
