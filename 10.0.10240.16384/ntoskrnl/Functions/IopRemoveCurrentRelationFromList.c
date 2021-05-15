// IopRemoveCurrentRelationFromList 
 
int __fastcall IopRemoveCurrentRelationFromList(unsigned int **a1, int a2, _DWORD *a3, unsigned int a4)
{
  unsigned int v7; // r5
  int result; // r0
  unsigned int v9[6]; // [sp+8h] [bp-18h] BYREF

  v9[1] = a4;
  v9[0] = 0;
  if ( *a3 != 1 && *a3 )
    return -1073741637;
  v7 = a3[1] - 1;
  PipDeviceObjectListElementAt(*a1, v7, v9, 0, 0);
  if ( v9[0] != a2 )
    return -1073741810;
  result = PipDeviceObjectListRemove(*a1, v7);
  if ( *a3 > 1u )
    return -1073741637;
  a3[1] = v7;
  return result;
}
