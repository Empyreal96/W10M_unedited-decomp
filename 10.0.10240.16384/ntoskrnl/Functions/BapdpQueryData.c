// BapdpQueryData 
 
int __fastcall BapdpQueryData(int a1, unsigned int a2, int a3, int a4, unsigned int *a5)
{
  unsigned int v5; // r0
  unsigned int v7; // r8
  int v8; // r7
  int *v9; // r5
  _DWORD *v10; // r4
  unsigned int v11; // r3
  unsigned int v12; // r2
  int result; // r0

  v5 = a2;
  if ( !a5 )
    return -1073741811;
  if ( !a2 )
    return -1073741811;
  v7 = *a5;
  if ( *a5 )
  {
    if ( !a4 )
      return -1073741811;
  }
  v8 = 0;
  v9 = (int *)dword_6475C0;
  while ( 1 )
  {
    do
    {
      if ( v9 == &dword_6475C0 )
        return -1073741275;
      v10 = (_DWORD *)v9[2];
      v9 = (int *)*v9;
      v11 = v10[8];
    }
    while ( !v11 || v11 > 2 );
    if ( !memcmp(v5, (unsigned int)(v10 + 4), 16) )
      break;
LABEL_9:
    v5 = a2;
  }
  if ( a3 != v8 )
  {
    ++v8;
    goto LABEL_9;
  }
  v12 = v10[9];
  if ( v7 >= v12 )
  {
    memmove(a4, (int)v10 + v10[10], v12);
    result = 0;
  }
  else
  {
    result = -1073741789;
    *a5 = v12;
  }
  return result;
}
