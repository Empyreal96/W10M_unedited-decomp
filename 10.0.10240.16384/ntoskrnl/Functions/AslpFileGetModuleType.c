// AslpFileGetModuleType 
 
int __fastcall AslpFileGetModuleType(int *a1, int a2)
{
  int v2; // r3
  int v3; // r3

  v2 = *(_DWORD *)(a2 + 552);
  switch ( v2 )
  {
    case 4:
      v3 = 1;
      break;
    case 5:
      v3 = 2;
      break;
    case 6:
      v3 = 3;
      break;
    default:
      v3 = 0;
      break;
  }
  *a1 = v3;
  return 0;
}
