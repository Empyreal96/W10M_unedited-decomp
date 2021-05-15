// HdlspSetBlueScreenInformation 
 
int __fastcall HdlspSetBlueScreenInformation(unsigned int *a1, int a2)
{
  int v3; // r6
  int v4; // r4
  unsigned int v5; // r2
  char *v6; // r10
  int *v7; // r8
  int *i; // r5
  char *v9; // r0
  char *v10; // r9
  _BYTE *v11; // r0
  _BYTE *v12; // r6
  unsigned int v13; // r0
  int v14; // r2
  unsigned int v15; // r0
  _BYTE *v16; // r0
  char *v17; // r0
  char *v18; // r6
  _BYTE *v19; // r0
  int v20; // r2

  v3 = HeadlessGlobals;
  if ( (*(_DWORD *)(HeadlessGlobals + 24) & 2) != 0 )
    return -1073741823;
  if ( !a1 )
    return -1073741811;
  v5 = *a1;
  if ( *a1 < 2 )
    return -1073741811;
  if ( v5 >= a2 - 8 )
    return -1073741811;
  v6 = (char *)a1 + v5;
  if ( *((_BYTE *)a1 + v5 + 3) || *((_BYTE *)a1 + a2 - 4) )
    return -1073741811;
  v7 = *(int **)(HeadlessGlobals + 20);
  v4 = 0;
  for ( i = v7; i; i = (int *)i[2] )
  {
    if ( !strcmp(*i, a1 + 1) )
      break;
    v7 = i;
  }
  v9 = strlen((unsigned int)(v6 + 4));
  v10 = v9;
  if ( !i )
  {
    if ( v9 )
    {
      i = (int *)ExAllocatePoolWithTag(512, 12, 1936483400);
      if ( !i )
        return v4;
      v16 = (_BYTE *)ExAllocatePoolWithTag(512, (int)(v10 + 1), 1936483400);
      i[1] = (int)v16;
      if ( !v16 )
      {
        v4 = -1073741801;
        goto LABEL_32;
      }
      strcpy_s(v16, (int)(v10 + 1), v6 + 4);
      v17 = strlen((unsigned int)(a1 + 1));
      v18 = v17;
      if ( v17 )
      {
        v19 = (_BYTE *)ExAllocatePoolWithTag(512, (int)(v17 + 1), 1936483400);
        *i = (int)v19;
        if ( v19 )
        {
          strcpy_s(v19, (int)(v18 + 1), (char *)a1 + 4);
          v20 = HeadlessGlobals;
          i[2] = *(_DWORD *)(HeadlessGlobals + 20);
          *(_DWORD *)(v20 + 20) = i;
          return v4;
        }
        v4 = -1073741801;
      }
      else
      {
        v4 = -1073741811;
      }
      v15 = i[1];
LABEL_21:
      ExFreePoolWithTag(v15);
LABEL_32:
      v13 = (unsigned int)i;
      goto LABEL_33;
    }
    return -1073741811;
  }
  if ( !v9 )
  {
    v14 = i[2];
    v7[2] = v14;
    if ( *(int **)(v3 + 20) == i )
      *(_DWORD *)(v3 + 20) = v14;
    if ( (*(_DWORD *)(v3 + 24) & 2) != 0 )
      return v4;
    ExFreePoolWithTag(i[1]);
    v15 = *i;
    goto LABEL_21;
  }
  v11 = (_BYTE *)ExAllocatePoolWithTag(512, (int)(v9 + 1), 1936483400);
  v12 = v11;
  if ( !v11 )
    return -1073741801;
  strcpy_s(v11, (int)(v10 + 1), v6 + 4);
  v13 = i[1];
  i[1] = (int)v12;
  if ( (*(_DWORD *)(HeadlessGlobals + 24) & 2) == 0 )
LABEL_33:
    ExFreePoolWithTag(v13);
  return v4;
}
