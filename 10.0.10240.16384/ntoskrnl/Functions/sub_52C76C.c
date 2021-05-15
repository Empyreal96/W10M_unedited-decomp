// sub_52C76C 
 
void __fastcall sub_52C76C(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
  int v10; // r5
  int v11; // r6
  int (__fastcall **v12)(int, int, _DWORD, int); // r7

  do
  {
    if ( IopAllocateReserveIrp(a1, v10, 3) )
      break;
    a1 = (*v12)(v11, v10, 0, a10);
  }
  while ( !a1 );
  JUMPOUT(0x4737D8);
}
