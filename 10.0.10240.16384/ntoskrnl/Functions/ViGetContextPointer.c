// ViGetContextPointer 
 
int __fastcall ViGetContextPointer(int a1, int a2)
{
  int v3; // r0

  switch ( a2 )
  {
    case 0:
      return *(_DWORD *)(a1 + 176) + 52;
    case 1:
      return *(_DWORD *)(a1 + 24) + 36;
    case 2:
      v3 = IopAllocateIrpExtension(a1, 3);
      if ( v3 )
        return v3 + 8;
      break;
    case 3:
      return a1 + 1044;
  }
  return 0;
}
