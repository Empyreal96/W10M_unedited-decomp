// ApiSetResolveToHost 
 
int __fastcall ApiSetResolveToHost(int a1, unsigned __int16 *a2, int a3, char *a4, int a5)
{
  unsigned int v6; // r4
  char v7; // r7
  _DWORD *v10; // lr
  unsigned int v11; // r0
  unsigned int v12; // r5
  char *v14; // r2
  int v15; // t1
  int v16; // r0
  int v17; // r0

  *(_DWORD *)a5 = 0;
  *(_DWORD *)(a5 + 4) = 0;
  v6 = *a2;
  v7 = 0;
  if ( v6 < 8 )
    goto LABEL_6;
  v10 = (_DWORD *)*((_DWORD *)a2 + 1);
  v11 = *v10 & 0xFFDFFFDF;
  v12 = v10[1] & 0xFFFFFFDF;
  if ( (v11 != 5242945 || v12 != 2949193) && (v11 != 5767237 || v12 != 2949204) )
    goto LABEL_6;
  v14 = (char *)v10 + v6;
  do
  {
    if ( v6 <= 1 )
      break;
    v15 = *((unsigned __int16 *)v14 - 1);
    v14 -= 2;
    v6 -= 2;
  }
  while ( v15 != 45 );
  if ( !((unsigned __int16)v6 >> 1) )
    goto LABEL_6;
  v16 = ApiSetpSearchForApiSet(a1, v10);
  if ( !v16 )
    goto LABEL_6;
  if ( !a3 || *(_DWORD *)(v16 + 20) <= 1u )
  {
    if ( *(_DWORD *)(v16 + 20) )
    {
      v17 = *(_DWORD *)(v16 + 16) + a1;
      *(_DWORD *)(a5 + 4) = *(_DWORD *)(v17 + 12) + a1;
      v7 = 1;
      *(_WORD *)(a5 + 2) = *(_DWORD *)(v17 + 16);
      *(_WORD *)a5 = *(_DWORD *)(v17 + 16);
    }
LABEL_6:
    *a4 = v7;
    return 0;
  }
  return sub_50A620();
}
