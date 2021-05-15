// PiDevCfgQueryIncludedDriverConfigurations 
 
int __fastcall PiDevCfgQueryIncludedDriverConfigurations(int a1)
{
  int v1; // r3
  int **v2; // r4
  int *v3; // r2
  int v5; // r3
  __int64 v6; // kr00_8
  int *v7; // [sp+20h] [bp-30h] BYREF
  int **v8; // [sp+24h] [bp-2Ch]

  v1 = *(_DWORD *)(a1 + 204);
  v2 = &v7;
  v3 = (int *)&v7;
  v7 = (int *)&v7;
  v8 = &v7;
  if ( v1 )
    return sub_7E16D0();
  do
  {
    if ( v3 == (int *)&v7 )
    {
      v5 = 0;
    }
    else
    {
      v6 = *(_QWORD *)v2;
      if ( *v2 != (int *)&v7 || *(int ***)HIDWORD(v6) != v2 )
        __fastfail(3u);
      v8 = (int **)v2[1];
      *(_DWORD *)HIDWORD(v6) = &v7;
      ExFreePoolWithTag((unsigned int)v2);
      v3 = v7;
      v2 = v8;
      v5 = 1;
    }
  }
  while ( v5 );
  return 0;
}
