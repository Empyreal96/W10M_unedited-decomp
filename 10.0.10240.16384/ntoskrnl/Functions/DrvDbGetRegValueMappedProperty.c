// DrvDbGetRegValueMappedProperty 
 
int __fastcall DrvDbGetRegValueMappedProperty(int a1, int a2, int a3, _DWORD *a4, int *a5, unsigned int a6, _DWORD *a7)
{
  int v8; // r2
  int *v10; // r0
  int result; // r0
  int v12; // r3
  unsigned int v13; // r2
  unsigned int v14; // [sp+8h] [bp-20h] BYREF
  int v15; // [sp+Ch] [bp-1Ch] BYREF
  int v16[6]; // [sp+10h] [bp-18h] BYREF

  v8 = *(_DWORD *)(a3 + 4);
  v15 = 0;
  v16[0] = 0;
  if ( v8 == 17 || v8 == 5 )
  {
    v10 = &v15;
    v14 = 4;
  }
  else
  {
    v10 = a5;
    v14 = a6;
  }
  result = PnpCtxRegQueryValue((int)v10, a2, *(unsigned __int16 **)(a3 + 8), v16, (int)v10, &v14);
  if ( result == -1073741772 )
    return -1073741275;
  if ( result && result != -1073741789 )
    return result;
  if ( v16[0] != *(_DWORD *)(a3 + 12) )
    return -1073741595;
  *a4 = *(_DWORD *)(a3 + 4);
  v12 = *(_DWORD *)(a3 + 4);
  if ( v12 == 5 )
  {
    *a7 = 2;
    if ( !a5 || a6 < 2 )
      return -1073741789;
    if ( result != -1073741789 )
    {
      *(_WORD *)a5 = v15;
      return result;
    }
    return -1073741595;
  }
  if ( v12 == 17 )
    return sub_7E3100();
  v13 = v14;
  *a7 = v14;
  if ( !a5 || a6 < v13 )
    return -1073741789;
  return result;
}
