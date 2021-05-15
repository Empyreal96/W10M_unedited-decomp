// ExpWnfCaptureScopeInstanceId 
 
int __fastcall ExpWnfCaptureScopeInstanceId(int a1, int *a2, char a3, _DWORD *a4, int *a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
  int *v11; // r4
  _DWORD *v13; // r3
  int v15; // r3
  int v16; // r0

  v11 = a2;
  if ( !a2 )
  {
    v13 = 0;
LABEL_3:
    *a4 = v13;
    return 0;
  }
  if ( a1 != 1 )
    return sub_7C4914(a1, (int)a2, a3, (int)a4, (int)a5, a6, a7, a8, a9, a10, a11);
  if ( a3 )
  {
    if ( (unsigned int)a2 >= MmUserProbeAddress )
      v11 = (int *)MmUserProbeAddress;
    v15 = *v11;
  }
  else
  {
    v15 = *a2;
  }
  a5[1] = v15;
  v16 = MmGetSessionById(v15, (int)a2, a3, v15);
  *a5 = v16;
  if ( v16 )
  {
    v13 = a5 + 1;
    goto LABEL_3;
  }
  return -1073741811;
}
