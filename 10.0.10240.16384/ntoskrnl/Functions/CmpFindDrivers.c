// CmpFindDrivers 
 
int __fastcall CmpFindDrivers(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int v10; // r6
  unsigned int v11; // r9
  int v12; // r7
  int v13[2]; // [sp+8h] [bp-30h] BYREF
  int v14; // [sp+10h] [bp-28h] BYREF
  _DWORD *v15; // [sp+14h] [bp-24h] BYREF

  v13[1] = -1;
  v14 = -1;
  if ( !CmpLoadServicesNode(a1, a2, &v15, &v14) )
    return 0;
  v13[0] = 0;
  if ( a7 )
    return sub_968204();
  v10 = CmpFindGroupOrderList(a1, a2);
  if ( v10 == -1 )
    return 0;
  v11 = 0;
  while ( 1 )
  {
    CmpFindSubKeyByNumber(a1, v15, v11, v13);
    v12 = v13[0];
    ++v11;
    if ( v13[0] == -1 )
      break;
    if ( CmpIsLoadType(a1, v13[0]) )
      CmpAddDriverToList(a1, v12, v10);
  }
  (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v14);
  return 1;
}
