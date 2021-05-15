// StEtaCheckForRefresh 
 
int __fastcall StEtaCheckForRefresh(int a1, int *a2, int *a3, _DWORD *a4)
{
  int v5; // r6
  unsigned int v6; // r7
  int *v7; // r5
  int v8; // t1
  int v10; // r3

  v5 = 0;
  while ( 1 )
  {
    v6 = *(_DWORD *)(a1 + 16);
    if ( v6 )
      break;
LABEL_7:
    ++v5;
    a1 += 4;
    if ( v5 >= 2 )
      return 0;
  }
  v7 = *(int **)(a1 + 16);
  while ( *((unsigned __int16 *)v7 + 2) <= 0x80u || !*((_QWORD *)v7 + 1) )
  {
    v8 = *v7;
    v7 += 8;
    if ( v8 == -1 )
      goto LABEL_7;
  }
  if ( (unsigned int)v7 <= v6 )
    v10 = 0;
  else
    v10 = *(v7 - 8) + 1;
  if ( a3 )
    *a3 = v10;
  if ( a4 )
    *a4 = *v7;
  if ( a2 )
    *a2 = v5;
  return 1;
}
