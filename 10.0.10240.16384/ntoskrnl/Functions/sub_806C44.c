// sub_806C44 
 
void sub_806C44()
{
  int v0; // r5
  _DWORD **v1; // r6
  _DWORD *v2; // r1
  __int64 v3; // r2

  while ( *v1 != v1 )
  {
    LODWORD(v3) = *v1;
    HIDWORD(v3) = (*v1)[1];
    v2 = (_DWORD *)**v1;
    if ( v3 != __PAIR64__((unsigned int)v1, v2[1]) )
      __fastfail(3u);
    *v1 = v2;
    v2[1] = v1;
    *(_DWORD *)v3 = v0;
    *(_DWORD *)(v3 + 4) = v0;
    FsRtlFreeExtraCreateParameter(v3 + 44);
  }
  JUMPOUT(0x756EEA);
}
