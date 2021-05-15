// sub_7CE994 
 
void __fastcall sub_7CE994(int a1, int a2)
{
  int v2; // r4
  _DWORD *v3; // r0
  int v4; // r2
  int v5; // r3
  int (*v6)(void); // r0

  v3 = MiSessionLookupImage(a2);
  v5 = v3[8];
  if ( v5 == 1 )
  {
    v6 = (int (*)(void))RtlFindExportedRoutineByName(*(_DWORD *)(v2 + 24), (int)"DllUnload", v4, 1);
    if ( v6 )
    {
      if ( v6() >= 0 )
        JUMPOUT(0x773EBE);
    }
  }
  else
  {
    v3[8] = v5 - 1;
  }
  JUMPOUT(0x773EBC);
}
