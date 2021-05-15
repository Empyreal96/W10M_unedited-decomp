// sub_7E0B48 
 
void __fastcall sub_7E0B48(__int64 *a1)
{
  _DWORD *v1; // r4
  __int64 v2; // r2

  v2 = *a1;
  if ( *((_DWORD **)a1 + 1) == v1 && *(__int64 **)(v2 + 4) == a1 )
  {
    *v1 = v2;
    *(_DWORD *)(v2 + 4) = v1;
    PiSwInterfaceFree(a1);
    JUMPOUT(0x77777E);
  }
  __fastfail(3u);
}
