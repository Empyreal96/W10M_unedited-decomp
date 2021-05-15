// IopParseFile 
 
int __fastcall IopParseFile(_DWORD *a1, void *a2, int a3, char a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
  int v11; // r7
  int v14; // r0

  v11 = a4;
  if ( a2 != IoFileObjectType || !a8 || *(_WORD *)a8 != 8 || *(_WORD *)(a8 + 2) != 112 )
    return -1073741788;
  v14 = IoGetRelatedDeviceObject(a1);
  *(_DWORD *)(a8 + 20) = a1;
  return IopParseDevice(v14, a2, a3, v11, a5, a6, a7, a8, a9, a10);
}
