// sub_5269EC 
 
void sub_5269EC()
{
  int v0; // r6
  int v1; // r8
  __int64 **v2; // r5
  __int64 *v3; // r7
  __int64 v4; // r2
  void **v5; // r3
  int v6; // r4

  v2 = (__int64 **)(v0 + 756);
  while ( 1 )
  {
    v3 = *v2;
    v4 = **v2;
    if ( (__int64 **)HIDWORD(v4) != v2 || *(__int64 **)(v4 + 4) != v3 )
      break;
    v5 = HalIommuDispatch;
    *v2 = (__int64 *)v4;
    *(_DWORD *)(v4 + 4) = v2;
    if ( v3 == (__int64 *)v2 )
    {
      ((void (__cdecl *)())v5[8])();
      *(_DWORD *)(v0 + 744) = 0;
      ExpFreeAsid(v1 - 1);
      JUMPOUT(0x461DA2);
    }
    v6 = *((_DWORD *)v3 + 2);
    ((void (__cdecl *)())v5[6])();
    ExpSvmDereferenceDevice(v6);
    ExFreePoolWithTag(v3, 0);
  }
  __fastfail(3u);
}
