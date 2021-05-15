// WmipFindISinGEbyName 
 
int __fastcall WmipFindISinGEbyName(int a1, unsigned __int16 *a2, _DWORD *a3)
{
  int v6; // r0
  _DWORD *v7; // r5
  _DWORD *v8; // r10
  int v9; // r3
  unsigned int v11; // r6
  int v12; // r4
  char **v13; // r7
  char *v14; // t1

  wcslen(a2);
  v6 = KeWaitForSingleObject((unsigned int)&WmipSMMutex, 0, 0, 0, 0);
  v7 = *(_DWORD **)(a1 + 32);
  v8 = (_DWORD *)(a1 + 32);
  while ( 1 )
  {
    if ( v7 == v8 )
    {
      v7 = 0;
      goto LABEL_12;
    }
    v9 = v7[2];
    if ( (v9 & 1) != 0 )
      return sub_7EF260(v6);
    if ( (v9 & 2) != 0 )
    {
      v11 = v7[9];
      v12 = 0;
      if ( v11 )
        break;
    }
LABEL_10:
    v7 = (_DWORD *)*v7;
  }
  v13 = (char **)v7[12];
  while ( 1 )
  {
    v14 = *v13++;
    v6 = wcscmp((char *)a2, v14);
    if ( !v6 )
      break;
    if ( ++v12 >= v11 )
      goto LABEL_10;
  }
  *a3 = v12;
  WmipReferenceEntry((int)v7);
LABEL_12:
  KeReleaseMutex((int)&WmipSMMutex);
  return (int)v7;
}
