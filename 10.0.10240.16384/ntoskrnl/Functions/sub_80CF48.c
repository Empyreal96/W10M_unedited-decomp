// sub_80CF48 
 
void __fastcall sub_80CF48(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
  int v9; // r5
  int v10; // r9
  int v11; // r5

  if ( (*(_DWORD *)(v10 + 28) & 0x1000) == 0 )
  {
    v11 = PipAllocateDeviceNode(v10, &a9);
    if ( a9 )
    {
      if ( v11 != -1073740946 )
      {
        PipSetDevNodeFlags(a9, 0x20000);
        JUMPOUT(0x7942A4);
      }
      IopDestroyDeviceNode(a9);
      goto LABEL_8;
    }
    v9 = -1073741670;
  }
  if ( v9 >= 0 )
    JUMPOUT(0x7942A8);
LABEL_8:
  JUMPOUT(0x7942F4);
}
