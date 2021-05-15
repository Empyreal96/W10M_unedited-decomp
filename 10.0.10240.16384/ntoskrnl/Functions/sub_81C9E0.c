// sub_81C9E0 
 
void __fastcall sub_81C9E0(int a1, int a2, int a3)
{
  _DWORD *v3; // r5
  _DWORD *v4; // r4
  _DWORD *v5; // r6
  int v6; // r3

  v3 = (_DWORD *)(a1 + 8);
  v4 = *(_DWORD **)(a1 + 8);
  while ( v4 != v3 )
  {
    v5 = v4 - 13;
    v6 = *(v4 - 12);
    v4 = (_DWORD *)*v4;
    if ( (v6 & 1) == 0 )
    {
      PiSwCloseDecendents(v5 + 10, a2, a3, v6);
      PiSwCloseDevice(v5);
    }
  }
  JUMPOUT(0x7BCED6);
}
