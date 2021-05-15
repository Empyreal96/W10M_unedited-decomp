// IopRemoveRelationFromList 
 
int __fastcall IopRemoveRelationFromList(int *a1, int a2, int a3, int a4)
{
  int v5; // r1
  int result; // r0
  int v7; // [sp+0h] [bp-8h] BYREF

  v7 = a4;
  v5 = PipDeviceObjectListIndexOf(*a1, a2, *(_DWORD *)*a1, &v7);
  if ( v5 == -1 )
    result = -1073741810;
  else
    result = PipDeviceObjectListRemove(*a1, v5);
  return result;
}
