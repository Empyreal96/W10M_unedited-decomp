// PiDmGetCmObjectListFromCache 
 
int __fastcall PiDmGetCmObjectListFromCache(int a1, int a2, int a3)
{
  int v3; // r0
  _DWORD v5[6]; // [sp+8h] [bp-18h] BYREF

  v5[0] = a2;
  v5[1] = a3;
  v5[2] = a1;
  v3 = CmMapCmObjectTypeToPnpObjectType(a1);
  return PiDmGetObjectList(v3, PiDmCmObjectMatchCallback, v5);
}
