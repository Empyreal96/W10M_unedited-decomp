// SepFilterPrivilegeAudits 
 
int __fastcall SepFilterPrivilegeAudits(char a1, int *a2)
{
  int v2; // r5
  int v3; // r4
  int *v4; // r8
  _DWORD *v5; // r6
  int v6; // lr
  int v7; // r10
  int v8; // t1
  int **v9; // r7
  int *v10; // t1
  int *v11; // r7
  _DWORD *v12; // r1
  int v13; // r6
  int **v14; // r0
  int v15; // r8
  int v16; // t1
  int result; // r0
  int *v18; // t1

  v2 = 0;
  if ( !a2 )
    goto LABEL_20;
  v3 = *a2;
  if ( !*a2 )
    goto LABEL_20;
  v4 = a2 + 2;
  v5 = a2 + 3;
  v6 = *a2;
  do
  {
    v8 = *v4;
    v4 += 3;
    v7 = v8;
    v9 = SepFilterPrivileges;
    while ( v7 != **v9 || *v5 != (*v9)[1] )
    {
      v10 = v9[1];
      ++v9;
      if ( !v10 )
        goto LABEL_10;
    }
    ++v2;
LABEL_10:
    v5 += 3;
    --v6;
  }
  while ( v6 );
  if ( (a1 & 1) != 0 && v3 )
  {
    v11 = a2 + 2;
    v12 = a2 + 3;
    v13 = v3;
    do
    {
      v14 = &SepServicesFilterPrivileges;
      v16 = *v11;
      v11 += 3;
      v15 = v16;
      do
      {
        if ( v15 == **v14 )
          return sub_7E8BCC();
        v18 = v14[1];
        ++v14;
      }
      while ( v18 );
      v12 += 3;
      --v13;
    }
    while ( v13 );
  }
  if ( v2 != v3 )
    result = 1;
  else
LABEL_20:
    result = 0;
  return result;
}
