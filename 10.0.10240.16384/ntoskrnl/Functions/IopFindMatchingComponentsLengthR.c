// IopFindMatchingComponentsLengthR 
 
int __fastcall IopFindMatchingComponentsLengthR(unsigned __int16 *a1, unsigned __int16 *a2)
{
  int v2; // r6
  unsigned int v3; // r4
  unsigned __int16 *v4; // r2
  unsigned __int16 *v5; // r0
  unsigned int v6; // r7
  unsigned __int16 *v7; // r5
  int v8; // r1
  int v9; // t1
  int v10; // t1
  int result; // r0

  v2 = *a1;
  v3 = *((_DWORD *)a1 + 1);
  v4 = (unsigned __int16 *)(v3 + v2);
  v5 = 0;
  if ( v3 + v2 < v3 )
    goto LABEL_10;
  v6 = *((_DWORD *)a2 + 1);
  v7 = (unsigned __int16 *)(v6 + *a2);
  do
  {
    if ( (unsigned int)v7 < v6 )
      break;
    v9 = *v4--;
    v8 = v9;
    v10 = *v7--;
    if ( v8 != v10 )
      break;
    if ( v8 == 92 )
      v5 = v4 + 1;
  }
  while ( (unsigned int)v4 >= v3 );
  if ( v5 )
    result = (unsigned __int16)((int)(v3 - (_DWORD)v5 + v2) >> 1);
  else
LABEL_10:
    result = 0;
  return result;
}
