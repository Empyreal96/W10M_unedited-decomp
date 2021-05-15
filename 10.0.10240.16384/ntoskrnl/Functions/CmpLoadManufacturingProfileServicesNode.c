// CmpLoadManufacturingProfileServicesNode 
 
BOOL __fastcall CmpLoadManufacturingProfileServicesNode(int a1, int a2, unsigned __int16 *a3, int *a4, int a5)
{
  int v7; // r3
  BOOL result; // r0
  int v9; // r4
  int v10; // r0
  int v11; // [sp+8h] [bp-18h] BYREF
  int *v12; // [sp+Ch] [bp-14h] BYREF

  v12 = a4;
  v11 = -1;
  result = 0;
  if ( CmpLoadManufacturingProfileNode(a1, a2, a3, (int *)&v12, (int)&v11) )
  {
    v9 = CmpFindSubKeyByName(a1, (int)v12, (int)&CmpServicesString, v7);
    (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v11);
    if ( v9 != -1 )
    {
      v10 = (*(int (__fastcall **)(int, int, int))(a1 + 4))(a1, v9, a5);
      *a4 = v10;
      if ( v10 )
        result = 1;
    }
  }
  return result;
}
