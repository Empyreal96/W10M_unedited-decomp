// sub_51B580 
 
void __fastcall sub_51B580(int a1, int a2, int a3, int a4)
{
  switch ( a4 )
  {
    case 0:
      JUMPOUT(0x4431E8);
    case 1:
      JUMPOUT(0x4431DC);
    case 2:
      JUMPOUT(0x4431D0);
    case 3:
      JUMPOUT(0x4431C4);
    case 4:
      JUMPOUT(0x4431B8);
    case 5:
      JUMPOUT(0x4431AC);
    case 7:
      break;
    default:
      *(_DWORD *)(a1 + 28) = __mrc(14, 0, 0, 7, 4);
      *(_DWORD *)(a2 + 28) = __mrc(14, 0, 0, 7, 5);
      break;
  }
  *(_DWORD *)(a1 + 24) = __mrc(14, 0, 0, 6, 4);
  *(_DWORD *)(a2 + 24) = __mrc(14, 0, 0, 6, 5);
  JUMPOUT(0x4431A0);
}
