// sub_7CD5C0 
 
void sub_7CD5C0()
{
  __int64 **v0; // r5
  __int64 *v1; // r0
  __int64 v2; // r2
  unsigned int v3; // r4

  v1 = *v0;
  v2 = **v0;
  if ( (__int64 **)HIDWORD(v2) == v0 )
  {
    HIDWORD(v2) = *(_DWORD *)(v2 + 4);
    if ( (__int64 *)HIDWORD(v2) == v1 )
    {
      *v0 = (__int64 *)v2;
      *(_DWORD *)(v2 + 4) = v0;
      if ( v1 )
      {
        v3 = *((_DWORD *)v1 + 3);
        RtlDeleteElementGenericTableAvl((int)(v0 + 2), (int)v1, v2, SHIDWORD(v2));
        ExFreePoolWithTag(v3);
      }
      JUMPOUT(0x77140A);
    }
  }
  __fastfail(3u);
}
