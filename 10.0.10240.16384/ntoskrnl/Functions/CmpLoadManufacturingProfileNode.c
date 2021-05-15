// CmpLoadManufacturingProfileNode 
 
BOOL __fastcall CmpLoadManufacturingProfileNode(int a1, int a2, unsigned __int16 *a3, int *a4, int a5)
{
  int v9; // r3
  int v10; // r5
  int v11; // r0
  int v12; // [sp+0h] [bp-20h] BYREF
  int v13; // [sp+4h] [bp-1Ch] BYREF
  _DWORD v14[6]; // [sp+8h] [bp-18h] BYREF

  v13 = a2;
  v14[0] = a3;
  v14[1] = a4;
  v12 = -1;
  if ( !a3 || !CmpLoadManufacturingModeNode(a1, a2, &v13, (int)&v12) )
    return 0;
  if ( RtlInitUnicodeStringEx((int)v14, a3) < 0 )
  {
    (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v12);
    return 0;
  }
  v10 = CmpFindSubKeyByName(a1, v13, (int)v14, v9);
  (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v12);
  if ( v10 == -1 )
    return 0;
  v11 = (*(int (__fastcall **)(int, int, int))(a1 + 4))(a1, v10, a5);
  *a4 = v11;
  return v11 != 0;
}
